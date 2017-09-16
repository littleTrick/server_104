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
#include "dlt634_5104slave_app.h"
#include "dlt634_5104slave_disk.h"
#include "dlt634_5101master_app.h"
#include "dlt634_5101master_disk.h"

using namespace std;

/* -----------------------------------------------------------------------------
** 函数名称: thread_main_104slave
** 功能描述: 104线程入口
** 输　  入: 无
** 输　  出: 无
** 全局变量: circularQueue，写入主站的报文至循环队列中
** 调用模块: DLT634_5104_SlaveInit()、TCPSocket类
** 作　  者: Mrs.Ly
** 日　  期: 2017.09.12
** -----------------------------------------------------------------------------
** 修 改 人:
** 修改内容:
** 日　  期:
** ---------------------------------------------------------------------------*/

Queue circularQueue;//用于存储主站报文
Queue *ptrQ = &circularQueue;

void* thread_main_104slave(void*)
{
    printf("104 thread id %lu", (unsigned long)pthread_self());
    uint8_t buff[255];
    circularQueue.front = circularQueue.rear = 0;

    DLT634_5104_SlaveInit();//１０４从站初始化与定时启动

    DatabaseInit();//数据缓存区初始化

    TCPSocket tcpConnect;//网络套接字建立连接
    tcpConnect.setReuseAddr(true);
    tcpConnect.bind("0.0.0.0",2404);
    tcpConnect.listen();
    TCPSocket *client = tcpConnect.accept();

    if(client == NULL)
    {
        printf("client falied connect");
    }
    else
    {
        setClientFd(client->fd());
        printf("client success connect fd = %d \n",client->fd());
        while(1)
        {
            int n = client->read(buff,255);
            if(n < 0)
            {
                //#if _DEBUG
                printf("read error client return number  = %d,errno = %d\n",(int)n,errno);
                pthread_exit(NULL);
            }
            if(n == 0)
            {
                printf("connection closed by client");
                pthread_exit(NULL);
            }
            else
            {
                printf("----------------------- \n");
                printf("104 salve %d \n",n);
                for(int i = 0;i < n;i++)
                {
                    printf("%02X ",buff[i]);
                    AddQ(ptrQ,buff[i]);
                    //printf("%02X ",circularQueue.data[i]);已证实数据已进入循环队列
                }
                printf("\n");
            }
        }
    }
    return 0;
}

/* -----------------------------------------------------------------------------
** 函数名称: thread_main_101master
** 功能描述: 101主站线程入口
** 输　  入: 无
** 输　  出: 无
** 全局变量: circularQueue，写入主站的报文至循环队列中
** 调用模块: DLT634_5104_SlaveInit()、TCPSocket类
** 作　  者: Mrs.Ly
** 日　  期: 2017.09.12
** -----------------------------------------------------------------------------
** 修 改 人:
** 修改内容:
** 日　  期:
** ---------------------------------------------------------------------------*/
Queue circular_queue_101master;//用于存储底层设备报文
Queue *ptr_101master = &circular_queue_101master;

void* thread_main_101master(void*)
{
    printf("101 thread id %lu\n",(unsigned long)pthread_self());
    circular_queue_101master.front = circular_queue_101master.rear = 0;
    uint8_t buff[255];
    DLT634_5101_MasterTask();//101主站初始化与定时运行
    SerialPort serialPort;//建立串口链接
    //const char *portname = "/dev/ttyS2";
//    serialPort.fd_ = open (portname, O_RDWR | O_NOCTTY | O_SYNC);
    serialPort.fd_= open("/tmp/fack_serial", O_RDWR);
    bool flag = serialPort.fd_;
    //bool flag = serialPort.openPort("/dev/ttyS2");
    //serialPort.SetSerialAttribs(B9600,0);//mo parity
    
    setSerialFd(serialPort.fd_);
    if(!flag)
    {
        std::cout << "fail to open serial" << std::endl;
        pthread_exit(NULL);
    }
    else
    {   while(1)
        {
            //int n = serialPort.readPort(buff,255);
            int n = read(serialPort.fd_, buff, 255);
            if(n < 0)
            {
                printf("read error from serial1 return number  = %d,errno = %d\n",(int)n,errno);
                pthread_exit(NULL);
            }
            if(n == 0)
            {
                printf("connection closed by device %d \n",serialPort.fd_);
                pthread_exit(NULL);
            }
            else
            {
                printf("*******************************\n");
                printf("101 master numberis : %d \n",n);
                for(int i= 0;i < n;i++)
                {
                    printf("%02X ",buff[i]);
                    AddQ(ptr_101master,buff[i]);
                }
                printf("\n");
            }
        }

    }
    
    return 0;
}

int main()
{
    void *tret;
    pthread_t ntid_104slave;
    if (pthread_create(&ntid_104slave, NULL, thread_main_104slave, NULL))//创建１０４从站线程
    {
        std::cout << "fail to create pthread" << std::endl;
    }
    else
    {
        std::cout << std::endl;
        std::cout << "thread id =" << (unsigned int)ntid_104slave << std::endl;
    }

    pthread_t ntid_101master;
    if (pthread_create(&ntid_101master, NULL, thread_main_101master, NULL))//创建１０１主站线程
    {
        std::cout << "fail to create pthread" <<std::endl;
    }
    else
    {
        std::cout << std::endl;
        std::cout << "thread id =" << (unsigned int)ntid_101master << std::endl;
    }

    pthread_join(ntid_104slave,&tret);//阻塞至线程结束
    pthread_join(ntid_101master,&tret);

    exit(0);
//    while(1)
//    {
//        sleep(30000);
//    }

//    return 0;
}

