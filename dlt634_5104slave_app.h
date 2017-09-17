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
** File name:               dlt634_5104slave_link.h
** Descriptions:            The application layer of DL/T634.5104_2002
**
** -----------------------------------------------------------------------------
** Created by:              Mr.Sun
** Created date:            2017.07.11
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
#ifndef    _DLT634_5104SLAVE_LINK_H_
#define _DLT634_5104SLAVE_LINK_H_

#ifdef __cplusplus
extern "C"{
#endif


/* INCLUDE FILES -------------------------------------------------------------*/
#include "integer.h"
#include "dlt634_5104slave_config.h"

#ifndef  FALSE
#define  FALSE     0
#define  TRUE      !FALSE
#endif

/* PUBLIC VARIABLE -----------------------------------------------------------*/

/* DEFINE --------------------------------------------------------------------*/

/* 链路层接收状态 */

/* Struct  -------------------------------------------------------------------*/
struct DLT634_5104SLAVE_AppMsg
{
    unsigned short Cmd;
    unsigned short ConNum;
    unsigned char Len;
    unsigned char* pData;
};

struct DLT634_5104SLAVE_PAD
{
    unsigned char   Port;            //端口
    
    unsigned char   CotSize;      // 传输原因字节长度
    unsigned char   PubAddrSize;  // 链路公共地址字节长度
    unsigned char   LinkAddrSize; // 链路地址占用字节  
    unsigned char   InfoAddrSize; // 信息体地址字节长度

    unsigned short  YCNum;        // 遥测量总数
    unsigned short  YXNum;        // 遥信量总数
    unsigned short  YKNum;        // 遥控量总数
    unsigned short  DDNum;        // 电度量总数

    unsigned short  LinkAddress;  // 链路地址,链路地址可与公共地址相同
    unsigned short  PubAddress;   // 公共地址，可与链路地址相同，即：同一链路上的设备(子站)地址

    unsigned short  YX_AllNum;    // 遥信总数
    unsigned short  YX_FirstAddr; // 遥信首地址
    unsigned short  YX_FrameNum;    // 遥信每组数量
    unsigned short  YC_AllNum;        // 遥测总数
    unsigned short  YC_FirstAddr; // 遥信首地址
    unsigned short  YC_FrameNum;  // 遥测每组数量
    
    unsigned short  TickValue[4]; // IEC104 4个延时时钟
    unsigned long   ClockTimers;  // 调用超出次数，程序执行一次，控制运行周期
};
/* PUBLIC VARIABLES ----------------------------------------------------------*/
extern struct DLT634_5104SLAVE_PAD DLT634_5104Slave_Pad[DLT634_5104SLAVE_VOLUMES]; // DL/T634_5101规约参数

/* PUBLIC FUNCTION DECLARATION -----------------------------------------------*/
extern void DLT634_5104_SLAVE_Clock(BYTE port);
extern BYTE DLT634_5104_SLAVE_AppInit(BYTE port);
extern void DLT634_5104_SLAVE_ParaInit(BYTE port);
extern BYTE DLT634_5104_SLAVE_Reply(BYTE pdrv, BYTE *pbuf);

#ifdef __cplusplus
}
#endif

#endif /* END _DLT634_5104SLAVE_LINK_H_*/

/* END OF FILE ---------------------------------------------------------------*/


