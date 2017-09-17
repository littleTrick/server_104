/*
** ------------------------------- Copyright (c) -------------------------------                                     
**
**                           http://www.sojoline.com
**
** note:    Copyright SOJO. ALL RIGHTS RESERVED.
**          This software is provided under license and contains proprietary and
**          confidential material which is the property of Company Name tech. 
**    
** -------------------------------- File Info ----------------------------------
** File name:               DLT634_5104_link.c
** Descriptions:            The application of DLT634.5104_2002
**
** -----------------------------------------------------------------------------
** Created by:              Mr.Sun
** Created date:            2017.7.11
** System:                  Protocol Software System
** Version:                 V3.01
** Descriptions:            The original version
**
** -----------------------------------------------------------------------------
** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
** ---------------------------------------------------------------------------*/


/* INCLUDE FILES -------------------------------------------------------------*/
#include "stdbool.h"
#include "dlt634_5104slave_app.h"
#include "dlt634_5104slave_disk.h"

/* PRIVATE VARIABLES ----------------------------------------------------------*/
#pragma pack(push,1)
typedef struct 
{
    BYTE Milliseconds_L;   // D7-D0
    BYTE Milliseconds_H;   // D7-D0
    BYTE Minutes;                    // D5-D0
    BYTE Hours;                        // D4-D0
    BYTE DayofWeekMonth;        // WEEK(D7-D5)MONTH(D4-D0)
    BYTE Months;                        // D3-D0
    BYTE Years;                        // D6-D0
}_DLT634_5104SLAVE_CP56Time2a_t;

typedef struct 
{
    struct STATUS
    {
        BYTE Length;
        union 
        {
            BYTE priority;    
            BYTE Lock_ID;
        }symbol;
    }status;

    struct HEAD
    {
        BYTE TypeID;     
        BYTE VSQ;  
        BYTE COT_L;
        BYTE COT_H;
        BYTE PubAddr_L;
        BYTE PubAddr_H;
    }Head;

    union 
    {
        BYTE buff[256-sizeof(struct STATUS)-sizeof(struct HEAD)];
        
        struct 
        {
            BYTE InfoAddr_L;
            BYTE InfoAddr_M;
            BYTE InfoAddr_H;
            BYTE QOI; 
        }C_100;

        struct 
        {
            BYTE InfoAddr_L;
            BYTE InfoAddr_M;
            BYTE InfoAddr_H;    
            _DLT634_5104SLAVE_CP56Time2a_t CP56Time2a;
        }C_103;

        struct 
        {
            BYTE InfoAddr_L;
            BYTE InfoAddr_M;
            BYTE InfoAddr_H;    
            BYTE QRP; 
        }C_105;

        struct 
        {
            BYTE InfoAddr_L;
            BYTE InfoAddr_M;
            BYTE InfoAddr_H;    
            BYTE COI; 
        }C_70;

        struct 
        {
            BYTE InfoAddr_L;
            BYTE InfoAddr_M;
            BYTE InfoAddr_H;
            BYTE FBP_L;
            BYTE FBP_H;                
        }C_104;

        union 
        {
            struct 
            {
                struct 
                {
                    BYTE InfoAddr_L;
                    BYTE InfoAddr_M;
                    BYTE InfoAddr_H;    
                    BYTE Value; 
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/4];
            }SQ0;
            struct 
            {
                BYTE InfoAddr_L;
                BYTE InfoAddr_M;
                BYTE InfoAddr_H;
                struct 
                {
                    BYTE Value; 
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-3)/1];
            }SQ1;
        }C_1;

        union 
        {
            struct 
            {
                struct 
                {
                    BYTE InfoAddr_L;
                    BYTE InfoAddr_M;
                    BYTE InfoAddr_H;    
                    BYTE Value; 
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/4];
            }SQ0;
            struct 
            {
                BYTE InfoAddr_L;
                BYTE InfoAddr_M; 
                BYTE InfoAddr_H;    
                struct 
                {
                    BYTE Value; 
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-3)/1];
            }SQ1;
        }C_3;

        union 
        {
            struct 
            {
                struct 
                {
                    BYTE InfoAddr_L;
                    BYTE InfoAddr_M;
                    BYTE InfoAddr_H;
                    BYTE Value; 
                    _DLT634_5104SLAVE_CP56Time2a_t CP56Time2a;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/11];
            }SQ0;
            struct 
            {
                BYTE InfoAddr_L;
                BYTE InfoAddr_M;
                BYTE InfoAddr_H;    
                struct 
                {
                    BYTE Value; 
                    _DLT634_5104SLAVE_CP56Time2a_t CP56Time2a;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-3)/8];
            }SQ1;
        }C_30;

        union 
        {
            struct 
            {
                struct 
                {
                    BYTE InfoAddr_L;
                    BYTE InfoAddr_M;
                    BYTE InfoAddr_H;    
                    BYTE Value; 
                    _DLT634_5104SLAVE_CP56Time2a_t CP56Time2a;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/11];
            }SQ0;
            struct 
            {
                BYTE InfoAddr_L;
                BYTE InfoAddr_M;
                BYTE InfoAddr_H;    
                struct 
                {
                    BYTE Value; 
                    _DLT634_5104SLAVE_CP56Time2a_t CP56Time2a;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-3)/8];
            }SQ1;
        }C_31;

        union 
        {
            struct 
            {
                struct 
                {
                    BYTE InfoAddr_L;
                    BYTE InfoAddr_M;
                    BYTE InfoAddr_H;
                    WORD Value;
                    BYTE QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/8];
            }SQ0;
            struct 
            {
                BYTE InfoAddr_L;
                BYTE InfoAddr_M;
                BYTE InfoAddr_H;    
                struct 
                {
                    WORD Value;                                    
                    BYTE QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-3)/5];
            }SQ1;
        }C_9;

        union 
        {
            struct 
            {
                struct 
                {
                    BYTE InfoAddr_L;
                    BYTE InfoAddr_M;
                    BYTE InfoAddr_H;
                    WORD Value;
                    BYTE QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/8];
            }SQ0;
            struct 
            {
                BYTE InfoAddr_L;
                BYTE InfoAddr_M;
                BYTE InfoAddr_H;
                struct 
                {
                    WORD Value;
                    BYTE QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-3)/5];
            }SQ1;
        }C_11;

        union 
        {
            struct 
            {
                struct 
                {
                    BYTE InfoAddr_L;
                    BYTE InfoAddr_M;
                    BYTE InfoAddr_H;
                    DWORD Value;    
                    BYTE QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/8];
            }SQ0;

            struct 
            {
                BYTE InfoAddr_L;
                BYTE InfoAddr_M;
                BYTE InfoAddr_H;
                struct 
                {
                    DWORD Value;    
                    BYTE QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-3)/5];
            }SQ1;
        }C_13;

        struct 
        {
            BYTE InfoAddr_L;
            BYTE InfoAddr_M;
            BYTE InfoAddr_H;
            BYTE SCO_L;
            BYTE SCO_H;
        }C_45;    

        struct 
        {
            BYTE InfoAddr_L;
            BYTE InfoAddr_M;
            BYTE InfoAddr_H;    
            BYTE DCO_L;
            BYTE DCO_H;
        }C_46;    

        struct 
        {
            BYTE Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))]; 
        }C_42;

        struct 
        {
            BYTE InfoAddr_L;
            BYTE InfoAddr_M;
            BYTE InfoAddr_H;    
            BYTE SN_L;
            BYTE SN_H;
        }C_200;

        union 
        {
            struct 
            {
                BYTE InfoAddr_L;
                BYTE InfoAddr_M;
                BYTE InfoAddr_H;
            }Down;

            struct 
            {
                BYTE InfoAddr_L;
                BYTE InfoAddr_M;
                BYTE InfoAddr_H;    
                BYTE SN1_L;
                BYTE SN1_H;
                BYTE SN2_L;
                BYTE SN2_H;
                BYTE SN3_L;
                BYTE SN3_H;
            }Up;
        }C_201;

        union 
        {
            struct 
            {
                BYTE SN1_L;
                BYTE SN1_H;
                WORD Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/4];        
            }Down;

            struct 
            {
                BYTE SN_L;
                BYTE SN_H;    
                BYTE PI_L;
                BYTE PI_H;
                struct 
                {
                    BYTE InfoAddr_L;
                    BYTE InfoAddr_M;
                    BYTE InfoAddr_H;
                    BYTE Tag;
                    BYTE Len;
                    DWORD Value;    
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-4)/9];
            }Up;
        }C_202;

        union 
        {
            BYTE SN_L;
            BYTE SN_H;    
            BYTE PI_L;
            BYTE PI_H;
            struct 
            {
                BYTE InfoAddr_L;
                BYTE InfoAddr_M;
                BYTE InfoAddr_H;
                BYTE Tag;
                BYTE Len;
                DWORD Value;    
            }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-4)/9];
        }C_203;

        struct 
        {
            BYTE Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))]; 
        }C_210;
    }Data;
}DLT634_5104SLAVE_PASDU;

 struct DLT634_5104SLAVE_PASDU_104
{
         struct PASDUHead_104
        {   
                BYTE    TypeID; // 类型标识
                BYTE    VSQ;    // 可变结构限定词
             
