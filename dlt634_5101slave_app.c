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
** File name:               DLT634_5101_app.c
** Descriptions:            The application of DLT634.5101_2002
**
** -----------------------------------------------------------------------------
** Created by:              Mr.J
** Created date:            2017.5.16
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
#include "string.h"
#include "dlt634_5101slave_app.h"
#include "dlt634_5101slave_disk.h"


/* PRIVATE VARIABLES ----------------------------------------------------------*/
#pragma pack(push,1)
typedef struct 
{
    uint8_t Milliseconds_L;   // D7-D0
    uint8_t Milliseconds_H;   // D7-D0
    uint8_t Minutes;					// D5-D0
    uint8_t Hours;						// D4-D0
    uint8_t DayofWeekMonth;		// WEEK(D7-D5)MONTH(D4-D0)
    uint8_t Months;						// D3-D0
    uint8_t Years;						// D6-D0
}_DLT634_5101SLAVE_CP56Time2a_t;

typedef struct 
{
    struct STATUS
    {
        uint8_t Length;
        union
        {
            uint8_t priority;	
            uint8_t Lock_ID;
        }symbol;
    }status;

    struct HEAD
    {
        uint8_t TypeID;     
        uint8_t VSQ;  
        uint8_t COT_L;
        uint8_t COT_H;
        uint8_t PubAddr_L;
        uint8_t PubAddr_H;
    }Head;

    union
    {
        uint8_t	buff[256-sizeof(struct STATUS)-sizeof(struct HEAD)];
        struct
        {
            uint8_t InfoAddr_L;
            uint8_t InfoAddr_H;
            uint8_t QOI; 
        }C_100;

        struct
        {
            uint8_t InfoAddr_L;
            uint8_t InfoAddr_H;	
            _DLT634_5101SLAVE_CP56Time2a_t CP56Time2a;
        }C_103;

        struct
        {
            uint8_t InfoAddr_L;
            uint8_t InfoAddr_H;	
            uint8_t QRP; 
        }C_105;

        struct
        {
            uint8_t InfoAddr_L;
            uint8_t InfoAddr_H;	
            uint8_t COI; 
        }C_70;

        struct
        {
            uint8_t InfoAddr_L;
            uint8_t InfoAddr_H;
            uint8_t FBP_L;
            uint8_t FBP_H;				
        }C_104;

        union
        {
            struct
            {
                struct
                {
                    uint8_t InfoAddr_L;
                    uint8_t InfoAddr_H;	
                    uint8_t Value; 
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/3];
            }SQ0;

            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;
                struct
                {
                    uint8_t Value; 
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/1];
            }SQ1;
        }C_1;

        union
        {
            struct
            {
                struct
                {
                    uint8_t InfoAddr_L;
                    uint8_t InfoAddr_H;	
                    uint8_t Value; 
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/3];
            }SQ0;

            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;	
                struct
                {
                    uint8_t Value; 
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/1];
            }SQ1;
        }C_3;

        union
        {
            struct
            {
                struct
                {
                    uint8_t InfoAddr_L;
                    uint8_t InfoAddr_H;
                    uint8_t Value; 
                    _DLT634_5101SLAVE_CP56Time2a_t CP56Time2a;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/10];
            }SQ0;

            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;	
                struct
                {
                    uint8_t Value; 
                    _DLT634_5101SLAVE_CP56Time2a_t CP56Time2a;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/8];
            }SQ1;
        }C_30;

        union
        {
            struct
            {
                struct
                {
                    uint8_t InfoAddr_L;
                    uint8_t InfoAddr_H;	
                    uint8_t Value; 
                    _DLT634_5101SLAVE_CP56Time2a_t CP56Time2a;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/10];
            }SQ0;

            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;	
                struct
                {
                    uint8_t Value; 
                    _DLT634_5101SLAVE_CP56Time2a_t CP56Time2a;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/8];
            }SQ1;
        }C_31;

        union
        {
            struct
            {
                struct
                {
                    uint8_t InfoAddr_L;
                    uint8_t InfoAddr_H;
                    uint32_t Value;
                    uint8_t QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/7];
            }SQ0;

            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;	
                struct
                {
                    uint32_t Value;									
                    uint8_t QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/5];
            }SQ1;
        }C_9;

        union
        {
            struct
            {
                struct
                {
                    uint8_t InfoAddr_L;
                    uint8_t InfoAddr_H;
                    uint32_t Value;
                    uint8_t QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/7];
            }SQ0;

            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;
                struct
                {
                    uint32_t Value_L;
                    uint8_t QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/5];
            }SQ1;
        }C_11;

        union
        {
            struct
            {
                struct
                {
                    uint8_t InfoAddr_L;
                    uint8_t InfoAddr_H;
                    uint32_t Value;	
                    uint8_t QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/7];
            }SQ0;

            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;
                struct
                {
                    uint32_t Value;	
                    uint8_t QDS;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/5];
            }SQ1;
        }C_13;

        struct
        {
            uint8_t InfoAddr_L;
            uint8_t InfoAddr_H;
            uint8_t SCO_L;
            uint8_t SCO_H;
        }C_45;	

        struct
        {
            uint8_t InfoAddr_L;
            uint8_t InfoAddr_H;	
            uint8_t DCO_L;
            uint8_t DCO_H;
        }C_46;	

        struct
        {
            uint8_t Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))]; 
        }C_42;

        struct
        {
            uint8_t InfoAddr_L;
            uint8_t InfoAddr_H;	
            uint8_t SN_L;
            uint8_t SN_H;
        }C_200;

        union
        {
            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;
            }Down;

            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;	
                uint8_t SN1_L;
                uint8_t SN1_H;
                uint8_t SN2_L;
                uint8_t SN2_H;
                uint8_t SN3_L;
                uint8_t SN3_H;
            }Up;
        }C_201;

        union
        {
            struct
            {
                uint8_t SN1_L;
                uint8_t SN1_H;
                uint32_t Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/4];		
            }Down;

            struct
            {
                uint8_t SN_L;
                uint8_t SN_H;	
                uint8_t PI_L;
                uint8_t PI_H;
                struct
                {
                    uint8_t InfoAddr_L;
                    uint8_t InfoAddr_H;
                    uint8_t Tag;
                    uint8_t Len;
                    uint32_t Value;	
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-4)/8];
            }Up;
        }C_202;

        union
        {
            uint8_t SN_L;
            uint8_t SN_H;	
            uint8_t PI_L;
            uint8_t PI_H;
            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;
                uint8_t Tag;
                uint8_t Len;
                uint32_t Value;	
            }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-4)/8];
        }C_203;

        struct
        {
            uint8_t Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-4)/1];
        }C_210;
    }Data;
}DLT634_5101SLAVE_PASDU;

typedef struct 
{
//link	
	enum
	{
        RXDSTART = 0,	          // 寻找起始标志状态
        RXDHEAD,	              // 寻找报文头
        RXDCONTINUE             // 接收后续报文
	}RxdStatus;           			// 接收状态
	
	uint16_t TxdHead;	      				// 发送缓冲区头指针
	uint16_t TxdTail;	     					// 发送缓冲区尾指针
	uint8_t TxdBuf[_DLT634_5101SLAVE_LPDUSIZE];     	// 发送缓冲区
	
	uint16_t RxdHead;	      				// 接收数据区头指针
    uint16_t RxdTail;       				// 接收数据区尾指针
	uint16_t RxdLength;     				// 接收一帧数据长度
	uint8_t RxdBuf[_DLT634_5101SLAVE_LPDUSIZE];			// 接收缓冲区
	
	uint16_t TxdTail_Pri;
	uint8_t TxdBuf_Pri[_DLT634_5101SLAVE_LPDUSIZE]; // 发送缓冲区，暂存发送的数据，重发时用
	
	uint16_t TxdTail_Special;
	uint8_t TxdBuf_Special[_DLT634_5101SLAVE_LPDUSIZE]; // 发送缓冲区，暂存发送的数据，特殊数据链路重建时发送
	
//app
	DLT634_5101SLAVE_PASDU *StoreDATA1IN;              //待发送缓冲区1级数据入指针
	DLT634_5101SLAVE_PASDU *StoreDATA1OUT;             //待发送缓冲区1级数据出指针
	DLT634_5101SLAVE_PASDU StoreDATA1Buf[_DLT634_5101SLAVE_STOREDATA1NUM];     	// 1级数据待发送缓冲区
	DLT634_5101SLAVE_PASDU *StoreDATA2IN;              //待发送缓冲区2级数据入指针
	DLT634_5101SLAVE_PASDU *StoreDATA2OUT;             //待发送缓冲区2级数据出指针
	DLT634_5101SLAVE_PASDU StoreDATA2Buf[_DLT634_5101SLAVE_STOREDATA2NUM];     	// 2级数据待发送缓冲区
	DLT634_5101SLAVE_PASDU ST_Temp;              //存储数据处理
	
	DLT634_5101SLAVE_PASDU TX_Temp;              //发送数据处理
	DLT634_5101SLAVE_PASDU RX_Temp;              //接受数据处理
	
	uint32_t LinkFlag;              //回复链路数据标志
	uint32_t Data1Flag;						 //回复1级数据标志
	uint32_t Data2Flag;						 //回复2级数据标志
	
	uint32_t AllDataFlag;					//总召状态标志
	
	uint32_t ClockCounter;  				//程序运行周期控制
	uint32_t TimeOutTick_Pri; 			//超时节拍计时器
	uint32_t RetryCount;						//超时记数器
	
	uint32_t TimeOutTick_AskSta;
	
	uint8_t RlaConCode;	   // 接收的控制码FCB位记录
	uint8_t FCBNoTurnNum;    // FCB未翻转计数
}DLT634_5101SLAVE_APPINFO;
#pragma pack(pop)
/* PUBLIC VARIABLES ----------------------------------------------------------*/
DLT634_5101SLAVE_PAD      DLT634_5101Slave_Pad[_DLT634_5101SLAVE_VOLUMES];
DLT634_5101SLAVE_APPINFO  DLT634_5101Slave_App[_DLT634_5101SLAVE_VOLUMES];

