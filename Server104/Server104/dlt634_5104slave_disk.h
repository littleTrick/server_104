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
    DLT634_5104_NET1_ID = 0,
}DLT634_5104_DISK;

/* PUBLIC VARIABLES ----------------------------------------------------------*/

/* PUBLIC FUNCTION -----------------------------------------------------------*/
extern void DLT634_5104_SlaveTask(void* arg);
extern bool DLT634_5104_SLAVE_C_REPLY(BYTE drvid, BYTE *pbuf);
extern WORD DLT634_5104_SLAVE_ReadData(BYTE port, BYTE *pbuf, WORD count);
extern WORD DLT634_5104_SLAVE_WriteData(BYTE port, BYTE *pbuf, WORD count);
extern BYTE DLT634_5104_SLAVE_StopLink(BYTE pdrv);
extern BYTE DLT634_5104_SLAVE_CheckLink(BYTE pdrv);

extern void DLT634_5104_SLAVE_ReadYxData(BYTE port, WORD addr, WORD num, BYTE *pbuf);
extern void DLT634_5104_SLAVE_ReadYcData(BYTE port, WORD addr, WORD num, BYTE *pbuf);
extern void DLT634_5104_SLAVE_HandleCtrlProcess(BYTE port, BYTE *pbuf);
extern void DLT634_5104_SLAVE_SYNProcess(BYTE port, BYTE *pbuf);
extern void DLT634_5104_SLAVE_FixedParaProcess(BYTE port, BYTE *pbuf);
extern void DLT634_5104_SLAVE_FileHandleProcess(BYTE port, BYTE *pbuf);
extern BYTE DLT634_5104_SLAVE_H_SOE(BYTE pdrv);
extern void DLT634_5104_SLAVE_R_SOE(BYTE pdrv, BYTE *pbuf);
extern BYTE DLT634_5104_SLAVE_H_NVA(BYTE pdrv);
extern void DLT634_5104_SLAVE_R_NVA(BYTE pdrv, BYTE *pbuf);
extern BYTE DLT634_5104_SLAVE_H_FEvent(BYTE pdrv);
extern void DLT634_5104_SLAVE_R_FEvent(BYTE pdrv, BYTE *pbuf);

extern void DLT634_5104_SlaveInit();

#ifdef __cplusplus
}
#endif

#endif /* END _DLT634_5104SLAVE_APP_H_*/
    

/* END OF FILE ---------------------------------------------------------------*/