                // 传送原因
                WORD COT;

                // 应用服务数据单元公共地址
                WORD PubAddr;

                // 信息对象地址
                WORD InfoAddr;

        }Head;
    BYTE Data[DLT634_5104SLAVE_ASDUSIZE - sizeof(struct PASDUHead_104)];
};

 struct DLT634_5104SLAVE_SendData
{
        BYTE TxLen;
        BYTE TxData[DLT634_5104SLAVE_ASDUSIZE];    
};  
        
/* 组处理结构 -----------------------------------------------------------------*/ 
struct DLT634_5104SLAVE_APPINFO
{    
    BYTE Connect; // 网络连接状态    

    BYTE  YXTypeID;           // 遥信类型标识
    BYTE  YCTypeID;           // 遥测类型标识    
    WORD  CurSData;           // 未被确认的I帧备份缓冲区位置标识

      BYTE  RxdBuf[2*DLT634_5104SLAVE_APDUSIZE]; // 接收缓冲区
    BYTE  TxdBuf[2*DLT634_5104SLAVE_APDUSIZE]; // 发送缓冲区    

      DWORD  Data1Flag; 
    DWORD  AllDataFlag; // 总召状态标志
    DWORD  AppNextFlag; // 续发数据标志

      BYTE TxLen;     

      struct DLT634_5104SLAVE_PASDU_104 TxMsg;  // 应用层发送数据指针
    struct DLT634_5104SLAVE_PASDU_104 *RxMsg; // 应用层接收数据指针         
    
        struct DLT634_5104SLAVE_SendData SData[DLT634_5104SLAVE_K]; // 未被确认的I帧备份    
    
        struct PGroupTrn
        {        
                WORD InfoAddr;
                BYTE TypeID;
                BYTE COT;
                BYTE GroupNo;
        }GroupTrn;// 分组处理结构体
    
      DLT634_5104SLAVE_PASDU *StoreDATA1IN;              // 待发送缓冲区1级数据入指针
      DLT634_5104SLAVE_PASDU *StoreDATA1OUT;             // 待发送缓冲区1级数据出指针
    DLT634_5104SLAVE_PASDU StoreDATA1Buf[DLT634_5104SLAVE_STOREDATA1NUM];         // 1级数据待发送缓冲区
      DLT634_5104SLAVE_PASDU *StoreDATA2IN;              // 待发送缓冲区1级数据入指针
      DLT634_5104SLAVE_PASDU *StoreDATA2OUT;             // 待发送缓冲区1级数据出指针
      DLT634_5104SLAVE_PASDU StoreDATA2Buf[DLT634_5104SLAVE_STOREDATA1NUM];         // 2级数据待发送缓冲区
      DLT634_5104SLAVE_PASDU ST_Temp;              // 存储数据处理
    
      DLT634_5104SLAVE_PASDU TX_Temp;              //发送数据处理
      DLT634_5104SLAVE_PASDU RX_Temp;              //接受数据处理      
};

struct DLT634_5104SLAVE_PAPCI
{
    BYTE    StartCode;
    BYTE    Length;
    WORD NS;
    WORD NR;
};

struct DLT634_5104SLAVE_LINKINFO
{
    BYTE Connect; // 网络连接状态
      BYTE DataType[DLT634_5104SLAVE_K]; // 接收数据类型，I格式帧
    BYTE StopSendFlag; //停止发送标志(未被确认的I格式帧达到K个，停止发送)        

      BYTE RxdBuf[2*DLT634_5104SLAVE_APDUSIZE]; // 接收缓冲区
    BYTE TxdBuf[2*DLT634_5104SLAVE_APDUSIZE]; // 发送缓冲区        
  
    WORD NR; // 接收包计数
    WORD NS; // 发送包计数
      WORD NRACK; // 上次确认的接受序列号
  
    WORD PeerNoAckNum; // 对方未发送确认的I格式帧数目      
    
      WORD RxdHead; // 处理数据的头指针
    WORD RxdTail;        
    WORD RxdLength;
    
    WORD FrameHead; // 组帧时数据头在发送缓冲区的位置
    WORD TxdHead;
    WORD TxdTail;
    
      // 参数输入
    WORD Tick0;
    WORD Tick1;
    WORD Tick2;
    WORD Tick3;

        DWORD  ClockCounter;  // 程序运行周期控制
        
        enum DLRXDSTATUS
        {
                RXDSTART = 0,                                   // 寻找起始标志状态
                RXDHEAD,                                       // 寻找报文头
                RXDCONTINUE                                  // 接收后续报文
        }RxdStatus;// 接收状态
            
        struct PTick
        {
            WORD TValue0;    
            WORD TValue1[DLT634_5104SLAVE_K];
            WORD TValue2;
            WORD TValue3;
            BYTE    Flag; // 按位使用
            BYTE    FlagBak; // 备份
        }Tick;
                
};
#pragma pack(pop)

/* PUBLIC VARIABLES ----------------------------------------------------------*/
struct DLT634_5104SLAVE_PAD DLT634_5104Slave_Pad[DLT634_5104SLAVE_VOLUMES]; // DL/T634_5101规约参数
struct DLT634_5104SLAVE_LINKINFO DLT104SlaveLink[DLT634_5104SLAVE_VOLUMES]; // 链路层变量
struct DLT634_5104SLAVE_APPINFO DLT104SlaveApp[DLT634_5104SLAVE_VOLUMES];

