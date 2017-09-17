#include "thread_101.h"
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <termios.h>
#include <unistd.h>
#include "data_cache.h"
#include "tcpsocket.h"
#include "serialport.h"
#include "mock_serialport.h"
#include "dlt634_5101master_app.h"
#include "dlt634_5101master_disk.h"
#include "queue.h"
#include "timestamp.h"

Queue g_queue_101;
Queue *ptr_101master = &g_queue_101;

void* thread_main_101(void *)
{
    printf("101 thread id %lu\n",(unsigned long)pthread_self());

#if 1
    SerialPort serialPort("/dev/ttyS2");
#else
    MockSerialPort serialPort(0);
#endif
    if (!serialPort.Open()) {
        return 0;
    }
    serialPort.SetSpeed(B9600);
    serialPort.SetParity(false);
    setSerialFd(serialPort.fd());

    // 101主站初始化与定时运行
    DLT634_5101_MasterTask();

    // create epoll instance
    int epfd = epoll_create(1);
    if (epfd < 0) 
    {
        perror("epoll_create");
        abort();
    }

    // add epoll events
    struct epoll_event events[2];
    events[0].data.fd = serialPort.fd();
    events[0].events = EPOLLIN | EPOLLRDHUP;

    if (epoll_ctl(epfd, EPOLL_CTL_ADD, serialPort.fd(), &events[0]))
    {
        perror("epoll_ctl");
        abort();
    }
    char buff[255];
    while (1)
    {
        int nevents = epoll_wait(epfd, events, 1, 100);
        if (nevents < 0)
        {
            perror("epoll_wait");
            break;
        }
        if (nevents == 0)
        {
            DLT634_5101_MASTER_Clock(0);
            continue;
        }

        int i = 0;
        for (i = 0; i < nevents; i++)
        {
            if (events[i].data.fd == serialPort.fd())
            {
                int n = serialPort.Read(buff, sizeof(buff));
                if(n < 0)
                {
                    if (errno == EINTR || errno == EAGAIN) {
                        continue;
                    }
                    printf("read error from serial1 return number  = %d,errno = %d\n",(int)n,errno);
                    break;
                }
                if(n == 0)
                {
                    printf("device closed by peer: %s\n", serialPort.name().c_str());
                    break;
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
       }

        if (i < nevents)
            break;
    }

    close(epfd);
    fprintf(stderr, "101 thread exit\n");
    return 0;
}


