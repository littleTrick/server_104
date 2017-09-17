#include "thread_104.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <unistd.h>
#include "data_cache.h"
#include "tcpsocket.h"
#include "mock_serialport.h"
#include "dlt634_5104slave_app.h"
#include "dlt634_5104slave_disk.h"
#include "queue.h"
#include "timestamp.h"

Queue circularQueue;
Queue *ptrQ = &circularQueue;

static void process_client(TCPSocket *client)
{
    char buff[255];
    setClientFd(client->fd());
    printf("new connection established fd = %d \n",client->fd());

    client->setblocking(false);
    // create epoll instance
    int epfd = epoll_create(1);
    if (epfd < 0) 
    {
        perror("epoll_create");
        abort();
    }

    // add epoll events
    struct epoll_event events[2];
    events[0].data.fd = client->fd();
    events[0].events = EPOLLIN | EPOLLRDHUP;

    if (epoll_ctl(epfd, EPOLL_CTL_ADD, client->fd(), &events[0]))
    {
        perror("epoll_ctl");
        abort();
    }
    while (1)
    {
        int nevents = epoll_wait(epfd, events, 1, 10);
        if (nevents < 0)
        {
            perror("epoll_wait");
            break;
        }
        if (nevents == 0)
        {
        DLT634_5104_SLAVE_Clock(0);
            continue;
        }

        int i = 0;
        for (; i < nevents; i++)
        {
            if (events[i].data.fd == client->fd())
            {
                int nread = client->read(buff, sizeof(buff));
                if (nread < 0) 
                {
                    fprintf(stderr, "read error: %s\n", strerror(errno));
                    break;
                }
                if (nread == 0) 
                {
                    fprintf(stderr, "connection closed by peer\n");
                    break;
                }
                printf("----------------------- \n");
                printf("104 slave %d \n",nread);
                ptrQ->EnqueueAll(buff, nread);
            } 
        }

        if (i < nevents)
            break;
    }

    ::close(epfd);
    setClientFd(-1);
}

void* thread_main_104(void*)
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