/* PRIVATE FUNCTION PROTOTYPES -----------------------------------------------*/
/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_CKS
** 功能描述: 计算CKS
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: 
** 调用模块: 
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static uint8_t DLT634_5101_SLAVE_CKS(uint8_t pdrv ,uint8_t *pBuf)
{
    uint16_t sum = 0;
    uint16_t j =0;
    uint8_t *p = 0;
    uint8_t i = 0;

    if (*(pBuf) == _DLT634_5101SLAVE_STARTCODE10)
    {
        for (j = 0; j < (DLT634_5101Slave_Pad[pdrv].LinkAddrSize + 1); j++)
        {
            sum += *(pBuf + 1 + j);
        }
    }
    else if(*(pBuf) == _DLT634_5101SLAVE_STARTCODE68)
    {
        p = pBuf+4;
        i = *(pBuf+1);

        while (i--)
        {
            sum += (*p++);
        }
    }

    return (uint8_t)(sum&0xff);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_CheckFram68Valid
** 功能描述: 可变帧报文检查
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**         : DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_SLAVE_CKS  计算CKS
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static uint8_t DLT634_5101_SLAVE_CheckFram68Valid(uint8_t pdrv)
{
    uint8_t *pBuf = 0;
    
    pBuf = (DLT634_5101Slave_App[pdrv].RxdBuf + DLT634_5101Slave_App[pdrv].RxdHead);

	  // 报头校验
    if ((pBuf[0] != pBuf[3]) || (pBuf[1] != pBuf[2]))
    {
        return(0);
    }

	  // 公共地址校验
    if (DLT634_5101Slave_Pad[pdrv].LinkAddrSize == 1)
    {
        if ((pBuf[5] != DLT634_5101Slave_Pad[pdrv].SourceAddr) && (pBuf[5] != 0xff))
        {
            return(0);
        }
    }
    else
    {
        if (((pBuf[5]|(pBuf[6]<<8)) != DLT634_5101Slave_Pad[pdrv].SourceAddr) && ((pBuf[5]|(pBuf[6]<<8)) != 0xffff))
        {
            return (0);
        }
    }
    
    return (1);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_CheckFram10Valid
** 功能描述: 固定帧报文检查
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**         : DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_SLAVE_CKS  计算CKS
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static uint8_t DLT634_5101_SLAVE_CheckFram10Valid(uint8_t pdrv)
{
    uint8_t *pBuf = 0;
    uint16_t addr = 0;

    pBuf = &DLT634_5101Slave_App[pdrv].RxdBuf[DLT634_5101Slave_App[pdrv].RxdHead];

	  // 固定帧长数据的校验和检测
    if (pBuf[2+DLT634_5101Slave_Pad[pdrv].LinkAddrSize] != (DLT634_5101_SLAVE_CKS(pdrv, pBuf)&0xFF))	
    {
        return (0);
    }

	  // 固定帧长数据的结束帧检测
    if (pBuf[3+DLT634_5101Slave_Pad[pdrv].LinkAddrSize] != _DLT634_5101SLAVE_ENDCODE)
    {
        return (0);
    }

	  // 固定帧数据公共地址检测
    if (DLT634_5101Slave_Pad[pdrv].LinkAddrSize == 1)
    {
        addr = pBuf[2];
    }
    else
    {
        addr = pBuf[2] | ((pBuf[3]<<8));
    }
		
    if (addr != DLT634_5101Slave_Pad[pdrv].SourceAddr)
    {
        return (0);
    }
    
    return (1);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_StoreIN
** 功能描述: 发送缓冲区堆栈
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**         : DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: 
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
uint8_t DLT634_5101_SLAVE_StoreIN(uint8_t pdrv,DLT634_5101SLAVE_PASDU *buf)
{	
	DLT634_5101SLAVE_PASDU *temp;
	DLT634_5101SLAVE_PASDU tempbuf;
	
	if(buf->status.symbol.priority<_DLT634_5101SLAVE_M_FT_NA_P)
	{
		temp = DLT634_5101Slave_App[pdrv].StoreDATA1IN;
		if(++temp >= DLT634_5101Slave_App[pdrv].StoreDATA1Buf + _DLT634_5101SLAVE_STOREDATA1NUM)
		{
			temp = DLT634_5101Slave_App[pdrv].StoreDATA1Buf;
		}
		
		if(temp == DLT634_5101Slave_App[pdrv].StoreDATA1OUT)
		{
			return(FALSE);
		}
	
		temp = DLT634_5101Slave_App[pdrv].StoreDATA1OUT;
		while(temp != DLT634_5101Slave_App[pdrv].StoreDATA1IN)
		{
			if(((temp->status.symbol.priority > buf->status.symbol.priority)||(temp->status.symbol.priority == 0))&&(temp != DLT634_5101Slave_App[pdrv].StoreDATA1OUT))
			{
				memcpy(&tempbuf,temp,sizeof(DLT634_5101SLAVE_PASDU));
				memcpy(temp,buf,sizeof(DLT634_5101SLAVE_PASDU));
				memcpy(buf,&tempbuf,sizeof(DLT634_5101SLAVE_PASDU));
			}
			if(++temp >= DLT634_5101Slave_App[pdrv].StoreDATA1Buf + _DLT634_5101SLAVE_STOREDATA1NUM)
			{
				temp = DLT634_5101Slave_App[pdrv].StoreDATA1Buf;
			}
		}
		
		memcpy(temp,buf,sizeof(DLT634_5101SLAVE_PASDU));	
		if(++DLT634_5101Slave_App[pdrv].StoreDATA1IN >= DLT634_5101Slave_App[pdrv].StoreDATA1Buf + _DLT634_5101SLAVE_STOREDATA1NUM)
		{
			DLT634_5101Slave_App[pdrv].StoreDATA1IN = DLT634_5101Slave_App[pdrv].StoreDATA1Buf;
		}
	}
	else
	{
		temp = DLT634_5101Slave_App[pdrv].StoreDATA2IN;
		if(++temp >= DLT634_5101Slave_App[pdrv].StoreDATA2Buf + _DLT634_5101SLAVE_STOREDATA2NUM)
		{
			temp = DLT634_5101Slave_App[pdrv].StoreDATA2Buf;
		}
		
		if(temp == DLT634_5101Slave_App[pdrv].StoreDATA2OUT)
		{
			return(FALSE);
		}
		
		temp = DLT634_5101Slave_App[pdrv].StoreDATA2OUT;
		while(temp != DLT634_5101Slave_App[pdrv].StoreDATA2IN)
		{
			if(((temp->status.symbol.priority > buf->status.symbol.priority)||(temp->status.symbol.priority == 0))&&(temp != DLT634_5101Slave_App[pdrv].StoreDATA2OUT))
			{
				memcpy(&tempbuf,temp,sizeof(DLT634_5101SLAVE_PASDU));
				memcpy(temp,buf,sizeof(DLT634_5101SLAVE_PASDU));
				memcpy(buf,&tempbuf,sizeof(DLT634_5101SLAVE_PASDU));
			}
			if(++temp >= DLT634_5101Slave_App[pdrv].StoreDATA2Buf + _DLT634_5101SLAVE_STOREDATA2NUM)
			{
				temp = DLT634_5101Slave_App[pdrv].StoreDATA2Buf;
			}
		}
		
		memcpy(temp,buf,sizeof(DLT634_5101SLAVE_PASDU));
		if(++DLT634_5101Slave_App[pdrv].StoreDATA2IN >= DLT634_5101Slave_App[pdrv].StoreDATA2Buf + _DLT634_5101SLAVE_STOREDATA2NUM)
		{
			DLT634_5101Slave_App[pdrv].StoreDATA2IN = DLT634_5101Slave_App[pdrv].StoreDATA2Buf;
		}
	}
	return(TRUE);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_AppProcess
** 功能描述: 应用处理函数
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**         : DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_SLAVE_C_SC  向其他设备发送遥控
**         : DLT634_5101_SLAVE_C_CS  向其他设备发送对时
**         : DLT634_5101_SLAVE_StoreIN  发送缓冲区堆栈 
**         : DLT634_5101_SLAVE_C_SR  向其他设备发送定值设置
**         : DLT634_5101_SLAVE_F_FR  向其他设备发送文件传输
**         : DLT634_5101_SLAVE_F_SR  向其他设备发送软件升级
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
void DLT634_5101_SLAVE_AppProcess(uint8_t pdrv)
{		
	//整理成02版报文，便于控制和传输
	memset((uint8_t *)&DLT634_5101Slave_App[pdrv].RX_Temp,0,sizeof(DLT634_5101SLAVE_PASDU));
	DLT634_5101Slave_App[pdrv].RX_Temp.status.Length = DLT634_5101Slave_App[pdrv].RxdBuf[1] -1 -DLT634_5101Slave_Pad[pdrv].LinkAddrSize;
	memcpy((uint8_t *)&DLT634_5101Slave_App[pdrv].RX_Temp.Head.TypeID,&DLT634_5101Slave_App[pdrv].RxdBuf[5+DLT634_5101Slave_Pad[pdrv].LinkAddrSize],DLT634_5101Slave_App[pdrv].RX_Temp.status.Length);
	if(DLT634_5101Slave_Pad[pdrv].ASDUCotSize == 1)
	{
		DLT634_5101Slave_App[pdrv].RX_Temp.Head.COT_H = 0;
		memcpy((uint8_t *)&DLT634_5101Slave_App[pdrv].RX_Temp.Head.PubAddr_L,&DLT634_5101Slave_App[pdrv].RxdBuf[5+DLT634_5101Slave_Pad[pdrv].LinkAddrSize+2+DLT634_5101Slave_Pad[pdrv].ASDUCotSize]
		,DLT634_5101Slave_App[pdrv].RX_Temp.status.Length-2-DLT634_5101Slave_Pad[pdrv].ASDUCotSize);	
		DLT634_5101Slave_App[pdrv].RX_Temp.status.Length = DLT634_5101Slave_App[pdrv].RX_Temp.status.Length - DLT634_5101Slave_Pad[pdrv].ASDUCotSize + 2;
	}
	if(DLT634_5101Slave_Pad[pdrv].ASDUAddrSize == 1)
	{
		DLT634_5101Slave_App[pdrv].RX_Temp.Head.PubAddr_H = 0;
		memcpy((uint8_t *)&DLT634_5101Slave_App[pdrv].RX_Temp.Data.buff[0],&DLT634_5101Slave_App[pdrv].RxdBuf[5+DLT634_5101Slave_Pad[pdrv].LinkAddrSize+2+DLT634_5101Slave_Pad[pdrv].ASDUCotSize+DLT634_5101Slave_Pad[pdrv].ASDUAddrSize]
		,DLT634_5101Slave_App[pdrv].RX_Temp.status.Length-2-DLT634_5101Slave_Pad[pdrv].ASDUCotSize-DLT634_5101Slave_Pad[pdrv].ASDUAddrSize);	
		DLT634_5101Slave_App[pdrv].RX_Temp.status.Length = DLT634_5101Slave_App[pdrv].RX_Temp.status.Length - DLT634_5101Slave_Pad[pdrv].ASDUAddrSize + 2;		
	}
	DLT634_5101Slave_App[pdrv].RX_Temp.status.Length += sizeof(DLT634_5101Slave_App[pdrv].RX_Temp.status);
	
	
	switch (DLT634_5101Slave_App[pdrv].RX_Temp.Head.TypeID)
	{
        //控制方向过程信息
        case _DLT634_5101SLAVE_C_SC_NA_1: // 单点遥控命令
        case _DLT634_5101SLAVE_C_SC_NB_1: // 双点遥控命令
            DLT634_5101_SLAVE_C_SC(pdrv,(uint8_t *)&DLT634_5101Slave_App[pdrv].RX_Temp);
                break;

        //控制方向命令信息
        case _DLT634_5101SLAVE_C_IC_NA_1: // 总召唤或分组召唤
            DLT634_5101Slave_App[pdrv].Data1Flag |= _DLT634_5101SLAVE_CALLALLDATA;
            DLT634_5101Slave_App[pdrv].AllDataFlag = 0;
            DLT634_5101_SLAVE_C_IC(pdrv,(uint8_t *)&DLT634_5101Slave_App[pdrv].RX_Temp);
                break;

        case _DLT634_5101SLAVE_C_CI_NA_1: // 电度总召唤或分组召唤
                break;

        case _DLT634_5101SLAVE_C_CS_NA_1: // 对时命令
            DLT634_5101_SLAVE_C_CS(pdrv,(uint8_t *)&DLT634_5101Slave_App[pdrv].RX_Temp);
                break;

        case _DLT634_5101SLAVE_C_TS_NA_1: // 测试命令
            DLT634_5101Slave_App[pdrv].RX_Temp.status.symbol.priority = _DLT634_5101SLAVE_C_TS_NA_P;
            DLT634_5101Slave_App[pdrv].RX_Temp.Head.COT_L = _DLT634_5101SLAVE_COT_ACTCON;
            DLT634_5101_SLAVE_StoreIN(pdrv,&DLT634_5101Slave_App[pdrv].RX_Temp);
                break;

        case _DLT634_5101SLAVE_C_RP_NA_1: // 复位进程命令
            DLT634_5101Slave_App[pdrv].Data1Flag |= _DLT634_5101SLAVE_HAVERESET;
                break;
        
        case _DLT634_5101SLAVE_C_SR_NA_1: // 切换定值区
        case _DLT634_5101SLAVE_C_RR_NA_1: // 读定值区号
        case _DLT634_5101SLAVE_C_RS_NA_1: // 读参数和定值命令
        case _DLT634_5101SLAVE_C_WS_NA_1: // 写参数和定值命令			
            DLT634_5101_SLAVE_C_SR(pdrv,(uint8_t *)&DLT634_5101Slave_App[pdrv].RX_Temp);
                break;

        case _DLT634_5101SLAVE_F_FR_NA_1: // 文件传输
            DLT634_5101_SLAVE_F_FR(pdrv,(uint8_t *)&DLT634_5101Slave_App[pdrv].RX_Temp);
                break;

        case _DLT634_5101SLAVE_F_SR_NA_1: // 软件升级
            DLT634_5101_SLAVE_F_SR(pdrv,(uint8_t *)&DLT634_5101Slave_App[pdrv].RX_Temp);
                break;			

        default: // 类型标识有错误或不支持
                break;
	}
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_WriteDataToMISI
** 功能描述: 发送函数
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**         : DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_SLAVE_WriteData  向底层驱动发送数据
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static uint8_t DLT634_5101_SLAVE_WriteDataToMISI(uint8_t pdrv)
{
    uint16_t sendlen = 0;
   
    sendlen = DLT634_5101_SLAVE_WriteData(pdrv ,DLT634_5101Slave_App[pdrv].TxdBuf + DLT634_5101Slave_App[pdrv].TxdHead, DLT634_5101Slave_App[pdrv].TxdTail - DLT634_5101Slave_App[pdrv].TxdHead);
    
    DLT634_5101Slave_App[pdrv].TxdHead += sendlen;
    if (DLT634_5101Slave_App[pdrv].TxdHead >= DLT634_5101Slave_App[pdrv].TxdTail) // 该次任务数据已经发完
    {
        DLT634_5101Slave_App[pdrv].TxdHead = 0;
        DLT634_5101Slave_App[pdrv].TxdTail = 0;
        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_DecodeFrame68
** 功能描述: 固定帧数据解析
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**         : DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_SLAVE_AppProcess  应用处理函数
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_SLAVE_DecodeFrame68(uint8_t pdrv)
{
    uint8_t control;
    
    control = DLT634_5101Slave_App[pdrv].RxdBuf[4];

    if (control & _DLT634_5101SLAVE_PRM) // 子站作为从动站接收主站链路报文。
    {
        if ((!(control&_DLT634_5101SLAVE_FCV)) || ((control&_DLT634_5101SLAVE_FCB) != ((DLT634_5101Slave_App[pdrv].RlaConCode) & 0x20)) || (!(DLT634_5101Slave_App[pdrv].LinkFlag & _DLT634_5101SLAVE_FIRST_RlaConCode)))
        {
            if(DLT634_5101Slave_App[pdrv].LinkFlag & _DLT634_5101SLAVE_INITEND)
            {
                if (control & _DLT634_5101SLAVE_FCV) // FCV有效而且FCB变位
                {
                    DLT634_5101Slave_App[pdrv].RlaConCode = DLT634_5101Slave_App[pdrv].RxdBuf[4]; // 保存最新的功能码，这里只用到FCB
                    DLT634_5101Slave_App[pdrv].FCBNoTurnNum = _DLT634_5101SLAVE_NUMOF_MAXRETRY; // 设置重发次数，指下次收到主站报文FCB未翻转时重发缓冲区内的报文。
                    DLT634_5101Slave_App[pdrv].LinkFlag |= _DLT634_5101SLAVE_FIRST_RlaConCode;
                }
                DLT634_5101Slave_App[pdrv].LinkFlag |= _DLT634_5101SLAVE_RECONFIRM;
                DLT634_5101_SLAVE_AppProcess(pdrv);
            }
        }
        else  // FCB 未翻转
        {
            if(DLT634_5101Slave_Pad[pdrv].BalanMode)
            {
                DLT634_5101Slave_App[pdrv].LinkFlag |= _DLT634_5101SLAVE_RECONFIRM;
            }
            else
            {
                if (DLT634_5101Slave_App[pdrv].FCBNoTurnNum)
                {
                    DLT634_5101Slave_App[pdrv].FCBNoTurnNum--;
                    memcpy(DLT634_5101Slave_App[pdrv].TxdBuf + DLT634_5101Slave_App[pdrv].TxdTail, DLT634_5101Slave_App[pdrv].TxdBuf_Pri, DLT634_5101Slave_App[pdrv].TxdTail_Pri);
                    DLT634_5101Slave_App[pdrv].TxdTail += DLT634_5101Slave_App[pdrv].TxdTail_Pri;
                    DLT634_5101_SLAVE_WriteDataToMISI(pdrv);
                }
            }
            return;
        }
    }
    else  // Prm=0；子站作为启动站接收主站链路报文
    {
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_StatusReset
** 功能描述: 状态复位
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
** 调用模块: 
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_SLAVE_StatusReset(uint8_t pdrv)
{
    DLT634_5101Slave_App[pdrv].LinkFlag = 0;
    DLT634_5101Slave_App[pdrv].Data1Flag = 0;
    DLT634_5101Slave_App[pdrv].Data2Flag = 0;
    
    DLT634_5101Slave_App[pdrv].StoreDATA1IN = DLT634_5101Slave_App[pdrv].StoreDATA1Buf;
    DLT634_5101Slave_App[pdrv].StoreDATA1OUT = DLT634_5101Slave_App[pdrv].StoreDATA1Buf;
    memset(DLT634_5101Slave_App[pdrv].StoreDATA1Buf,0,sizeof(DLT634_5101Slave_App[pdrv].StoreDATA1Buf));
    DLT634_5101Slave_App[pdrv].StoreDATA2IN = DLT634_5101Slave_App[pdrv].StoreDATA2Buf;
    DLT634_5101Slave_App[pdrv].StoreDATA2OUT = DLT634_5101Slave_App[pdrv].StoreDATA2Buf;
    memset(DLT634_5101Slave_App[pdrv].StoreDATA2Buf,0,sizeof(DLT634_5101Slave_App[pdrv].StoreDATA2Buf));
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_DecodeFrame10
** 功能描述: 解析固定桢报文
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**           DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_SLAVE_StatusReset  状态复位
**         : DLT634_5101_SLAVE_WriteDataToMISI  发送数据
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_SLAVE_DecodeFrame10(uint8_t pdrv)
{
    uint8_t stop = 0;
    uint8_t control = 0;

    control = DLT634_5101Slave_App[pdrv].RxdBuf[1];
    if (control & _DLT634_5101SLAVE_PRM) // 子站作为从动站接收主站的命令
    {
        if ((!(control&_DLT634_5101SLAVE_FCV)) || ((control&_DLT634_5101SLAVE_FCB) != ((DLT634_5101Slave_App[pdrv].RlaConCode) & 0x20)) || (!(DLT634_5101Slave_App[pdrv].LinkFlag & _DLT634_5101SLAVE_FIRST_RlaConCode)))
        {
            if (control & _DLT634_5101SLAVE_FCV) // FCV有效，FCB翻转
            {
                DLT634_5101Slave_App[pdrv].RlaConCode = DLT634_5101Slave_App[pdrv].RxdBuf[1];
                DLT634_5101Slave_App[pdrv].FCBNoTurnNum = _DLT634_5101SLAVE_NUMOF_MAXRETRY;
								DLT634_5101Slave_App[pdrv].LinkFlag |= _DLT634_5101SLAVE_FIRST_RlaConCode;
            }
            switch (control & _DLT634_5101SLAVE_FUNCODE)
            {
                case _DLT634_5101SLAVE_M_FUN2: // 心跳测试
                    DLT634_5101Slave_App[pdrv].LinkFlag |= _DLT634_5101SLAVE_RECONFIRM;
                    break;
										
                case _DLT634_5101SLAVE_M_FUN9: // 召唤链路状态
					DLT634_5101Slave_App[pdrv].LinkFlag |= _DLT634_5101SLAVE_REQSTATUS;
								    /* 可以避免答非所问的过程，尽快建立链路 */ 
                    while (((DLT634_5101Slave_App[pdrv].RxdTail - DLT634_5101Slave_App[pdrv].RxdHead) >= DLT634_5101Slave_Pad[pdrv].FixFrmLength) && (stop == 0)) // 收到召唤链路状态命令时，清掉后续相同命令。
                    {
                        if (memcmp(DLT634_5101Slave_App[pdrv].RxdBuf, DLT634_5101Slave_App[pdrv].RxdBuf + DLT634_5101Slave_App[pdrv].RxdHead, DLT634_5101Slave_Pad[pdrv].FixFrmLength) == 0)
                        {
                            DLT634_5101Slave_App[pdrv].RxdHead += DLT634_5101Slave_Pad[pdrv].FixFrmLength;
                        }
                        else
                        {
                            stop = 1;
                        }
                    }
                    break;

                case _DLT634_5101SLAVE_M_FUN0: // 复位链路					
                    DLT634_5101_SLAVE_StatusReset(pdrv);
            
                    DLT634_5101Slave_App[pdrv].LinkFlag |= _DLT634_5101SLAVE_INITEND;//初始化结束标志
                    if(DLT634_5101Slave_Pad[pdrv].BalanMode)
                    {
                        DLT634_5101Slave_App[pdrv].LinkFlag |= _DLT634_5101SLAVE_RECONFIRM;
                        DLT634_5101Slave_App[pdrv].LinkFlag |= _DLT634_5101SLAVE_ASKSTATUS;
                    }
                    else
                    {
                        DLT634_5101Slave_App[pdrv].LinkFlag |= _DLT634_5101SLAVE_RECONFIRM;
                        DLT634_5101Slave_App[pdrv].Data1Flag |= _DLT634_5101SLAVE_HAVEINITEND;
                    }
                    break;

                case _DLT634_5101SLAVE_M_FUN10: // 功能码-10，召唤用户一级数据
                    // 应用层调用
                    if (!(DLT634_5101Slave_App[pdrv].LinkFlag&_DLT634_5101SLAVE_INITEND))
                    {
                        return;
                    }  
                    DLT634_5101Slave_App[pdrv].LinkFlag |= _DLT634_5101SLAVE_REDATA1;
                    break;

                case _DLT634_5101SLAVE_M_FUN11: // 功能码-11，召唤用户二级数据
                    // 应用层调用
                    if (!(DLT634_5101Slave_App[pdrv].LinkFlag&_DLT634_5101SLAVE_INITEND))
                    {
                        return;
                    }  
                    DLT634_5101Slave_App[pdrv].LinkFlag |= _DLT634_5101SLAVE_REDATA2;
                    break;

                default:
                    break;
            }
            return;
        }
        else // FCB未翻转
        {
            if (DLT634_5101Slave_App[pdrv].FCBNoTurnNum)
            {
                DLT634_5101Slave_App[pdrv].FCBNoTurnNum--;
                memcpy(DLT634_5101Slave_App[pdrv].TxdBuf + DLT634_5101Slave_App[pdrv].TxdTail, DLT634_5101Slave_App[pdrv].TxdBuf_Pri, DLT634_5101Slave_App[pdrv].TxdTail_Pri);
                DLT634_5101Slave_App[pdrv].TxdTail += DLT634_5101Slave_App[pdrv].TxdTail_Pri;
                DLT634_5101_SLAVE_WriteDataToMISI(pdrv);
            }
        }
    }
    else // Prm=0 平衡模式子站作为启动站接收到主站的命令。
    {
        switch (control & _DLT634_5101SLAVE_FUNCODE)
        {
            case _DLT634_5101SLAVE_S_FUN0:	// 确认
                DLT634_5101Slave_App[pdrv].TimeOutTick_Pri = 0; // 链路有数据就可以不重发
                DLT634_5101Slave_App[pdrv].LinkFlag |= _DLT634_5101SLAVE_SENDABLE;
                break;

            case _DLT634_5101SLAVE_S_FUN11: // 应答链路
                DLT634_5101_SLAVE_StatusReset(pdrv);
        
                DLT634_5101Slave_App[pdrv].LinkFlag |= _DLT634_5101SLAVE_ASKRELINK;
                DLT634_5101Slave_App[pdrv].Data1Flag |= _DLT634_5101SLAVE_HAVEINITEND;
        
                DLT634_5101Slave_App[pdrv].LinkFlag |= _DLT634_5101SLAVE_INITEND;//初始化结束标志
                break;

            default:
                break;
        }
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_SearchValidFrame
** 功能描述: 数据处理函数
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**           DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_SLAVE_CheckFram68Valid  检查可变帧报文
**         : DLT634_5101_SLAVE_CheckFram10Valid  检查固定帧报文
**         : DLT634_5101_SLAVE_DecodeFrame68  解析可变桢报文
**         : DLT634_5101_SLAVE_DecodeFrame10  解析固定桢报文
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
void DLT634_5101_SLAVE_SearchValidFrame(uint8_t pdrv)
{
    uint8_t stop = 0;
    uint8_t length = 0;
    
    while ((DLT634_5101Slave_App[pdrv].RxdHead < DLT634_5101Slave_App[pdrv].RxdTail) && (!stop))
    {
        if (DLT634_5101Slave_App[pdrv].RxdStatus == RXDSTART)
        {
            while ((DLT634_5101Slave_App[pdrv].RxdBuf[DLT634_5101Slave_App[pdrv].RxdHead] != _DLT634_5101SLAVE_STARTCODE10)
                    && (DLT634_5101Slave_App[pdrv].RxdBuf[DLT634_5101Slave_App[pdrv].RxdHead] != _DLT634_5101SLAVE_STARTCODE68)
                    && (DLT634_5101Slave_App[pdrv].RxdHead < DLT634_5101Slave_App[pdrv].RxdTail))
            {
                DLT634_5101Slave_App[pdrv].RxdHead++;
            }

            if (DLT634_5101Slave_App[pdrv].RxdHead < DLT634_5101Slave_App[pdrv].RxdTail) // 找到启动字符，并将报文与缓冲区对齐。
            {
                DLT634_5101Slave_App[pdrv].RxdStatus = RXDHEAD;
                if (DLT634_5101Slave_App[pdrv].RxdHead != 0)
                {
                    memcpy(DLT634_5101Slave_App[pdrv].RxdBuf,DLT634_5101Slave_App[pdrv].RxdBuf+DLT634_5101Slave_App[pdrv].RxdHead,DLT634_5101Slave_App[pdrv].RxdTail-DLT634_5101Slave_App[pdrv].RxdHead);
                    DLT634_5101Slave_App[pdrv].RxdTail -= DLT634_5101Slave_App[pdrv].RxdHead;
                    DLT634_5101Slave_App[pdrv].RxdHead = 0;
                }
            }
        }
        
        DLT634_5101Slave_App[pdrv].RxdLength = DLT634_5101Slave_App[pdrv].RxdTail - DLT634_5101Slave_App[pdrv].RxdHead;
        if (DLT634_5101Slave_App[pdrv].RxdStatus == RXDHEAD) // 报文够一帧则处理
        {
            switch (DLT634_5101Slave_App[pdrv].RxdBuf[DLT634_5101Slave_App[pdrv].RxdHead])
            {
                case _DLT634_5101SLAVE_STARTCODE68:
                    if (DLT634_5101Slave_App[pdrv].RxdLength >= 5+DLT634_5101Slave_Pad[pdrv].LinkAddrSize) // 启动字符到链路地址共6字节。
                    {
                        if (!DLT634_5101_SLAVE_CheckFram68Valid(pdrv)) // 判断是否报文头
                        {
                            DLT634_5101Slave_App[pdrv].RxdHead++;
                            DLT634_5101Slave_App[pdrv].RxdStatus = RXDSTART;
                        }
                        else
                        {
                            DLT634_5101Slave_App[pdrv].RxdStatus = RXDCONTINUE;
                        }
                    }
                    else
                    {
                        stop = 1;
                    }
                    break;
                    
                case _DLT634_5101SLAVE_STARTCODE10:
                    if (DLT634_5101Slave_App[pdrv].RxdLength >= 4 + DLT634_5101Slave_Pad[pdrv].LinkAddrSize)
                    {
                        if (!DLT634_5101_SLAVE_CheckFram10Valid(pdrv))
                        {
                            DLT634_5101Slave_App[pdrv].RxdHead++;
                            DLT634_5101Slave_App[pdrv].RxdStatus = RXDSTART;
                        }
                        else
                        {
                            DLT634_5101Slave_App[pdrv].RxdStatus = RXDCONTINUE;
                        }
                    }
                    else
                    {
                        stop = 1;
                    }
                    break;
            }
        }
        if (DLT634_5101Slave_App[pdrv].RxdStatus == RXDCONTINUE)
        {
            switch (DLT634_5101Slave_App[pdrv].RxdBuf[DLT634_5101Slave_App[pdrv].RxdHead])
            {
            case _DLT634_5101SLAVE_STARTCODE68:
                length = DLT634_5101Slave_App[pdrv].RxdBuf[DLT634_5101Slave_App[pdrv].RxdHead+1];
                if (DLT634_5101Slave_App[pdrv].RxdLength >= length+6) // 报文收全，进行处理
                {
                    if ((DLT634_5101Slave_App[pdrv].RxdBuf[DLT634_5101Slave_App[pdrv].RxdHead+length+4] == (DLT634_5101_SLAVE_CKS(pdrv, DLT634_5101Slave_App[pdrv].RxdBuf+DLT634_5101Slave_App[pdrv].RxdHead)&0xFF))//校验正确
                            && (DLT634_5101Slave_App[pdrv].RxdBuf[DLT634_5101Slave_App[pdrv].RxdHead+length+4+1] == _DLT634_5101SLAVE_ENDCODE)) // 结束码正确
 					          {
                        if ( DLT634_5101Slave_App[pdrv].RxdHead > 0 )
                        {
                            memcpy(DLT634_5101Slave_App[pdrv].RxdBuf,DLT634_5101Slave_App[pdrv].RxdBuf+DLT634_5101Slave_App[pdrv].RxdHead,DLT634_5101Slave_App[pdrv].RxdTail-DLT634_5101Slave_App[pdrv].RxdHead);//报文与缓冲区对齐
                            DLT634_5101Slave_App[pdrv].RxdTail -= DLT634_5101Slave_App[pdrv].RxdHead;
                            DLT634_5101Slave_App[pdrv].RxdHead = 0;
                        }
												/* 头指针后移到报文后 */
                        DLT634_5101Slave_App[pdrv].RxdHead += (DLT634_5101Slave_App[pdrv].RxdBuf[1]+6);
                        DLT634_5101Slave_App[pdrv].RxdStatus = RXDSTART;

                        DLT634_5101_SLAVE_DecodeFrame68(pdrv);
                    }
                    else
                    {
                        DLT634_5101Slave_App[pdrv].RxdHead += 6;
                        DLT634_5101Slave_App[pdrv].RxdStatus = RXDSTART;
                    }
                }
                else // 报文未收全，不处理，继续等待数据。
                {
                    stop = 1;
                }
                break;
                
            case _DLT634_5101SLAVE_STARTCODE10:
                if (DLT634_5101Slave_App[pdrv].RxdHead > 0)
                {
                    memcpy(DLT634_5101Slave_App[pdrv].RxdBuf,DLT634_5101Slave_App[pdrv].RxdBuf+DLT634_5101Slave_App[pdrv].RxdHead,DLT634_5101Slave_App[pdrv].RxdTail-DLT634_5101Slave_App[pdrv].RxdHead);
                    DLT634_5101Slave_App[pdrv].RxdTail -= DLT634_5101Slave_App[pdrv].RxdHead;
                    DLT634_5101Slave_App[pdrv].RxdHead = 0;
                }
                DLT634_5101Slave_App[pdrv].RxdHead += 4 + DLT634_5101Slave_Pad[pdrv].LinkAddrSize;
                DLT634_5101Slave_App[pdrv].RxdStatus = RXDSTART;
			
                DLT634_5101_SLAVE_DecodeFrame10(pdrv);
                break;
            }
        }
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_ReadMISIData
** 功能描述: 接受处理函数
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**           DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_SLAVE_ReadData  读取数据函数
**         : DLT634_5101_SLAVE_SearchValidFrame  数据处理函数
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_SLAVE_ReadMISIData(uint8_t pdrv)
{
    uint16_t count = 0;
    
    if (DLT634_5101Slave_App[pdrv].RxdHead < DLT634_5101Slave_App[pdrv].RxdTail) // 接收缓冲区中有尚未处理的数据
    {
        if (DLT634_5101Slave_App[pdrv].RxdHead != 0)
        {
            memcpy(DLT634_5101Slave_App[pdrv].RxdBuf, DLT634_5101Slave_App[pdrv].RxdBuf+DLT634_5101Slave_App[pdrv].RxdHead, DLT634_5101Slave_App[pdrv].RxdTail-DLT634_5101Slave_App[pdrv].RxdHead);//将未处理的数据移到缓冲区头
            DLT634_5101Slave_App[pdrv].RxdTail -= DLT634_5101Slave_App[pdrv].RxdHead;
            DLT634_5101Slave_App[pdrv].RxdHead = 0;
        }
    }
    else
    {
        DLT634_5101Slave_App[pdrv].RxdHead = 0;
		    DLT634_5101Slave_App[pdrv].RxdTail = 0;
    }
    
    count = DLT634_5101_SLAVE_ReadData(pdrv,(uint8_t *)&DLT634_5101Slave_App[pdrv].RxdBuf[DLT634_5101Slave_App[pdrv].RxdTail], _DLT634_5101SLAVE_LPDUSIZE);
    if (count > 0)
    {
        DLT634_5101Slave_App[pdrv].RxdTail += count;
        DLT634_5101_SLAVE_SearchValidFrame(pdrv);
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_SlaveFrame10Packet
** 功能描述: 固定帧从动站打包
** 输　  入: pdrv：设备序号
**         : Function  功能码
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**           DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_SLAVE_CKS  计算CKS
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_SLAVE_SlaveFrame10Packet(uint8_t pdrv, uint8_t Function)
{
    uint8_t *pBuf;
    uint8_t i = 0;
									
    pBuf = DLT634_5101Slave_App[pdrv].TxdBuf + DLT634_5101Slave_App[pdrv].TxdTail;
    pBuf[0] = _DLT634_5101SLAVE_STARTCODE10;
    pBuf[1] = Function&0x0f;
    if(DLT634_5101Slave_Pad[pdrv].BalanMode)
    {
        pBuf[1] |= DLT634_5101Slave_Pad[pdrv].IEC_DIR; // 子站向主站传输，平衡模式为1，非平衡模式为0
    }
    else
    {
        if(DLT634_5101Slave_App[pdrv].Data1Flag)
        {pBuf[1] |= _DLT634_5101SLAVE_ACD;}
    }

    for (i=0; i<DLT634_5101Slave_Pad[pdrv].LinkAddrSize; i++)
    {
        pBuf[2+i] = (DLT634_5101Slave_Pad[pdrv].SourceAddr>>(8*i)) & 0xff;
    }

    pBuf[2+DLT634_5101Slave_Pad[pdrv].LinkAddrSize] = DLT634_5101_SLAVE_CKS(pdrv, pBuf);
    pBuf[3+DLT634_5101Slave_Pad[pdrv].LinkAddrSize] = _DLT634_5101SLAVE_ENDCODE;
    DLT634_5101Slave_App[pdrv].TxdTail += DLT634_5101Slave_Pad[pdrv].FixFrmLength;//移动发送尾指针
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_MasterFrame10Packet
** 功能描述: 固定帧启动站打包
** 输　  入: pdrv：设备序号
**         : Function  功能码
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**           DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_SLAVE_CKS  计算CKS
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_SLAVE_MasterFrame10Packet(uint8_t pdrv, uint8_t Function)
{
    uint8_t *pBuf;
    uint8_t i = 0;

    pBuf = DLT634_5101Slave_App[pdrv].TxdBuf + DLT634_5101Slave_App[pdrv].TxdTail;
    pBuf[0] = _DLT634_5101SLAVE_STARTCODE10;
    pBuf[1] = Function&0x0f;
    pBuf[1] |= _DLT634_5101SLAVE_PRM;
    pBuf[1] |= DLT634_5101Slave_Pad[pdrv].IEC_DIR; // 子站向主站传输，平衡模式为1，非平衡模式为0

    for (i=0; i<DLT634_5101Slave_Pad[pdrv].LinkAddrSize; i++)
    {
        pBuf[2+i] = (DLT634_5101Slave_Pad[pdrv].SourceAddr>>(8*i)) & 0xff;
    }

    pBuf[2+DLT634_5101Slave_Pad[pdrv].LinkAddrSize] = DLT634_5101_SLAVE_CKS(pdrv, pBuf);
    pBuf[3+DLT634_5101Slave_Pad[pdrv].LinkAddrSize] = _DLT634_5101SLAVE_ENDCODE;
    DLT634_5101Slave_App[pdrv].TxdTail += DLT634_5101Slave_Pad[pdrv].FixFrmLength;//移动发送尾指针

    memcpy(DLT634_5101Slave_App[pdrv].TxdBuf_Pri, pBuf, DLT634_5101Slave_Pad[pdrv].FixFrmLength); // 将发送数据保存到启动站重发数据区
    DLT634_5101Slave_App[pdrv].TxdTail_Pri = DLT634_5101Slave_Pad[pdrv].FixFrmLength;
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_Link10Process
** 功能描述: 固定帧发送处理
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**           DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_SLAVE_WriteDataToMISI  发送函数
**           DLT634_5101_SLAVE_SlaveFrame10Packet  固定帧从动站打包
**           DLT634_5101_SLAVE_MasterFrame10Packet  固定帧启动站打包
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_SLAVE_Link10Process(uint8_t pdrv)
{ 
	if(DLT634_5101Slave_App[pdrv].LinkFlag&_DLT634_5101SLAVE_REQSTATUS)
	{
		DLT634_5101_SLAVE_SlaveFrame10Packet(pdrv, _DLT634_5101SLAVE_S_FUN11);
		DLT634_5101_SLAVE_WriteDataToMISI(pdrv);
		DLT634_5101Slave_App[pdrv].LinkFlag &= (~_DLT634_5101SLAVE_REQSTATUS);
		return;
	}
	
	if(DLT634_5101Slave_App[pdrv].LinkFlag&_DLT634_5101SLAVE_RECONFIRM)
	{
		DLT634_5101_SLAVE_SlaveFrame10Packet(pdrv, _DLT634_5101SLAVE_S_FUN0);
		DLT634_5101_SLAVE_WriteDataToMISI(pdrv);
		DLT634_5101Slave_App[pdrv].LinkFlag &= (~_DLT634_5101SLAVE_RECONFIRM);
		return;
	}
	
	if(DLT634_5101Slave_App[pdrv].LinkFlag&_DLT634_5101SLAVE_ASKSTATUS)
	{
		DLT634_5101_SLAVE_MasterFrame10Packet(pdrv, _DLT634_5101SLAVE_M_FUN9);
		DLT634_5101_SLAVE_WriteDataToMISI(pdrv);
		DLT634_5101Slave_App[pdrv].LinkFlag &= (~_DLT634_5101SLAVE_ASKSTATUS);
		DLT634_5101Slave_App[pdrv].TimeOutTick_AskSta = DLT634_5101Slave_Pad[pdrv].AskStaOutValue;
		return;
	}
	if(DLT634_5101Slave_App[pdrv].LinkFlag&_DLT634_5101SLAVE_ASKRELINK)
	{
		DLT634_5101_SLAVE_MasterFrame10Packet(pdrv, _DLT634_5101SLAVE_M_FUN0);
		DLT634_5101_SLAVE_WriteDataToMISI(pdrv);
		DLT634_5101Slave_App[pdrv].LinkFlag &= (~_DLT634_5101SLAVE_ASKRELINK);
		return;
	}	
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_RestReply
** 功能描述: 复位
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**           DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: 
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_SLAVE_RestReply(uint8_t pdrv)
{
    DLT634_5101Slave_App[pdrv].TX_Temp.status.Length = sizeof(DLT634_5101Slave_App[pdrv].TX_Temp.status) + sizeof(DLT634_5101Slave_App[pdrv].TX_Temp.Head) + sizeof(DLT634_5101Slave_App[pdrv].TX_Temp.Data.C_105);
    DLT634_5101Slave_App[pdrv].TX_Temp.Head.TypeID = _DLT634_5101SLAVE_C_RP_NA_1;
    DLT634_5101Slave_App[pdrv].TX_Temp.Head.VSQ = 1;
    DLT634_5101Slave_App[pdrv].TX_Temp.Head.COT_L = _DLT634_5101SLAVE_COT_ACTCON;
    DLT634_5101Slave_App[pdrv].TX_Temp.Head.PubAddr_H = (uint8_t)((DLT634_5101Slave_Pad[pdrv].ASDUAddr>>8)&0xff);
    DLT634_5101Slave_App[pdrv].TX_Temp.Head.PubAddr_L = (uint8_t)(DLT634_5101Slave_Pad[pdrv].ASDUAddr&0xff);
    DLT634_5101Slave_App[pdrv].TX_Temp.Data.C_105.QRP = 1;
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_InitEndReply
** 功能描述: 初始化结束
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**           DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: 
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_SLAVE_InitEndReply(uint8_t pdrv)
{
    DLT634_5101Slave_App[pdrv].TX_Temp.status.Length = sizeof(DLT634_5101Slave_App[pdrv].TX_Temp.status) + sizeof(DLT634_5101Slave_App[pdrv].TX_Temp.Head) + sizeof(DLT634_5101Slave_App[pdrv].TX_Temp.Data.C_70);
    DLT634_5101Slave_App[pdrv].TX_Temp.status.symbol.priority = _DLT634_5101SLAVE_M_EI_NA_P;
    DLT634_5101Slave_App[pdrv].TX_Temp.Head.TypeID = _DLT634_5101SLAVE_M_EI_NA_1;
    DLT634_5101Slave_App[pdrv].TX_Temp.Head.VSQ = 1;
    DLT634_5101Slave_App[pdrv].TX_Temp.Head.COT_L = _DLT634_5101SLAVE_COT_INIT;
    DLT634_5101Slave_App[pdrv].TX_Temp.Head.PubAddr_H = (uint8_t)((DLT634_5101Slave_Pad[pdrv].ASDUAddr>>8)&0xff);
    DLT634_5101Slave_App[pdrv].TX_Temp.Head.PubAddr_L = (uint8_t)(DLT634_5101Slave_Pad[pdrv].ASDUAddr&0xff);
    DLT634_5101Slave_App[pdrv].TX_Temp.Data.C_70.COI = 2;
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_AllDataConReply
** 功能描述: 总召确认
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**           DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: 
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_SLAVE_AllDataConReply(uint8_t pdrv)
{
    DLT634_5101Slave_App[pdrv].TX_Temp.status.Length = sizeof(DLT634_5101Slave_App[pdrv].TX_Temp.status) + sizeof(DLT634_5101Slave_App[pdrv].TX_Temp.Head) + sizeof(DLT634_5101Slave_App[pdrv].TX_Temp.Data.C_100);
    DLT634_5101Slave_App[pdrv].TX_Temp.status.symbol.priority = _DLT634_5101SLAVE_C_IC_NA_PF;
    DLT634_5101Slave_App[pdrv].TX_Temp.Head.TypeID = _DLT634_5101SLAVE_C_IC_NA_1;
    DLT634_5101Slave_App[pdrv].TX_Temp.Head.VSQ = 1;
    DLT634_5101Slave_App[pdrv].TX_Temp.Head.COT_L = _DLT634_5101SLAVE_COT_ACTCON;
    DLT634_5101Slave_App[pdrv].TX_Temp.Head.PubAddr_H = (uint8_t)((DLT634_5101Slave_Pad[pdrv].ASDUAddr>>8)&0xff);
    DLT634_5101Slave_App[pdrv].TX_Temp.Head.PubAddr_L = (uint8_t)(DLT634_5101Slave_Pad[pdrv].ASDUAddr&0xff);
    DLT634_5101Slave_App[pdrv].TX_Temp.Data.C_70.COI = 20;
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_AllDataEndReply
** 功能描述: 总召结束
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**           DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: 
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_SLAVE_AllDataEndReply(uint8_t pdrv)
{
    DLT634_5101Slave_App[pdrv].TX_Temp.status.Length = sizeof(DLT634_5101Slave_App[pdrv].TX_Temp.status) + sizeof(DLT634_5101Slave_App[pdrv].TX_Temp.Head) + sizeof(DLT634_5101Slave_App[pdrv].TX_Temp.Data.C_100);
    DLT634_5101Slave_App[pdrv].TX_Temp.status.symbol.priority = _DLT634_5101SLAVE_C_IC_NA_PF;
    DLT634_5101Slave_App[pdrv].TX_Temp.Head.TypeID = _DLT634_5101SLAVE_C_IC_NA_1;
    DLT634_5101Slave_App[pdrv].TX_Temp.Head.VSQ = 1;
    DLT634_5101Slave_App[pdrv].TX_Temp.Head.COT_L = _DLT634_5101SLAVE_COT_ACCTTERM;
    DLT634_5101Slave_App[pdrv].TX_Temp.Head.PubAddr_H = (uint8_t)((DLT634_5101Slave_Pad[pdrv].ASDUAddr>>8)&0xff);
    DLT634_5101Slave_App[pdrv].TX_Temp.Head.PubAddr_L = (uint8_t)(DLT634_5101Slave_Pad[pdrv].ASDUAddr&0xff);
    DLT634_5101Slave_App[pdrv].TX_Temp.Data.C_70.COI = 20;
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_ReadAllDataProcess
** 功能描述: 总召函数
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**           DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_SLAVE_AllDataConReply  总召确认
**           DLT634_5101_SLAVE_R_YXDATA  读遥信
**           DLT634_5101_SLAVE_R_YCDATA  读遥测
**           DLT634_5101_SLAVE_AllDataEndReply  总召结束
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_SLAVE_ReadAllDataProcess(uint8_t pdrv)
{
	static uint8_t group;
	static uint8_t yx_group;
	static uint8_t yc_group;
	switch(DLT634_5101Slave_App[pdrv].AllDataFlag)
	{
		case 0:
            DLT634_5101_SLAVE_AllDataConReply(pdrv);
            group = 0;
            yx_group = (DLT634_5101Slave_Pad[pdrv].YX_AllNum%DLT634_5101Slave_Pad[pdrv].YX_FrameNum) ? 
                    (DLT634_5101Slave_Pad[pdrv].YX_AllNum/DLT634_5101Slave_Pad[pdrv].YX_FrameNum + 1)  : (DLT634_5101Slave_Pad[pdrv].YX_AllNum/DLT634_5101Slave_Pad[pdrv].YX_FrameNum);
            yc_group = (DLT634_5101Slave_Pad[pdrv].YC_AllNum%DLT634_5101Slave_Pad[pdrv].YC_FrameNum) ? 
                    (DLT634_5101Slave_Pad[pdrv].YC_AllNum/DLT634_5101Slave_Pad[pdrv].YC_FrameNum + 1)  : (DLT634_5101Slave_Pad[pdrv].YC_AllNum/DLT634_5101Slave_Pad[pdrv].YC_FrameNum);
            DLT634_5101Slave_App[pdrv].AllDataFlag = 1;
			break;
		case 1:
            if(DLT634_5101Slave_Pad[pdrv].YX_AllNum/DLT634_5101Slave_Pad[pdrv].YX_FrameNum > group)
            {
                DLT634_5101_SLAVE_R_YXDATA(pdrv ,DLT634_5101Slave_Pad[pdrv].YX_FrameNum*group +  DLT634_5101Slave_Pad[pdrv].YX_FIRSTADDR,DLT634_5101Slave_Pad[pdrv].YX_FrameNum ,(uint8_t *)&DLT634_5101Slave_App[pdrv].TX_Temp);
            }
            else
            {
                DLT634_5101_SLAVE_R_YXDATA(pdrv ,DLT634_5101Slave_Pad[pdrv].YX_FrameNum*group +  DLT634_5101Slave_Pad[pdrv].YX_FIRSTADDR
                ,DLT634_5101Slave_Pad[pdrv].YX_AllNum - group*DLT634_5101Slave_Pad[pdrv].YX_FrameNum ,(uint8_t *)&DLT634_5101Slave_App[pdrv].TX_Temp);
            }
            if(++group >= yx_group)
            {
                DLT634_5101Slave_App[pdrv].AllDataFlag = 2;
                group = 0;
            }
			break;
		case 2:
            if(DLT634_5101Slave_Pad[pdrv].YC_AllNum/DLT634_5101Slave_Pad[pdrv].YC_FrameNum > group)
            {
                DLT634_5101_SLAVE_R_YCDATA(pdrv ,DLT634_5101Slave_Pad[pdrv].YC_FrameNum*group +  DLT634_5101Slave_Pad[pdrv].YC_FIRSTADDR,DLT634_5101Slave_Pad[pdrv].YC_FrameNum ,(uint8_t *)&DLT634_5101Slave_App[pdrv].TX_Temp);
            }
            else
            {
                DLT634_5101_SLAVE_R_YCDATA(pdrv ,DLT634_5101Slave_Pad[pdrv].YC_FrameNum*group +  DLT634_5101Slave_Pad[pdrv].YC_FIRSTADDR
                ,DLT634_5101Slave_Pad[pdrv].YC_AllNum - group*DLT634_5101Slave_Pad[pdrv].YC_FrameNum ,(uint8_t *)&DLT634_5101Slave_App[pdrv].TX_Temp);
            }
            if(++group >= yc_group)
            {
                DLT634_5101Slave_App[pdrv].AllDataFlag = 3;
                group = 0;
            }
			break;
		case 3:
            DLT634_5101_SLAVE_AllDataEndReply(pdrv);
            DLT634_5101Slave_App[pdrv].Data1Flag &= (~_DLT634_5101SLAVE_CALLALLDATA);
			break;
		default:
			break;
		
	}

}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_Data1Process
** 功能描述: 1级数据发送处理函数
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**           DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_SLAVE_WriteDataToMISI  数据发送函数
**           DLT634_5101_SLAVE_H_SOE  SOE判断函数
**           DLT634_5101_SLAVE_R_SOE  SOE读取函数
**           DLT634_5101_SLAVE_ReadAllDataProcess  总召函数
**           DLT634_5101_SLAVE_InitEndReply  初始化结束
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_SLAVE_Data1Process(uint8_t pdrv)
{ 
    if (DLT634_5101Slave_App[pdrv].Data1Flag & _DLT634_5101SLAVE_HAVERESET) // 复位进程
    {
        DLT634_5101_SLAVE_RestReply(pdrv);
        DLT634_5101Slave_App[pdrv].Data1Flag &= (~_DLT634_5101SLAVE_HAVERESET);
        DLT634_5101Slave_App[pdrv].LinkFlag = 0;
        return;
    }
		
    if ((DLT634_5101Slave_App[pdrv].Data1Flag & _DLT634_5101SLAVE_HAVEINITEND)&&
			((DLT634_5101Slave_App[pdrv].StoreDATA1IN->status.symbol.priority > _DLT634_5101SLAVE_M_EI_NA_P)||
			(DLT634_5101Slave_App[pdrv].StoreDATA1IN->status.symbol.priority == 0))) // 初始化结束回复过程
    {
        DLT634_5101_SLAVE_InitEndReply(pdrv);
        DLT634_5101Slave_App[pdrv].Data1Flag &= (~_DLT634_5101SLAVE_HAVEINITEND);
        return;
    }
		
    if(DLT634_5101Slave_App[pdrv].TxdTail_Special)//特殊数据重发
    {
        memcpy(DLT634_5101Slave_App[pdrv].TxdBuf + DLT634_5101Slave_App[pdrv].TxdTail, DLT634_5101Slave_App[pdrv].TxdBuf_Special, DLT634_5101Slave_App[pdrv].TxdTail_Special);
        DLT634_5101Slave_App[pdrv].TxdTail += DLT634_5101Slave_App[pdrv].TxdTail_Special;
        DLT634_5101Slave_App[pdrv].TxdTail_Special = 0;
        memcpy(DLT634_5101Slave_App[pdrv].TxdBuf_Pri, DLT634_5101Slave_App[pdrv].TxdBuf_Special, DLT634_5101Slave_App[pdrv].TxdTail_Special);
        DLT634_5101Slave_App[pdrv].TxdTail_Pri = DLT634_5101Slave_App[pdrv].TxdTail_Special;
        DLT634_5101_SLAVE_WriteDataToMISI(pdrv);
        DLT634_5101Slave_App[pdrv].TimeOutTick_Pri = DLT634_5101Slave_Pad[pdrv].TimeOutValue;
        DLT634_5101Slave_App[pdrv].RetryCount  = _DLT634_5101SLAVE_NUMOF_MAXRETRY;
        DLT634_5101Slave_App[pdrv].LinkFlag &= (~_DLT634_5101SLAVE_SENDABLE);
        return;
    }
    
    if ((DLT634_5101_SLAVE_H_SOE(pdrv))&&
        ((DLT634_5101Slave_App[pdrv].StoreDATA1IN->status.symbol.priority > _DLT634_5101SLAVE_M_SP_TB_P)||
        (DLT634_5101Slave_App[pdrv].StoreDATA1IN->status.symbol.priority == 0))) 
    {
        DLT634_5101_SLAVE_R_SOE(pdrv,(uint8_t *)&DLT634_5101Slave_App[pdrv].TX_Temp);
        DLT634_5101Slave_App[pdrv].Data1Flag &= (~_DLT634_5101SLAVE_HAVESOE);
        return;
    }

	  if (DLT634_5101Slave_App[pdrv].Data1Flag & _DLT634_5101SLAVE_CALLALLDATA) // 召唤全数据
    {
        DLT634_5101_SLAVE_ReadAllDataProcess(pdrv);
        return;
    }
		
    if(DLT634_5101Slave_App[pdrv].StoreDATA1OUT != DLT634_5101Slave_App[pdrv].StoreDATA1IN)
    {
        memcpy((uint8_t *)&DLT634_5101Slave_App[pdrv].TX_Temp, (uint8_t *)DLT634_5101Slave_App[pdrv].StoreDATA1OUT, DLT634_5101Slave_App[pdrv].StoreDATA1OUT->status.Length);
        memset((uint8_t *)DLT634_5101Slave_App[pdrv].StoreDATA1OUT,0,sizeof(DLT634_5101SLAVE_PASDU));
        if(++DLT634_5101Slave_App[pdrv].StoreDATA1OUT >= DLT634_5101Slave_App[pdrv].StoreDATA1Buf + _DLT634_5101SLAVE_STOREDATA1NUM)
        {
            DLT634_5101Slave_App[pdrv].StoreDATA1OUT = DLT634_5101Slave_App[pdrv].StoreDATA1Buf;
        }
        return;
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_Data2Process
** 功能描述: 2级数据发送处理函数
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**           DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_SLAVE_WriteDataToMISI  数据发送函数
**           DLT634_5101_SLAVE_H_NVA  遥测变化判断函数
**           DLT634_5101_SLAVE_R_NVA  遥测变化读取函数
**           DLT634_5101_SLAVE_H_FEvent  故障事件判断函数
**           DLT634_5101_SLAVE_R_FEvent  故障事件读取函数
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_SLAVE_Data2Process(uint8_t pdrv)
{
    if(DLT634_5101Slave_App[pdrv].TxdTail_Special)//特殊数据重发
    {
        memcpy(DLT634_5101Slave_App[pdrv].TxdBuf + DLT634_5101Slave_App[pdrv].TxdTail, DLT634_5101Slave_App[pdrv].TxdBuf_Special, DLT634_5101Slave_App[pdrv].TxdTail_Special);
        DLT634_5101Slave_App[pdrv].TxdTail += DLT634_5101Slave_App[pdrv].TxdTail_Special;
        memcpy(DLT634_5101Slave_App[pdrv].TxdBuf_Pri, DLT634_5101Slave_App[pdrv].TxdBuf_Special, DLT634_5101Slave_App[pdrv].TxdTail_Special);
        DLT634_5101Slave_App[pdrv].TxdTail_Pri = DLT634_5101Slave_App[pdrv].TxdTail_Special;
        DLT634_5101Slave_App[pdrv].TxdTail_Special = 0;
        DLT634_5101_SLAVE_WriteDataToMISI(pdrv);
        DLT634_5101Slave_App[pdrv].TimeOutTick_Pri = DLT634_5101Slave_Pad[pdrv].TimeOutValue;
        DLT634_5101Slave_App[pdrv].RetryCount  = _DLT634_5101SLAVE_NUMOF_MAXRETRY;
        DLT634_5101Slave_App[pdrv].LinkFlag &= (~_DLT634_5101SLAVE_SENDABLE);
        return;
    }
    
    if ((DLT634_5101_SLAVE_H_NVA(pdrv))&&
        ((DLT634_5101Slave_App[pdrv].StoreDATA2IN->status.symbol.priority > _DLT634_5101SLAVE_M_ME_NC_P)||
        (DLT634_5101Slave_App[pdrv].StoreDATA2IN->status.symbol.priority == 0))) 
    {
        DLT634_5101_SLAVE_R_NVA(pdrv,(uint8_t *)&DLT634_5101Slave_App[pdrv].TX_Temp);
        return;
    }
    
    if ((DLT634_5101_SLAVE_H_FEvent(pdrv))&&
        ((DLT634_5101Slave_App[pdrv].StoreDATA2IN->status.symbol.priority > _DLT634_5101SLAVE_M_FT_NA_P)||
        (DLT634_5101Slave_App[pdrv].StoreDATA2IN->status.symbol.priority == 0))) 
    {
        DLT634_5101_SLAVE_R_FEvent(pdrv,(uint8_t *)&DLT634_5101Slave_App[pdrv].TX_Temp);
        return;
    }
    
    if(DLT634_5101Slave_App[pdrv].StoreDATA2OUT != DLT634_5101Slave_App[pdrv].StoreDATA2IN)
    {
        memcpy((uint8_t *)&DLT634_5101Slave_App[pdrv].TX_Temp, (uint8_t *)DLT634_5101Slave_App[pdrv].StoreDATA2OUT, DLT634_5101Slave_App[pdrv].StoreDATA2OUT->status.Length);
        memset((uint8_t *)DLT634_5101Slave_App[pdrv].StoreDATA2OUT,0,sizeof(DLT634_5101SLAVE_PASDU));
        if(++DLT634_5101Slave_App[pdrv].StoreDATA2OUT >= DLT634_5101Slave_App[pdrv].StoreDATA2Buf + _DLT634_5101SLAVE_STOREDATA2NUM)
        {
            DLT634_5101Slave_App[pdrv].StoreDATA2OUT = DLT634_5101Slave_App[pdrv].StoreDATA2Buf;
        }
        return;
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_MasterFrame68Packet
** 功能描述: 可变帧启动站数据打包
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**           DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_SLAVE_CKS  计算CKS
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_SLAVE_MasterFrame68Packet(uint8_t pdrv, uint8_t Function)
{
    uint16_t length = 0;
    uint16_t i = 0;
    uint8_t *pBuf;
    uint8_t ptemp[256];
    
    pBuf = DLT634_5101Slave_App[pdrv].TxdBuf + DLT634_5101Slave_App[pdrv].TxdTail;

    pBuf[0] = pBuf[3] = _DLT634_5101SLAVE_STARTCODE68;
    pBuf[1] = pBuf[2] = DLT634_5101Slave_App[pdrv].TX_Temp.status.Length - sizeof(DLT634_5101Slave_App[pdrv].TX_Temp.status)+ 1 + 2;
    pBuf[4] = Function&0x0f;
    pBuf[4] |= _DLT634_5101SLAVE_DIR;
    pBuf[4] |= _DLT634_5101SLAVE_PRM;

    for (i = 0; i < 2; i++)
    {
        pBuf[5+i] = ((DLT634_5101Slave_Pad[pdrv].SourceAddr >> (8*i)) & 0xff);
    }
		
		memcpy(&pBuf[5+2], &DLT634_5101Slave_App[pdrv].TX_Temp.Head, DLT634_5101Slave_App[pdrv].TX_Temp.status.Length - sizeof(DLT634_5101Slave_App[pdrv].TX_Temp.status));
			
		for (i = 0; i < 2; i++)
    {
        pBuf[11+i] = ((DLT634_5101Slave_Pad[pdrv].ASDUAddr >> (8*i)) & 0xff);
    }
		
    length = 6 + pBuf[2]; // 全部报文长度	
    memcpy(&ptemp,pBuf,length);
    if(DLT634_5101Slave_Pad[pdrv].LinkAddrSize == 1)
    {
        length--;
        memcpy(&pBuf[6],&ptemp[7],length-3);	
    }
    if(DLT634_5101Slave_Pad[pdrv].ASDUCotSize == 1)
    {
        length--;
        memcpy(&pBuf[9],&ptemp[11],length-7);	
    }
    if(DLT634_5101Slave_Pad[pdrv].ASDUAddrSize == 1)
    {
        length--;
        memcpy(&pBuf[10],&ptemp[13],length-9);	
    }
    pBuf[length-2] = DLT634_5101_SLAVE_CKS(pdrv, pBuf)&0xFF;
    pBuf[length-1] = _DLT634_5101SLAVE_ENDCODE;
    DLT634_5101Slave_App[pdrv].TxdTail += length;

    memcpy(DLT634_5101Slave_App[pdrv].TxdBuf_Pri, pBuf, length);
    DLT634_5101Slave_App[pdrv].TxdTail_Pri = length;
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_SlaveFrame68Packet
** 功能描述: 可变帧从动站数据打包
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**           DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_SLAVE_CKS  计算CKS
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_SLAVE_SlaveFrame68Packet(uint8_t pdrv, uint8_t Function)
{
    uint16_t length = 0;
    uint16_t i = 0;
    uint8_t *pBuf = 0;
    uint8_t ptemp[256];
    
    pBuf = DLT634_5101Slave_App[pdrv].TxdBuf + DLT634_5101Slave_App[pdrv].TxdTail;

    pBuf[0] = pBuf[3] = _DLT634_5101SLAVE_STARTCODE68;
    pBuf[1] = pBuf[2] = DLT634_5101Slave_App[pdrv].TX_Temp.status.Length - sizeof(DLT634_5101Slave_App[pdrv].TX_Temp.status)+ 1 + DLT634_5101Slave_Pad[pdrv].LinkAddrSize;
    pBuf[4] = Function&0x0f;
    if(DLT634_5101Slave_App[pdrv].Data1Flag)
    {pBuf[4] |= _DLT634_5101SLAVE_ACD;}

    for (i = 0; i < DLT634_5101Slave_Pad[pdrv].LinkAddrSize; i++)
    {
        pBuf[5+i] = ((DLT634_5101Slave_Pad[pdrv].SourceAddr >> (8*i)) & 0xff);
    }
		memcpy(&pBuf[5+DLT634_5101Slave_Pad[pdrv].LinkAddrSize], &DLT634_5101Slave_App[pdrv].TX_Temp.Head, DLT634_5101Slave_App[pdrv].TX_Temp.status.Length - sizeof(DLT634_5101Slave_App[pdrv].TX_Temp.status));
    for (i = 0; i < 2; i++)
    {
        pBuf[11+i] = ((DLT634_5101Slave_Pad[pdrv].ASDUAddr >> (8*i)) & 0xff);
    }
    length = 6 + pBuf[2]; // 全部报文长度
    memcpy(&ptemp,pBuf,length);
    if(DLT634_5101Slave_Pad[pdrv].LinkAddrSize == 1)
    {
        length--;
        memcpy(&pBuf[6],&ptemp[7],length-3);	
    }
    if(DLT634_5101Slave_Pad[pdrv].ASDUCotSize == 1)
    {
        length--;
        memcpy(&pBuf[9],&ptemp[11],length-3);	
    }
    if(DLT634_5101Slave_Pad[pdrv].ASDUAddrSize == 1)
    {
        length--;
        memcpy(&pBuf[10],&ptemp[13],length-3);	
    }
    pBuf[length-2] = DLT634_5101_SLAVE_CKS(pdrv, pBuf)&0xFF;
    pBuf[length-1] = _DLT634_5101SLAVE_ENDCODE;
    DLT634_5101Slave_App[pdrv].TxdTail += length;

    memcpy(DLT634_5101Slave_App[pdrv].TxdBuf_Pri, pBuf, length);
    DLT634_5101Slave_App[pdrv].TxdTail_Pri = length;
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_SetFlagProcess
** 功能描述: 1级数据置位函数
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
** 调用模块: DLT634_5101_SLAVE_H_SOE  判断是否有未发送SOE
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_SLAVE_SetFlagProcess(uint8_t pdrv)
{
    if(DLT634_5101_SLAVE_H_SOE(pdrv))//soe
    {DLT634_5101Slave_App[pdrv].Data1Flag |= _DLT634_5101SLAVE_HAVESOE;}
    if(DLT634_5101Slave_App[pdrv].StoreDATA1OUT->status.Length)
    {DLT634_5101Slave_App[pdrv].Data1Flag |= _DLT634_5101SLAVE_HAVESTDATA1;}
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_Link68Process
** 功能描述: 可变帧发送函数
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**           DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_SLAVE_SetFlagProcess  1级数据置位函数
**           DLT634_5101_SLAVE_MasterFrame68Packet  可变帧启动站打包
**           DLT634_5101_SLAVE_WriteDataToMISI  数据发送函数
**           DLT634_5101_SLAVE_MasterFrame68Packet  可变帧从动站打包
**           DLT634_5101_SLAVE_SlaveFrame10Packet  固定帧从动站打包
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_SLAVE_Link68Process(uint8_t pdrv)
{
    DLT634_5101_SLAVE_SetFlagProcess(pdrv);

    if(DLT634_5101Slave_App[pdrv].TX_Temp.status.Length)
    {
        if(DLT634_5101Slave_Pad[pdrv].BalanMode)
        {
            DLT634_5101_SLAVE_MasterFrame68Packet(pdrv, _DLT634_5101SLAVE_M_FUN3);
            DLT634_5101_SLAVE_WriteDataToMISI(pdrv);
            DLT634_5101Slave_App[pdrv].TimeOutTick_Pri = DLT634_5101Slave_Pad[pdrv].TimeOutValue;
            DLT634_5101Slave_App[pdrv].RetryCount  = _DLT634_5101SLAVE_NUMOF_MAXRETRY;
            DLT634_5101Slave_App[pdrv].LinkFlag &= (~_DLT634_5101SLAVE_SENDABLE);
        }
        else
        {
            DLT634_5101_SLAVE_SlaveFrame68Packet(pdrv, _DLT634_5101SLAVE_M_FUN8);
            DLT634_5101_SLAVE_WriteDataToMISI(pdrv);
        }
        memset((uint8_t *)&DLT634_5101Slave_App[pdrv].TX_Temp,0,sizeof(DLT634_5101SLAVE_PASDU));
    }
    else
    {
        if (!DLT634_5101Slave_Pad[pdrv].BalanMode)
        {
            DLT634_5101_SLAVE_SlaveFrame10Packet(pdrv, _DLT634_5101SLAVE_S_FUN9);
            DLT634_5101_SLAVE_WriteDataToMISI(pdrv);
        }
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_SendProcess
** 功能描述: 发送处理区
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**           DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_SLAVE_Link10Process  固定帧发送数据函数
**           DLT634_5101_SLAVE_Data1Process  1级数据发送数据函数
**           DLT634_5101_SLAVE_Data2Process  2级数据发送数据函数
**           DLT634_5101_SLAVE_Link68Process  可变帧发送函数
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_SLAVE_SendProcess(uint8_t pdrv)
{   	
    if(DLT634_5101Slave_App[pdrv].LinkFlag&0x000000ff)
    {
        DLT634_5101_SLAVE_Link10Process(pdrv);
        return;
    }
    
    if(DLT634_5101Slave_Pad[pdrv].BalanMode)
    {
        if(DLT634_5101Slave_App[pdrv].LinkFlag&_DLT634_5101SLAVE_SENDABLE)
        {
            DLT634_5101_SLAVE_Data1Process(pdrv);
            if(DLT634_5101Slave_App[pdrv].TX_Temp.status.Length == 0)
            {DLT634_5101_SLAVE_Data2Process(pdrv);}
            DLT634_5101_SLAVE_Link68Process(pdrv);
            return;
        }
    }
    else
    {
        if(DLT634_5101Slave_App[pdrv].LinkFlag&_DLT634_5101SLAVE_REDATA1)
        {	
            DLT634_5101_SLAVE_Data1Process(pdrv);
            DLT634_5101_SLAVE_Link68Process(pdrv);
        }	
        else if(DLT634_5101Slave_App[pdrv].LinkFlag&_DLT634_5101SLAVE_REDATA2)
        {
            DLT634_5101_SLAVE_Data2Process(pdrv);
            if(DLT634_5101Slave_App[pdrv].TX_Temp.status.Length == 0)
            {DLT634_5101_SLAVE_Data1Process(pdrv);}
            DLT634_5101_SLAVE_Link68Process(pdrv);
        }
        DLT634_5101Slave_App[pdrv].LinkFlag &= (~(_DLT634_5101SLAVE_REDATA1|_DLT634_5101SLAVE_REDATA2));
        return;
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_LinkOnTimer
** 功能描述: 链路层定时器处理区
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**           DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_SLAVE_WriteDataToMISI  发送数据函数
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
void DLT634_5101_SLAVE_LinkOnTimer(uint8_t pdrv)
{
    if (DLT634_5101Slave_App[pdrv].TimeOutTick_Pri) // 单位是秒
    {
        DLT634_5101Slave_App[pdrv].TimeOutTick_Pri--;
        if (!DLT634_5101Slave_App[pdrv].TimeOutTick_Pri)
        {
            if (!DLT634_5101Slave_App[pdrv].RetryCount)
            {
                return;
            }

            DLT634_5101Slave_App[pdrv].RetryCount--;
            if (DLT634_5101Slave_App[pdrv].RetryCount)
            {
                memcpy(DLT634_5101Slave_App[pdrv].TxdBuf + DLT634_5101Slave_App[pdrv].TxdTail, DLT634_5101Slave_App[pdrv].TxdBuf_Pri, DLT634_5101Slave_App[pdrv].TxdTail_Pri);
                DLT634_5101Slave_App[pdrv].TxdTail += DLT634_5101Slave_App[pdrv].TxdTail_Pri;

                DLT634_5101_SLAVE_WriteDataToMISI(pdrv);
                DLT634_5101Slave_App[pdrv].TimeOutTick_Pri = DLT634_5101Slave_Pad[pdrv].TimeOutValue;
                return;
            }
            else // 超过重发次数后，重新建立链路，并通知应用层。
            {
                DLT634_5101Slave_App[pdrv].LinkFlag = 0;
                if(DLT634_5101Slave_App[pdrv].TxdBuf_Pri[5+DLT634_5101Slave_Pad[pdrv].LinkAddrSize]& (_DLT634_5101SLAVE_M_SP_TB_1|_DLT634_5101SLAVE_M_DP_TB_1))
                {
                    DLT634_5101Slave_App[pdrv].TxdTail_Special= DLT634_5101Slave_App[pdrv].TxdTail_Pri;
                    memcpy(DLT634_5101Slave_App[pdrv].TxdBuf_Special, DLT634_5101Slave_App[pdrv].TxdBuf_Pri, DLT634_5101Slave_App[pdrv].TxdTail_Pri);
                }
            }
        }
    }
		
    if((!(DLT634_5101Slave_App[pdrv].LinkFlag&_DLT634_5101SLAVE_INITEND))&&(DLT634_5101Slave_Pad[pdrv].BalanMode))
    {
        if (!DLT634_5101Slave_App[pdrv].TimeOutTick_AskSta)
        {
            DLT634_5101Slave_App[pdrv].LinkFlag |= _DLT634_5101SLAVE_ASKSTATUS;
        }
        else
        {
            DLT634_5101Slave_App[pdrv].TimeOutTick_AskSta--;
        }
    }
}
/* PUBLIC FUNCTION PROTOTYPES -----------------------------------------------*/
/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_REPLY
** 功能描述: 其他设备应答处理
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**         : DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_SLAVE_StoreIN  发送缓冲区堆栈
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
uint8_t DLT634_5101_SLAVE_REPLY(uint8_t pdrv, uint8_t *pbuf)//回复
{ 
	uint8_t res = FALSE;
	
	memcpy(&DLT634_5101Slave_App[pdrv].ST_Temp, pbuf,_DLT634_5101SLAVE_LPDUSIZE);
	switch (DLT634_5101Slave_App[pdrv].ST_Temp.Head.TypeID)
	{
        //控制方向过程信息
        case _DLT634_5101SLAVE_C_SC_NA_1: // 单点遥控命令
        case _DLT634_5101SLAVE_C_SC_NB_1: // 双点遥控命令
            DLT634_5101Slave_App[pdrv].ST_Temp.status.symbol.priority = _DLT634_5101SLAVE_C_SC_NA_P;
            res = DLT634_5101_SLAVE_StoreIN(pdrv,&DLT634_5101Slave_App[pdrv].ST_Temp);
                break;

        case _DLT634_5101SLAVE_C_CS_NA_1: // 对时命令
            DLT634_5101Slave_App[pdrv].ST_Temp.status.symbol.priority = _DLT634_5101SLAVE_C_CS_NA_P;
            res = DLT634_5101_SLAVE_StoreIN(pdrv,&DLT634_5101Slave_App[pdrv].ST_Temp);
                break;

        case _DLT634_5101SLAVE_C_RP_NA_1: // 复位进程命令
                break;
        
        case _DLT634_5101SLAVE_C_RR_NA_1: // 读定值区号
        case _DLT634_5101SLAVE_C_RS_NA_1: // 读参数和定值命令
            DLT634_5101Slave_App[pdrv].ST_Temp.status.symbol.priority = _DLT634_5101SLAVE_C_IC_NA_P;
            res = DLT634_5101_SLAVE_StoreIN(pdrv,&DLT634_5101Slave_App[pdrv].ST_Temp);
                break;
        
        case _DLT634_5101SLAVE_C_SR_NA_1: // 切换定值区
        case _DLT634_5101SLAVE_C_WS_NA_1: // 写参数和定值命令
            DLT634_5101Slave_App[pdrv].ST_Temp.status.symbol.priority = _DLT634_5101SLAVE_C_SC_NA_P;
            res = DLT634_5101_SLAVE_StoreIN(pdrv,&DLT634_5101Slave_App[pdrv].ST_Temp);
                break;

        case _DLT634_5101SLAVE_F_FR_NA_1: // 文件传输
            DLT634_5101Slave_App[pdrv].ST_Temp.status.symbol.priority = _DLT634_5101SLAVE_F_FW_NA_P;
            res = DLT634_5101_SLAVE_StoreIN(pdrv,&DLT634_5101Slave_App[pdrv].ST_Temp);
                break;

        case _DLT634_5101SLAVE_F_SR_NA_1: // 软件升级
            DLT634_5101Slave_App[pdrv].ST_Temp.status.symbol.priority = _DLT634_5101SLAVE_F_FW_NA_P;
            res = DLT634_5101_SLAVE_StoreIN(pdrv,&DLT634_5101Slave_App[pdrv].ST_Temp);
                break;			

        default: // 类型标识有错误或不支持
                break;
	}
	return(res);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_Clock
** 功能描述: 定时处理函数
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Slave_App[pdrv]：运行参数结构体
**           DLT634_5101Slave_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_SLAVE_ReadMISIData  查询MISI接收缓冲区
**           DLT634_5101_SLAVE_SendProcess  发送处理区
**           DLT634_5101_SLAVE_LinkOnTimer  链路层定时器处理区
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
void DLT634_5101_SLAVE_Clock(uint8_t pdrv)
{

	DLT634_5101Slave_App[pdrv].ClockCounter++;
	if (DLT634_5101Slave_App[pdrv].ClockCounter >= DLT634_5101Slave_Pad[pdrv].ClockTimers)
	{
        DLT634_5101Slave_App[pdrv].ClockCounter = 0;
                                            
        // 查询MISI接收缓冲区
        DLT634_5101_SLAVE_ReadMISIData(pdrv);
    
        // 发送处理
        DLT634_5101_SLAVE_SendProcess(pdrv);
            
        // 链路层定时器
        DLT634_5101_SLAVE_LinkOnTimer(pdrv);
	}
}

