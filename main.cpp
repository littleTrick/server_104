#include <iostream>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <signal.h>
#include <sys/socket.h>
#include <unistd.h>
#include <termios.h>
#include "data_cache.h"
#include "tcpsocket.h"
#include "serialport.h"
#include "mock_serialport.h"
#include "dlt634_5104slave_app.h"
#include "dlt634_5104slave_disk.h"
#include "dlt634_5101master_app.h"
#include "dlt634_5101master_disk.h"
#include "queue.h"

using namespace std;

Queue circularQueue;
Queue *ptrQ = &circularQueue;

Queue g_queue_101;
Queue *ptr_101master = &g_queue_101;

void process_client(TCPSocket *client)
{
    char buff[255];
	setClientFd(client->fd());
	printf("client success connect fd = %d \n",client->fd());
	while(1)
	{
	    int n = client->read(buff,255);
	    if(n < 0)
	    {
			break;
	    }
	    if(n == 0)
	    {
	        printf("connection closed by client\n");
			break;
	    }
	    else
	    {
	        printf("----------------------- \n");
	        printf("104 salve %d \n",n);
	        ptrQ->EnqueueAll(buff, n);
			DLT634_5104_SLAVE_Clock(0);
	    }
	}
	setClientFd(-1);
}

void* thread_main_104slave(void*)
{
    printf("104 thread id %lu\n", (unsigned long)pthread_self());

    DLT634_5104_SlaveInit();//１０４从站初始化与定时启动

    DatabaseInit();//数据缓存区初始化

    TCPSocket tcpConnect;//网络套接字建立连接
    tcpConnect.setReuseAddr(true);
    if (!tcpConnect.bind("0.0.0.0",2404)) 
	{
		return 0;
	}
    if (!tcpConnect.listen()) 
	{
		return 0;
	}

	while (1) 
	{
    	TCPSocket *client = tcpConnect.accept();
    	if(client == NULL)
    	{
    	    printf("client falied connect");
			return 0;
    	}
    	else
    	{
			process_client(client);
    	}
		delete client;
	}
    return 0;
}

void* thread_main_101master(void *arg)
{
    printf("101 thread id %lu\n",(unsigned long)pthread_self());

    DLT634_5101_MasterTask();//101主站初始化与定时运行

#if 0
	const char *name = (const char*)arg;
    SerialPort serialPort(name);
#else
	MockSerialPort serialPort(0);
#endif
	if (!serialPort.Open()) {
		return 0;
	}
	serialPort.SetSpeed(B9600);
	serialPort.SetParity(false);
    setSerialFd(serialPort.fd());

    char buff[255];
    while(1)
    {
        int n = serialPort.Read(buff,255);
        if(n < 0)
        {
			if (errno == EINTR || errno == EAGAIN) {
				continue;
			}
            printf("read error from serial1 return number  = %d,errno = %d\n",(int)n,errno);
            pthread_exit(NULL);
        }
        if(n == 0)
        {
            printf("device closed by peer: %s\n", serialPort.name().c_str());
            pthread_exit(NULL);
        }
        else
        {
            printf("*******************************\n");
            printf("101 master numberis : %d \n",n);
			ptr_101master->EnqueueAll(buff, n);
            printf("\n");
			DLT634_5101_MASTER_Clock(0);
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 2) 
	{
		printf("Usage: %s <serial port>\n", argv[0]);
		return -1;
	}

	//创建１０４从站线程
    pthread_t tid_104;
    if (pthread_create(&tid_104, NULL, thread_main_104slave, NULL))
    {
        std::cout << "fail to create pthread" << std::endl;
		return -1;
    }

	//创建１０１主站线程
    pthread_t tid_101;
    if (pthread_create(&tid_101, NULL, thread_main_101master, (void*)argv[1]))
    {
        std::cout << "fail to create pthread" << std::endl;
		return -1;
    }

    pthread_join(tid_104, NULL);//阻塞至线程结束
    pthread_join(tid_101, NULL);

    return 0;
}

