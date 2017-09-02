#include <stdio.h>
#include <unistd.h>
#include "data_cache.h"

extern int clientfd;
extern Queue *ptrQ;

void AddQ(Queue *ptrQ,unsigned char item)
{
    if((ptrQ->rear + 1) % MaxSize  == ptrQ->front)
    {
        printf("the queue is full");
    }
    else
    {
        ptrQ->rear = (ptrQ->rear + 1) % MaxSize;
        ptrQ->data[ptrQ->rear] = item;

    }
}

unsigned char DeleteQ(Queue *ptrQ)
{
    ptrQ->front = (ptrQ->front + 1) % MaxSize;
    return ptrQ->data[ptrQ->front];
}

//从网络读取数据
int readTCP(unsigned char *pbuf, unsigned short size)
{
    int len;
    for(len = 0; len < size;len++)
    {
        if(ptrQ->rear == ptrQ->front)
        {
            break;
        }
        *(pbuf++) = DeleteQ(ptrQ);
        printf("%02x ",pbuf[len]);
    }
    return len;
}

//网络写数
int writeTCP(const char *data, int sz)
{
    ssize_t nwrite = write(clientfd,data,sz);
    if(nwrite < 0)
    {
        printf("write error clint fd");
    }
    return nwrite;
}

//关闭与主站的链接
void ShutDown()
{
    if (clientfd >= 0)
    {
        close(clientfd);
        clientfd = -1;
    }
}

//从主站中读取数据
int Readx(unsigned char *pbuf, unsigned short count, unsigned char port)
{
    unsigned short len = 0;

    switch (port)
    {
        case 1:
            len = readTCP(pbuf, count);
            break;
    }
    return len;
}

//写入数据到主站中
int WriteX(unsigned char *pbuf, unsigned short count, unsigned char port)
{
    unsigned short len = 0;

    switch (port)
    {
        case 1:
            len = writeTCP(pbuf, count);
            break;
    }
    return len;
}
