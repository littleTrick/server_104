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

typedef struct
{
        SOE_t *SOE_IN;
        SOE_t *SOE_OUT[MAX_DEV_MUN];
        NVA *NVA_IN;
        NVA *NVA_OUT[MAX_DEV_MUN];
        FEvent *FEvent_IN;
        FEvent *FEvent_OUT[MAX_DEV_MUN];
}DBCONFIG;

#pragma pack(pop)

_DATABASE_CP56Time2a_t SysTime; //系统时间

static DBCONFIG DBCFGS; // 数据库配置指针
static unsigned char YXDB[_DATABASE_YX_TOTAL_NUM]; // 遥信数据库
static YCSTRU YCDB[_DATABASE_YC_TOTAL_NUM]; // 遥测数据库
static SOE_t SOEDB[_DATABASE_SOELIMIT]; // SOE数据库
static NVA NVADB[_DATABASE_NVALIMIT]; // NVA数据库
static FEvent FEventDB[_DATABASE_EVENTLIMIT]; // NVA数据库,暂时未使用
static _DATABASE_PASDU DATABASE_TXTemp;
static _DATABASE_PASDU DATABASE_RXTemp;

void DatabaseInit()
{
    uint32_t i;

    DBCFGS.SOE_IN = SOEDB;
    for(i = 0;i < MAX_DEV_MUN;i++)
    {
        DBCFGS.SOE_OUT[i] = SOEDB;
    }

    DBCFGS.NVA_IN = NVADB;
    for(i = 0;i < MAX_DEV_MUN;i++)
    {
        DBCFGS.NVA_OUT[i] = NVADB;
    }

    DBCFGS.FEvent_IN = FEventDB;
    for(i = 0;i < MAX_DEV_MUN;i++)
    {
        DBCFGS.FEvent_OUT[i] = FEventDB;
    }
}

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

//写入总召唤的遥信报文
void DBWrite_YX( uint8_t *pBuf)
{
    uint32_t addr;

    memset(&DATABASE_RXTemp,0,sizeof(_DATABASE_PASDU));
    DATABASE_RXTemp.status.Length =0x0A;
    DATABASE_RXTemp.Head.TypeID = _DATABASE_M_SP_NA_1;
    DATABASE_RXTemp.Head.VSQ =0x82;
    DATABASE_RXTemp.Head.COT_L =0x14;
    DATABASE_RXTemp.Head.COT_H =0x00;
    DATABASE_RXTemp.Head.PubAddr_L =0x01;
    DATABASE_RXTemp.Head.PubAddr_H =0x00;
    DATABASE_RXTemp.Data.C_1.SQ1.InfoAddr_L =0x03;
    DATABASE_RXTemp.Data.C_1.SQ1.InfoAddr_H =0x00;
    DATABASE_RXTemp.Data.C_1.SQ1.Array[0].Value =0x00;
    DATABASE_RXTemp.Data.C_1.SQ1.Array[1].Value =0x00;


   // memcpy(&DATABASE_RXTemp,pBuf,pBuf[0]);
   // switch(DATABASE_RXTemp.status.symbol.Lock_ID&0x0f)
    //{
    //case 0:
        switch (DATABASE_RXTemp.Head.TypeID)
        {
        case _DATABASE_M_SP_NA_1:
            if(DATABASE_RXTemp.Head.VSQ&0x80)
            {
                addr = DATABASE_RXTemp.Data.C_1.SQ1.InfoAddr_H&0xff;
                addr = (addr << 8)|(DATABASE_RXTemp.Data.C_1.SQ1.InfoAddr_L&0xff);
                printf("yx addr is %d   ",addr);
                if((addr>=_DATABASE_YX_START_ADDR)&&(addr + (DATABASE_RXTemp.Head.VSQ&0x7f) <= _DATABASE_YX_START_ADDR + _DATABASE_YX_TOTAL_NUM))
                {
                    memcpy(&YXDB[addr - _DATABASE_YX_START_ADDR],&DATABASE_RXTemp.Data.C_1.SQ1.Array[0].Value,(DATABASE_RXTemp.Head.VSQ&0x7f));
                }
                printf("YXDB is :");
                for(int i = 0; i < _DATABASE_YX_TOTAL_NUM; i++)
                    printf("%d ",YXDB[i]);
                printf("\n");
            }
            break;
        default:
            break;
        }
    //    break;
   // default:
     //   break;
   // }
}

