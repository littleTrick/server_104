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
** File name:               dlt634_5101slave_disk.h
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
#ifndef	_DLT634_5101SLAVE_DISK_H_
#define _DLT634_5101SLAVE_DISK_H_

#ifdef __cplusplus
extern "C"{
#endif

/* INCLUDE FILES -------------------------------------------------------------*/
#include <stdint.h>

/* PUBLIC FUNCTION DECLARATION -----------------------------------------------*/
extern uint16_t DLT634_5101_SLAVE_ReadData(uint8_t pdrv, uint8_t *pbuf, uint16_t count);
extern uint16_t DLT634_5101_SLAVE_WriteData(uint8_t pdrv, uint8_t *pbuf, uint16_t count);

extern void DLT634_5101_SLAVE_C_IC(uint8_t pdrv, uint8_t *pbuf);
extern void DLT634_5101_SLAVE_C_SC(uint8_t pdrv, uint8_t *pbuf);
extern void DLT634_5101_SLAVE_C_CS(uint8_t pdrv, uint8_t *pbuf);
extern void DLT634_5101_SLAVE_C_SR(uint8_t pdrv, uint8_t *pbuf);
extern void DLT634_5101_SLAVE_F_FR(uint8_t pdrv, uint8_t *pbuf);
extern void DLT634_5101_SLAVE_F_SR(uint8_t pdrv, uint8_t *pbuf);
extern uint8_t DLT634_5101_SLAVE_H_SOE(uint8_t pdrv);
extern void DLT634_5101_SLAVE_R_SOE(uint8_t pdrv, uint8_t *pbuf);
extern uint8_t DLT634_5101_SLAVE_H_NVA(uint8_t pdrv);
extern void DLT634_5101_SLAVE_R_NVA(uint8_t pdrv, uint8_t *pbuf);
extern uint8_t DLT634_5101_SLAVE_H_FEvent(uint8_t pdrv);
extern void DLT634_5101_SLAVE_R_FEvent(uint8_t pdrv, uint8_t *pbuf);
extern void DLT634_5101_SLAVE_R_YXDATA(uint8_t pdrv,uint16_t addr,uint16_t num, uint8_t *pbuf);
extern void DLT634_5101_SLAVE_R_YCDATA(uint8_t pdrv,uint16_t addr,uint16_t num, uint8_t *pbuf);
extern uint8_t DLT634_5101_SLAVE_C_REPLY(uint8_t drvid,uint8_t *pbuf);

extern void DLT634_5101_SlaveTask();
extern int getMasterSPfd();
extern void setMasterSPfd(int );

#ifdef __cplusplus
}
#endif

#endif /* END _DLT634_5101_APP_H_ */
    

/* END OF FILE ---------------------------------------------------------------*/