/* PRIVATE FUNCTION PROTOTYPES -----------------------------------------------*/
/* -----------------------------------------------------------------------------
** 函数名称: SetTimer
** 功能描述: 启动定时器。
** 输　  入: No:定时器号.
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Sun
** 日　  期: 2017.07.11
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5104_SLAVE_SetTimer(BYTE pdrv, BYTE No)
{
    BYTE    i = 0;
    
    switch (No)
    {
        case 0:
            DLT104SlaveLink[pdrv].Tick.TValue0 = 0;
            DLT104SlaveLink[pdrv].Tick.Flag |= DLT634_5104SLAVE_T0FLAG;
            break;
            
        case 1:
            for (i = 0; i < DLT634_5104SLAVE_K; i++)
            {
                DLT104SlaveLink[pdrv].Tick.TValue1[i] = 0;
            }
            DLT104SlaveLink[pdrv].Tick.Flag |= DLT634_5104SLAVE_T1FLAG;            
            break;
            
        case 2:
            DLT104SlaveLink[pdrv].Tick.TValue2 = 0;
            DLT104SlaveLink[pdrv].Tick.Flag |= DLT634_5104SLAVE_T2FLAG;            
            break;
            
        case 3:
            DLT104SlaveLink[pdrv].Tick.TValue3 = 0;
            DLT104SlaveLink[pdrv].Tick.Flag |= DLT634_5104SLAVE_T3FLAG;            
            break;
        
        default:
            break;
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: KillTimer
** 功能描述: 停止定时器。
** 输　  入: No:定时器号.
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Lee
** 日　  期: 2016.10.25
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5104_SLAVE_KillTimer(BYTE pdrv, BYTE No)
{
    switch (No)
    {
        case 0:
            DLT104SlaveLink[pdrv].Tick.Flag &= (~DLT634_5104SLAVE_T0FLAG);
            break;
            
        case 1:
            DLT104SlaveLink[pdrv].Tick.Flag &= (~DLT634_5104SLAVE_T1FLAG);
            break;
            
        case 2:
            DLT104SlaveLink[pdrv].Tick.Flag &= (~DLT634_5104SLAVE_T2FLAG);            
            break;
            
        case 3:
            DLT104SlaveLink[pdrv].Tick.Flag &= (~DLT634_5104SLAVE_T3FLAG);            
            break;
            
        default:
            break;
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5104_SLAVE_BackupProcess
** 功能描述: 未被确认I帧备份处理
** 输　  入: pdrv: 设备ID
**           LastNoAckNum: 上次未确认的数量
**           NowNoAckNum: 本次未确认的数量
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Sun
** 日　  期: 2017.07.20
** -----------------------------------------------------------------------------
** 修 改 人:                                              
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
void DLT634_5104_SLAVE_BackupProcess(BYTE pdrv, WORD LastNoAckNum, WORD NowNoAckNum)
{
      WORD num;
      struct DLT634_5104SLAVE_APPINFO *pMsg;
       
        pMsg = &DLT104SlaveApp[pdrv];     
      num = LastNoAckNum - NowNoAckNum; // 本次被确认的数量
    memcpy(&pMsg[pdrv].SData, &pMsg[pdrv].SData[num], sizeof(struct DLT634_5104SLAVE_SendData) * NowNoAckNum); 
      pMsg[pdrv].CurSData -= num;
}

/* -----------------------------------------------------------------------------
** 函数名称: PeerNoAckNumProcess
** 功能描述: 处理对方确认。
** 输　  入: PeerNR:接受序列号.
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Lee
** 日　  期: 2016.10.25
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static BYTE DLT634_5104_SLAVE_PeerNoAckNumProcess(BYTE pdrv, WORD PeerNR)
{
    WORD i = 0;
    WORD tmp = 0, num = 0;
    
    if (PeerNR <= DLT104SlaveLink[pdrv].NS)
    {
        num = DLT104SlaveLink[pdrv].NS - PeerNR;
    }
    else
    {
        num = 32767 + DLT104SlaveLink[pdrv].NS - PeerNR;          
    }
    
    if (num > DLT104SlaveLink[pdrv].PeerNoAckNum)
    {
        return (FALSE);
    }

    for (i = 0, tmp = 0; i < DLT104SlaveLink[pdrv].PeerNoAckNum - num; i++)
    {
        if (DLT104SlaveLink[pdrv].DataType[i])
        {
            tmp++;
        }
    }

        DLT634_5104_SLAVE_BackupProcess(pdrv, DLT104SlaveLink[pdrv].PeerNoAckNum, num); // 未被确认I帧备份处理
    
    for (i = 0; i < num; i++)
    {
        DLT104SlaveLink[pdrv].Tick.TValue1[i] = DLT104SlaveLink[pdrv].Tick.TValue1[num+i];
        DLT104SlaveLink[pdrv].DataType[i] = DLT104SlaveLink[pdrv].DataType[num+i];
    }
    
    for (i = num; i < DLT634_5104SLAVE_K; i++)
    {
        DLT104SlaveLink[pdrv].Tick.TValue1[i] = 0;
        DLT104SlaveLink[pdrv].DataType[i] = FALSE;
    }
    
    DLT104SlaveLink[pdrv].PeerNoAckNum = num;    
    
    return (TRUE);
}

static BYTE DLT634_5104_SLAVE_StoreIN(BYTE pdrv, DLT634_5104SLAVE_PASDU *buf)
{        
    DLT634_5104SLAVE_PASDU *temp;
    DLT634_5104SLAVE_PASDU tempbuf;
    
    if(buf->status.symbol.priority<DLT634_5104SLAVE_M_FT_NA_P)
    {
        temp = DLT104SlaveApp[pdrv].StoreDATA1IN;
        if(++temp >= DLT104SlaveApp[pdrv].StoreDATA1Buf + DLT634_5104SLAVE_STOREDATA1NUM)
        {
            temp = DLT104SlaveApp[pdrv].StoreDATA1Buf;
        }
        
        if(temp == DLT104SlaveApp[pdrv].StoreDATA1OUT)
        {
            return(FALSE);
        }
    
        temp = DLT104SlaveApp[pdrv].StoreDATA1OUT;
        while(temp != DLT104SlaveApp[pdrv].StoreDATA1IN)
        {
            if(((temp->status.symbol.priority > buf->status.symbol.priority)||(temp->status.symbol.priority == 0))&&(temp != DLT104SlaveApp[pdrv].StoreDATA1OUT))
            {
                memcpy(&tempbuf,temp,sizeof(DLT634_5104SLAVE_PASDU));
                memcpy(temp,buf,sizeof(DLT634_5104SLAVE_PASDU));
                memcpy(buf,&tempbuf,sizeof(DLT634_5104SLAVE_PASDU));
            }
            if(++temp >= DLT104SlaveApp[pdrv].StoreDATA1Buf + DLT634_5104SLAVE_STOREDATA1NUM)
            {
                temp = DLT104SlaveApp[pdrv].StoreDATA1Buf;
            }
        }
        
        memcpy(temp,buf,sizeof(DLT634_5104SLAVE_PASDU));    
        if(++DLT104SlaveApp[pdrv].StoreDATA1IN >= DLT104SlaveApp[pdrv].StoreDATA1Buf + DLT634_5104SLAVE_STOREDATA1NUM)
        {
            DLT104SlaveApp[pdrv].StoreDATA1IN = DLT104SlaveApp[pdrv].StoreDATA1Buf;
        }
    }
    else
    {
        temp = DLT104SlaveApp[pdrv].StoreDATA2IN;
        if(++temp >= DLT104SlaveApp[pdrv].StoreDATA2Buf + DLT634_5104SLAVE_STOREDATA2NUM)
        {
            temp = DLT104SlaveApp[pdrv].StoreDATA2Buf;
        }
        
        if(temp == DLT104SlaveApp[pdrv].StoreDATA2OUT)
        {
            return(FALSE);
        }
        
        temp = DLT104SlaveApp[pdrv].StoreDATA2OUT;
        while(temp != DLT104SlaveApp[pdrv].StoreDATA2IN)
        {
            if(((temp->status.symbol.priority > buf->status.symbol.priority)||(temp->status.symbol.priority == 0))&&(temp != DLT104SlaveApp[pdrv].StoreDATA2OUT))
            {
                memcpy(&tempbuf,temp,sizeof(DLT634_5104SLAVE_PASDU));
                memcpy(temp,buf,sizeof(DLT634_5104SLAVE_PASDU));
                memcpy(buf,&tempbuf,sizeof(DLT634_5104SLAVE_PASDU));
            }
            if(++temp >= DLT104SlaveApp[pdrv].StoreDATA2Buf + DLT634_5104SLAVE_STOREDATA2NUM)
            {
                temp = DLT104SlaveApp[pdrv].StoreDATA2Buf;
            }
        }
        
        memcpy(temp,buf,sizeof(DLT634_5104SLAVE_PASDU));
        if(++DLT104SlaveApp[pdrv].StoreDATA2IN >= DLT104SlaveApp[pdrv].StoreDATA2Buf + DLT634_5104SLAVE_STOREDATA2NUM)
        {
            DLT104SlaveApp[pdrv].StoreDATA2IN = DLT104SlaveApp[pdrv].StoreDATA2Buf;
        }
    }
    return(TRUE);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5104_AppInitReset
** 功能描述: 应用层数据初始化复位.
** 输　  入: 无
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Lee
** 日　  期: 2016.10.25
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
BYTE DLT634_5104_AppInitReset(BYTE pdrv)
{
    DLT104SlaveApp[pdrv].AllDataFlag = FALSE;
    DLT104SlaveApp[pdrv].AppNextFlag = FALSE;    
    
    // Link
    DLT104SlaveLink[pdrv].Connect = FALSE;
    DLT104SlaveLink[pdrv].NR = 0;
    DLT104SlaveLink[pdrv].NS = 0;
    DLT104SlaveLink[pdrv].PeerNoAckNum = 0;
    DLT104SlaveLink[pdrv].FrameHead = 0;
    DLT104SlaveLink[pdrv].TxdHead = 0;
    DLT104SlaveLink[pdrv].TxdTail = 0;
        
        memset(DLT104SlaveLink[pdrv].TxdBuf, 0, sizeof(DLT104SlaveLink[pdrv].RxdBuf)); // 清空接收缓冲区
        memset(DLT104SlaveLink[pdrv].RxdBuf, 0, sizeof(DLT104SlaveLink[pdrv].TxdBuf)); // 清空发送缓冲区
    
        DLT104SlaveApp[pdrv].StoreDATA1IN = DLT104SlaveApp[pdrv].StoreDATA1Buf;
        DLT104SlaveApp[pdrv].StoreDATA1OUT = DLT104SlaveApp[pdrv].StoreDATA1Buf;
        memset(DLT104SlaveApp[pdrv].StoreDATA1Buf,0,sizeof(DLT104SlaveApp[pdrv].StoreDATA1Buf));
        DLT104SlaveApp[pdrv].StoreDATA2IN = DLT104SlaveApp[pdrv].StoreDATA2Buf;
        DLT104SlaveApp[pdrv].StoreDATA2OUT = DLT104SlaveApp[pdrv].StoreDATA2Buf;
        memset(DLT104SlaveApp[pdrv].StoreDATA2Buf,0,sizeof(DLT104SlaveApp[pdrv].StoreDATA2Buf));
    
        return (TRUE);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5104_SLAVE_AppProcess
** 功能描述: 应用层数据处理。
** 输　  入: struct DLT634_5104SLAVE_AppMsg* Msg：应用层信息结构.
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Lee
** 日　  期: 2016.10.25
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
void DLT634_5104_SLAVE_AppProcess(BYTE pdrv, struct DLT634_5104SLAVE_AppMsg* Msg)
{    
      DLT104SlaveApp[pdrv].TxLen = 0;
    DLT104SlaveApp[pdrv].RxMsg = (struct DLT634_5104SLAVE_PASDU_104*)Msg->pData;
//  这里将104报文转为02版104报文    
      memset((BYTE *)&DLT104SlaveApp[pdrv].RX_Temp,0,sizeof(DLT634_5104SLAVE_PASDU));
      memcpy((BYTE *)&DLT104SlaveApp[pdrv].RX_Temp.Head,Msg->pData, Msg->Len);
        DLT104SlaveApp[pdrv].RX_Temp.status.Length = Msg->Len + sizeof(DLT104SlaveApp[pdrv].RX_Temp.status);

      switch (Msg->Cmd)
        {
            case DLT634_5104SLAVE_LINK_CALLDATA:
                
            switch (DLT104SlaveApp[pdrv].RxMsg->Head.TypeID) // 具体类型标识处理
            {
                case DLT634_5104SLAVE_C_SC_NA_1:    // <45>单点遥控命令
                case DLT634_5104SLAVE_C_SC_NB_1:    // <46>双点遥控命令
                    DLT634_5104_SLAVE_HandleCtrlProcess(pdrv, (BYTE *)&DLT104SlaveApp[pdrv].RX_Temp);
                    break;                        
                        
                case DLT634_5104SLAVE_C_IC_NA_1:    // <100>总召唤或分组召唤
                                    DLT104SlaveApp[pdrv].Data1Flag |= DLT634_5104SLAVE_CALLALLDATA;
                                    DLT104SlaveApp[pdrv].AllDataFlag = 0;
                    break;
                        
                case DLT634_5104SLAVE_C_CI_NA_1:    // <101>电度总召唤或分组召唤
                    //ReadDDProcess(pdrv);
                    break;
                        
                case DLT634_5104SLAVE_C_CS_NA_1:    // <103>对钟命令
                    DLT634_5104_SLAVE_SYNProcess(pdrv, (BYTE *)&DLT104SlaveApp[pdrv].RX_Temp);
                    break;
                        
                case DLT634_5104SLAVE_C_RP_NA_1:    // <105>复位进程命令
                    //ResetProcess(pdrv);
                    break;                        
                        
                case DLT634_5104SLAVE_C_TS_NA_1:    // <104>测试命令
                    DLT104SlaveApp[pdrv].RX_Temp.status.symbol.priority = DLT634_5104SLAVE_C_TS_NA_P;
                    DLT104SlaveApp[pdrv].RX_Temp.Head.COT_L = DLT634_5104SLAVE_COT_ACTCON;
                    DLT634_5104_SLAVE_StoreIN(pdrv,&DLT104SlaveApp[pdrv].RX_Temp);                                
//                    TestReply(pdrv);
                    break;   
                
                case DLT634_5104SLAVE_C_SR_NA_1: // <200>切换定值区
                case DLT634_5104SLAVE_C_RR_NA_1: // <201>读定值区号
                case DLT634_5104SLAVE_C_RS_NA_1: // <202>读参数和定值
                case DLT634_5104SLAVE_C_WS_NA_1: // <203>写参数和定值    
                            DLT634_5104_SLAVE_FixedParaProcess(pdrv,(BYTE *)&DLT104SlaveApp[pdrv].RX_Temp);            
                    break;
                
                case DLT634_5104SLAVE_F_FR_NA_1: // <210>文件传输
                    DLT634_5104_SLAVE_FileHandleProcess(pdrv,(BYTE *)&DLT104SlaveApp[pdrv].RX_Temp);
//                    FUNC_F_FR_NA_1_ID210(pdrv);
                    break;
                                
                case DLT634_5104SLAVE_F_SR_NA_1: // <211>软件升级
                      
                    break;
                                
                default:    // 类型标识有错误或不支持
                    break;
            }
            break;
                
        case DLT634_5104SLAVE_LINK_APPCON:
            break;    

        case DLT634_5104SLAVE_LINK_WORK:
            DLT104SlaveApp[pdrv].Connect = TRUE; // 收到STSRTDT后
            break;
                
        case DLT634_5104SLAVE_LINK_NOWORK:
            DLT634_5104_AppInitReset(pdrv);
            DLT104SlaveApp[pdrv].Connect = FALSE;
            break;
        
        default:
            break; 
        }                  
}

/* -----------------------------------------------------------------------------
** 函数名称: StopDTOper
** 功能描述: 停止数据传输，关闭TCP连接。
** 输　  入: 无
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Lee
** 日　  期: 2016.10.25
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5104_SLAVE_StopDTOper(BYTE pdrv)
{
      struct DLT634_5104SLAVE_AppMsg    msg;
    
    msg.Cmd = DLT634_5104SLAVE_LINK_NOWORK;
    msg.ConNum = 0;
    msg.pData = NULL;
    msg.Len = 0;
    DLT634_5104_SLAVE_AppProcess(pdrv, &msg);    
    
    DLT634_5104_SLAVE_StopLink(pdrv);
    DLT104SlaveLink[pdrv].Connect = FALSE;    // 清链路连接标志
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5104_WriteDataToMISI
** 功能描述: 发送数据到MISI。
** 输　  入: 无
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Lee
** 日　  期: 2016.10.25
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
void DLT634_5104_SLAVE_WriteDataToMISI(BYTE pdrv)
{
    WORD count = 0, num = 0;
    
    if (DLT104SlaveLink[pdrv].TxdHead >= DLT104SlaveLink[pdrv].TxdTail)
    {
        return ;
    }
    
    num = DLT104SlaveLink[pdrv].TxdTail - DLT104SlaveLink[pdrv].TxdHead;
    
    // 写数据库函数
    count = DLT634_5104_SLAVE_WriteData(pdrv,(BYTE *)&DLT104SlaveLink[pdrv].TxdBuf[DLT104SlaveLink[pdrv].TxdHead], num);
        DLT104SlaveLink[pdrv].TxdHead += count;
    
        if (DLT104SlaveLink[pdrv].TxdHead >= DLT104SlaveLink[pdrv].TxdTail)
    {
        DLT104SlaveLink[pdrv].TxdTail = 0;
        DLT104SlaveLink[pdrv].TxdHead = 0;
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: S104SendCtrlFrame
** 功能描述: 发送链路层数据数据，包括S和U格式。
** 输　  入: ctrl：控制域类型.
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Lee
** 日　  期: 2016.10.25
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5104_SLAVE_S104SendCtrlFrame(BYTE pdrv, BYTE ctrl)
{
    struct DLT634_5104SLAVE_PAPCI *pFrame;
    
    pFrame = (struct DLT634_5104SLAVE_PAPCI*)&DLT104SlaveLink[pdrv].TxdBuf[DLT104SlaveLink[pdrv].TxdHead];
    
    pFrame->StartCode = DLT634_5104SLAVE_STARTCODE68;
    pFrame->Length = 0x04;
    pFrame->NS = ctrl;
    if (ctrl == DLT634_5104SLAVE_S_FRAME)
    {
              DLT104SlaveLink[pdrv].NRACK = DLT104SlaveLink[pdrv].NR;
        pFrame->NR = DLT104SlaveLink[pdrv].NR << 1;
        
        DLT634_5104_SLAVE_KillTimer(pdrv, 2);
    }
    else
    {
        pFrame->NR = 0x00;
            
        DLT634_5104_SLAVE_SetTimer(pdrv, 3);
            
        if (ctrl == DLT634_5104SLAVE_U_TESTFRACT)
        {
            DLT634_5104_SLAVE_SetTimer(pdrv, 1); // U测试针应在t1时间内得到确认
                        DLT104SlaveLink[pdrv].PeerNoAckNum++;
        }
    }
    
    DLT104SlaveLink[pdrv].TxdTail += 0x06;
    
    // 发送                                        
    DLT634_5104_SLAVE_WriteDataToMISI(pdrv);
}

/* -----------------------------------------------------------------------------
** 函数名称: DecodeSFrame
** 功能描述: 处理S格式帧数据。
** 输　  入: 无
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Lee
** 日　  期: 2016.10.25
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5104_SLAVE_DecodeSFrame(BYTE pdrv)
{
    WORD tmp = 0;
    struct DLT634_5104SLAVE_PAPCI *pAPCI;
    struct DLT634_5104SLAVE_AppMsg    msg;
    
    pAPCI = (struct DLT634_5104SLAVE_PAPCI*)DLT104SlaveLink[pdrv].RxdBuf;
    
    if (!DLT104SlaveLink[pdrv].Connect)
    {
        return;
    }
    
    tmp = DLT104SlaveLink[pdrv].PeerNoAckNum;
    if (!DLT634_5104_SLAVE_PeerNoAckNumProcess(pdrv, pAPCI->NR >> 1))
    {
        return;
    }
    DLT104SlaveLink[pdrv].StopSendFlag = FALSE;
        
    msg.Cmd = DLT634_5104SLAVE_LINK_APPCON; // 这里存在疑问  原来对应的是LINK_NOWORK！！！
    msg.ConNum = tmp - DLT104SlaveLink[pdrv].PeerNoAckNum;
    msg.pData = NULL;
    msg.Len = 0;
    DLT634_5104_SLAVE_AppProcess(pdrv, &msg);
}

/* -----------------------------------------------------------------------------
** 函数名称: DecodeUFrame
** 功能描述: 处理U格式帧数据。
** 输　  入: 无
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Lee
** 日　  期: 2016.10.25
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5104_SLAVE_DecodeUFrame(BYTE pdrv)
{
      struct DLT634_5104SLAVE_PAPCI *pAPCI;
    struct DLT634_5104SLAVE_AppMsg    msg;
            
    pAPCI = (struct DLT634_5104SLAVE_PAPCI*)DLT104SlaveLink[pdrv].RxdBuf;
    
    switch (pAPCI->NS & 0xFF)
    {
        case DLT634_5104SLAVE_U_STARTDTACT:
            // 是否初始化
            DLT104SlaveLink[pdrv].Tick.Flag = DLT104SlaveLink[pdrv].Tick.FlagBak;
            
                    DLT634_5104_SLAVE_S104SendCtrlFrame(pdrv, DLT634_5104SLAVE_U_STARTDTCON);  
                    DLT104SlaveLink[pdrv].Connect = TRUE; 
        
            msg.Cmd = DLT634_5104SLAVE_LINK_WORK;
            msg.ConNum = 0;
            msg.pData = NULL;
            msg.Len = 0;
            DLT634_5104_SLAVE_AppProcess(pdrv, &msg);                    
            break;
            
        case DLT634_5104SLAVE_U_STARTDTCON: // 终端 应该不会收到该命令
            break;
    
        case DLT634_5104SLAVE_U_STOPDTACT:
            DLT104SlaveLink[pdrv].Tick.FlagBak = DLT104SlaveLink[pdrv].Tick.Flag;
            DLT104SlaveLink[pdrv].Tick.Flag = 0;
                    /*回复停止确认之前需对控制站未确认报文进行确认，若被控站存在未确认报文 需等待确认*/
            if (DLT104SlaveLink[pdrv].NR > DLT104SlaveLink[pdrv].NRACK)
                        {
                            DLT634_5104_SLAVE_S104SendCtrlFrame(pdrv, DLT634_5104SLAVE_S_FRAME); // 收到主站U_STOPDTACT命令
                        }
                        else
                        {
                            DLT634_5104_SLAVE_S104SendCtrlFrame(pdrv, DLT634_5104SLAVE_U_STOPDTCON);
                
                              msg.Cmd = DLT634_5104SLAVE_LINK_NOWORK;
                msg.ConNum = 0;
                msg.pData = NULL;
                msg.Len = 0;
                DLT634_5104_SLAVE_AppProcess(pdrv, &msg);                                    
                        }
            break;
    
        case DLT634_5104SLAVE_U_STOPDTCON: // 终端 应该不会收到该命令
            break;
    
        case DLT634_5104SLAVE_U_TESTFRACT:
            DLT634_5104_SLAVE_S104SendCtrlFrame(pdrv, DLT634_5104SLAVE_U_TESTFRCON);
                 
                    break;
    
        case DLT634_5104SLAVE_U_TESTFRCON:
                    /*收到测试确认后 应清t1, 此时t1应该只有测试计时*/
                        
            break;
            
        default:
            break;
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: DecodeIFrame
** 功能描述: 处理I格式帧数据。
** 输　  入: 无
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Lee
** 日　  期: 2016.10.25
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5104_SLAVE_DecodeIFrame(BYTE pdrv)
{
    WORD tmp = 0;
    struct DLT634_5104SLAVE_AppMsg msg;
    struct DLT634_5104SLAVE_PAPCI *pAPCI;
    
    pAPCI = (struct DLT634_5104SLAVE_PAPCI*)DLT104SlaveLink[pdrv].RxdBuf;
    
    if (!DLT104SlaveLink[pdrv].Connect)
    {
        return;
    }
    
    tmp = DLT104SlaveLink[pdrv].PeerNoAckNum;
    if (!DLT634_5104_SLAVE_PeerNoAckNumProcess(pdrv, pAPCI->NR >> 1))
    {
        DLT634_5104_SLAVE_StopDTOper(pdrv);
        return;
    }

    if (DLT104SlaveLink[pdrv].NR == 32767)
    {
        DLT104SlaveLink[pdrv].NR = 0;
    }
    else
    {
        DLT104SlaveLink[pdrv].NR++;
    }

    DLT104SlaveLink[pdrv].StopSendFlag = FALSE; // 清停止发送标志
        
    DLT634_5104_SLAVE_KillTimer(pdrv, 1);
    DLT634_5104_SLAVE_SetTimer(pdrv, 2);
    DLT634_5104_SLAVE_SetTimer(pdrv, 3);
    
    msg.Cmd = DLT634_5104SLAVE_LINK_CALLDATA;
    msg.ConNum = tmp - DLT104SlaveLink[pdrv].PeerNoAckNum;
    msg.pData = &DLT104SlaveLink[pdrv].RxdBuf[6];
    msg.Len = pAPCI->Length - 4;
    
    DLT634_5104_SLAVE_AppProcess(pdrv, &msg);
}