//读取总召唤遥信报文,信息地址为addr+num,存储到pbuf指向的地方,重组１０４报文
uint8_t DBRead_YX(unsigned short addr,uint8_t num,uint8_t *pbuf)
{
    memset(&DATABASE_TXTemp,0,sizeof(_DATABASE_PASDU));

    if((addr >= _DATABASE_YX_START_ADDR)&&(addr + num <= _DATABASE_YX_START_ADDR + _DATABASE_YX_TOTAL_NUM))
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

//写入遥测报文
void DBWrite_YC(uint8_t *pBuf)
{
    uint32_t addr;

    memset(&DATABASE_RXTemp,0,sizeof(_DATABASE_PASDU));
    DATABASE_RXTemp.status.Length =0x0C;
    DATABASE_RXTemp.Head.TypeID = _DATABASE_M_ME_NC_1;
    DATABASE_RXTemp.Head.VSQ =0x82;
    DATABASE_RXTemp.Head.COT_L =0x14;
    DATABASE_RXTemp.Head.COT_H =0x00;
    DATABASE_RXTemp.Head.PubAddr_L =0x01;
    DATABASE_RXTemp.Head.PubAddr_H =0x00;
    DATABASE_RXTemp.Data.C_13.SQ1.InfoAddr_L =0x05;
    DATABASE_RXTemp.Data.C_13.SQ1.InfoAddr_H =0x40;
    DATABASE_RXTemp.Data.C_13.SQ1.Array[0].Value =0x11;
    DATABASE_RXTemp.Data.C_13.SQ1.Array[0].QDS = 0x00;
    DATABASE_RXTemp.Data.C_13.SQ1.Array[1].Value =0x11;
    DATABASE_RXTemp.Data.C_13.SQ1.Array[1].QDS = 0x00;

//	memcpy(&DATABASE_RXTemp,pBuf,pBuf[0]);
//	switch(DATABASE_RXTemp.status.symbol.Lock_ID&0x0f)
//	{
        //case NULL_ID:
            switch (DATABASE_RXTemp.Head.TypeID)
            {
            case _DATABASE_M_ME_NC_1:
                if(DATABASE_RXTemp.Head.VSQ&0x80)
                {
                    addr = DATABASE_RXTemp.Data.C_13.SQ1.InfoAddr_H&0xff;
                    addr = (addr<<8)|(DATABASE_RXTemp.Data.C_13.SQ1.InfoAddr_L&0xff);
                    printf("yc addr is %d   ",addr);
                    if((addr>=_DATABASE_YC_START_ADDR)&&(addr + (DATABASE_RXTemp.Head.VSQ&0x7f) <= _DATABASE_YC_START_ADDR + _DATABASE_YC_TOTAL_NUM))
                    {
                        memcpy(&YCDB[addr - _DATABASE_YC_START_ADDR],&DATABASE_RXTemp.Data.C_13.SQ1.Array[0],(sizeof(YCSTRU)*(DATABASE_RXTemp.Head.VSQ&0x7f)));
                    }
                    printf("YCDB is :");
                    for(int i = 0; i < _DATABASE_YC_TOTAL_NUM; i++)
                        printf("%d ",YCDB[i]);
                    printf("\n");
                }
                break;
            default:
                break;
            //}
//            break;
//        default:
//            break;
    }
}

//读取遥测报文
uint8_t DBRead_YC(uint32_t addr,uint8_t num,uint8_t *pbuf)
{
    memset(&DATABASE_TXTemp,0,sizeof(_DATABASE_PASDU));

    if((addr>=_DATABASE_YC_START_ADDR)&&(addr + num <= _DATABASE_YC_START_ADDR + _DATABASE_YC_TOTAL_NUM))
    {
        DATABASE_TXTemp.status.Length = sizeof(DATABASE_TXTemp.status) + sizeof(DATABASE_TXTemp.Head) + 2 + num*sizeof(YCSTRU);
        DATABASE_TXTemp.Head.COT_L = _DATABASE_COT_INTROGEN;
        DATABASE_TXTemp.Head.TypeID = _DATABASE_M_ME_NC_1;
        DATABASE_TXTemp.Head.VSQ = num|0x80;
        DATABASE_TXTemp.Data.C_13.SQ1.InfoAddr_H = (addr>>8)&0xFF;
        DATABASE_TXTemp.Data.C_13.SQ1.InfoAddr_L = addr&0xFF;
        memcpy(&DATABASE_TXTemp.Data.C_1.SQ1.Array[0].Value,&YCDB[addr - _DATABASE_YC_START_ADDR],num*sizeof(YCSTRU));
        memcpy(pbuf,&DATABASE_TXTemp,DATABASE_TXTemp.status.Length);
        return(TRUE);
    }
    return(FALSE);
}

//写入ＳＯＥ
void DBWrite_SOE(uint8_t *pBuf)
{
    uint8_t i,j;
    uint32_t addr;

    memset(&DATABASE_RXTemp,0,sizeof(_DATABASE_PASDU));
    DATABASE_RXTemp.status.Length = 0x1A;
    DATABASE_RXTemp.Head.TypeID = _DATABASE_M_SP_TB_1;
    DATABASE_RXTemp.Head.VSQ =0x02;//信息地址不连续
    DATABASE_RXTemp.Head.COT_L =0x03;
    DATABASE_RXTemp.Head.COT_H =0x00;
    DATABASE_RXTemp.Head.PubAddr_L =0x01;
    DATABASE_RXTemp.Head.PubAddr_H =0x00;
    DATABASE_RXTemp.Data.C_30.SQ0.Array[0].InfoAddr_L =0x05;
    DATABASE_RXTemp.Data.C_30.SQ0.Array[0].InfoAddr_H =0x00;
    DATABASE_RXTemp.Data.C_30.SQ0.Array[0].Value =0x01;
    DATABASE_RXTemp.Data.C_30.SQ0.Array[0].CP56Time2a.Years = 0x11;
    DATABASE_RXTemp.Data.C_30.SQ0.Array[0].CP56Time2a.Months = 0x07;
    DATABASE_RXTemp.Data.C_30.SQ0.Array[0].CP56Time2a.DayofWeekMonth = 0x07;
    DATABASE_RXTemp.Data.C_30.SQ0.Array[0].CP56Time2a.Hours = 0x07;
    DATABASE_RXTemp.Data.C_30.SQ0.Array[0].CP56Time2a.Minutes = 0x07;
    DATABASE_RXTemp.Data.C_30.SQ0.Array[0].CP56Time2a.Milliseconds_L = 0x07;
    DATABASE_RXTemp.Data.C_30.SQ0.Array[0].CP56Time2a.Milliseconds_H = 0x07;

    DATABASE_RXTemp.Data.C_30.SQ0.Array[1].InfoAddr_L =0x10;
    DATABASE_RXTemp.Data.C_30.SQ0.Array[1].InfoAddr_H =0x00;
    DATABASE_RXTemp.Data.C_30.SQ0.Array[1].Value =0x02;
    DATABASE_RXTemp.Data.C_30.SQ0.Array[1].CP56Time2a.Years = 0x11;
    DATABASE_RXTemp.Data.C_30.SQ0.Array[1].CP56Time2a.Months = 0x08;
    DATABASE_RXTemp.Data.C_30.SQ0.Array[1].CP56Time2a.DayofWeekMonth = 0x08;
    DATABASE_RXTemp.Data.C_30.SQ0.Array[1].CP56Time2a.Hours = 0x08;
    DATABASE_RXTemp.Data.C_30.SQ0.Array[1].CP56Time2a.Minutes = 0x08;
    DATABASE_RXTemp.Data.C_30.SQ0.Array[1].CP56Time2a.Milliseconds_L = 0x08;
    DATABASE_RXTemp.Data.C_30.SQ0.Array[1].CP56Time2a.Milliseconds_H = 0x08;
    //memcpy(&DATABASE_RXTemp,pBuf,pBuf[0]);
    //switch(DATABASE_RXTemp.status.symbol.Lock_ID&0x0f)
    //{
       // case NULL_ID:
            switch (DATABASE_RXTemp.Head.TypeID)
            {
            case _DATABASE_M_SP_TB_1:
                if(!(DATABASE_RXTemp.Head.VSQ & 0x80))
                {
                    for(i = 0; i < (DATABASE_RXTemp.Head.VSQ & 0xff); i++)
                    {
                        addr = DATABASE_RXTemp.Data.C_30.SQ0.Array[i].InfoAddr_H&0xff;
                        addr = (addr<<8)|(DATABASE_RXTemp.Data.C_30.SQ0.Array[i].InfoAddr_L&0xff);
                        printf("soe addr is %d   ",addr);
                        if((addr>=_DATABASE_YX_START_ADDR) && (addr<_DATABASE_YX_START_ADDR+_DATABASE_YX_TOTAL_NUM))
                        {
                            YXDB[addr - _DATABASE_YX_START_ADDR] = DATABASE_RXTemp.Data.C_30.SQ0.Array[i].Value;
                            printf("SOE is :");
                            for(int i = 0; i < _DATABASE_YX_TOTAL_NUM; i++)
                                printf("%d ",YXDB[i]);
                            printf("\n");
                        }
                        memcpy(DBCFGS.SOE_IN,&DATABASE_RXTemp.Data.C_30.SQ0.Array[i],sizeof(SOE_t));
                        if(++DBCFGS.SOE_IN >= SOEDB + _DATABASE_SOELIMIT)
                        {
                            DBCFGS.SOE_IN = SOEDB;
                        }
                        for(j = 0;j < MAX_DEV_MUN;j++)
                        {
                            if(DBCFGS.SOE_IN == DBCFGS.SOE_OUT[j])
                                if(++DBCFGS.SOE_OUT[j] >= SOEDB + _DATABASE_SOELIMIT)
                                {
                                    DBCFGS.SOE_OUT[j] = SOEDB;
                                }
                        }

                    }

                }
                break;
            default:
                break;
            }
//            break;
//        default:
//            break;
//	}
}

//判断ＳＯＥ是否有数值
uint8_t DBCheck_SOE(uint8_t ID)
{
    if((ID <= MAX_DEV_MUN) && (DBCFGS.SOE_OUT[ID] != DBCFGS.SOE_IN))
    {
        printf("the soe number is: %d \n",(DBCFGS.SOE_OUT[ID] != DBCFGS.SOE_IN));
        return(TRUE);
    }
    return(FALSE);
}

//读取ＳＯＥ数值，设备ＩＤ读取ＳＯＥ数据至pbuf中
uint8_t DBRead_SOE(uint8_t ID,uint8_t *pbuf)
{
    uint8_t i,num = 0;

    memset(&DATABASE_TXTemp,0,sizeof(_DATABASE_PASDU));
    if((ID<=MAX_DEV_MUN)&&(DBCFGS.SOE_OUT[ID] != DBCFGS.SOE_IN))
    {
        for(i=0;(i<_DATABASE_SOESENDNUM)&&(DBCFGS.SOE_OUT[ID] != DBCFGS.SOE_IN);i++)
        {
            memcpy(&DATABASE_TXTemp.Data.C_30.SQ0.Array[i],DBCFGS.SOE_OUT[ID],sizeof(SOE_t));
            if(++DBCFGS.SOE_OUT[ID] >= SOEDB + _DATABASE_SOELIMIT)
            {
                DBCFGS.SOE_OUT[ID] = SOEDB;
            }
            num++;
        }
        DATABASE_TXTemp.status.Length = sizeof(DATABASE_TXTemp.status) + sizeof(DATABASE_TXTemp.Head) + num*sizeof(SOE_t);
        DATABASE_TXTemp.status.symbol.Lock_ID = ID;
        DATABASE_TXTemp.Head.COT_L = _DATABASE_COT_SPONT;
        DATABASE_TXTemp.Head.TypeID = _DATABASE_M_SP_TB_1;
        DATABASE_TXTemp.Head.VSQ = num&0x7f;
        memcpy(pbuf,&DATABASE_TXTemp,DATABASE_TXTemp.status.Length);
        return(TRUE);
    }
    return(FALSE);
}

void DBWrite_NVA(uint8_t *pBuf)
{
    uint8_t i;
    uint32_t addr;

    memset(&DATABASE_RXTemp,0,sizeof(_DATABASE_PASDU));
//	memcpy(&DATABASE_RXTemp,pBuf,pBuf[0]);
    DATABASE_RXTemp.status.Length = 0x14;
    DATABASE_RXTemp.Head.TypeID = _DATABASE_M_ME_NC_1;
    DATABASE_RXTemp.Head.VSQ =0x02;//信息地址不连续
    DATABASE_RXTemp.Head.COT_L =0x03;
    DATABASE_RXTemp.Head.COT_H =0x00;
    DATABASE_RXTemp.Head.PubAddr_L =0x01;
    DATABASE_RXTemp.Head.PubAddr_H =0x00;
    DATABASE_RXTemp.Data.C_13.SQ0.Array[0].InfoAddr_L =0x09;
    DATABASE_RXTemp.Data.C_13.SQ0.Array[0].InfoAddr_H =0x40;
    DATABASE_RXTemp.Data.C_13.SQ0.Array[0].Value = 6.6;
    DATABASE_RXTemp.Data.C_13.SQ0.Array[0].QDS = 0x11;


    DATABASE_RXTemp.Data.C_13.SQ0.Array[1].InfoAddr_L =0x10;
    DATABASE_RXTemp.Data.C_13.SQ0.Array[1].InfoAddr_H =0x40;
    DATABASE_RXTemp.Data.C_13.SQ0.Array[1].Value = 8.8;
    DATABASE_RXTemp.Data.C_13.SQ0.Array[1].QDS = 0x11;

//    switch(DATABASE_RXTemp.status.symbol.Lock_ID&0x0f)
//    {
//        case NULL_ID:
            switch (DATABASE_RXTemp.Head.TypeID)
            {
            case _DATABASE_M_ME_NC_1:
                if(!(DATABASE_RXTemp.Head.VSQ&0x80))
                {
                    for(i=0;i<(DATABASE_RXTemp.Head.VSQ&0xff);i++)
                    {
                        addr = DATABASE_RXTemp.Data.C_13.SQ0.Array[i].InfoAddr_H&0xff;
                        addr = (addr<<8)|(DATABASE_RXTemp.Data.C_13.SQ0.Array[i].InfoAddr_L&0xff);
                        printf("nva addr is %d   ",addr);
                        if((addr>=_DATABASE_YC_START_ADDR)&&(addr<_DATABASE_YC_START_ADDR+_DATABASE_YC_TOTAL_NUM))
                        {
                            YCDB[addr - _DATABASE_YC_START_ADDR].Value = DATABASE_RXTemp.Data.C_13.SQ0.Array[i].Value;
                            YCDB[addr - _DATABASE_YC_START_ADDR].QDS = DATABASE_RXTemp.Data.C_13.SQ0.Array[i].QDS;
                        }
                        memcpy(DBCFGS.NVA_IN,&DATABASE_RXTemp.Data.C_13.SQ0.Array[i],sizeof(NVA));
                        if(++DBCFGS.NVA_IN >= NVADB + _DATABASE_NVALIMIT)
                        {
                            DBCFGS.NVA_IN = NVADB;
                        }
                        printf("nva is :");
                        for(int i = 0; i < _DATABASE_YC_TOTAL_NUM; i++)
                            printf("%d ",YCDB[i]);
                        printf("\n");
                    }
                }
                break;
            default:
                break;
            }
//            break;
//        default:
//            break;
//    }
}

uint8_t DBCheck_NVA(uint8_t ID)
{
    if((ID <= MAX_DEV_MUN) && (DBCFGS.NVA_OUT[ID] != DBCFGS.NVA_IN))
    {
        return(TRUE);
    }
    return(FALSE);
}

uint8_t DBReset_NVA(uint8_t ID)
{
    if(ID <= MAX_DEV_MUN)
    {
        DBCFGS.NVA_OUT[ID] = DBCFGS.NVA_IN;
        return(TRUE);
    }
    return(FALSE);
}

uint8_t DBRead_NVA(uint8_t ID,uint8_t *pbuf)
{
    uint8_t i;
    uint8_t num = 0;

    memset(&DATABASE_TXTemp,0,sizeof(_DATABASE_PASDU));

    if((ID <= MAX_DEV_MUN) && (DBCFGS.NVA_OUT[ID] != DBCFGS.NVA_IN))
    {
        for(i = 0;(i < _DATABASE_NVASENDNUM) && (DBCFGS.NVA_OUT[ID] != DBCFGS.NVA_IN);i++)
        {
            memcpy(&DATABASE_TXTemp.Data.C_13.SQ0.Array[i],DBCFGS.NVA_OUT[ID],sizeof(NVA));
            if(++DBCFGS.NVA_OUT[ID] >= NVADB + _DATABASE_NVALIMIT)
            {
                DBCFGS.NVA_OUT[ID] = NVADB;
            }
            num++;
        }
        DATABASE_TXTemp.status.Length = sizeof(DATABASE_TXTemp.status) + sizeof(DATABASE_TXTemp.Head) + num*sizeof(NVA);
        DATABASE_TXTemp.status.symbol.Lock_ID = ID;
        DATABASE_TXTemp.Head.COT_L = _DATABASE_COT_SPONT;
        DATABASE_TXTemp.Head.TypeID = _DATABASE_M_ME_NC_1;
        DATABASE_TXTemp.Head.VSQ = num&0x7f;
        memcpy(pbuf,&DATABASE_TXTemp,DATABASE_TXTemp.status.Length);

        return(TRUE);
    }
    return(FALSE);
}


//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/
uint8_t DBSend(uint8_t *pbuf)
{
    uint8_t res = 0;
    switch(pbuf[1]&0x0f)//Lock_ID
    {
//        case NULL_ID:
//            DBAcceptHandle(pbuf);
//            break;
        case NET1_ID:
            res = DLT634_5104_SLAVE_C_REPLY(NET1_ID, pbuf);
            break;
//        case USART6_ID:
//			OSQPost((OS_Q *)&DLT101MasterApp_CommQ, pbuf, pbuf[0], OS_OPT_POST_FIFO | OS_OPT_POST_NO_SCHED, &err);
//			OSFlagPost (&DLT101MasterApp_Event, PARAFIX | FTXNEXT, OS_OPT_POST_FLAG_SET, &err);
//            res = DLT634_5101_MASTER_C_REPLY(USART6_ID, pbuf);
//            break;
//        case UART8_ID:
//            res = DLT634_5101_SLAVE_C_REPLY(UART8_ID, pbuf);
//			OSQPost((OS_Q *)&DLT101SlaveApp_CommQ, pbuf, pbuf[0], OS_OPT_POST_FIFO|OS_OPT_POST_NO_SCHED, &err);
//			OSFlagPost((OS_FLAG_GRP *)&DLT101SlaveApp_Event, (OS_FLAGS)PARAFIX, (OS_OPT)OS_OPT_POST_FLAG_SET, (OS_ERR *)&err);
//           break;
//        case N25QXXX_ID:
//#if N25QXXX_CFG
//            N25QXXX_REPLY(pbuf);
//#endif
//        break;
    }
    return(res);
}

