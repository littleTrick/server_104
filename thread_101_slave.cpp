#include "thread_101_slave.h"
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
#include "serialport.h"
#include "dlt634_5101slave_app.h"
#include "dlt634_5101slave_disk.h"
#include "queue.h"

Queue g_queue_101slave;
Queue *ptr_101slave = &g_queue_101slave;

void* thread_main_101_slave(void *)
{
    printf("101 slave thread id %lu\n",(unsigned long)pthread_self());

    SerialPort serialPortSlave("/dev/ttyS1"); //CN15

    if (!serialPortSlave.Open()) {
        return 0;
    }
    serialPortSlave.SetSpeed(B9600);
    serialPortSlave.SetParity(false);
    setMasterSPfd(serialPortSlave.fd());

    // 101从站程序初始化
    DLT634_5101_SlaveTask();

    // create epoll instance
    int epfd = epoll_create(1);
    if (epfd < 0)
    {
        perror("epoll_create");
        abort();
    }

    // add epoll events
    struct epoll_event events[2];
    events[0].data.fd = serialPortSlave.fd();
    events[0].events = EPOLLIN | EPOLLRDHUP;

    if (epoll_ctl(epfd, EPOLL_CTL_ADD, serialPortSlave.fd(), &events[0]))
    {
        perror("epoll_ctl");
        abort();
    }
    char buff[255];
    while (1)
    {
        int nevents = epoll_wait(epfd, events, 1, 100);//100ms
        if (nevents < 0)
        {
            perror("epoll_wait");
            break;
        }
        if (nevents == 0) //timeout
        {
            DLT634_5101_SLAVE_Clock(0);
            continue;
        }

        int i = 0;
        for (i = 0; i < nevents; i++)
        {
            if (events[i].data.fd == serialPortSlave.fd())
            {
                int n = serialPortSlave.Read(buff, sizeof(buff));
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
                    printf("device closed by peer: %s\n", serialPortSlave.name().c_str());
                    break;
                }
                else
                {
                    printf("*******************************\n");
                    printf("101 salve numberis : %d \n",n);
                    ptr_101slave->EnqueueAll(buff, n);
                    printf("\n");
                     DLT634_5101_SLAVE_Clock(0);
                }
            }
       }

        if (i < nevents)
            break;
    }

    close(epfd);
    fprintf(stderr, "101 salve thread exit\n");
    return 0;
}