/* -----------------------------------------------------------------------------
** 函数名称: SearchValidFrame
** 功能描述: 查找有效帧
** 输　  入: 无
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Sun
** 日　  期: 2017.07.12
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5104_SLAVE_SearchValidFrame(BYTE pdrv)
{
      BYTE stop = FALSE;
    struct DLT634_5104SLAVE_PAPCI *pAPCI;
    
    while ((DLT104SlaveLink[pdrv].RxdHead < DLT104SlaveLink[pdrv].RxdTail) && (!stop))
    {
        if (DLT104SlaveLink[pdrv].RxdStatus == RXDSTART)
        {
            if (DLT104SlaveLink[pdrv].RxdBuf[DLT104SlaveLink[pdrv].RxdHead] != DLT634_5104SLAVE_STARTCODE68)
            {
                DLT104SlaveLink[pdrv].RxdHead++;
                continue;
            }
            
            // 找到后，清除无用的缓冲区报文
            if (DLT104SlaveLink[pdrv].RxdTail > DLT104SlaveLink[pdrv].RxdHead)
            {
                DLT104SlaveLink[pdrv].RxdLength = DLT104SlaveLink[pdrv].RxdTail - DLT104SlaveLink[pdrv].RxdHead;
                memcpy (DLT104SlaveLink[pdrv].RxdBuf, &DLT104SlaveLink[pdrv].RxdBuf[DLT104SlaveLink[pdrv].RxdHead], DLT104SlaveLink[pdrv].RxdLength);
                DLT104SlaveLink[pdrv].RxdHead = 0;
                DLT104SlaveLink[pdrv].RxdTail = DLT104SlaveLink[pdrv].RxdLength;
            }

            DLT104SlaveLink[pdrv].RxdStatus = RXDHEAD;
        }
            
        if (DLT104SlaveLink[pdrv].RxdStatus == RXDHEAD)
        {
            pAPCI = (struct DLT634_5104SLAVE_PAPCI*)DLT104SlaveLink[pdrv].RxdBuf;
            if (DLT104SlaveLink[pdrv].RxdLength >= sizeof (struct DLT634_5104SLAVE_PAPCI))
            {
                switch (pAPCI->NS & DLT634_5104SLAVE_U_FRAME)
                {
                    case DLT634_5104SLAVE_S_FRAME:
                        if (pAPCI->Length == 4)
                        {
                            DLT634_5104_SLAVE_KillTimer(pdrv, 1);
                            DLT634_5104_SLAVE_SetTimer(pdrv, 3);
                            DLT634_5104_SLAVE_DecodeSFrame(pdrv);
                        }
                        break;
                
                    case DLT634_5104SLAVE_U_FRAME:
                        if (pAPCI->Length == 4)
                        {
                            DLT634_5104_SLAVE_KillTimer(pdrv, 1);
                            DLT634_5104_SLAVE_SetTimer(pdrv, 3);
                            DLT634_5104_SLAVE_DecodeUFrame(pdrv);
                        }
                        break;
                        
                    default:
                        if ((DLT104SlaveLink[pdrv].RxdLength >= (pAPCI->Length + 2)))
                        {
                            DLT634_5104_SLAVE_DecodeIFrame(pdrv);
                        }
                        else
                        {
                            stop = TRUE;
                        }
                        break;
                }
            }
            else
            {
                stop = TRUE;
            }
            
            if (!stop)
            {
                DLT104SlaveLink[pdrv].RxdStatus = RXDCONTINUE;
            }
        }
            
        if (DLT104SlaveLink[pdrv].RxdStatus == RXDCONTINUE)
        {
            DLT104SlaveLink[pdrv].RxdLength = DLT104SlaveLink[pdrv].RxdTail - (pAPCI->Length + 2);
            memcpy (DLT104SlaveLink[pdrv].RxdBuf, &DLT104SlaveLink[pdrv].RxdBuf[pAPCI->Length + 2], DLT104SlaveLink[pdrv].RxdLength);
            DLT104SlaveLink[pdrv].RxdHead = 0;
            DLT104SlaveLink[pdrv].RxdTail = DLT104SlaveLink[pdrv].RxdLength;
            DLT104SlaveLink[pdrv].RxdStatus = RXDSTART;
        
            if (DLT104SlaveLink[pdrv].RxdTail > DLT104SlaveLink[pdrv].RxdHead)
            {
                stop = TRUE;
            }
        }    
    }
}

/* PUBLIC FUNCTION PROTOTYPES ------------------------------------------------*/

