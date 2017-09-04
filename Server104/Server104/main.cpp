#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include "data_cache.h"
#include "tcpsocket.h"
#include "dlt634_5104slave_app.h"
#include "dlt634_5104slave_disk.h"

using namespace std;

Queue circularQueue;//用于存储主站报文
Queue *ptrQ = &circularQueue;

int main()
{
    unsigned char buff[255];
    circularQueue.front = circularQueue.rear = 0;

    DLT634_5104_SlaveInit();

    TCPSocket tcpConnect;
    tcpConnect.setReuseAddr(true);
    tcpConnect.bind("INADDR_ANY",2404);
    tcpConnect.listen();
    TCPSocket *client = tcpConnect.accept();

    setClientFd(client->fd());
    if(client == NULL)
    {
        printf("client falied connect");
    }
    else
    {
        printf("client success connect fd = %d \n",client->fd());
        while(1)
        {
            int n = client->read(buff,255);
           // ssize_t n = read(clientfd, buff, 255);
            if(n < 0)
            {
                printf("read error client return number  = %d,errno = %d\n",(int)n,errno);
                return -1;
            }
            if(n == 0)
            {
                printf("connection closed by client");
                return -1;
            }
            else
            {
                printf("%d \n",(int)n);
                for(int i= 0;i < n;i++)
                {
                    printf("%02X ",buff[i]);
                    AddQ(ptrQ,buff[i]);
                }
                printf("\n");
            }
            printf("the queue is:");
            for(int i= 1;i <= n;i++)
            {
                printf("%02X ",ptrQ->data[i]);
            }
            printf("\n");
        }
    }

    return 0;
}

