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
** File name:               dlt634_5104slave_app.h
** Descriptions:            The application layer of DL/T634.5104_2002
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
#ifndef	_DLT634_5104SLAVE_APP_H_
#define _DLT634_5104SLAVE_APP_H_

#ifdef __cplusplus
extern "C"{
#endif

/* INCLUDE FILES -------------------------------------------------------------*/
#include "string.h"
#include "integer.h"
#include "stdbool.h"
#include "dlt634_5104slave_disk.h"
#include "dlt634_5104slave_app.h"

/* DEFINE --------------------------------------------------------------------*/

/* Enum ----------------------------------------------------------------------*/
typedef enum
{
    DLT634_5104_NET1_ID = 0 //104内部网络端口１
}DLT634_5104_DISK;

typedef enum
{

    NET1_ID = 0,     //数据缓存识别网络端口１
    NULL_ID,
    USART6_ID


}DEVICE_ID;
/* PUBLIC VARIABLES ----------------------------------------------------------*/

/* PUBLIC FUNCTION -----------------------------------------------------------*/
extern void DLT634_5104_SlaveTask(void* arg);
extern bool DLT634_5104_SLAVE_C_REPLY(unsigned char drvid, unsigned char *pbuf);
extern WORD DLT634_5104_SLAVE_ReadData(unsigned char port, unsigned char *pbuf, WORD count);
extern WORD DLT634_5104_SLAVE_WriteData(unsigned char port, unsigned char *pbuf, WORD count);
extern unsigned char DLT634_5104_SLAVE_StopLink(unsigned char pdrv);
extern unsigned char DLT634_5104_SLAVE_CheckLink(unsigned char pdrv);

extern void DLT634_5104_SLAVE_ReadYxData(unsigned char port, WORD addr, WORD num, unsigned char *pbuf);
extern void DLT634_5104_SLAVE_ReadYcData(unsigned char port, WORD addr, WORD num, unsigned char *pbuf);
extern void DLT634_5104_SLAVE_HandleCtrlProcess(unsigned char port, unsigned char *pbuf);
extern void DLT634_5104_SLAVE_SYNProcess(unsigned char port, unsigned char *pbuf);
extern void DLT634_5104_SLAVE_FixedParaProcess(unsigned char port, unsigned char *pbuf);
extern void DLT634_5104_SLAVE_FileHandleProcess(unsigned char port, unsigned char *pbuf);
extern unsigned char DLT634_5104_SLAVE_H_SOE(unsigned char pdrv);
extern void DLT634_5104_SLAVE_R_SOE(unsigned char pdrv, unsigned char *pbuf);
extern unsigned char DLT634_5104_SLAVE_H_NVA(unsigned char pdrv);
extern void DLT634_5104_SLAVE_R_NVA(unsigned char pdrv, unsigned char *pbuf);
extern unsigned char DLT634_5104_SLAVE_H_FEvent(unsigned char pdrv);
extern void DLT634_5104_SLAVE_R_FEvent(unsigned char pdrv, unsigned char *pbuf);

extern void DLT634_5104_SlaveInit();
extern int getClientFd();
extern void setClientFd(int);

#ifdef __cplusplus
}
#endif

#endif /* END _DLT634_5104SLAVE_APP_H_*/
    

/* END OF FILE ---------------------------------------------------------------*/