BYTE DLT634_5104_SLAVE_Reply(BYTE pdrv, BYTE *pbuf) //回复
{ 
        BYTE res;
      memcpy(&DLT104SlaveApp[pdrv].ST_Temp, pbuf, DLT634_5104SLAVE_LPDUSIZE);
        switch (DLT104SlaveApp[pdrv].ST_Temp.Head.TypeID)
      {
              //控制方向过程信息
              case DLT634_5104SLAVE_C_SC_NA_1: // 单点遥控命令
              case DLT634_5104SLAVE_C_SC_NB_1: // 双点遥控命令
                     DLT104SlaveApp[pdrv].ST_Temp.status.symbol.priority = DLT634_5104SLAVE_C_SC_NA_P;
                    res = DLT634_5104_SLAVE_StoreIN(pdrv,&DLT104SlaveApp[pdrv].ST_Temp);
                      break;

              case DLT634_5104SLAVE_C_CS_NA_1: // 对时命令
                    DLT104SlaveApp[pdrv].ST_Temp.status.symbol.priority = DLT634_5104SLAVE_C_CS_NA_P;
                    res = DLT634_5104_SLAVE_StoreIN(pdrv,&DLT104SlaveApp[pdrv].ST_Temp);
                    break;

              case DLT634_5104SLAVE_C_RP_NA_1: // 复位进程命令
                      break;
            
              case DLT634_5104SLAVE_C_RR_NA_1: // 读定值区号
              case DLT634_5104SLAVE_C_RS_NA_1: // 读参数和定值命令
                    DLT104SlaveApp[pdrv].ST_Temp.status.symbol.priority = DLT634_5104SLAVE_C_IC_NA_P;
                    res = DLT634_5104_SLAVE_StoreIN(pdrv,&DLT104SlaveApp[pdrv].ST_Temp);
                      break;
            
              case DLT634_5104SLAVE_C_SR_NA_1: // 切换定值区
              case DLT634_5104SLAVE_C_WS_NA_1: // 写参数和定值命令
                    DLT104SlaveApp[pdrv].ST_Temp.status.symbol.priority = DLT634_5104SLAVE_C_SC_NA_P;
                    res = DLT634_5104_SLAVE_StoreIN(pdrv,&DLT104SlaveApp[pdrv].ST_Temp);
                      break;

              case DLT634_5104SLAVE_F_FR_NA_1: // 文件传输
                    DLT104SlaveApp[pdrv].ST_Temp.status.symbol.priority = DLT634_5104SLAVE_F_FW_NA_P;
                    res = DLT634_5104_SLAVE_StoreIN(pdrv,&DLT104SlaveApp[pdrv].ST_Temp);
                      break;

              case DLT634_5104SLAVE_F_SR_NA_1: // 软件升级
                      break;            

              default: // 类型标识有错误或不支持
                      break;
      }
        return(res);
}

