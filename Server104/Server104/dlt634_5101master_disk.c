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
** File name:               DLT634_5101_master_disk.c
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

#include <sys/time.h>
#include <signal.h>
#include "dlt634_5101master_disk.h"
#include "dlt634_5101master_app.h"
#include "data_cache.h"

/* PRIVATE VARIABLES ----------------------------------------------------------*/
/* PUBLIC VARIABLES ----------------------------------------------------------*/
static int s_serialfd;

/* PRIVATE FUNCTION PROTOTYPES -----------------------------------------------*/

/* PUBLIC FUNCTION PROTOTYPES -----------------------------------------------*/
int getSerialFd()
{
    return s_serialfd;
}

void setSerialFd(int serialfd)
{
    s_serialfd = serialfd;
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_ReadData
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
uint16_t DLT634_5101_MASTER_ReadData(uint8_t pdrv, uint8_t *pbuf, uint16_t count)
{ 
	uint16_t len = 0;  
	
	switch(pdrv)
	{
		case 0:
			len = Readx(pbuf, count, DLT634_5101Master_Pad[pdrv].Port);
			break;
		default:
			break;
	}
	return(len);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_WriteData
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
uint16_t DLT634_5101_MASTER_WriteData(uint8_t pdrv, uint8_t *pbuf, uint16_t count)
{ 
	uint16_t len = 0; 
	
	switch(pdrv)
	{
		case 0:
			len = WriteX(pbuf,count,DLT634_5101Master_Pad[pdrv].Port);
			break;
		default:
			break;
	}
	return(len);
}

//app
/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_C_SC
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
void DLT634_5101_MASTER_C_SC(uint8_t pdrv, uint8_t *pbuf)//遥控
{ 
//	switch(pdrv)
//	{
//		case 0:
//			pbuf[1] = (DLT634_5101Master_Pad[pdrv].Port<<4)|(pbuf[1]>>4);
//			DBSend(pbuf);
//			break;
//		default:
//			break;
//	}
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_C_CS
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
void DLT634_5101_MASTER_C_CS(uint8_t pdrv, uint8_t *pbuf)//对时
{ 
//	switch(pdrv)
//	{
//		case 0:
//			pbuf[1] = (DLT634_5101Master_Pad[pdrv].Port<<4)|(pbuf[1]>>4);
//			DBSend(pbuf);
//			break;
//		default:
//			break;
//	}
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_C_SR
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
void DLT634_5101_MASTER_C_SR(uint8_t pdrv, uint8_t *pbuf)//定值参数
{ 
//	switch(pdrv)
//	{
//		case 0:
//			pbuf[1] = (DLT634_5101Master_Pad[pdrv].Port<<4)|(pbuf[1]>>4);
//			DBSend(pbuf);
//			break;
//		default:
//			break;
//	}
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_W_YXDATA
** 功能描述: 写YXDATA
** 输　  入: pdrv：设备序号
**         : pbuf：数据指针
** 输　  出: 无
** 全局变量: 
** 调用模块: DBWrite_YX  写YXDATA
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/Array(Value)
void DLT634_5101_MASTER_W_YXDATA(uint8_t pdrv, uint8_t *pbuf)//写YXDATA
{ 
    switch(pdrv)
    {
        case 0:
            pbuf[1] = (DLT634_5101Master_Pad[pdrv].Port<<4)|NULL_ID;//TRANSIT_DEV0;
            DBWrite_YX(pbuf);
            break;
        default:
            break;
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_W_YCDATA
** 功能描述: 写YCDATA
** 输　  入: pdrv：设备序号
**         : pbuf：数据指针
** 输　  出: 无
** 全局变量: 
** 调用模块: DBWrite_YC  写YCDATA
**         : DBWrite_NVA  写NVA
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_H/Array(Value)
void DLT634_5101_MASTER_W_YCDATA(uint8_t pdrv, uint8_t *pbuf)//写YCDATA
{ 
    switch(pdrv)
    {
        case 0:
            pbuf[1] = (DLT634_5101Master_Pad[pdrv].Port<<4)|NULL_ID;
            if(pbuf[3]&0x80)//SQ==0为变化遥测
            {DBWrite_YC(pbuf);}
            else
            {DBWrite_NVA(pbuf);}
            break;
        default:
            break;
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_W_SOE
** 功能描述: 写soe
** 输　  入: pdrv：设备序号
**         : pbuf：数据指针
** 输　  出: 无
** 全局变量: 
** 调用模块: DBWrite_SOE  写soe
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/Array(InfoAddr_L/InfoAddr_H/Value/CP56Time2a)
void DLT634_5101_MASTER_W_SOE(uint8_t pdrv, uint8_t *pbuf)//写soe
{ 
    switch(pdrv)
    {
        case 0:
            pbuf[1] = (DLT634_5101Master_Pad[pdrv].Port<<4)|NULL_ID;
            DBWrite_SOE(pbuf);
            break;
        default:
            break;
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_W_FEvent
** 功能描述: 写FEvent
** 输　  入: pdrv：设备序号
**         : pbuf：数据指针
** 输　  出: 无
** 全局变量: 
** 调用模块: DBWrite_FEvent  写故障事件
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/Array
void DLT634_5101_MASTER_W_FEvent(uint8_t pdrv, uint8_t *pbuf)//写FEvent
{
//	switch(pdrv)
//	{
//		case 0:
//			pbuf[1] = (DLT634_5101Master_Pad[pdrv].Port<<4)|TRANSIT_DEV0;
//			DBWrite_FEvent(pbuf);
//			break;
//		default:
//			break;
//	}
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_F_FR
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
void DLT634_5101_MASTER_F_FR(uint8_t pdrv, uint8_t *pbuf)//文件读写
{ 
//	switch(pdrv)
//	{
//		case 0:
//			pbuf[1] = (DLT634_5101Master_Pad[pdrv].Port<<4)|(pbuf[1]>>4);
//			DBSend(pbuf);
//			break;
//		default:
//			break;
//	}
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_F_SR
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
void DLT634_5101_MASTER_F_SR(uint8_t pdrv, uint8_t *pbuf)//软件升级
{ 
//	switch(pdrv)
//	{
//		case 0:
//			pbuf[1] = (DLT634_5101Master_Pad[pdrv].Port<<4)|(pbuf[1]>>4);
//			DBSend(pbuf);
//			break;
//		default:
//			break;
//	}
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
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/
uint8_t DLT634_5101_MASTER_C_REPLY(uint8_t drvid,uint8_t *pbuf)//其他设备回复
{
    uint8_t res;
    switch(drvid)
    {
        case USART1_ID:
            res = DLT634_5101_MASTER_REPLY(DLT634_5101MASTER_DISK0, pbuf);
            if(!res)//加载不成功，返回否定回答
            {
                pbuf[1] = ((pbuf[1]&0x0f)<<4)|((pbuf[1]&0xf0)>>4);
                pbuf[4] = 47;
                DBSend(pbuf);
            }
            break;
        default:
            break;
    }
    return(res);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MASTER_INIT
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
void DLT634_5101_MASTER_INIT(uint8_t pdrv)//初始化
{
    switch(pdrv)
	{
        case 0:
            DLT634_5101Master_Pad[pdrv].Port = USART1_ID;
            DLT634_5101Master_Pad[pdrv].IEC_DIR = 0;
            DLT634_5101Master_Pad[pdrv].SourceAddr = 1;
            DLT634_5101Master_Pad[pdrv].LinkAddrSize = 2;//1:97,2:02
            DLT634_5101Master_Pad[pdrv].ASDUCotSize = 2;//1:97,2:02
            DLT634_5101Master_Pad[pdrv].ASDUAddr = 1;
            DLT634_5101Master_Pad[pdrv].ASDUAddrSize = 2;//1:97,2:02
            DLT634_5101Master_Pad[pdrv].FixFrmLength = 6;//5:97,6:02
            DLT634_5101Master_Pad[pdrv].ClockTimers = 1;//程序运行间隔节拍
            DLT634_5101Master_Pad[pdrv].TimeOutValue = 100;//重发间隔节拍
            DLT634_5101Master_Pad[pdrv].AskStaOutValue = 100;//链路请求间隔节拍
            DLT634_5101Master_Pad[pdrv].AllDataOutValue = 1000;//全数据召唤间隔节拍
            DLT634_5101Master_Pad[pdrv].LinkTestValue = 300;//测试链路间隔节拍
            DLT634_5101Master_Pad[pdrv].LinkIdleValue = DLT634_5101Master_Pad[pdrv].LinkTestValue + 100;//链路空闲自动复位时间节拍
            DLT634_5101Master_Pad[pdrv].DevidValue = 200;//设备占用间隔节拍
            break;
        default:
            break;
	}
}

/* -----------------------------------------------------------------------------
** 函数名称: start
** 功能描述: 101函数
** 输　  入: 无
** 输　  出: 无
** 全局变量:
** 调用模块: DLT634_5101_MASTER_Clock  定时执行函数
** 作　  者: Mrs.Ly
** 日　  期: 2017.9.12
** -----------------------------------------------------------------------------
** 修 改 人:
** 修改内容:
** 日　  期:
** ---------------------------------------------------------------------------*/
void start()
{
    DLT634_5101_MASTER_Clock(DLT634_5101MASTER_DISK0);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_MasterTask
** 功能描述: 101主站任务函数
** 输　  入: 无
** 输　  出: 无
** 全局变量: 
** 调用模块: DLT634_5101_MASTER_Clock  定时执行函数
** 作　  者: Mr.J
** 日　  期: 2017.8.3
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
void DLT634_5101_MasterTask()
{
//	OS_ERR  err;
//	uint32_t results = 0;

//	OSFlagCreate((OS_FLAG_GRP *)&DLT101MasterApp_Event, (CPU_CHAR *)"DLT101MasterPad.Event", (OS_FLAGS)0, (OS_ERR *)&err);
	
	DLT634_5101_MASTER_INIT(DLT634_5101MASTER_DISK0);

    signal(SIGALRM,start);
    struct timeval tv_interval;
    tv_interval.tv_sec = 0;
    tv_interval.tv_usec = 10000;
    struct timeval tv_value;
    tv_value.tv_sec = 0;
    tv_value.tv_usec = 10000;
    struct itimerval it;
    it.it_interval = tv_interval;
    it.it_value = tv_value;
    setitimer(ITIMER_REAL, &it ,NULL);

		 
	// 进入事项处理循环
//	for (;;)
//	{
//        results = OSFlagPend((OS_FLAG_GRP *)&DLT101MasterApp_Event,
//                             (OS_FLAGS)PRTCLEVENT_MASK,
//                             (OS_TICK)0,
//                             (OS_OPT)OS_OPT_PEND_FLAG_SET_ANY + OS_OPT_PEND_FLAG_CONSUME,
//                             (CPU_TS *)0,
//                             (OS_ERR *)&err);

//        // 定时处理区（100MS）
//        if (results & TIME100MS)
//        {
//            DLT634_5101_MASTER_Clock(DLT634_5101MASTER_DISK0);
//        }
				
//    }
}

/* END OF FILE ---------------------------------------------------------------*/

