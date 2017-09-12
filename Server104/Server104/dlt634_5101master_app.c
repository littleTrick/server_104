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
#include "dlt634_5101master_app.h"
#include "dlt634_5101master_disk.h"

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
}_DLT634_5101MASTER_CP56Time2a_t;

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
            _DLT634_5101MASTER_CP56Time2a_t CP56Time2a;
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
                    _DLT634_5101MASTER_CP56Time2a_t CP56Time2a;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/10];
            }SQ0;

            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;	
                struct
                {
                    uint8_t Value; 
                    _DLT634_5101MASTER_CP56Time2a_t CP56Time2a;
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
                    _DLT634_5101MASTER_CP56Time2a_t CP56Time2a;
                }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/10];
            }SQ0;

            struct
            {
                uint8_t InfoAddr_L;
                uint8_t InfoAddr_H;	
                struct
                {
                    uint8_t Value; 
                    _DLT634_5101MASTER_CP56Time2a_t CP56Time2a;
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
}DLT634_5101MASTER_PASDU;

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
	uint8_t TxdBuf[_DLT634_5101MASTER_LPDUSIZE];     	// 发送缓冲区
	
	uint16_t RxdHead;	      				// 接收数据区头指针
    uint16_t RxdTail;       				// 接收数据区尾指针
	uint16_t RxdLength;     				// 接收一帧数据长度
	uint8_t RxdBuf[_DLT634_5101MASTER_LPDUSIZE];			// 接收缓冲区
	
	uint16_t TxdTail_Pri;
	uint8_t TxdBuf_Pri[_DLT634_5101MASTER_LPDUSIZE]; // 发送缓冲区，暂存发送的数据，重发时用
	
//app
	uint8_t Devid;	  								//发送设备id
	uint32_t TimeOutTick_Devid; 			//设备占用计时器
	
	DLT634_5101MASTER_PASDU *StoreDATA1IN;              //待发送缓冲区1级数据入指针
	DLT634_5101MASTER_PASDU *StoreDATA1OUT;             //待发送缓冲区1级数据出指针
	DLT634_5101MASTER_PASDU StoreDATA1Buf[_DLT634_5101MASTER_STOREDATA1NUM];     	// 1级数据待发送缓冲区
	DLT634_5101MASTER_PASDU ST_Temp;              //存储数据处理
	
	DLT634_5101MASTER_PASDU TX_Temp;              //发送数据处理
	DLT634_5101MASTER_PASDU RX_Temp;              //接受数据处理
	
	uint32_t LinkFlag;              //回复链路数据标志
	uint32_t Data1Flag;             //应用数据标志
	
	uint32_t ClockCounter;  				//程序运行周期控制
	uint32_t TimeOutTick_Pri; 			//超时节拍计时器
	uint32_t RetryCount;						//超时记数器
	
	uint32_t TimeOutTick_AskSta; 			//召唤链路节拍计时器
	uint32_t TimeOutTick_AllData; 			//全数据节拍计时器
	uint32_t TimeOutTick_LinkTest; 			//测试帧节拍计时器
	uint32_t TimeOutTick_LinkIdle; 			//链路空闲计时器
	
	uint8_t SendConCode;	  // 发送的控制码FCB位记录

}DLT634_5101MASTER_APPINFO;
#pragma pack(pop)
/* PUBLIC VARIABLES ----------------------------------------------------------*/
DLT634_5101MASTER_PAD      DLT634_5101Master_Pad[_DLT634_5101MASTER_VOLUMES];
DLT634_5101MASTER_APPINFO  DLT634_5101Master_App[_DLT634_5101MASTER_VOLUMES];

/* PRIVATE FUNCTION PROTOTYPES -----------------------------------------------*/