/* -----------------------------------------------------------------------------
** 函数名称: AllDataConfReply
** 功能描述: 总召唤确认
** 输　  入: 无
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Sun
** 日　  期: 2017.07.13
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5104_SLAVE_AllDataConfReply(BYTE pdrv)
{
        DLT104SlaveApp[pdrv].TX_Temp.status.Length = sizeof(DLT104SlaveApp[pdrv].TX_Temp.status) + sizeof(DLT104SlaveApp[pdrv].TX_Temp.Head) + sizeof(DLT104SlaveApp[pdrv].TX_Temp.Data.C_100);
        DLT104SlaveApp[pdrv].TX_Temp.status.symbol.priority = DLT634_5104SLAVE_C_IC_NA_PF;
        DLT104SlaveApp[pdrv].TX_Temp.Head.TypeID = DLT634_5104SLAVE_C_IC_NA_1; 
        DLT104SlaveApp[pdrv].TX_Temp.Head.VSQ = 1;
        DLT104SlaveApp[pdrv].TX_Temp.Head.COT_L = DLT634_5104SLAVE_COT_ACTCON;
        DLT104SlaveApp[pdrv].TX_Temp.Head.PubAddr_H = (BYTE)((DLT634_5104Slave_Pad[pdrv].PubAddress>>8)&0xff);
        DLT104SlaveApp[pdrv].TX_Temp.Head.PubAddr_L = (BYTE)(DLT634_5104Slave_Pad[pdrv].PubAddress&0xff);
        DLT104SlaveApp[pdrv].TX_Temp.Data.C_100.InfoAddr_L = 0;  
        DLT104SlaveApp[pdrv].TX_Temp.Data.C_100.QOI = 20;  
}

/* -----------------------------------------------------------------------------
** 函数名称: AllDataEndReply
** 功能描述: 总召唤结束
** 输　  入: 无
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Sun
** 日　  期: 2017.07.13
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5104_SLAVE_AllDataEndReply(BYTE pdrv)
{
        DLT104SlaveApp[pdrv].TX_Temp.status.Length = sizeof(DLT104SlaveApp[pdrv].TX_Temp.status) + sizeof(DLT104SlaveApp[pdrv].TX_Temp.Head) + sizeof(DLT104SlaveApp[pdrv].TX_Temp.Data.C_100);
        DLT104SlaveApp[pdrv].TX_Temp.status.symbol.priority = DLT634_5104SLAVE_C_IC_NA_PF;
        DLT104SlaveApp[pdrv].TX_Temp.Head.TypeID = DLT634_5104SLAVE_C_IC_NA_1;
        DLT104SlaveApp[pdrv].TX_Temp.Head.VSQ = 1;
        DLT104SlaveApp[pdrv].TX_Temp.Head.COT_L = DLT634_5104SLAVE_COT_ACCTTERM;
        DLT104SlaveApp[pdrv].TX_Temp.Head.PubAddr_H = (BYTE)((DLT634_5104Slave_Pad[pdrv].PubAddress>>8)&0xff);
        DLT104SlaveApp[pdrv].TX_Temp.Head.PubAddr_L = (BYTE)(DLT634_5104Slave_Pad[pdrv].PubAddress&0xff);
        DLT104SlaveApp[pdrv].TX_Temp.Data.C_100.QOI = 20;    
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5104_SLAVE_LinkSendProcess
** 功能描述: 链路层发送处理。
** 输　  入: BYTE* pData：发送数据起始地址.
**           BYTE Len   ：发送数据长度
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Lee
** 日　  期: 2016.10.25
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
void DLT634_5104_SLAVE_LinkSendProcess(BYTE pdrv, BYTE* pData, BYTE Len)
{
    struct DLT634_5104SLAVE_PAPCI *pFrame;
    
    pFrame = (struct DLT634_5104SLAVE_PAPCI*)&DLT104SlaveLink[pdrv].TxdBuf[DLT104SlaveLink[pdrv].TxdHead];
    
    if (Len == 0 || DLT104SlaveLink[pdrv].StopSendFlag)
    {
        return;
    }
    DLT104SlaveLink[pdrv].NRACK = DLT104SlaveLink[pdrv].NR;
        
    pFrame->StartCode = DLT634_5104SLAVE_STARTCODE68;
    pFrame->Length = Len + 0x04;
    pFrame->NS = DLT104SlaveLink[pdrv].NS << 1;
    pFrame->NR = DLT104SlaveLink[pdrv].NR << 1;
    memcpy((BYTE*)(pFrame+1), pData, Len);
    DLT104SlaveLink[pdrv].TxdTail += Len + 0x06;        

    DLT104SlaveLink[pdrv].DataType[DLT104SlaveLink[pdrv].PeerNoAckNum] = TRUE;
    DLT104SlaveLink[pdrv].PeerNoAckNum++;
    DLT104SlaveLink[pdrv].NS++;
        
        if (DLT104SlaveLink[pdrv].PeerNoAckNum >= DLT634_5104SLAVE_K) // 未被确认的I帧数量达到K个时  停止发送
        {
            DLT104SlaveLink[pdrv].StopSendFlag = TRUE;
        }
    // 发送
    DLT634_5104_SLAVE_KillTimer(pdrv, 2);
    DLT634_5104_SLAVE_SetTimer(pdrv, 3);
    DLT634_5104_SLAVE_WriteDataToMISI(pdrv);
    DLT634_5104_SLAVE_SetTimer(pdrv, 1); //         
        
}

/* -----------------------------------------------------------------------------
** 函数名称: ReadAllDataProcess
** 功能描述: 总召唤处理过程
** 输　  入: 无
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Sun
** 日　  期: 2017.07.13
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
void ReadAllDataProcess(BYTE pdrv)
{
      static BYTE group;
      static BYTE YX_group;
      static BYTE YC_group;
    
      switch (DLT104SlaveApp[pdrv].AllDataFlag)
      {
              case 0:
                      DLT634_5104_SLAVE_AllDataConfReply(pdrv);
                      group = 0;
                      YX_group = (DLT634_5104Slave_Pad[pdrv].YX_AllNum % DLT634_5104Slave_Pad[pdrv].YX_FrameNum) ? \
                                 (DLT634_5104Slave_Pad[pdrv].YX_AllNum / DLT634_5104Slave_Pad[pdrv].YX_FrameNum + 1) : (DLT634_5104Slave_Pad[pdrv].YX_AllNum/DLT634_5104Slave_Pad[pdrv].YX_FrameNum);
                      YC_group = (DLT634_5104Slave_Pad[pdrv].YC_AllNum % DLT634_5104Slave_Pad[pdrv].YC_FrameNum) ? \
                                     (DLT634_5104Slave_Pad[pdrv].YC_AllNum / DLT634_5104Slave_Pad[pdrv].YC_FrameNum + 1) : (DLT634_5104Slave_Pad[pdrv].YC_AllNum/DLT634_5104Slave_Pad[pdrv].YC_FrameNum);
                      DLT104SlaveApp[pdrv].AllDataFlag = 1;
                     break;
              case 1:
                      if (DLT634_5104Slave_Pad[pdrv].YX_AllNum / DLT634_5104Slave_Pad[pdrv].YX_FrameNum > group)
                      {
                            DLT634_5104_SLAVE_ReadYxData(pdrv ,DLT634_5104Slave_Pad[pdrv].YX_FrameNum*group + DLT634_5104Slave_Pad[pdrv].YX_FirstAddr, \
                                                    DLT634_5104Slave_Pad[pdrv].YX_FrameNum, 
                                                    (BYTE *)&DLT104SlaveApp[pdrv].TX_Temp);
                      }
                      else
                      {
                            DLT634_5104_SLAVE_ReadYxData(pdrv, DLT634_5104Slave_Pad[pdrv].YX_FrameNum*group + DLT634_5104Slave_Pad[pdrv].YX_FirstAddr, \
                                                   DLT634_5104Slave_Pad[pdrv].YX_AllNum - group * DLT634_5104Slave_Pad[pdrv].YX_FrameNum, \
                                                    (BYTE *)&DLT104SlaveApp[pdrv].TX_Temp);
                      }
                      if (++group >= YX_group)
                      {      
                             DLT104SlaveApp[pdrv].AllDataFlag = 2;
                            group = 0;
                      }
                    break;
              case 2:
                      if (DLT634_5104Slave_Pad[pdrv].YC_AllNum/DLT634_5104Slave_Pad[pdrv].YC_FrameNum > group)
                      {
                            DLT634_5104_SLAVE_ReadYcData(pdrv, DLT634_5104Slave_Pad[pdrv].YC_FrameNum*group + DLT634_5104Slave_Pad[pdrv].YC_FirstAddr, \
                                                   DLT634_5104Slave_Pad[pdrv].YC_FrameNum, \
                                                    (BYTE *)&DLT104SlaveApp[pdrv].TX_Temp);
                      }
                      else
                      {
                             DLT634_5104_SLAVE_ReadYcData(pdrv ,DLT634_5104Slave_Pad[pdrv].YC_FrameNum*group + DLT634_5104Slave_Pad[pdrv].YC_FirstAddr, \
                                                 DLT634_5104Slave_Pad[pdrv].YC_AllNum - group * DLT634_5104Slave_Pad[pdrv].YC_FrameNum, \
                                                    (BYTE *)&DLT104SlaveApp[pdrv].TX_Temp);
                      }
                
                      if (++group >= YC_group)
                      {
                            DLT104SlaveApp[pdrv].AllDataFlag = 3;
                            group = 0;
                      }
                    break;
              case 3:
                      DLT634_5104_SLAVE_AllDataEndReply(pdrv);
                      DLT104SlaveApp[pdrv].Data1Flag &= (~DLT634_5104SLAVE_CALLALLDATA);
                     break;
              default:
                    break;    
    }   
}

/* -----------------------------------------------------------------------------
** 函数名称: ReadData1Process
** 功能描述: 处理一级数据
** 输　  入: 无
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Sun
** 日　  期: 2017.07.13
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
void ReadData1Process(BYTE pdrv)
{
        if ((DLT634_5104_SLAVE_H_SOE(pdrv))&&
            ((DLT104SlaveApp[pdrv].StoreDATA1IN->status.symbol.priority > DLT634_5104SLAVE_M_SP_TB_P)||
            (DLT104SlaveApp[pdrv].StoreDATA1IN->status.symbol.priority == 0))) 
        {
            DLT634_5104_SLAVE_R_SOE(pdrv,(BYTE *)&DLT104SlaveApp[pdrv].TX_Temp);
            DLT104SlaveApp[pdrv].Data1Flag &= (~DLT634_5104SLAVE_HAVESOE);
            return;
        }
        
    if (DLT104SlaveApp[pdrv].Data1Flag & DLT634_5104SLAVE_CALLALLDATA)
        {
            ReadAllDataProcess(pdrv);
              return;
        }

        if (DLT104SlaveApp[pdrv].StoreDATA1OUT != DLT104SlaveApp[pdrv].StoreDATA1IN)
        {
              memcpy((BYTE *)&DLT104SlaveApp[pdrv].TX_Temp, (BYTE *)DLT104SlaveApp[pdrv].StoreDATA1OUT, DLT104SlaveApp[pdrv].StoreDATA1OUT->status.Length);
              memset((BYTE *)DLT104SlaveApp[pdrv].StoreDATA1OUT,0,sizeof(DLT634_5104SLAVE_PASDU));
              if (++DLT104SlaveApp[pdrv].StoreDATA1OUT >= DLT104SlaveApp[pdrv].StoreDATA1Buf + DLT634_5104SLAVE_STOREDATA1NUM)
              {
                    DLT104SlaveApp[pdrv].StoreDATA1OUT = DLT104SlaveApp[pdrv].StoreDATA1Buf;
              }
              return;
        }        
}

/* -----------------------------------------------------------------------------
** 函数名称: ReadData2Process
** 功能描述: 处理一级数据
** 输　  入: 无
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Sun
** 日　  期: 2017.07.13
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
void ReadData2Process(BYTE pdrv)
{
        if ((DLT634_5104_SLAVE_H_NVA(pdrv))&&
            ((DLT104SlaveApp[pdrv].StoreDATA2IN->status.symbol.priority > DLT634_5104SLAVE_M_ME_NC_P)||
            (DLT104SlaveApp[pdrv].StoreDATA2IN->status.symbol.priority == 0))) 
        {
            DLT634_5104_SLAVE_R_NVA(pdrv,(BYTE *)&DLT104SlaveApp[pdrv].TX_Temp);
            return;
        }
        
        if ((DLT634_5104_SLAVE_H_FEvent(pdrv))&&
            ((DLT104SlaveApp[pdrv].StoreDATA2IN->status.symbol.priority > DLT634_5104SLAVE_M_FT_NA_P)||
            (DLT104SlaveApp[pdrv].StoreDATA2IN->status.symbol.priority == 0))) 
        {
            DLT634_5104_SLAVE_R_FEvent(pdrv,(BYTE *)&DLT104SlaveApp[pdrv].TX_Temp);
            return;
        }

        if (DLT104SlaveApp[pdrv].StoreDATA2OUT != DLT104SlaveApp[pdrv].StoreDATA2IN)
        {
              memcpy((BYTE *)&DLT104SlaveApp[pdrv].TX_Temp, (BYTE *)DLT104SlaveApp[pdrv].StoreDATA2OUT, DLT104SlaveApp[pdrv].StoreDATA2OUT->status.Length);
              memset((BYTE *)DLT104SlaveApp[pdrv].StoreDATA2OUT,0,sizeof(DLT634_5104SLAVE_PASDU));
              if (++DLT104SlaveApp[pdrv].StoreDATA2OUT >= DLT104SlaveApp[pdrv].StoreDATA2Buf + DLT634_5104SLAVE_STOREDATA2NUM)
              {
                    DLT104SlaveApp[pdrv].StoreDATA2OUT = DLT104SlaveApp[pdrv].StoreDATA2Buf;
              }
              return;
        }    
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5104_NetTest
** 功能描述: 网络连接状态判断。
** 输　  入: PORT_Type pdrv：接口类型.
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Lee
** 日　  期: 2016.10.25
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
void DLT634_5104_SLAVE_NetTest(BYTE pdrv)
{
  //#if (PHY_LAN8720_CFG || PHY_ENC28J60_CFG)  
    
    if (!DLT634_5104_SLAVE_CheckLink(pdrv))//是否链接
    {            
        DLT634_5104_AppInitReset(pdrv);                
        DLT104SlaveApp[pdrv].Connect = FALSE;
              DLT104SlaveLink[pdrv].Connect = FALSE;
    }
    else if (!DLT104SlaveLink[pdrv].Connect)
    {
        // DLT634_5104_AppInitReset(pdrv);                
        DLT104SlaveLink[pdrv].Connect = TRUE;
    }
  //#endif /* END PHY_LAN8720_CFG || PHY_ENC28J60_CFG */
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5104_AppInit
** 功能描述: 应用层初始化.
** 输　  入: 无
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Lee
** 日　  期: 2016.10.25
** -----------------------------------------------------------------------------
** 修 改 人:                                              
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
BYTE DLT634_5104_SLAVE_AppInit(BYTE pdrv)
{
      memset (&DLT104SlaveApp[pdrv], 0, sizeof (struct DLT634_5104SLAVE_APPINFO));
    
      DLT104SlaveApp[pdrv].YXTypeID = DLT634_5104SLAVE_M_SP_NA_1;
    DLT104SlaveApp[pdrv].YCTypeID = DLT634_5104SLAVE_M_ME_NC_1;
      DLT634_5104_AppInitReset(pdrv);
      
      return(TRUE);
}


