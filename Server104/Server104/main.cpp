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
#include "dlt634_5104slave_app.h"
#include "dlt634_5104slave_disk.h"

using namespace std;

int clientfd;
Queue circularQueue;//用于存储主站报文
Queue *ptrQ = &circularQueue;

int main()
{
    unsigned char buff[255];
    circularQueue.front = circularQueue.rear = 0;

    DLT634_5104_SlaveInit();

    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if (sockfd < 0)
    {
        perror("socket");
        abort();
    }
    int value = 1;
    setsockopt(sockfd,SOL_SOCKET, SO_REUSEADDR, &value, sizeof(int));

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(2404);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    int r = bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    if(r < 0)
    {
        perror("bind");
    }

    listen(sockfd,10);
    if(r < 0)
    {
        perror("listen");
    }

    struct sockaddr_in clientaddr;
    socklen_t clientaddrlen = sizeof(clientaddr);
    clientfd = accept(sockfd,(struct sockaddr *)&clientaddr,&clientaddrlen);

    if(clientfd <= 0)
    {
        printf("client falied connect");
    }
    else
    {
        printf("client success connect fd = %d \n",clientfd);
        while(1)
        {
            ssize_t n = read(clientfd, buff, 255);
            if(n < 0)
            {
                printf("read error client return number  = %d,errno = %d\n",n,errno);
                return -1;
            }
            if(n == 0)
            {
                printf("connection closed by client");
                return -1;
            }
            else
            {
                printf("%d \n",n);
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

