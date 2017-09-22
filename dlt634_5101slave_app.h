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
** File name:               dlt634_5101slave_app.h
** Descriptions:            The application layer of DL/T634.5101_2002
**
** -----------------------------------------------------------------------------
** Created by:              Mr.Lee
** Created date:            2015.10.25
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
#ifndef	_DLT634_5101SLAVE_APP_H_
#define _DLT634_5101SLAVE_APP_H_

#ifdef __cplusplus
extern "C"{
#endif

/* INCLUDE FILES -------------------------------------------------------------*/
#include <stdint.h>
#include "dlt634_5101slave_config.h"

#ifndef  FALSE
#define  FALSE     0
#define  TRUE      !FALSE
#endif

/* PUBLIC VARIABLE -----------------------------------------------------------*/

typedef struct 
{
	uint8_t Port;            //端口
	uint8_t BalanMode;	    	// 1平衡，0非平衡
	uint8_t IEC_DIR;         // 终端0x80,主站0x00
	
	uint8_t SourceAddr;	    // 源地址，即本机地址
	
	uint8_t LinkAddrSize;   //链路地址长度
	uint8_t ASDUCotSize;    //传送原因长度
	
	uint8_t ASDUAddr;       //ASDU地址
	uint8_t ASDUAddrSize;    //ASDU地址长度
	uint8_t FixFrmLength;		//固定帧长度
	
	uint32_t ClockTimers;		//调用超出次数，程序执行一次，控制运行周期
	uint32_t TimeOutValue;		//超时重发间隔
	uint32_t AskStaOutValue; //链路请求间隔
	
	uint16_t YX_AllNum;       //遥信总数
	uint16_t YX_FIRSTADDR;    //遥信首地址
	uint16_t YX_FrameNum;			//遥信每组数量
	uint16_t YC_AllNum;				//遥测总数
	uint16_t YC_FIRSTADDR;    //遥信首地址
	uint16_t YC_FrameNum;			//遥测每组数量
	
}DLT634_5101SLAVE_PAD;

extern DLT634_5101SLAVE_PAD      DLT634_5101Slave_Pad[_DLT634_5101SLAVE_VOLUMES];

/* PUBLIC FUNCTION DECLARATION -----------------------------------------------*/
extern uint8_t DLT634_5101_SLAVE_REPLY(uint8_t pdrv, uint8_t *pbuf);
extern void DLT634_5101_SLAVE_Clock(uint8_t pdrv);

#ifdef __cplusplus
}
#endif

#endif /* END _DLT634_5101_APP_H_ */
    

/* END OF FILE ---------------------------------------------------------------*/


