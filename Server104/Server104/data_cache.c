#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <dlt634_5104slave_disk.h>
#include "data_cache.h"

extern Queue *ptrQ;

#pragma pack(push,1)
typedef struct
{
        uint32_t Value;
        uint8_t QDS;
}YCSTRU;

typedef struct
{
         uint8_t InfoAddr_L;
         uint8_t InfoAddr_H;
         uint8_t Value;
        _DATABASE_CP56Time2a_t CP56Time2a;
}SOE_t;

typedef struct
{
        uint8_t InfoAddr_L;
        uint8_t InfoAddr_H;
        uint32_t Value;
        uint8_t QDS;
}NVA;

typedef struct
{
        uint8_t Length;
        uint8_t arry[250];
}FEvent;
#pragma pack(pop)

static unsigned char YXDB[_DATABASE_YX_TOTAL_NUM]; // 遥信数据库
static YCSTRU YCDB[_DATABASE_YC_TOTAL_NUM]; // 遥测数据库
static SOE_t SOEDB[_DATABASE_SOELIMIT]; // SOE数据库
static NVA NVADB[_DATABASE_NVALIMIT]; // NVA数据库
static FEvent FEventDB[_DATABASE_EVENTLIMIT]; // NVA数据库
static _DATABASE_PASDU DATABASE_TXTemp;
static _DATABASE_PASDU DATABASE_RXTemp;

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
    ssize_t nwrite = write(getClientFd(),data,sz);
    if(nwrite < 0)
    {
        printf("write error clint fd");
    }
    return nwrite;
}

//关闭与主站的链接
void ShutDown()
{
    if (getClientFd() >= 0)
    {
        close(getClientFd());
        setClientFd(-1);
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

//读取总召唤遥信报文,信息地址为addr+num,存储到pbuf指向的地方
unsigned char DBRead_YX(unsigned short addr,unsigned char num,unsigned char *pbuf)
{
    memset(&DATABASE_TXTemp,0,sizeof(_DATABASE_PASDU));

    if((addr>=_DATABASE_YX_START_ADDR)&&(addr + num <= _DATABASE_YX_START_ADDR + _DATABASE_YX_TOTAL_NUM))
        {
            DATABASE_TXTemp.status.Length = sizeof(DATABASE_TXTemp.status) + sizeof(DATABASE_TXTemp.Head) + 2 + num*1;
            DATABASE_TXTemp.Head.COT_L = _DATABASE_COT_INTROGEN;
            DATABASE_TXTemp.Head.TypeID = _DATABASE_M_SP_NA_1;
            DATABASE_TXTemp.Head.VSQ = num|0x80;
            DATABASE_TXTemp.Data.C_1.SQ1.InfoAddr_H = (addr>>8)&0xFF;
            DATABASE_TXTemp.Data.C_1.SQ1.InfoAddr_L = addr&0xFF;
            memcpy(&DATABASE_TXTemp.Data.C_1.SQ1.Array[0].Value,&YXDB[addr - _DATABASE_YX_START_ADDR],num);
            memcpy(pbuf,&DATABASE_TXTemp,DATABASE_TXTemp.status.Length);
            return(TRUE);
    }
    return(FALSE);
}