void DLT634_5104_SLAVE_SendProcess(BYTE pdrv)
{
    ReadData1Process(pdrv);    

        if (DLT104SlaveApp[pdrv].TX_Temp.status.Length)
        {
              DLT104SlaveApp[pdrv].TxLen = DLT104SlaveApp[pdrv].TX_Temp.status.Length - sizeof(DLT104SlaveApp[pdrv].TX_Temp.status);        
              memcpy(&DLT104SlaveApp[pdrv].TxMsg, &DLT104SlaveApp[pdrv].TX_Temp.Head, DLT104SlaveApp[pdrv].TxLen); 
       DLT634_5104_SLAVE_LinkSendProcess(pdrv, (BYTE*)&DLT104SlaveApp[pdrv].TxMsg, DLT104SlaveApp[pdrv].TxLen);        
                memset((BYTE *)&DLT104SlaveApp[pdrv].TX_Temp, 0, sizeof(DLT634_5104SLAVE_PASDU));            
        }    
    else
        {
            ReadData2Process(pdrv);
            if (DLT104SlaveApp[pdrv].TX_Temp.status.Length)
            {
                  DLT104SlaveApp[pdrv].TxLen = DLT104SlaveApp[pdrv].TX_Temp.status.Length - sizeof(DLT104SlaveApp[pdrv].TX_Temp.status);        
                  memcpy(&DLT104SlaveApp[pdrv].TxMsg, &DLT104SlaveApp[pdrv].TX_Temp.Head, DLT104SlaveApp[pdrv].TxLen); 
            DLT634_5104_SLAVE_LinkSendProcess(pdrv, (BYTE*)&DLT104SlaveApp[pdrv].TxMsg, DLT104SlaveApp[pdrv].TxLen);        
                    memset((BYTE *)&DLT104SlaveApp[pdrv].TX_Temp, 0, sizeof(DLT634_5104SLAVE_PASDU));            
            }                
        }
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5104_LinkOnTimer
** 功能描述: 链路层定时器。
** 输　  入: 无
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Lee
** 日　  期: 2016.10.25
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
void DLT634_5104_SLAVE_LinkOnTimer(BYTE pdrv)
{
    BYTE    i = 0;
        
    if (DLT104SlaveLink[pdrv].Tick.Flag & DLT634_5104SLAVE_T0FLAG)
    {
        DLT104SlaveLink[pdrv].Tick.TValue0++;

        if (DLT104SlaveLink[pdrv].Tick.TValue0 > DLT634_5104Slave_Pad[pdrv].TickValue[0])
        {
            DLT634_5104_SLAVE_KillTimer(pdrv, 0);
            DLT634_5104_SLAVE_StopDTOper(pdrv);
        }
    }

    if (DLT104SlaveLink[pdrv].Tick.Flag & DLT634_5104SLAVE_T1FLAG)
    {
        for (i=0; i<DLT104SlaveLink[pdrv].PeerNoAckNum; i++)
        {
            DLT104SlaveLink[pdrv].Tick.TValue1[i]++;

            if (DLT104SlaveLink[pdrv].Tick.TValue1[i] > DLT634_5104Slave_Pad[pdrv].TickValue[1])
            {
                DLT634_5104_SLAVE_KillTimer(pdrv, 1);
                DLT634_5104_SLAVE_StopDTOper(pdrv);
            }
        }
    }
    
    if (DLT104SlaveLink[pdrv].Tick.Flag & DLT634_5104SLAVE_T2FLAG)
    {
        DLT104SlaveLink[pdrv].Tick.TValue2++;

        if ( DLT104SlaveLink[pdrv].Tick.TValue2 > DLT634_5104Slave_Pad[pdrv].TickValue[2] )
        {
            DLT634_5104_SLAVE_KillTimer(pdrv, 2);
            DLT634_5104_SLAVE_S104SendCtrlFrame(pdrv, DLT634_5104SLAVE_S_FRAME);
        }
    }
    
    if (DLT104SlaveLink[pdrv].Tick.Flag & DLT634_5104SLAVE_T3FLAG)
    {
        DLT104SlaveLink[pdrv].Tick.TValue3++;

        if (DLT104SlaveLink[pdrv].Tick.TValue3 > DLT634_5104Slave_Pad[pdrv].TickValue[3])
        {
            DLT634_5104_SLAVE_KillTimer(pdrv, 3);
            
            if (DLT104SlaveLink[pdrv].PeerNoAckNum)
            {
                DLT634_5104_SLAVE_S104SendCtrlFrame(pdrv, DLT634_5104SLAVE_U_TESTFRACT);
            }
            else if (!(DLT104SlaveLink[pdrv].Tick.Flag & DLT634_5104SLAVE_T1FLAG))
            {
                DLT634_5104_SLAVE_SetTimer(pdrv, 1);
            }
        }
    }    
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5104_SLAVE_ReadMISIData
** 功能描述: 接收MISI数据。
** 输　  入: PORT_Type pdrv：通信接口类型；
**           BYTE Flag     ：是否接收数据标志。
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Lee
** 日　  期: 2016.10.25
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
void DLT634_5104_SLAVE_ReadMISIData(BYTE pdrv, BYTE Flag)
{
    WORD count = 0;
    
      /*读取接收缓冲区*/
    count = DLT634_5104_SLAVE_ReadData(pdrv, (BYTE *)&DLT104SlaveLink[pdrv].RxdBuf[DLT104SlaveLink[pdrv].RxdTail], DLT634_5104SLAVE_FRAMEBUFSIZE);    
    
      if (Flag)
    {
        DLT104SlaveLink[pdrv].RxdTail += count;
        DLT104SlaveLink[pdrv].RxdLength += count;
    }
    
    DLT634_5104_SLAVE_SearchValidFrame(pdrv); 
}

void DLT634_5104_SLAVE_Clock(BYTE pdrv)
{
      DLT104SlaveLink[pdrv].ClockCounter++;
      if (DLT104SlaveLink[pdrv].ClockCounter >= DLT634_5104Slave_Pad[pdrv].ClockTimers)
      {
        DLT104SlaveLink[pdrv].ClockCounter = 0;
        // 查询MISI接收缓冲区
            
        if(!DLT104SlaveApp[pdrv].Connect) // 状态连接
        {
            DLT634_5104_SLAVE_NetTest(pdrv);
            DLT634_5104_SLAVE_ReadMISIData(pdrv, TRUE);
        }
        else
        {
        
            DLT634_5104_SLAVE_ReadMISIData(pdrv, TRUE); // 链路层数据查询

            DLT634_5104_SLAVE_SendProcess(pdrv);    // 发送数据

            DLT634_5104_SLAVE_LinkOnTimer(pdrv); // 链路层定时器

            DLT634_5104_SLAVE_NetTest(pdrv); // 网络判断
        }                    
      }      
}



