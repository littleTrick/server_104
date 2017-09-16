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
** File name:               DLT634_5104_app.c
** Descriptions:            The application of DLT634.5104_2002
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

//#if APP_TASK_DLT634_5104_SLAVE_CFG
#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include "data_cache.h"
#include "dlt634_5104slave_app.h"
#include "dlt634_5104slave_disk.h"

static int s_clientfd;
/* PRIVATE VARIABLES ----------------------------------------------------------*/
/* PUBLIC VARIABLES ----------------------------------------------------------*/


/* PRIVATE FUNCTION PROTOTYPES -----------------------------------------------*/

/* PUBLIC FUNCTION PROTOTYPES -----------------------------------------------*/

int getClientFd()
{
    return s_clientfd;
}

void setClientFd(int clientfd)
{
    s_clientfd = clientfd;
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5104WriteData
** 功能描述: 向通信接口写数据
** 输　  入: Port ：通信接口类型；
**           *pbuf：数据存储区
**           count：数据长度 
** 输　  出: 所读出的数据长度
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Sun
** 日　  期: 2017.07.12
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容: 
** 日　  期: 
** ---------------------------------------------------------------------------*/
uint16_t DLT634_5104_SLAVE_WriteData(uint8_t pdrv, uint8_t *pbuf, uint16_t count)
{ 
    uint16_t len = 0;
	
    switch (pdrv)
    {
        case 0:
            len = WriteX(pbuf, count, DLT634_5104Slave_Pad[pdrv].Port);
            if(len != 0)
            {
            printf("the pbuf in Writex is ");
            int i;
            for(i = 0;i < len;i++)
                printf("%02x ",*(pbuf++));
            printf("\n");
            }
        break;
		default:
        break;
	}
	return(len);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5101_SLAVE_ReadData
** 功能描述: 读取数据
** 输　  入: Port ：通信接口类型；
**           *pbuf：读出数据存储区
**           count：读取数据长度 
** 输　  出: 所读出的数据长度
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Sun
** 日　  期: 2017.07.12
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
uint16_t DLT634_5104_SLAVE_ReadData(uint8_t pdrv, uint8_t *pbuf, uint16_t count)
{ 
    uint16_t len = 0;
	
    switch(pdrv)
    {
        case 0:
            len = Readx(pbuf, count, DLT634_5104Slave_Pad[pdrv].Port);
            if(len != 0)
            {
            printf("the pbuf in Readx is ");
            int i;
            for(i = 0;i < len;i++)
                printf("%02x ",*(pbuf++));
            printf("\n");
            }
        break;
        default:
        break;
    }
	return(len);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5104_SLAVE_CheckLink
** 功能描述: 检查链路
** 输　  入: Port ：通信接口类型；
** 输　  出: 所读出的数据长度
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Sun
** 日　  期: 2017.07.12
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
uint8_t DLT634_5104_SLAVE_CheckLink(uint8_t pdrv)
{ 
    uint8_t res = FALSE;

    switch(pdrv)
    {
        case 0:
            if(getClientFd() > 0)
            {res = TRUE;}
        break;
        default:
        break;
    }
    return(res);
}

/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5104_SLAVE_StopLink
** 功能描述: 断开链路
** 输　  入: Port ：通信接口类型；
** 输　  出: 所读出的数据长度
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Sun
** 日　  期: 2017.07.12
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
uint8_t DLT634_5104_SLAVE_StopLink(uint8_t pdrv)
{ 
    //OS_ERR err;

    switch(pdrv)
    {
        case 0:
            ShutDown();
            //TCPSERVER2404_Disconnect(); // 断开链接
            //OSTimeDlyHMSM(0, 0, 0, 50, OS_OPT_TIME_HMSM_STRICT, &err); // 延时50us
        break;
        default:
        break;
    }
    return(TRUE);
}

/* -----------------------------------------------------------------------------
** 函数名称: HandleCtrlProcess
** 功能描述: 遥控处理
** 输　  入: port：接口类型.
**           *pbuf：数据指针
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Sun
** 日　  期: 2017.07.12
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/SCO_L/SCO_H
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/DCO_L/DCO_H
void DLT634_5104_SLAVE_HandleCtrlProcess(uint8_t pdrv, uint8_t *pbuf)
{
    uint8_t buf[256];

    memset(buf,0,sizeof(buf));
    memcpy(buf,pbuf,pbuf[0]);
    memcpy(&buf[10],&pbuf[11],pbuf[0]-11);
    buf[0] -= 1;
    //转换成101,02版

    switch (pdrv)
    {
        case 0:
            buf[1] = (DLT634_5104Slave_Pad[pdrv].Port<<4)|USART1_ID;// send to serial 1
            DBSend(buf);
        break;
        case 1:
        break;
        default:
        break;
    }
}

/* -----------------------------------------------------------------------------
** 函数名称: SYNProcess
** 功能描述: 时钟同步操作
** 输　  入: port：接口类型.
**           *pbuf：数据指针
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Sun
** 日　  期: 2017.07.12
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/CP56Time2a
void DLT634_5104_SLAVE_SYNProcess(uint8_t pdrv, uint8_t *pbuf)
{
    uint8_t buf[256];
	
    memset(buf,0,sizeof(buf));
    memcpy(buf,pbuf,pbuf[0]);
    memcpy(&buf[10],&pbuf[11],pbuf[0]-11);
    buf[0] -= 1;
    //转换成101,02版
	
    switch (pdrv)
    {
    case 0:
        buf[1] = (DLT634_5104Slave_Pad[pdrv].Port << 4)|USART1_ID;//send to serail 1
        DBSend(buf);
    break;
    case 1:
    break;
    default:
    break;
    }
}

//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/Array(Value)
void DLT634_5104_SLAVE_ReadYxData(uint8_t pdrv, uint16_t addr, uint16_t num, uint8_t *pbuf)//读YXDATA
{ 
    uint8_t buf[256];
    memset(&buf,0,sizeof(buf));
	
    switch (pdrv)
    {
        case 0:
            DBRead_YX(addr, num, buf);
            memcpy(pbuf,buf,buf[0]);
            pbuf[0] += 1;
            pbuf[10] = 0;
            memcpy(&pbuf[11],&buf[10],pbuf[0]-11);
            //转换成104,02版
        break;
        default:
        break;
   }
}

//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/Array(Value)
void DLT634_5104_SLAVE_ReadYcData(uint8_t pdrv, uint16_t addr, uint16_t num, uint8_t *pbuf)//读YCDATA
{ 
    uint8_t buf[256];
    memset(&buf,0,sizeof(buf));
	
    switch (pdrv)
    {
        case 0:
            DBRead_YC(addr, num, buf);
            memcpy(pbuf,buf,buf[0]);
            pbuf[0] += 1;
            pbuf[10] = 0;
            memcpy(&pbuf[11],&buf[10],pbuf[0]-11);
            //转换成104,02版
        break;
        default:
        break;
    }
}

//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/sty/Array
void DLT634_5104_SLAVE_FileHandleProcess(BYTE pdrv, BYTE *pbuf)
{
//    BYTE buf[256];

//    memset(buf,0,sizeof(buf));
//    memcpy(buf,pbuf,pbuf[0]);
//    memcpy(&buf[10],&pbuf[11],pbuf[0]-11);
//    buf[0] -= 1;
//    //转换成101,02版

//    switch (pdrv)
//    {
//        case 0:
//            if(pbuf[12]>=7)//写文件
//            {
//                buf[1] = (DLT634_5104Slave_Pad[pdrv].Port<<4)|USART6_ID;
//                DBSend(buf);
//            }
//            else//读文件
//            {
//                buf[1] = (DLT634_5104Slave_Pad[pdrv].Port<<4)|N25QXXX_ID;
//                DBSend(buf);
//            }
//        break;
//        case 1:
//        break;
//        default:
//        break;
//    }
}

//切换定值区号//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/SN_L/SN_H
//读当前定值区号//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H
//读多个定值//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/SN1_L/SN1_H/Array(InfoAddr_L/InfoAddr_M/InfoAddr_H)
//读全部定值//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/SN1_L/SN1_H
//写定值//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/SN_L/SN_H/PI//Array(InfoAddr_L/InfoAddr_M/InfoAddr_H/Tag/Len/Value)
//固化定值//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/SN1_L/SN1_H/PI
void DLT634_5104_SLAVE_FixedParaProcess(BYTE pdrv, BYTE *pbuf)
{	
//    BYTE buf[256];
//    BYTE i;
//    BYTE temp1,temp2;

//    memset(buf,0,sizeof(buf));
//    memcpy(buf,pbuf,pbuf[0]);
//    //转换成101,02版
	
//    switch(pdrv)
//    {
//    case 0:
//        switch(pbuf[2])
//        {
//            case 200://切换定值区号
//                memcpy(&buf[10],&pbuf[11],pbuf[0]-11);
//                buf[0] -= 1;
//                buf[1] = (DLT634_5104Slave_Pad[pdrv].Port<<4)|USART6_ID;
//            break;
//            case 201://读当前定值区号
//                buf[0] -= 1;
//                buf[1] = (DLT634_5104Slave_Pad[pdrv].Port<<4)|USART6_ID;
//            break;
//            case 202://读定值
//                if(pbuf[3])//读多个
//                {
//                    for(i=0;i<pbuf[3]-1;i++)
//                    {memcpy(&buf[12+2*i],&pbuf[13+3*i],pbuf[0]-13-3*i);}
//                    buf[0] -= pbuf[3];
//                    buf[1] = (DLT634_5104Slave_Pad[pdrv].Port<<4)|USART6_ID;
//                }
//                else//读全部
//                {
//                    buf[1] = (DLT634_5104Slave_Pad[pdrv].Port<<4)|USART6_ID;
//                }
//            break;
//            case 203://写定值
//                if(pbuf[10]&0x80)//预制
//                {
//                    for(temp1=0,temp2=0,i=0;i<pbuf[3];i++)
//                    {
//                        memcpy(&buf[13+temp1],&pbuf[14+temp2],pbuf[0]-14-temp2);
//                        temp1 += 1+1+buf[13+1+temp1]+2;
//                        temp2 += 1+1+pbuf[14+1+temp2]+3;
//                    }
//                    buf[0] -= pbuf[3];
//                    buf[1] = (DLT634_5104Slave_Pad[pdrv].Port<<4)|USART6_ID;
//                }
//                else//固化
//                {
//                    buf[1] = (DLT634_5104Slave_Pad[pdrv].Port<<4)|USART6_ID;
//                }
//            break;
//        }
//        DBSend(buf);
//        break;
//        default:
//        break;
//    }
}

uint8_t DLT634_5104_SLAVE_H_SOE(uint8_t pdrv)//判断是否有soe
{ 
    switch(pdrv)
    {
        case 0:
            return(DBCheck_SOE(DLT634_5104Slave_Pad[pdrv].Port));
            default:
        break;
    }
    return(FALSE);
}

//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/Array(InfoAddr_L/InfoAddr_M/InfoAddr_H/Value/CP56Time2a)
void DLT634_5104_SLAVE_R_SOE(uint8_t pdrv, uint8_t *pbuf)//读soe
{ 
    uint8_t buf[256];
    uint8_t i;

    memset(buf,0,sizeof(buf));

    switch(pdrv)
    {
        case 0:
            DBRead_SOE(DLT634_5104Slave_Pad[pdrv].Port,buf);
            memcpy(pbuf,buf,buf[0]);
            for(i=0;i<buf[3];i++)
            {
                memcpy(&pbuf[11+i*11],&buf[10+i*10],buf[0]-10-i*10);
                pbuf[10+i*11] = 0;
            }
            pbuf[0] += buf[3];
        break;
        default:
        break;
    }
}

uint8_t DLT634_5104_SLAVE_H_NVA(uint8_t pdrv)//判断是否有NVA
{ 
    switch(pdrv)
    {
        case 0:
            return(DBCheck_NVA(DLT634_5104Slave_Pad[pdrv].Port));
        default:
        break;
    }
    return(FALSE);
}

//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/Array(InfoAddr_L/InfoAddr_M/InfoAddr_H/Value/QDS)
void DLT634_5104_SLAVE_R_NVA(uint8_t pdrv, uint8_t *pbuf)//读NVA
{ 
    uint8_t buf[256];
    uint8_t i;

    memset(buf,0,sizeof(buf));

    switch(pdrv)
    {
        case 0:
            DBRead_NVA(DLT634_5104Slave_Pad[pdrv].Port,buf);
            memcpy(pbuf,buf,buf[0]);
            for(i=0;i<buf[3];i++)
            {
                memcpy(&pbuf[11+i*8],&buf[10+i*7],buf[0]-10-i*7);
                pbuf[10+i*8] = 0;
            }
            pbuf[0] += buf[3];
        break;
        default:
        break;
    }
}

uint8_t DLT634_5104_SLAVE_H_FEvent(uint8_t pdrv)//判断是否有FEvent
{ 
//	switch(pdrv)
//	{
//		case 0:
//			return(DBCheck_FEvent(DLT634_5104Slave_Pad[pdrv].Port));
//		default:
//			break;
//	}
    return(FALSE);
}

//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/Array
void DLT634_5104_SLAVE_R_FEvent(uint8_t pdrv, uint8_t *pbuf)//读FEvent
{ 
//	BYTE buf[256];
//	BYTE i;
//	BYTE temp1,temp2;
	
//	memset(buf,0,sizeof(buf));
	
//	switch(pdrv)
//	{
//		case 0:
//			DBRead_FEvent(DLT634_5104Slave_Pad[pdrv].Port,buf);
//			memcpy(pbuf,buf,buf[0]);
//			for(temp1=0,temp2=0,i=0;i<buf[10+buf[7]*10];i++)
//			{
//				memcpy(&pbuf[10+buf[7]*10+5+7*i],&buf[10+buf[7]*10+4+6*i],buf[0]-10-buf[7]*10-4-6*i);
//				pbuf[10+buf[7]*10+4+7*i] = 0;
//			}
//			pbuf[0] += buf[10+buf[7]*10];
//			break;
//		default:
//			break;
//	}
}

bool DLT634_5104_SLAVE_C_REPLY(uint8_t drvid, uint8_t *pbuf)//其他设备回复
{ 
    uint8_t buf[256];
    uint8_t i;
    uint8_t temp1,temp2;

    memset(buf,0,sizeof(buf));
    memcpy(buf,pbuf,pbuf[0]);
    //转换成104,02版
    bool res;
    switch(drvid)
    {
        case NET1_ID:
        switch(pbuf[2]) //TI
        {
            //LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/SCO_L/SCO_H
            //LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/DCO_L/DCO_H
            case 45:case 46://遥控
                memcpy(&buf[11],&pbuf[10],pbuf[0]-10);
                buf[10] = 0;
                buf[0] += 1;
            break;
            //LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/CP56Time2a
            case 103://对时
                memcpy(&buf[11],&pbuf[10],pbuf[0]-10);
                buf[10] = 0;
                buf[0] += 1;
            break;
//            //LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/sty/Array
//            case 210://文件服务
//                memcpy(&buf[11],&pbuf[10],pbuf[0]-10);
//                buf[10] = 0;
//                buf[0] += 1;
//            break;
//            //LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/SN_L/SN_H
//            case 200://切换定值区号
//                memcpy(&buf[11],&pbuf[10],pbuf[0]-10);
//                buf[10] = 0;
//                buf[0] += 1;
//            break;
//            //LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/SN0_L/SN0_H/SN1_L/SN1_H/SN2_L/SN2_H
//            case 201://读当前定值区号
//                memcpy(&buf[11],&pbuf[10],pbuf[0]-10);
//                buf[10] = 0;
//                buf[0] += 1;
//            break;
//            //LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/SN_L/SN_H/PI//Array(InfoAddr_L/InfoAddr_M/InfoAddr_H/Tag/Len/Value)
//            case 202://读定值
//                for(temp1=0,temp2=0,i=0;i<pbuf[3];i++)
//                {
//                    memcpy(&buf[14+temp1],&pbuf[13+temp2],pbuf[0]-13-temp2);
//                    buf[13+temp1] = 0;
//                    temp1 += 1+1+pbuf[14+1+temp1]+3;
//                    temp2 += 1+1+pbuf[13+1+temp2]+2;
//                }
//                buf[0] += pbuf[3];
//            break;
//            //LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/SN_L/SN_H/PI//Array(InfoAddr_L/InfoAddr_M/InfoAddr_H/Tag/Len/Value)
//            //LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/SN1_L/SN1_H/PI
//            case 203://写定值
//                if(pbuf[10]&0x80)//预制
//                {
//                    for(temp1=0,temp2=0,i=0;i<pbuf[3];i++)
//                    {
//                        memcpy(&buf[14+temp1],&pbuf[13+temp2],pbuf[0]-13-temp2);
//                        buf[13+temp1] = 0;
//                        temp1 += 1+1+pbuf[14+1+temp1]+3;
//                        temp2 += 1+1+pbuf[13+1+temp2]+2;
//                    }
//                    buf[0] += pbuf[3];
//                }
//                else//固化
//                {
//                }
//            break;
        }
        res = DLT634_5104_SLAVE_Reply(DLT634_5104_NET1_ID, buf); //回复
        break;
        default:
        break;
    }
    return(res);
}

/* -----------------------------------------------------------------------------           
** 函数名称: DLT634_5104_ParaInit
** 功能描述: DL/T634.5104规约参数初始化
** 输　  入: 无
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Sun
** 日　  期: 2017.07.13
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
void DLT634_5104_ParaInit(BYTE pdrv)
{
    //OS_ERR err;
          
//    OSFlagCreate((OS_FLAG_GRP *)&DLT104SlaveApp_Event,
//                   (CPU_CHAR *)"DLT104SlaveApp_Event",
//                   (OS_FLAGS)0,
//                   (OS_ERR *)&err);

    DLT634_5104Slave_Pad[pdrv].Port = NET1_ID; // device端口号

    DLT634_5104Slave_Pad[pdrv].LinkAddress = 0x01; // salve链路地址
    DLT634_5104Slave_Pad[pdrv].PubAddress  = 0x01; // 公共地址
        
    DLT634_5104Slave_Pad[pdrv].CotSize = 2;        // 传输原因字节数
    DLT634_5104Slave_Pad[pdrv].InfoAddrSize = 3;   // 信息体地址字节数
    DLT634_5104Slave_Pad[pdrv].LinkAddrSize = 2;   // 链路层地址字节数
    DLT634_5104Slave_Pad[pdrv].PubAddrSize = 2;    // 公共地址字节数

    DLT634_5104Slave_Pad[pdrv].ClockTimers = 1;
    DLT634_5104Slave_Pad[pdrv].YX_AllNum = 10;
    DLT634_5104Slave_Pad[pdrv].YX_FirstAddr = 0x0001;
    DLT634_5104Slave_Pad[pdrv].YX_FrameNum = 24;
    DLT634_5104Slave_Pad[pdrv].YC_AllNum = 18;
    DLT634_5104Slave_Pad[pdrv].YC_FirstAddr = 0x4001;
    DLT634_5104Slave_Pad[pdrv].YC_FrameNum = 24;

    DLT634_5104Slave_Pad[pdrv].TickValue[0] = 3000;  // 30s 连接建立的超时
    DLT634_5104Slave_Pad[pdrv].TickValue[1] = 1500;  // 15s 发送或测试APDU的超时
    DLT634_5104Slave_Pad[pdrv].TickValue[2] = 1000;  // 10s 无数据报文t2 t1状态下发送测试帧的超时
    DLT634_5104Slave_Pad[pdrv].TickValue[3] = 2000;  // 20s 若在t3内未接收到任何报文，将向对方发送测试链路帧。
}

/* -----------------------------------------------------------------------------
** 函数名称: handle
** 功能描述: Timing is triggered.
** 输　  入: void
** 输　  出: void
** 全局变量: 无
** 调用模块: DLT634_5104_SLAVE_Clock();
** 作　  者: Mrs.Li
** 日　  期: 2017.09.01
** -----------------------------------------------------------------------------
** 修 改 人:
** 修改内容:
** 日　  期:
** ---------------------------------------------------------------------------*/
void handle()
{
    printf("handle(): thread id:%ul", (unsigned long)pthread_self());
    DLT634_5104_SLAVE_Clock(0);
}
/* -----------------------------------------------------------------------------
** 函数名称: DLT634_5104_SlaveTask
** 功能描述: 104规约从站方任务.
** 输　  入: parg:任务参数
** 输　  出: 无
** 全局变量: 无
** 调用模块: 无
** 作　  者: Mr.Sun
** 日　  期: 2017.07.11
** -----------------------------------------------------------------------------
** 修 改 人: 
** 修改内容:
** 日　  期: 
** ---------------------------------------------------------------------------*/
//void DLT634_5104_SlaveInit(void* arg)
void DLT634_5104_SlaveInit()
{
    uint8_t pdrv;

    pdrv = DLT634_5104_NET1_ID;

    DLT634_5104_ParaInit(pdrv);

    if (!DLT634_5104_SLAVE_AppInit(pdrv))
    {
        return;
    }

    signal(SIGALRM,handle);
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
}

//#endif /* END DLT634_5104_SLAVE_CFG */

/* END OF FILE ---------------------------------------------------------------*/