/* PUBLIC FUNCTION PROTOTYPES -----------------------------------------------*/
/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_CKS
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
static uint8_t DLT634_5101_MASTER_CKS(uint8_t pdrv ,uint8_t *pBuf)
{
    uint16_t sum = 0;
    uint16_t j =0;
    uint8_t *p = 0;
    uint8_t i = 0;

    if (*(pBuf) == _DLT634_5101MASTER_STARTCODE10)
    {
        for (j = 0; j < (DLT634_5101Master_Pad[pdrv].LinkAddrSize + 1); j++)
        {
            sum += *(pBuf + 1 + j);
        }
    }
    else if(*(pBuf) == _DLT634_5101MASTER_STARTCODE68)
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
** 函数名称: DLT634_5101_MASTER_CheckFram68Valid
** 功能描述: 可变帧报文检查
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Master_App[pdrv]：运行参数结构体
**         : DLT634_5101Master_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_MASTER_CKS 计算CKS
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static uint8_t DLT634_5101_MASTER_CheckFram68Valid(uint8_t pdrv)
{
    uint8_t *pBuf = 0;
    
    pBuf = (DLT634_5101Master_App[pdrv].RxdBuf + DLT634_5101Master_App[pdrv].RxdHead);

	  // 报头校验
    if ((pBuf[0] != pBuf[3]) || (pBuf[1] != pBuf[2]))
    {
        return(0);
    }

	  // 公共地址校验
    if (DLT634_5101Master_Pad[pdrv].LinkAddrSize == 1)
    {
        if ((pBuf[5] != DLT634_5101Master_Pad[pdrv].SourceAddr) && (pBuf[5] != 0xff))
        {
            return(0);
        }
    }
    else
    {
        if (((pBuf[5]|(pBuf[6]<<8)) != DLT634_5101Master_Pad[pdrv].SourceAddr) && ((pBuf[5]|(pBuf[6]<<8)) != 0xffff))
        {
            return (0);
        }
    }
    
    return (1);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_CheckFram10Valid
** 功能描述: 固定帧报文检查
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Master_App[pdrv]：运行参数结构体
**         : DLT634_5101Master_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_MASTER_CKS 计算CKS
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static uint8_t DLT634_5101_MASTER_CheckFram10Valid(uint8_t pdrv)
{
    uint8_t *pBuf = 0;
    uint16_t addr = 0;

    pBuf = &DLT634_5101Master_App[pdrv].RxdBuf[DLT634_5101Master_App[pdrv].RxdHead];

	  // 固定帧长数据的校验和检测
    if (pBuf[2+DLT634_5101Master_Pad[pdrv].LinkAddrSize] != (DLT634_5101_MASTER_CKS(pdrv, pBuf)&0xFF))	
    {
        return (0);
    }

	  // 固定帧长数据的结束帧检测
    if (pBuf[3+DLT634_5101Master_Pad[pdrv].LinkAddrSize] != _DLT634_5101MASTER_ENDCODE)
    {
        return (0);
    }

	  // 固定帧数据公共地址检测
    if (DLT634_5101Master_Pad[pdrv].LinkAddrSize == 1)
    {
        addr = pBuf[2];
    }
    else
    {
        addr = pBuf[2] | ((pBuf[3]<<8));
    }
		
    if (addr != DLT634_5101Master_Pad[pdrv].SourceAddr)
    {
        return (0);
    }
    
    return (1);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_DecodeFrame10
** 功能描述: 固定帧报文解析
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Master_App[pdrv]：运行参数结构体
**         : DLT634_5101Master_Pad[pdrv]：设定参数结构体
** 调用模块: 
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_DecodeFrame10(uint8_t pdrv)
{
    uint8_t stop = 0;
    uint8_t control = 0;

    control = DLT634_5101Master_App[pdrv].RxdBuf[1];
    DLT634_5101Master_App[pdrv].TimeOutTick_LinkTest = DLT634_5101Master_Pad[pdrv].LinkTestValue;
    if (control & _DLT634_5101MASTER_PRM) // 主站作为从动站接收主站的命令
    {
        switch (control & _DLT634_5101MASTER_FUNCODE)
        {
            case _DLT634_5101MASTER_M_FUN9: // 召唤链路状态
                DLT634_5101Master_App[pdrv].TimeOutTick_AskSta = DLT634_5101Master_Pad[pdrv].AskStaOutValue;
                DLT634_5101Master_App[pdrv].LinkFlag = 0;
                DLT634_5101Master_App[pdrv].LinkFlag |= _DLT634_5101MASTER_REQSTATUS;
                /* 可以避免答非所问的过程，尽快建立链路 */ 
                while (((DLT634_5101Master_App[pdrv].RxdTail - DLT634_5101Master_App[pdrv].RxdHead) >= DLT634_5101Master_Pad[pdrv].FixFrmLength) && (stop == 0)) // 收到召唤链路状态命令时，清掉后续相同命令。
                {
                    if (memcmp(DLT634_5101Master_App[pdrv].RxdBuf, DLT634_5101Master_App[pdrv].RxdBuf + DLT634_5101Master_App[pdrv].RxdHead, DLT634_5101Master_Pad[pdrv].FixFrmLength) == 0)
                    {
                        DLT634_5101Master_App[pdrv].RxdHead += DLT634_5101Master_Pad[pdrv].FixFrmLength;
                    }
                    else
                    {
                        stop = 1;
                    }
                }
                break;

            case _DLT634_5101MASTER_M_FUN0: // 复位链路
                DLT634_5101Master_App[pdrv].LinkFlag |= _DLT634_5101MASTER_RECONFIRM;
                DLT634_5101Master_App[pdrv].SendConCode = 0x20;
                DLT634_5101Master_App[pdrv].StoreDATA1IN = DLT634_5101Master_App[pdrv].StoreDATA1Buf;
                DLT634_5101Master_App[pdrv].StoreDATA1OUT = DLT634_5101Master_App[pdrv].StoreDATA1Buf;
                memset(DLT634_5101Master_App[pdrv].StoreDATA1Buf,0,sizeof(DLT634_5101Master_App[pdrv].StoreDATA1Buf));
                break;
            default:
                break;
        }
        return;
    }
    else // Prm=0 平衡模式主站作为启动站接收到主站的命令。
    {
        switch (control & _DLT634_5101MASTER_FUNCODE)
        {
            case _DLT634_5101MASTER_S_FUN0:	// 确认
                DLT634_5101Master_App[pdrv].LinkFlag |= _DLT634_5101MASTER_SENDABLE;
                DLT634_5101Master_App[pdrv].TimeOutTick_Pri = 0; // 链路有数据就可以不重发
                break;

            case _DLT634_5101MASTER_S_FUN11: // 应答链路
                DLT634_5101Master_App[pdrv].TimeOutTick_Pri = 0; // 链路有数据就可以不重发
                DLT634_5101Master_App[pdrv].LinkFlag |= _DLT634_5101MASTER_ASKRELINK;
                break;

            default:
                break;
        }
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_StoreIN
** 功能描述: 发送缓冲区堆栈
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Master_App[pdrv]：运行参数结构体
**         : DLT634_5101Master_Pad[pdrv]：设定参数结构体
** 调用模块: 
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static uint8_t DLT634_5101_MASTER_StoreIN(uint8_t pdrv,DLT634_5101MASTER_PASDU *buf)
{	
	DLT634_5101MASTER_PASDU *temp;
	
	temp = DLT634_5101Master_App[pdrv].StoreDATA1IN;
	if(++temp >= DLT634_5101Master_App[pdrv].StoreDATA1Buf + _DLT634_5101MASTER_STOREDATA1NUM)
	{
		temp = DLT634_5101Master_App[pdrv].StoreDATA1Buf;
	}
	
	if(temp == DLT634_5101Master_App[pdrv].StoreDATA1OUT)
	{
		return(FALSE);
	}
	
	memcpy(DLT634_5101Master_App[pdrv].StoreDATA1IN,buf,sizeof(DLT634_5101MASTER_PASDU));	

	if(++DLT634_5101Master_App[pdrv].StoreDATA1IN >= DLT634_5101Master_App[pdrv].StoreDATA1Buf + _DLT634_5101MASTER_STOREDATA1NUM)
	{
		DLT634_5101Master_App[pdrv].StoreDATA1IN = DLT634_5101Master_App[pdrv].StoreDATA1Buf;
	}
		
	return(TRUE);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_AppProcess
** 功能描述: 应用处理函数
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Master_App[pdrv]：运行参数结构体
**         : DLT634_5101Master_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_MASTER_C_SC  向其他设备发送遥控
**         : DLT634_5101_MASTER_C_CS  向其他设备发送定值
**         : DLT634_5101_MASTER_W_YXDATA  写YXDATA
**         : DLT634_5101_MASTER_W_SOE  写SOE
**         : DLT634_5101_MASTER_W_YCDATA  写YCDATA
**         : DLT634_5101_MASTER_W_FEvent  写FEvent
**         : DLT634_5101_MASTER_StoreIN  发送缓冲区堆栈 
**         : DLT634_5101_MASTER_F_FR  向其他设备发送文件传输
**         : DLT634_5101_MASTER_F_SR  向其他设备发送软件升级
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_AppProcess(uint8_t pdrv,uint8_t Control)
{		
    //整理成02版报文，便于控制和传输
    memset((uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp,0,sizeof(DLT634_5101MASTER_PASDU));
    DLT634_5101Master_App[pdrv].RX_Temp.status.Length = DLT634_5101Master_App[pdrv].RxdBuf[1] -1 -DLT634_5101Master_Pad[pdrv].LinkAddrSize;
    memcpy((uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp.Head.TypeID,&DLT634_5101Master_App[pdrv].RxdBuf[5+DLT634_5101Master_Pad[pdrv].LinkAddrSize],DLT634_5101Master_App[pdrv].RX_Temp.status.Length);
    if(DLT634_5101Master_Pad[pdrv].ASDUCotSize == 1)
    {
        DLT634_5101Master_App[pdrv].RX_Temp.Head.COT_H = 0;
        memcpy((uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp.Head.PubAddr_L,&DLT634_5101Master_App[pdrv].RxdBuf[5+DLT634_5101Master_Pad[pdrv].LinkAddrSize+2+DLT634_5101Master_Pad[pdrv].ASDUCotSize]
        ,DLT634_5101Master_App[pdrv].RX_Temp.status.Length-2-DLT634_5101Master_Pad[pdrv].ASDUCotSize);	
        DLT634_5101Master_App[pdrv].RX_Temp.status.Length = DLT634_5101Master_App[pdrv].RX_Temp.status.Length - DLT634_5101Master_Pad[pdrv].ASDUCotSize + 2;
    }
    if(DLT634_5101Master_Pad[pdrv].ASDUAddrSize == 1)
    {
        DLT634_5101Master_App[pdrv].RX_Temp.Head.PubAddr_H = 0;
        memcpy((uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp.Data.buff[0],&DLT634_5101Master_App[pdrv].RxdBuf[5+DLT634_5101Master_Pad[pdrv].LinkAddrSize+2+DLT634_5101Master_Pad[pdrv].ASDUCotSize+DLT634_5101Master_Pad[pdrv].ASDUAddrSize]
        ,DLT634_5101Master_App[pdrv].RX_Temp.status.Length-2-DLT634_5101Master_Pad[pdrv].ASDUCotSize-DLT634_5101Master_Pad[pdrv].ASDUAddrSize);	
        DLT634_5101Master_App[pdrv].RX_Temp.status.Length = DLT634_5101Master_App[pdrv].RX_Temp.status.Length - DLT634_5101Master_Pad[pdrv].ASDUAddrSize + 2;		
    }
    DLT634_5101Master_App[pdrv].RX_Temp.status.Length += sizeof(DLT634_5101Master_App[pdrv].RX_Temp.status);
    
    if (Control & _DLT634_5101MASTER_PRM) // 主站作为从动站接收子站链路报文。
    {
        switch (DLT634_5101Master_App[pdrv].RX_Temp.Head.TypeID)
        {
            //控制方向过程信息
            case _DLT634_5101MASTER_C_SC_NA_1: // 单点遥控命令
            case _DLT634_5101MASTER_C_SC_NB_1: // 双点遥控命令
                DLT634_5101Master_App[pdrv].RX_Temp.status.symbol.Lock_ID = DLT634_5101Master_App[pdrv].Devid;
                DLT634_5101_MASTER_C_SC(pdrv,(uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp);
                break;

            //监视方向的系统命令
            case _DLT634_5101MASTER_M_EI_NA_1:// 初始化结束
                DLT634_5101Master_App[pdrv].LinkFlag |= _DLT634_5101MASTER_INITEND;
                DLT634_5101Master_App[pdrv].LinkFlag |= _DLT634_5101MASTER_SENDABLE;
                DLT634_5101Master_App[pdrv].Data1Flag |= _DLT634_5101MASTER_CALLALLDATA;
                DLT634_5101Master_App[pdrv].Data1Flag |= _DLT634_5101MASTER_READTIME;
                DLT634_5101Master_App[pdrv].TimeOutTick_Devid = DLT634_5101Master_Pad[pdrv].DevidValue;
                break;
            
            //控制方向命令信息
            case _DLT634_5101MASTER_C_SR_NA_1: // 切换定值区
            case _DLT634_5101MASTER_C_RR_NA_1: // 读定值区号
            case _DLT634_5101MASTER_C_RS_NA_1: // 读参数和定值命令
            case _DLT634_5101MASTER_C_WS_NA_1: // 写参数和定值命令
                DLT634_5101Master_App[pdrv].RX_Temp.status.symbol.Lock_ID = DLT634_5101Master_App[pdrv].Devid;
                DLT634_5101_MASTER_C_SR(pdrv, (uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp);
                break;
        
            case _DLT634_5101MASTER_C_IC_NA_1: // 总召唤或分组召唤
                DLT634_5101Master_App[pdrv].TimeOutTick_AllData = DLT634_5101Master_Pad[pdrv].AllDataOutValue;
                break;

            case _DLT634_5101MASTER_C_CI_NA_1: // 电度总召唤或分组召唤
                break;
            
            case _DLT634_5101MASTER_M_SP_NA_1: //单点信息
            case _DLT634_5101MASTER_M_DP_NA_1: //双点信息
                DLT634_5101_MASTER_W_YXDATA(pdrv, (uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp);
                break;
            
            case _DLT634_5101MASTER_M_SP_TB_1: //带时标单点信息
            case _DLT634_5101MASTER_M_DP_TB_1: //带时标双点信息
                DLT634_5101_MASTER_W_SOE(pdrv, (uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp);
                break;
            
            case _DLT634_5101MASTER_M_ME_NA_1: //测量值，归一化值
            case _DLT634_5101MASTER_M_ME_NB_1: //测量值，标度化值
            case _DLT634_5101MASTER_M_ME_NC_1: //测量值，短浮点数
                DLT634_5101_MASTER_W_YCDATA(pdrv, (uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp);
                break;
            
            case _DLT634_5101MASTER_M_FT_NA_1: //故障事件
                DLT634_5101_MASTER_W_FEvent(pdrv, (uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp);
                break;

            case _DLT634_5101MASTER_C_CS_NA_1: // 对时命令
                DLT634_5101Master_App[pdrv].RX_Temp.status.symbol.Lock_ID = DLT634_5101Master_App[pdrv].Devid;
                DLT634_5101_MASTER_C_CS(pdrv, (uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp);
                break;

            case _DLT634_5101MASTER_C_TS_NA_1: // 测试命令
                if(DLT634_5101Master_App[pdrv].RX_Temp.Head.COT_L == _DLT634_5101MASTER_COT_ACT)
                {
                    DLT634_5101Master_App[pdrv].RX_Temp.Head.COT_L = _DLT634_5101MASTER_COT_ACTCON;
                    DLT634_5101_MASTER_StoreIN(pdrv,&DLT634_5101Master_App[pdrv].RX_Temp);
                }
                break;

            case _DLT634_5101MASTER_C_RP_NA_1: // 复位进程命令
                break;

            case _DLT634_5101MASTER_F_FR_NA_1: // 文件传输
                DLT634_5101Master_App[pdrv].RX_Temp.status.symbol.Lock_ID = DLT634_5101Master_App[pdrv].Devid;
                DLT634_5101_MASTER_F_FR(pdrv, (uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp);
                break;

            case _DLT634_5101MASTER_F_SR_NA_1: // 软件升级
                DLT634_5101Master_App[pdrv].RX_Temp.status.symbol.Lock_ID = DLT634_5101Master_App[pdrv].Devid;
                DLT634_5101_MASTER_F_SR(pdrv, (uint8_t *)&DLT634_5101Master_App[pdrv].RX_Temp);
                break;			

            default: // 类型标识有错误或不支持
                break;
        }
    }
    else  // Prm=0；主站作为启动站接收子站链路报文,需回复报文
    {
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_DecodeFrame68
** 功能描述: 解析可变帧桢报文
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Master_App[pdrv]：运行参数结构体
**           DLT634_5101Master_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_MASTER_AppProcess  应用处理函数
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_DecodeFrame68(uint8_t pdrv)
{
    uint8_t control;
    
    control = DLT634_5101Master_App[pdrv].RxdBuf[4];

    DLT634_5101Master_App[pdrv].TimeOutTick_LinkTest = DLT634_5101Master_Pad[pdrv].LinkTestValue;
    DLT634_5101Master_App[pdrv].LinkFlag |= _DLT634_5101MASTER_RECONFIRM;
    DLT634_5101_MASTER_AppProcess(pdrv,control);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_SearchValidFrame
** 功能描述: 数据处理函数
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Master_App[pdrv]：运行参数结构体
**           DLT634_5101Master_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_MASTER_CheckFram68Valid  检查可变帧报文
**         : DLT634_5101_MASTER_CheckFram10Valid  检查固定帧报文
**         : DLT634_5101_MASTER_DecodeFrame68  解析可变桢报文
**         : DLT634_5101_MASTER_DecodeFrame10  解析固定桢报文
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_SearchValidFrame(uint8_t pdrv)
{
    uint8_t stop = 0;
    uint8_t length = 0;
    
    while ((DLT634_5101Master_App[pdrv].RxdHead < DLT634_5101Master_App[pdrv].RxdTail) && (!stop))
    {
        if (DLT634_5101Master_App[pdrv].RxdStatus == RXDSTART)
        {
            while ((DLT634_5101Master_App[pdrv].RxdBuf[DLT634_5101Master_App[pdrv].RxdHead] != _DLT634_5101MASTER_STARTCODE10)
                    && (DLT634_5101Master_App[pdrv].RxdBuf[DLT634_5101Master_App[pdrv].RxdHead] != _DLT634_5101MASTER_STARTCODE68)
                    && (DLT634_5101Master_App[pdrv].RxdHead < DLT634_5101Master_App[pdrv].RxdTail))
            {
                DLT634_5101Master_App[pdrv].RxdHead++;
            }

            if (DLT634_5101Master_App[pdrv].RxdHead < DLT634_5101Master_App[pdrv].RxdTail) // 找到启动字符，并将报文与缓冲区对齐。
            {
                DLT634_5101Master_App[pdrv].RxdStatus = RXDHEAD;
                if (DLT634_5101Master_App[pdrv].RxdHead != 0)
                {
                    memcpy(DLT634_5101Master_App[pdrv].RxdBuf,DLT634_5101Master_App[pdrv].RxdBuf+DLT634_5101Master_App[pdrv].RxdHead,DLT634_5101Master_App[pdrv].RxdTail-DLT634_5101Master_App[pdrv].RxdHead);
                    DLT634_5101Master_App[pdrv].RxdTail -= DLT634_5101Master_App[pdrv].RxdHead;
                    DLT634_5101Master_App[pdrv].RxdHead = 0;
                }
            }
        }
        
        DLT634_5101Master_App[pdrv].RxdLength = DLT634_5101Master_App[pdrv].RxdTail - DLT634_5101Master_App[pdrv].RxdHead;
        if (DLT634_5101Master_App[pdrv].RxdStatus == RXDHEAD) // 报文够一帧则处理
        {
            switch (DLT634_5101Master_App[pdrv].RxdBuf[DLT634_5101Master_App[pdrv].RxdHead])
            {
                case _DLT634_5101MASTER_STARTCODE68:
                    if (DLT634_5101Master_App[pdrv].RxdLength >= 5+DLT634_5101Master_Pad[pdrv].LinkAddrSize) // 启动字符到链路地址共6字节。
                    {
                        if (!DLT634_5101_MASTER_CheckFram68Valid(pdrv)) // 判断是否报文头
                        {
                            DLT634_5101Master_App[pdrv].RxdHead++;
                            DLT634_5101Master_App[pdrv].RxdStatus = RXDSTART;
                        }
                        else
                        {
                            DLT634_5101Master_App[pdrv].RxdStatus = RXDCONTINUE;
                        }
                    }
                    else
                    {
                        stop = 1;
                    }
                    break;
                    
                case _DLT634_5101MASTER_STARTCODE10:
                    if (DLT634_5101Master_App[pdrv].RxdLength >= 4 + DLT634_5101Master_Pad[pdrv].LinkAddrSize)
                    {
                        if (!DLT634_5101_MASTER_CheckFram10Valid(pdrv))
                        {
                            DLT634_5101Master_App[pdrv].RxdHead++;
                            DLT634_5101Master_App[pdrv].RxdStatus = RXDSTART;
                        }
                        else
                        {
                            DLT634_5101Master_App[pdrv].RxdStatus = RXDCONTINUE;
                        }
                    }
                    else
                    {
                        stop = 1;
                    }
                    break;
            }
        }
        if (DLT634_5101Master_App[pdrv].RxdStatus == RXDCONTINUE)
        {
            switch (DLT634_5101Master_App[pdrv].RxdBuf[DLT634_5101Master_App[pdrv].RxdHead])
            {
            case _DLT634_5101MASTER_STARTCODE68:
                length = DLT634_5101Master_App[pdrv].RxdBuf[DLT634_5101Master_App[pdrv].RxdHead+1];
                if (DLT634_5101Master_App[pdrv].RxdLength >= length+6) // 报文收全，进行处理
                {
                    if ((DLT634_5101Master_App[pdrv].RxdBuf[DLT634_5101Master_App[pdrv].RxdHead+length+4] == (DLT634_5101_MASTER_CKS(pdrv, DLT634_5101Master_App[pdrv].RxdBuf+DLT634_5101Master_App[pdrv].RxdHead)&0xFF))//校验正确
                            && (DLT634_5101Master_App[pdrv].RxdBuf[DLT634_5101Master_App[pdrv].RxdHead+length+4+1] == _DLT634_5101MASTER_ENDCODE)) // 结束码正确
 					          {
                        if ( DLT634_5101Master_App[pdrv].RxdHead > 0 )
                        {
                            memcpy(DLT634_5101Master_App[pdrv].RxdBuf,DLT634_5101Master_App[pdrv].RxdBuf+DLT634_5101Master_App[pdrv].RxdHead,DLT634_5101Master_App[pdrv].RxdTail-DLT634_5101Master_App[pdrv].RxdHead);//报文与缓冲区对齐
                            DLT634_5101Master_App[pdrv].RxdTail -= DLT634_5101Master_App[pdrv].RxdHead;
                            DLT634_5101Master_App[pdrv].RxdHead = 0;
                        }
												/* 头指针后移到报文后 */
                        DLT634_5101Master_App[pdrv].RxdHead += (DLT634_5101Master_App[pdrv].RxdBuf[1]+6);
                        DLT634_5101Master_App[pdrv].RxdStatus = RXDSTART;

                        DLT634_5101_MASTER_DecodeFrame68(pdrv);
                    }
                    else
                    {
                        DLT634_5101Master_App[pdrv].RxdHead += 6;
                        DLT634_5101Master_App[pdrv].RxdStatus = RXDSTART;
                    }
                }
                else // 报文未收全，不处理，继续等待数据。
                {
                    stop = 1;
                }
                break;
                
            case _DLT634_5101MASTER_STARTCODE10:
                if (DLT634_5101Master_App[pdrv].RxdHead > 0)
                {
                    memcpy(DLT634_5101Master_App[pdrv].RxdBuf,DLT634_5101Master_App[pdrv].RxdBuf+DLT634_5101Master_App[pdrv].RxdHead,DLT634_5101Master_App[pdrv].RxdTail-DLT634_5101Master_App[pdrv].RxdHead);
                    DLT634_5101Master_App[pdrv].RxdTail -= DLT634_5101Master_App[pdrv].RxdHead;
                    DLT634_5101Master_App[pdrv].RxdHead = 0;
                }
                DLT634_5101Master_App[pdrv].RxdHead += 4 + DLT634_5101Master_Pad[pdrv].LinkAddrSize;
                DLT634_5101Master_App[pdrv].RxdStatus = RXDSTART;
			
                DLT634_5101_MASTER_DecodeFrame10(pdrv);
                break;
            }
        }
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_ReadMISIData
** 功能描述: 读取函数
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Master_App[pdrv]：运行参数结构体
**           DLT634_5101Master_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_MASTER_ReadData  读取函数
**         : DLT634_5101_MASTER_SearchValidFrame  数据处理函数
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_ReadMISIData(uint8_t pdrv)
{
    uint16_t count = 0;
    
    if (DLT634_5101Master_App[pdrv].RxdHead < DLT634_5101Master_App[pdrv].RxdTail) // 接收缓冲区中有尚未处理的数据
    {
        if (DLT634_5101Master_App[pdrv].RxdHead != 0)
        {
            memcpy(DLT634_5101Master_App[pdrv].RxdBuf, DLT634_5101Master_App[pdrv].RxdBuf+DLT634_5101Master_App[pdrv].RxdHead, DLT634_5101Master_App[pdrv].RxdTail-DLT634_5101Master_App[pdrv].RxdHead);//将未处理的数据移到缓冲区头
            DLT634_5101Master_App[pdrv].RxdTail -= DLT634_5101Master_App[pdrv].RxdHead;
            DLT634_5101Master_App[pdrv].RxdHead = 0;
        }
    }
    else
    {
        DLT634_5101Master_App[pdrv].RxdHead = 0;
		    DLT634_5101Master_App[pdrv].RxdTail = 0;
    }
    
    count = DLT634_5101_MASTER_ReadData(pdrv,(uint8_t *)&DLT634_5101Master_App[pdrv].RxdBuf[DLT634_5101Master_App[pdrv].RxdTail], _DLT634_5101MASTER_LPDUSIZE);
    if (count > 0)
    {
        DLT634_5101Master_App[pdrv].RxdTail += count;
        DLT634_5101_MASTER_SearchValidFrame(pdrv);
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_WriteDataToMISI
** 功能描述: 发送函数
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Master_App[pdrv]：运行参数结构体
**           DLT634_5101Master_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_MASTER_WriteData  发送函数
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static uint8_t DLT634_5101_MASTER_WriteDataToMISI(uint8_t pdrv)
{
    uint16_t SendLen = 0;
   
    SendLen = DLT634_5101_MASTER_WriteData(pdrv ,DLT634_5101Master_App[pdrv].TxdBuf + DLT634_5101Master_App[pdrv].TxdHead, DLT634_5101Master_App[pdrv].TxdTail - DLT634_5101Master_App[pdrv].TxdHead);

  	DLT634_5101Master_App[pdrv].TimeOutTick_LinkIdle = DLT634_5101Master_Pad[pdrv].LinkIdleValue;
	
    DLT634_5101Master_App[pdrv].TxdHead += SendLen;
    if (DLT634_5101Master_App[pdrv].TxdHead >= DLT634_5101Master_App[pdrv].TxdTail) // 该次任务数据已经发完
    {
        DLT634_5101Master_App[pdrv].TxdHead = 0;
        DLT634_5101Master_App[pdrv].TxdTail = 0;
        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_SlaveFrame10Packet
** 功能描述: 固定帧从动站打包
** 输　  入: pdrv：设备序号
**         : Function  功能码
** 输　  出: 无
** 全局变量: DLT634_5101Master_App[pdrv]：运行参数结构体
**           DLT634_5101Master_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_MASTER_CKS  计算CKS
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_SlaveFrame10Packet(uint8_t pdrv, uint8_t Function)
{
    uint8_t *pBuf;
    uint8_t i = 0;
									
    pBuf = DLT634_5101Master_App[pdrv].TxdBuf + DLT634_5101Master_App[pdrv].TxdTail;
    pBuf[0] = _DLT634_5101MASTER_STARTCODE10;
    pBuf[1] = Function&0x0f;
    pBuf[1] |= DLT634_5101Master_Pad[pdrv].IEC_DIR; // 主站向子站传输

    for (i=0; i<DLT634_5101Master_Pad[pdrv].LinkAddrSize; i++)
    {
        pBuf[2+i] = (DLT634_5101Master_Pad[pdrv].SourceAddr>>(8*i)) & 0xff;
    }

    pBuf[2+DLT634_5101Master_Pad[pdrv].LinkAddrSize] = DLT634_5101_MASTER_CKS(pdrv, pBuf);
    pBuf[3+DLT634_5101Master_Pad[pdrv].LinkAddrSize] = _DLT634_5101MASTER_ENDCODE;
    DLT634_5101Master_App[pdrv].TxdTail += DLT634_5101Master_Pad[pdrv].FixFrmLength;//移动发送尾指针
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_MasterFrame10Packet
** 功能描述: 固定帧启动站打包
** 输　  入: pdrv：设备序号
**         : Function  功能码
** 输　  出: 无
** 全局变量: DLT634_5101Master_App[pdrv]：运行参数结构体
**           DLT634_5101Master_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_MASTER_CKS  计算CKS
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_MasterFrame10Packet(uint8_t pdrv, uint8_t Function)
{
    uint8_t *pBuf;
    uint8_t i = 0;

    pBuf = DLT634_5101Master_App[pdrv].TxdBuf + DLT634_5101Master_App[pdrv].TxdTail;
    pBuf[0] = _DLT634_5101MASTER_STARTCODE10;
    pBuf[1] = Function&0x0f;
    pBuf[1] |= _DLT634_5101MASTER_PRM;
    pBuf[1] |= DLT634_5101Master_Pad[pdrv].IEC_DIR; // 主站向子站传输

    for (i=0; i<DLT634_5101Master_Pad[pdrv].LinkAddrSize; i++)
    {
        pBuf[2+i] = (DLT634_5101Master_Pad[pdrv].SourceAddr>>(8*i)) & 0xff;
    }

    pBuf[2+DLT634_5101Master_Pad[pdrv].LinkAddrSize] = DLT634_5101_MASTER_CKS(pdrv, pBuf);
    pBuf[3+DLT634_5101Master_Pad[pdrv].LinkAddrSize] = _DLT634_5101MASTER_ENDCODE;
    DLT634_5101Master_App[pdrv].TxdTail += DLT634_5101Master_Pad[pdrv].FixFrmLength;//移动发送尾指针

    memcpy(DLT634_5101Master_App[pdrv].TxdBuf_Pri, pBuf, DLT634_5101Master_Pad[pdrv].FixFrmLength); // 将发送数据保存到启动站重发数据区
    DLT634_5101Master_App[pdrv].TxdTail_Pri = DLT634_5101Master_Pad[pdrv].FixFrmLength;
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_Link10Process
** 功能描述: 固定帧发送处理
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Master_App[pdrv]：运行参数结构体
**           DLT634_5101Master_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_MASTER_WriteDataToMISI  发送函数
**           DLT634_5101_MASTER_SlaveFrame10Packet  固定帧从动站打包
**           DLT634_5101_MASTER_MasterFrame10Packet  固定帧启动站打包
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_Link10Process(uint8_t pdrv)
{ 
	if(DLT634_5101Master_App[pdrv].LinkFlag&_DLT634_5101MASTER_REQSTATUS)
	{
		DLT634_5101_MASTER_SlaveFrame10Packet(pdrv, _DLT634_5101MASTER_S_FUN11);
		DLT634_5101_MASTER_WriteDataToMISI(pdrv);
		DLT634_5101Master_App[pdrv].LinkFlag &= (~_DLT634_5101MASTER_REQSTATUS);
		return;
	}
	
	if(DLT634_5101Master_App[pdrv].LinkFlag&_DLT634_5101MASTER_RECONFIRM)
	{
		DLT634_5101_MASTER_SlaveFrame10Packet(pdrv, _DLT634_5101MASTER_S_FUN0);
		DLT634_5101_MASTER_WriteDataToMISI(pdrv);
		DLT634_5101Master_App[pdrv].LinkFlag &= (~_DLT634_5101MASTER_RECONFIRM);
		return;
	}
	
	if((DLT634_5101Master_App[pdrv].LinkFlag&_DLT634_5101MASTER_ASKSTATUS)&&(!(DLT634_5101Master_App[pdrv].LinkFlag&_DLT634_5101MASTER_INITEND)))
	{
		DLT634_5101_MASTER_MasterFrame10Packet(pdrv, _DLT634_5101MASTER_M_FUN9);
		DLT634_5101_MASTER_WriteDataToMISI(pdrv);
		DLT634_5101Master_App[pdrv].LinkFlag &= (~_DLT634_5101MASTER_ASKSTATUS);
		DLT634_5101Master_App[pdrv].TimeOutTick_AskSta = DLT634_5101Master_Pad[pdrv].AskStaOutValue;
		return;
	}
	
	if(DLT634_5101Master_App[pdrv].LinkFlag&_DLT634_5101MASTER_ASKRELINK)
	{
		DLT634_5101_MASTER_MasterFrame10Packet(pdrv, _DLT634_5101MASTER_M_FUN0);
		DLT634_5101_MASTER_WriteDataToMISI(pdrv);
		DLT634_5101Master_App[pdrv].LinkFlag &= (~_DLT634_5101MASTER_ASKRELINK);
		return;
	}	
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_ReadAllDataProcess
** 功能描述: 总召
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
static void DLT634_5101_MASTER_ReadAllDataProcess(uint8_t pdrv)
{
    DLT634_5101Master_App[pdrv].TX_Temp.status.Length = sizeof(DLT634_5101Master_App[pdrv].TX_Temp.status) + sizeof(DLT634_5101Master_App[pdrv].TX_Temp.Head) + sizeof(DLT634_5101Master_App[pdrv].TX_Temp.Data.C_100);
    DLT634_5101Master_App[pdrv].TX_Temp.Head.TypeID = _DLT634_5101MASTER_C_IC_NA_1;
    DLT634_5101Master_App[pdrv].TX_Temp.Head.VSQ = 1;
    DLT634_5101Master_App[pdrv].TX_Temp.Head.COT_L = _DLT634_5101MASTER_COT_ACT;
    DLT634_5101Master_App[pdrv].TX_Temp.Head.PubAddr_H = (uint8_t)((DLT634_5101Master_Pad[pdrv].ASDUAddr>>8)&0xff);
    DLT634_5101Master_App[pdrv].TX_Temp.Head.PubAddr_L = (uint8_t)(DLT634_5101Master_Pad[pdrv].ASDUAddr&0xff);
    DLT634_5101Master_App[pdrv].TX_Temp.Data.C_100.QOI = 20;
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_LinkTestProcess
** 功能描述: 链路测试
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
static void DLT634_5101_MASTER_LinkTestProcess(uint8_t pdrv)
{
    DLT634_5101Master_App[pdrv].TX_Temp.status.Length = sizeof(DLT634_5101Master_App[pdrv].TX_Temp.status) + sizeof(DLT634_5101Master_App[pdrv].TX_Temp.Head) + sizeof(DLT634_5101Master_App[pdrv].TX_Temp.Data.C_104);
    DLT634_5101Master_App[pdrv].TX_Temp.Head.TypeID = _DLT634_5101MASTER_C_TS_NA_1;
    DLT634_5101Master_App[pdrv].TX_Temp.Head.VSQ = 1;
    DLT634_5101Master_App[pdrv].TX_Temp.Head.COT_L = _DLT634_5101MASTER_COT_ACT;
    DLT634_5101Master_App[pdrv].TX_Temp.Head.PubAddr_H = (uint8_t)((DLT634_5101Master_Pad[pdrv].ASDUAddr>>8)&0xff);
    DLT634_5101Master_App[pdrv].TX_Temp.Head.PubAddr_L = (uint8_t)(DLT634_5101Master_Pad[pdrv].ASDUAddr&0xff);
    DLT634_5101Master_App[pdrv].TX_Temp.Data.C_104.FBP_L = 0x55;
    DLT634_5101Master_App[pdrv].TX_Temp.Data.C_104.FBP_H = 0xaa;
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_ReadTime
** 功能描述: 对时
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
static void DLT634_5101_MASTER_ReadTime(uint8_t pdrv)
{
    DLT634_5101Master_App[pdrv].TX_Temp.status.Length = sizeof(DLT634_5101Master_App[pdrv].TX_Temp.status) + sizeof(DLT634_5101Master_App[pdrv].TX_Temp.Head) + sizeof(DLT634_5101Master_App[pdrv].TX_Temp.Data.C_103);
    DLT634_5101Master_App[pdrv].TX_Temp.Head.TypeID = _DLT634_5101MASTER_C_CS_NA_1;
    DLT634_5101Master_App[pdrv].TX_Temp.Head.VSQ = 1;
    DLT634_5101Master_App[pdrv].TX_Temp.Head.COT_L = _DLT634_5101MASTER_COT_REQ;
    DLT634_5101Master_App[pdrv].TX_Temp.Head.PubAddr_H = (uint8_t)((DLT634_5101Master_Pad[pdrv].ASDUAddr>>8)&0xff);
    DLT634_5101Master_App[pdrv].TX_Temp.Head.PubAddr_L = (uint8_t)(DLT634_5101Master_Pad[pdrv].ASDUAddr&0xff);
    DLT634_5101Master_App[pdrv].Devid = 0;
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_Data1Process
** 功能描述: 1级数据发送处理函数
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Master_App[pdrv]：运行参数结构体
**           DLT634_5101Master_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_MASTER_ReadAllDataProcess  总召函数
**           DLT634_5101_MASTER_ReadTime  对时
**           DLT634_5101_SLAVE_R_SOE  SOE读取函数
**           DLT634_5101_MASTER_LinkTestProcess  测试命令
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_Data1Process(uint8_t pdrv)
{ 
    if(DLT634_5101Master_App[pdrv].StoreDATA1OUT != DLT634_5101Master_App[pdrv].StoreDATA1IN)
    {
        memcpy((uint8_t *)&DLT634_5101Master_App[pdrv].TX_Temp, (uint8_t *)DLT634_5101Master_App[pdrv].StoreDATA1OUT, DLT634_5101Master_App[pdrv].StoreDATA1OUT->status.Length);
        memset((uint8_t *)DLT634_5101Master_App[pdrv].StoreDATA1OUT,0,sizeof(DLT634_5101MASTER_PASDU));
        if(++DLT634_5101Master_App[pdrv].StoreDATA1OUT >= DLT634_5101Master_App[pdrv].StoreDATA1Buf + _DLT634_5101MASTER_STOREDATA1NUM)
        {
            DLT634_5101Master_App[pdrv].StoreDATA1OUT = DLT634_5101Master_App[pdrv].StoreDATA1Buf;
        }
        return;
    }		
		
	  if (DLT634_5101Master_App[pdrv].Data1Flag & _DLT634_5101MASTER_CALLALLDATA) // 召唤全数据
    {
        DLT634_5101_MASTER_ReadAllDataProcess(pdrv);
				DLT634_5101Master_App[pdrv].Data1Flag &= (~_DLT634_5101MASTER_CALLALLDATA);
        return;
    }
		
		if ((DLT634_5101Master_App[pdrv].Data1Flag & _DLT634_5101MASTER_READTIME)&&(DLT634_5101Master_App[pdrv].TimeOutTick_Devid == 0)) // 对时
    {
        DLT634_5101_MASTER_ReadTime(pdrv);
				DLT634_5101Master_App[pdrv].Data1Flag &= (~_DLT634_5101MASTER_READTIME);
        return;
    }

	  if (DLT634_5101Master_App[pdrv].Data1Flag & _DLT634_5101MASTER_LINKTEST) // 测试命令
    {
        DLT634_5101_MASTER_LinkTestProcess(pdrv);
				DLT634_5101Master_App[pdrv].Data1Flag &= (~_DLT634_5101MASTER_LINKTEST);
        return;
    }		
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_MasterFrame68Packet
** 功能描述: 可变帧启动站数据打包
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Master_App[pdrv]：运行参数结构体
**           DLT634_5101Master_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_MASTER_CKS  计算CKS
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_MasterFrame68Packet(uint8_t pdrv, uint8_t Function)
{
    uint16_t length = 0;
    uint16_t i = 0;
    uint8_t *pBuf;
    uint8_t ptemp[256];
    
    pBuf = DLT634_5101Master_App[pdrv].TxdBuf + DLT634_5101Master_App[pdrv].TxdTail;

    pBuf[0] = pBuf[3] = _DLT634_5101MASTER_STARTCODE68;
    pBuf[1] = pBuf[2] = DLT634_5101Master_App[pdrv].TX_Temp.status.Length - sizeof(DLT634_5101Master_App[pdrv].TX_Temp.status)+ 1 + 2;
    pBuf[4] = Function&0x0f;
    if(DLT634_5101Master_App[pdrv].SendConCode&_DLT634_5101MASTER_FCB)
    {DLT634_5101Master_App[pdrv].SendConCode = 0;}
    else
    {DLT634_5101Master_App[pdrv].SendConCode = _DLT634_5101MASTER_FCB;}
    pBuf[4] |= _DLT634_5101MASTER_FCV;
    pBuf[4] |= DLT634_5101Master_App[pdrv].SendConCode;
    pBuf[4] |= _DLT634_5101MASTER_PRM;

    for (i = 0; i < 2; i++)
    {
        pBuf[5+i] = ((DLT634_5101Master_Pad[pdrv].SourceAddr >> (8*i)) & 0xff);
    }
		
    memcpy(&pBuf[5+2], &DLT634_5101Master_App[pdrv].TX_Temp.Head, DLT634_5101Master_App[pdrv].TX_Temp.status.Length - sizeof(DLT634_5101Master_App[pdrv].TX_Temp.status));
			
    for (i = 0; i < 2; i++)
    {
        pBuf[11+i] = ((DLT634_5101Master_Pad[pdrv].ASDUAddr >> (8*i)) & 0xff);
    }
		
    length = 6 + pBuf[2]; // 全部报文长度	
    memcpy(&ptemp,pBuf,length);
    if(DLT634_5101Master_Pad[pdrv].LinkAddrSize == 1)
    {
        length--;
        memcpy(&pBuf[6],&ptemp[7],length-3);	
    }
    if(DLT634_5101Master_Pad[pdrv].ASDUCotSize == 1)
    {
        length--;
        memcpy(&pBuf[9],&ptemp[11],length-7);	
    }
    if(DLT634_5101Master_Pad[pdrv].ASDUAddrSize == 1)
    {
        length--;
        memcpy(&pBuf[10],&ptemp[13],length-9);	
    }
    pBuf[length-2] = DLT634_5101_MASTER_CKS(pdrv, pBuf)&0xFF;
    pBuf[length-1] = _DLT634_5101MASTER_ENDCODE;
    DLT634_5101Master_App[pdrv].TxdTail += length;

    memcpy(DLT634_5101Master_App[pdrv].TxdBuf_Pri, pBuf, length);
    DLT634_5101Master_App[pdrv].TxdTail_Pri = length;
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_Link68Process
** 功能描述: 可变帧发送函数
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Master_App[pdrv]：运行参数结构体
**           DLT634_5101Master_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_MASTER_MasterFrame68Packet  可变帧启动站打包
**           DLT634_5101_MASTER_WriteDataToMISI  数据发送函数
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_Link68Process(uint8_t pdrv)
{
    if(DLT634_5101Master_App[pdrv].TX_Temp.status.Length)
    {
        DLT634_5101_MASTER_MasterFrame68Packet(pdrv, _DLT634_5101MASTER_M_FUN3);
        DLT634_5101_MASTER_WriteDataToMISI(pdrv);
        DLT634_5101Master_App[pdrv].TimeOutTick_Pri = DLT634_5101Master_Pad[pdrv].TimeOutValue;
        DLT634_5101Master_App[pdrv].RetryCount  = _DLT634_5101MASTER_NUMOF_MAXRETRY;
        DLT634_5101Master_App[pdrv].LinkFlag &= (~_DLT634_5101MASTER_SENDABLE);
        memset((uint8_t *)&DLT634_5101Master_App[pdrv].TX_Temp,0,sizeof(DLT634_5101MASTER_PASDU));
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_SendProcess
** 功能描述: 发送处理区
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Master_App[pdrv]：运行参数结构体
**           DLT634_5101Master_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_MASTER_Link10Process  固定帧发送数据函数
**           DLT634_5101_MASTER_Data1Process  1级数据发送数据函数
**           DLT634_5101_MASTER_Link68Process  可变帧发送函数
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
static void DLT634_5101_MASTER_SendProcess(uint8_t pdrv)
{   	
    if(DLT634_5101Master_App[pdrv].LinkFlag&0x000000ff)
    {
        DLT634_5101_MASTER_Link10Process(pdrv);
        return;
    }
    

    if((DLT634_5101Master_App[pdrv].LinkFlag&_DLT634_5101MASTER_SENDABLE)&&(DLT634_5101Master_App[pdrv].LinkFlag&_DLT634_5101MASTER_INITEND))
    {
        DLT634_5101_MASTER_Data1Process(pdrv);
        DLT634_5101_MASTER_Link68Process(pdrv);
        return;
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_LinkOnTimer
** 功能描述: 链路层定时器处理区
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Master_App[pdrv]：运行参数结构体
**           DLT634_5101Master_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_MASTER_WriteDataToMISI  发送数据函数
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
void DLT634_5101_MASTER_LinkOnTimer(uint8_t pdrv)
{
    if(DLT634_5101Master_App[pdrv].TimeOutTick_Devid)
    {DLT634_5101Master_App[pdrv].TimeOutTick_Devid--;}
		
    if (DLT634_5101Master_App[pdrv].TimeOutTick_Pri) // 单位是秒
    {
        DLT634_5101Master_App[pdrv].TimeOutTick_Pri--;
        if (!DLT634_5101Master_App[pdrv].TimeOutTick_Pri)
        {
            if (!DLT634_5101Master_App[pdrv].RetryCount)
            {
                    return;
            }

            DLT634_5101Master_App[pdrv].RetryCount--;
            if (DLT634_5101Master_App[pdrv].RetryCount)
            {
                memcpy(DLT634_5101Master_App[pdrv].TxdBuf + DLT634_5101Master_App[pdrv].TxdTail, DLT634_5101Master_App[pdrv].TxdBuf_Pri, DLT634_5101Master_App[pdrv].TxdTail_Pri);
                DLT634_5101Master_App[pdrv].TxdTail += DLT634_5101Master_App[pdrv].TxdTail_Pri;

                DLT634_5101_MASTER_WriteDataToMISI(pdrv);
                DLT634_5101Master_App[pdrv].TimeOutTick_Pri = DLT634_5101Master_Pad[pdrv].TimeOutValue;
                return;
            }
            else // 超过重发次数后，重新建立链路，并通知应用层。
            {
                DLT634_5101Master_App[pdrv].LinkFlag = 0;
            }
        }
    }	

    if (!DLT634_5101Master_App[pdrv].TimeOutTick_LinkIdle)
    {
        DLT634_5101Master_App[pdrv].TimeOutTick_LinkIdle = DLT634_5101Master_Pad[pdrv].LinkIdleValue;
        DLT634_5101Master_App[pdrv].LinkFlag = 0;
    }
    else
    {
        DLT634_5101Master_App[pdrv].TimeOutTick_LinkIdle--;
    }
    
    if(!(DLT634_5101Master_App[pdrv].LinkFlag&_DLT634_5101MASTER_INITEND))
    {
        if (!DLT634_5101Master_App[pdrv].TimeOutTick_AskSta)
        {
            DLT634_5101Master_App[pdrv].LinkFlag |= _DLT634_5101MASTER_ASKSTATUS;
        }
        else
        {
            DLT634_5101Master_App[pdrv].TimeOutTick_AskSta--;
        }
    }
    
    if(DLT634_5101Master_App[pdrv].LinkFlag&_DLT634_5101MASTER_INITEND)
    {
        if (!DLT634_5101Master_App[pdrv].TimeOutTick_AllData)
        {
            DLT634_5101Master_App[pdrv].TimeOutTick_AllData = DLT634_5101Master_Pad[pdrv].AllDataOutValue;
            DLT634_5101Master_App[pdrv].Data1Flag |= _DLT634_5101MASTER_CALLALLDATA;
        }
        else
        {
            DLT634_5101Master_App[pdrv].TimeOutTick_AllData--;
        }
        
        if (!DLT634_5101Master_App[pdrv].TimeOutTick_LinkTest)
        {
            DLT634_5101Master_App[pdrv].TimeOutTick_LinkTest = DLT634_5101Master_Pad[pdrv].LinkTestValue;
            DLT634_5101Master_App[pdrv].Data1Flag |= _DLT634_5101MASTER_LINKTEST;
        }
        else
        {
            DLT634_5101Master_App[pdrv].TimeOutTick_LinkTest--;
        }
    }
}

/* PUBLIC FUNCTION PROTOTYPES -----------------------------------------------*/
/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_REPLY
** 功能描述: 其他设备应答处理
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Master_App[pdrv]：运行参数结构体
**         : DLT634_5101Master_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_MASTER_StoreIN  发送缓冲区堆栈
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
uint8_t DLT634_5101_MASTER_REPLY(uint8_t pdrv, uint8_t *pbuf)//回复
{ 
	uint8_t res = FALSE;
	
	memcpy(&DLT634_5101Master_App[pdrv].ST_Temp, pbuf,_DLT634_5101MASTER_LPDUSIZE);
	
	if(((DLT634_5101Master_App[pdrv].TimeOutTick_Devid == 0)||(DLT634_5101Master_App[pdrv].Devid == (DLT634_5101Master_App[pdrv].ST_Temp.status.symbol.Lock_ID))
		||(DLT634_5101Master_App[pdrv].StoreDATA1OUT == DLT634_5101Master_App[pdrv].StoreDATA1IN))&&(DLT634_5101Master_App[pdrv].LinkFlag&_DLT634_5101MASTER_INITEND))
	{
		DLT634_5101Master_App[pdrv].TimeOutTick_Devid = DLT634_5101Master_Pad[pdrv].DevidValue;
		DLT634_5101Master_App[pdrv].Devid = DLT634_5101Master_App[pdrv].ST_Temp.status.symbol.Lock_ID;
	}
	else
	{
		return(res);
	}
	
	switch (DLT634_5101Master_App[pdrv].ST_Temp.Head.TypeID)
	{
        //控制方向过程信息
        case _DLT634_5101MASTER_C_IC_NA_1: // 总召
            res = DLT634_5101_MASTER_StoreIN(pdrv,&DLT634_5101Master_App[pdrv].ST_Temp);
            break;
        
        case _DLT634_5101MASTER_C_SC_NA_1: // 单点遥控命令
        case _DLT634_5101MASTER_C_SC_NB_1: // 双点遥控命令
            res = DLT634_5101_MASTER_StoreIN(pdrv,&DLT634_5101Master_App[pdrv].ST_Temp);
            break;

        case _DLT634_5101MASTER_C_CS_NA_1: // 对时命令
            res = DLT634_5101_MASTER_StoreIN(pdrv,&DLT634_5101Master_App[pdrv].ST_Temp);
            break;

        case _DLT634_5101MASTER_C_RP_NA_1: // 复位进程命令
            break;
        
        case _DLT634_5101MASTER_C_RR_NA_1: // 读定值区号
        case _DLT634_5101MASTER_C_RS_NA_1: // 读参数和定值命令
            res = DLT634_5101_MASTER_StoreIN(pdrv,&DLT634_5101Master_App[pdrv].ST_Temp);
            break;
        
        case _DLT634_5101MASTER_C_SR_NA_1: // 切换定值区
        case _DLT634_5101MASTER_C_WS_NA_1: // 写参数和定值命令
            res = DLT634_5101_MASTER_StoreIN(pdrv,&DLT634_5101Master_App[pdrv].ST_Temp);
            break;

        case _DLT634_5101MASTER_F_FR_NA_1: // 文件传输
            res = DLT634_5101_MASTER_StoreIN(pdrv,&DLT634_5101Master_App[pdrv].ST_Temp);
            break;

        case _DLT634_5101MASTER_F_SR_NA_1: // 软件升级
            res = DLT634_5101_MASTER_StoreIN(pdrv,&DLT634_5101Master_App[pdrv].ST_Temp);
            break;			

        default: // 类型标识有错误或不支持
            break;
	}
	return(res);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_Clock
** 功能描述: 定时处理函数
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: DLT634_5101Master_App[pdrv]：运行参数结构体
**           DLT634_5101Master_Pad[pdrv]：设定参数结构体
** 调用模块: DLT634_5101_MASTER_ReadMISIData  查询MISI接收缓冲区
**           DLT634_5101_MASTER_SendProcess  发送处理区
**           DLT634_5101_MASTER_LinkOnTimer  链路层定时器处理区
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
void DLT634_5101_MASTER_Clock(uint8_t pdrv)
{
	DLT634_5101Master_App[pdrv].ClockCounter++;
	if (DLT634_5101Master_App[pdrv].ClockCounter >= DLT634_5101Master_Pad[pdrv].ClockTimers)
	{
        DLT634_5101Master_App[pdrv].ClockCounter = 0;
                                            
        // 查询MISI接收缓冲区
        DLT634_5101_MASTER_ReadMISIData(pdrv);
    
        DLT634_5101_MASTER_SendProcess(pdrv);
            
        // 链路层定时器
        DLT634_5101_MASTER_LinkOnTimer(pdrv);
	}
}



