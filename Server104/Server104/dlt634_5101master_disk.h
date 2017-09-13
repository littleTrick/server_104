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
** File name:               dlt634_5101master_disk.h
** Descriptions:            The application layer of DL/T634.5101_2002
**
** -----------------------------------------------------------------------------
** Created by:              Mr.j
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
#ifndef	_DLT634_5101MASTER_DISK_H_
#define _DLT634_5101MASTER_DISK_H_

#ifdef __cplusplus
extern "C"{
#endif

/* INCLUDE FILES -------------------------------------------------------------*/
#include <stdint.h>
#include "string.h"
//#include "sys.h"



/* PUBLIC VARIABLE -----------------------------------------------------------*/

//typedef enum
//{
//    MASTER_101_DEV0 = 0 //底层串口设备０
//}DLT634_5101_DISK;


/* PUBLIC FUNCTION DECLARATION -----------------------------------------------*/
extern uint16_t DLT634_5101_MASTER_ReadData(uint8_t pdrv, uint8_t *pbuf, uint16_t count);
extern uint16_t DLT634_5101_MASTER_WriteData(uint8_t pdrv, uint8_t *pbuf, uint16_t count);
extern void DLT634_5101_MASTER_C_SC(uint8_t pdrv, uint8_t *pbuf);
extern void DLT634_5101_MASTER_C_SR(uint8_t pdrv, uint8_t *pbuf);
extern void DLT634_5101_MASTER_C_CS(uint8_t pdrv, uint8_t *pbuf);
extern void DLT634_5101_MASTER_F_FR(uint8_t pdrv, uint8_t *pbuf);
extern void DLT634_5101_MASTER_F_SR(uint8_t pdrv, uint8_t *pbuf);
extern void DLT634_5101_MASTER_W_YXDATA(uint8_t pdrv, uint8_t *pbuf);
extern void DLT634_5101_MASTER_W_YCDATA(uint8_t pdrv, uint8_t *pbuf);
extern void DLT634_5101_MASTER_W_SOE(uint8_t pdrv, uint8_t *pbuf);
extern void DLT634_5101_MASTER_W_FEvent(uint8_t pdrv, uint8_t *pbuf);
extern uint8_t DLT634_5101_MASTER_C_REPLY(uint8_t drvid,uint8_t *pbuf);


//extern void DLT634_5101_MasterTask(void* arg);
extern void DLT634_5101_MasterTask();
extern int getSerialFd();
extern void setSerialFd(int );

#ifdef __cplusplus
}
#endif

#endif /* END _DLT634_5101_APP_H_ */
    

/* END OF FILE ---------------------------------------------------------------*/
