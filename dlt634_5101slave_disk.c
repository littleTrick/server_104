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
** File name:               DLT634_5101_disk_uart6.c
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

//#if APP_TASK_DLT634_5101_SLAVE_CFG

#include "dlt634_5101slave_app.h"
#include "dlt634_5101slave_disk.h"
#include "data_cache.h"
#include "types.h"

static int s_masterSPfd;

/* PRIVATE FUNCTION PROTOTYPES -----------------------------------------------*/

/* PUBLIC FUNCTION PROTOTYPES -----------------------------------------------*/
int getMasterSPfd()
{
    return s_masterSPfd;
}

void setMasterSPfd(int serialfd)
{
    s_masterSPfd = serialfd;
}
/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_ReadData
** 功能描述: 读数据
** 输　  入: pdrv：设备序号
**           pbuf：数据内容指针
**           count：读数量
** 输　  出: 无
** 全局变量: 
** 调用模块: Readx  向底层读数据
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
uint16_t DLT634_5101_SLAVE_ReadData(uint8_t pdrv, uint8_t *pbuf, uint16_t count)
{ 
	uint16_t len = 0;  
	
	switch(pdrv)
	{
		case 0:
			len = Readx(pbuf, count, DLT634_5101Slave_Pad[pdrv].Port);
			break;
		default:
			break;
	}
	return(len);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_WriteData
** 功能描述: 写数据
** 输　  入: pdrv：设备序号
**           pbuf：数据内容指针
**           count：写数量
** 输　  出: 无
** 全局变量: 
** 调用模块: WriteX  向底层写数据
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
uint16_t DLT634_5101_SLAVE_WriteData(uint8_t pdrv, uint8_t *pbuf, uint16_t count)
{ 
	uint16_t len = 0; 
	
	switch(pdrv)
	{
		case 0:
			len = WriteX(pbuf,count,DLT634_5101Slave_Pad[pdrv].Port);
			break;
		default:
			break;
	}
	return(len);
}

//app
/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_C_IC
** 功能描述: 总召
** 输　  入: pdrv：设备序号
**           pbuf：数据内容指针
** 输　  出: 无
** 全局变量: 
** 调用模块: DBSend  发送给其他设备函数
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/QOI
void DLT634_5101_SLAVE_C_IC(uint8_t pdrv, uint8_t *pbuf)//总召
{ 
	switch(pdrv)
	{
		case 0:
            pbuf[1] = (DLT634_5101Slave_Pad[pdrv].Port<<4)|USART1_ID; //send to 101master serial device ,MASTER_101_DEV0;
			DBSend(pbuf);
			break;
		default:
			break;
	}
}
/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_C_SC
** 功能描述: 遥控
** 输　  入: pdrv：设备序号
**           pbuf：数据内容指针
** 输　  出: 无
** 全局变量: 
** 调用模块: DBSend  发送给其他设备函数
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/SCO_L/SCO_H
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/DCO_L/DCO_H
void DLT634_5101_SLAVE_C_SC(uint8_t pdrv, uint8_t *pbuf)//遥控
{ 
	switch(pdrv)
	{
		case 0:
            pbuf[1] = (DLT634_5101Slave_Pad[pdrv].Port<<4)|USART1_ID;//MASTER_101_DEV0;
			DBSend(pbuf);
			break;
		default:
			break;
	}
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_C_CS
** 功能描述: 对时
** 输　  入: pdrv：设备序号
**           pbuf：数据内容指针
** 输　  出: 无
** 全局变量: 
** 调用模块: DBSend  发送给其他设备函数
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/CP56Time2a
void DLT634_5101_SLAVE_C_CS(uint8_t pdrv, uint8_t *pbuf)//对时
{ 
	switch(pdrv)
	{
		case 0:
            pbuf[1] = (DLT634_5101Slave_Pad[pdrv].Port<<4)|USART1_ID;//MASTER_101_DEV0;
			DBSend(pbuf);
			break;
		default:
			break;
	}
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_C_SR
** 功能描述: 定值参数
** 输　  入: pdrv：设备序号
**           pbuf：数据内容指针
** 输　  出: 无
** 全局变量: 
** 调用模块: DBSend  发送给其他设备函数
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/SN_L/SN_H
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/SN1_L/SN1_H/SN2_L/SN2_H/SN3_L/SN3_H
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/SN1_L/SN1_H/Array
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/SN_L/SN_H/PI_L/PI_H//Array(InfoAddr_L/InfoAddr_H/Tag/Len/Value)
void DLT634_5101_SLAVE_C_SR(uint8_t pdrv, uint8_t *pbuf)//定值参数
{ 
//	switch(pdrv)
//	{
//		case 0:
//			pbuf[1] = (DLT634_5101Slave_Pad[pdrv].Port<<4)|MASTER_101_DEV0;
//			DBSend(pbuf);
//			break;
//		default:
//			break;
//	}
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_F_FR
** 功能描述: 文件读写
** 输　  入: pdrv：设备序号
**           pbuf：数据内容指针
** 输　  出: 无
** 全局变量: 
** 调用模块: DBSend  发送给其他设备函数
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/sty/Array
void DLT634_5101_SLAVE_F_FR(uint8_t pdrv, uint8_t *pbuf)//文件读写
{ 
//	switch(pdrv)
//	{
//		case 0:
//			if(pbuf[11]>=7)//写文件
//			{
//				pbuf[1] = (DLT634_5101Slave_Pad[pdrv].Port<<4)|MASTER_101_DEV0;
//				DBSend(pbuf);
//			}
//			else//读文件
//			{
//				pbuf[1] = (DLT634_5101Slave_Pad[pdrv].Port<<4)|STORAGE_DEV0;
//				DBSend(pbuf);
//			}
//			break;
//		default:
//			break;
//	}
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_F_SR
** 功能描述: 软件升级
** 输　  入: pdrv：设备序号
**           pbuf：数据内容指针
** 输　  出: 无
** 全局变量: 
** 调用模块: DBSend  发送给其他设备函数
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/CTYPE
void DLT634_5101_SLAVE_F_SR(uint8_t pdrv, uint8_t *pbuf)//软件升级
{ 
//	switch(pdrv)
//	{
//		case 0:
//			pbuf[1] = (DLT634_5101Slave_Pad[pdrv].Port<<4)|MASTER_101_DEV0;
//			DBSend(pbuf);
//			break;
//		default:
//			break;
//	}
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_H_SOE
** 功能描述: 判断是否有soe
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: 
** 调用模块: DBCheck_SOE  判断是否有SOE
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
uint8_t DLT634_5101_SLAVE_H_SOE(uint8_t pdrv)//判断是否有soe
{ 
	switch(pdrv)
	{
		case 0:
			return(DBCheck_SOE(DLT634_5101Slave_Pad[pdrv].Port));
		default:
			break;
	}
	return(FALSE);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_R_SOE
** 功能描述: 读soe
** 输　  入: pdrv：设备序号
**         : pbuf：数据指针
** 输　  出: 无
** 全局变量: 
** 调用模块: DBRead_SOE  读SOE
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/Array(InfoAddr_L/InfoAddr_H/Value/CP56Time2a)
void DLT634_5101_SLAVE_R_SOE(uint8_t pdrv, uint8_t *pbuf)//读soe
{ 
	switch(pdrv)
	{
		case 0:
			DBRead_SOE(DLT634_5101Slave_Pad[pdrv].Port,pbuf);
			break;
		default:
			break;
	}
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_H_NVA
** 功能描述: 判断是否有NVA
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: 
** 调用模块: DBCheck_NVA  判断是否有NVA
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
uint8_t DLT634_5101_SLAVE_H_NVA(uint8_t pdrv)//判断是否有NVA
{ 
	switch(pdrv)
	{
		case 0:
			return(DBCheck_NVA(DLT634_5101Slave_Pad[pdrv].Port));
		default:
			break;
	}
	return(FALSE);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_R_NVA
** 功能描述: 读NVA
** 输　  入: pdrv：设备序号
**         : pbuf：数据指针
** 输　  出: 无
** 全局变量: 
** 调用模块: DBRead_NVA  读变化遥测
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/Array(InfoAddr_L/InfoAddr_H/Value/QDS)
void DLT634_5101_SLAVE_R_NVA(uint8_t pdrv, uint8_t *pbuf)//读NVA
{ 
	switch(pdrv)
	{
		case 0:
			DBRead_NVA(DLT634_5101Slave_Pad[pdrv].Port,pbuf);
			break;
		default:
			break;
	}
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_H_FEvent
** 功能描述: 判断是否有FEvent
** 输　  入: pdrv：设备序号
** 输　  出: 无
** 全局变量: 
** 调用模块: DBCheck_FEvent  判断是否有故障事件
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
uint8_t DLT634_5101_SLAVE_H_FEvent(uint8_t pdrv)//判断是否有FEvent
{ 
//	switch(pdrv)
//	{
//		case 0:
//			return(DBCheck_FEvent(DLT634_5101Slave_Pad[pdrv].Port));
//		default:
//			break;
//	}
//	return(FALSE);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_R_FEvent
** 功能描述: 读FEvent
** 输　  入: pdrv：设备序号
**         : pbuf：数据指针
** 输　  出: 无
** 全局变量: 
** 调用模块: DBRead_FEvent  读故障事件
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/Array
void DLT634_5101_SLAVE_R_FEvent(uint8_t pdrv, uint8_t *pbuf)//读FEvent
{ 
//	switch(pdrv)
//	{
//		case 0:
//			DBRead_FEvent(DLT634_5101Slave_Pad[pdrv].Port,pbuf);
//			break;
//		default:
//			break;
//	}
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_R_YXDATA
** 功能描述: 读YXDATA
** 输　  入: pdrv：设备序号
**         : addr：首地址
**         : num：个数
**         : pbuf：数据指针
** 输　  出: 无
** 全局变量: 
** 调用模块: DBRead_YX  读遥信
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/Array(Value)
void DLT634_5101_SLAVE_R_YXDATA(uint8_t pdrv,uint16_t addr,uint16_t num, uint8_t *pbuf)//读YXDATA
{ 
	switch(pdrv)
	{
		case 0:
			DBRead_YX(addr,num,pbuf);
			break;
		default:
			break;
	}
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_R_YCDATA
** 功能描述: 读YCDATA
** 输　  入: pdrv：设备序号
**         : addr：首地址
**         : num：个数
**         : pbuf：数据指针
** 输　  出: 无
** 全局变量: 
** 调用模块: DBRead_YC  读遥测
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/Array(Value)
void DLT634_5101_SLAVE_R_YCDATA(uint8_t pdrv,uint16_t addr,uint16_t num, uint8_t *pbuf)//读YCDATA
{ 
	switch(pdrv)
	{
		case 0:
			DBRead_YC(addr,num,pbuf);
			break;
		default:
			break;
	}
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_C_REPLY
** 功能描述: 其他设备回复
** 输　  入: drvid：应用设备序号
**         : pbuf：回复内容数据指针
** 输　  出: 无
** 全局变量: 
** 调用模块: DBSend  发送给其他设备函数
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
uint8_t DLT634_5101_SLAVE_C_REPLY(uint8_t drvid,uint8_t *pbuf)//其他设备回复
{ 
	uint8_t res;
	switch(drvid)
	{
        case UART_ID:
			res = DLT634_5101_SLAVE_REPLY(DLT634_5101SLAVE_DISK0, pbuf); 
			break;
		default:
			break;
	}
	return(res);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_INIT
** 功能描述: 设置参数初始化
** 输　  入: 无
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
void DLT634_5101_SLAVE_INIT(uint8_t pdrv)
{
	switch(pdrv)
	{
		case 0:
            DLT634_5101Slave_Pad[pdrv].Port = UART_ID;
            DLT634_5101Slave_Pad[pdrv].BalanMode = 1;
            DLT634_5101Slave_Pad[pdrv].IEC_DIR = 0x80;
            DLT634_5101Slave_Pad[pdrv].SourceAddr = 0x01;
            DLT634_5101Slave_Pad[pdrv].LinkAddrSize = 2;//1:97,2:02
            DLT634_5101Slave_Pad[pdrv].ASDUCotSize = 2;//1:97,2:02
            DLT634_5101Slave_Pad[pdrv].ASDUAddr = 0x01;
            DLT634_5101Slave_Pad[pdrv].ASDUAddrSize = 2;//1:97,2:02
            DLT634_5101Slave_Pad[pdrv].FixFrmLength = 6;//5:97,6:02
            DLT634_5101Slave_Pad[pdrv].ClockTimers = 2;
            DLT634_5101Slave_Pad[pdrv].TimeOutValue = 10;
            DLT634_5101Slave_Pad[pdrv].YX_AllNum = 10;
            DLT634_5101Slave_Pad[pdrv].YX_FIRSTADDR = 0x0001;
            DLT634_5101Slave_Pad[pdrv].YX_FrameNum = 24;
            DLT634_5101Slave_Pad[pdrv].YC_AllNum = 18;
            DLT634_5101Slave_Pad[pdrv].YC_FIRSTADDR = 0x4001;
            DLT634_5101Slave_Pad[pdrv].YC_FrameNum = 24;
            DLT634_5101Slave_Pad[pdrv].AskStaOutValue = 100;//链路请求间隔节拍
			break;
		default:
			break;
	}
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SlaveTask
** 功能描述: 101从站任务函数
** 输　  入: 无
** 输　  出: 无
** 全局变量: 
** 调用模块: DLT634_5101_SLAVE_Clock  定时执行函数
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
void DLT634_5101_SlaveTask()
{
	DLT634_5101_SLAVE_INIT(DLT634_5101SLAVE_DISK0);		
}

//#endif	/* END DLT634_5101_SLAVE_CFG */ 

/* END OF FILE ---------------------------------------------------------------*/

