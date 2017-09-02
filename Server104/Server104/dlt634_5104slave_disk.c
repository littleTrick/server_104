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
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include "dataCache.h"
#include "dlt634_5104slave_app.h"
#include "dlt634_5104slave_disk.h"

extern int clientfd;
/* PRIVATE VARIABLES ----------------------------------------------------------*/
/* PUBLIC VARIABLES ----------------------------------------------------------*/


/* PRIVATE FUNCTION PROTOTYPES -----------------------------------------------*/

/* PUBLIC FUNCTION PROTOTYPES -----------------------------------------------*/
/* -----------------------------------------------------------------------------
** ��������: DLT634_5104WriteData
** ��������: ��ͨ�Žӿ�д����
** �䡡  ��: Port ��ͨ�Žӿ����ͣ�
**           *pbuf�����ݴ洢��
**           count�����ݳ��� 
** �䡡  ��: �����������ݳ���
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Sun
** �ա�  ��: 2017.07.12
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����: 
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
WORD DLT634_5104_SLAVE_WriteData(BYTE pdrv, BYTE *pbuf, WORD count)
{ 
    WORD len = 0; 
	
    switch (pdrv)
    {
        case 0:
            len = WriteX(pbuf, count, DLT634_5104Slave_Pad[pdrv].Port);
        break;
		default:
        break;
	}
	return(len);
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5101_SLAVE_ReadData
** ��������: ��ȡ����
** �䡡  ��: Port ��ͨ�Žӿ����ͣ�
**           *pbuf���������ݴ洢��
**           count����ȡ���ݳ��� 
** �䡡  ��: �����������ݳ���
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Sun
** �ա�  ��: 2017.07.12
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
WORD DLT634_5104_SLAVE_ReadData(BYTE pdrv, BYTE *pbuf, WORD count)
{ 
	WORD len = 0;  
	
    switch(pdrv)
    {
        case 0:
            len = Readx(pbuf, count, DLT634_5104Slave_Pad[pdrv].Port);
        break;
        default:
        break;
    }
	return(len);
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5104_SLAVE_CheckLink
** ��������: �����·
** �䡡  ��: Port ��ͨ�Žӿ����ͣ�
** �䡡  ��: �����������ݳ���
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Sun
** �ա�  ��: 2017.07.12
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
BYTE DLT634_5104_SLAVE_CheckLink(BYTE pdrv)
{ 
    BYTE res = FALSE;  

    switch(pdrv)
    {
        case 0:
            if(clientfd > 0)
            {res = TRUE;}
        break;
        default:
        break;
    }
    return(res);
}

/* -----------------------------------------------------------------------------
** ��������: DLT634_5104_SLAVE_StopLink
** ��������: �Ͽ���·
** �䡡  ��: Port ��ͨ�Žӿ����ͣ�
** �䡡  ��: �����������ݳ���
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Sun
** �ա�  ��: 2017.07.12
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
BYTE DLT634_5104_SLAVE_StopLink(BYTE pdrv)
{ 
    //OS_ERR err;

    switch(pdrv)
    {
        case 0:
            ShutDown();
            //TCPSERVER2404_Disconnect(); // �Ͽ�����
            //OSTimeDlyHMSM(0, 0, 0, 50, OS_OPT_TIME_HMSM_STRICT, &err); // ��ʱ50us
        break;
        default:
        break;
    }
    return(TRUE);
}

/* -----------------------------------------------------------------------------
** ��������: HandleCtrlProcess
** ��������: ң�ش���
** �䡡  ��: port���ӿ�����.
**           *pbuf������ָ��
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Sun
** �ա�  ��: 2017.07.12
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/SCO_L/SCO_H
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/DCO_L/DCO_H
void DLT634_5104_SLAVE_HandleCtrlProcess(BYTE pdrv, BYTE *pbuf)
{
//    BYTE buf[256];

//    memset(buf,0,sizeof(buf));
//    memcpy(buf,pbuf,pbuf[0]);
//    memcpy(&buf[10],&pbuf[11],pbuf[0]-11);
//    buf[0] -= 1;
//    //ת����101,02��

//    switch (pdrv)
//    {
//        case 0:
//            buf[1] = (DLT634_5104Slave_Pad[pdrv].Port<<4)|USART6_ID;
//            DBSend(buf);
//        break;
//        case 1:
//        break;
//        default:
//        break;
//    }
}

/* -----------------------------------------------------------------------------
** ��������: SYNProcess
** ��������: ʱ��ͬ������
** �䡡  ��: port���ӿ�����.
**           *pbuf������ָ��
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Sun
** �ա�  ��: 2017.07.12
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/CP56Time2a
void DLT634_5104_SLAVE_SYNProcess(BYTE pdrv, BYTE *pbuf)
{
//	BYTE buf[256];
	
//	memset(buf,0,sizeof(buf));
//	memcpy(buf,pbuf,pbuf[0]);
//	memcpy(&buf[10],&pbuf[11],pbuf[0]-11);
//	buf[0] -= 1;
//	//ת����101,02��
	
//    switch (pdrv)
//    {
//    case 0:
//        buf[1] = (DLT634_5104Slave_Pad[pdrv].Port<<4)|USART6_ID;
//        DBSend(buf);
//    break;
//    case 1:
//    break;
//    default:
//    break;
//    }
}

//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/Array(Value)
void DLT634_5104_SLAVE_ReadYxData(BYTE pdrv, WORD addr, WORD num, BYTE *pbuf)//��YXDATA
{ 
//	BYTE buf[256];
//	memset(&buf,0,sizeof(buf));
	
//    switch (pdrv)
//    {
//        case 0:
//            DBRead_YX(addr, num, buf);
//            memcpy(pbuf,buf,buf[0]);
//            pbuf[0] += 1;
//            pbuf[10] = 0;
//            memcpy(&pbuf[11],&buf[10],pbuf[0]-11);
//            //ת����104,02��
//        break;
//        default:
//        break;
//    }
}

//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/Array(Value)
void DLT634_5104_SLAVE_ReadYcData(BYTE pdrv, WORD addr, WORD num, BYTE *pbuf)//��YCDATA
{ 
//	BYTE buf[256];
//	memset(&buf,0,sizeof(buf));
	
//    switch (pdrv)
//    {
//        case 0:
//            DBRead_YC(addr, num, buf);
//            memcpy(pbuf,buf,buf[0]);
//            pbuf[0] += 1;
//            pbuf[10] = 0;
//            memcpy(&pbuf[11],&buf[10],pbuf[0]-11);
//            //ת����104,02��
//        break;
//        default:
//        break;
//    }
}

//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/sty/Array
void DLT634_5104_SLAVE_FileHandleProcess(BYTE pdrv, BYTE *pbuf)
{
//    BYTE buf[256];

//    memset(buf,0,sizeof(buf));
//    memcpy(buf,pbuf,pbuf[0]);
//    memcpy(&buf[10],&pbuf[11],pbuf[0]-11);
//    buf[0] -= 1;
//    //ת����101,02��

//    switch (pdrv)
//    {
//        case 0:
//            if(pbuf[12]>=7)//д�ļ�
//            {
//                buf[1] = (DLT634_5104Slave_Pad[pdrv].Port<<4)|USART6_ID;
//                DBSend(buf);
//            }
//            else//���ļ�
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

//�л���ֵ����//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/SN_L/SN_H
//����ǰ��ֵ����//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H
//�������ֵ//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/SN1_L/SN1_H/Array(InfoAddr_L/InfoAddr_M/InfoAddr_H)
//��ȫ����ֵ//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/SN1_L/SN1_H
//д��ֵ//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/SN_L/SN_H/PI//Array(InfoAddr_L/InfoAddr_M/InfoAddr_H/Tag/Len/Value)
//�̻���ֵ//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/SN1_L/SN1_H/PI
void DLT634_5104_SLAVE_FixedParaProcess(BYTE pdrv, BYTE *pbuf)
{	
//    BYTE buf[256];
//    BYTE i;
//    BYTE temp1,temp2;

//    memset(buf,0,sizeof(buf));
//    memcpy(buf,pbuf,pbuf[0]);
//    //ת����101,02��
	
//    switch(pdrv)
//    {
//    case 0:
//        switch(pbuf[2])
//        {
//            case 200://�л���ֵ����
//                memcpy(&buf[10],&pbuf[11],pbuf[0]-11);
//                buf[0] -= 1;
//                buf[1] = (DLT634_5104Slave_Pad[pdrv].Port<<4)|USART6_ID;
//            break;
//            case 201://����ǰ��ֵ����
//                buf[0] -= 1;
//                buf[1] = (DLT634_5104Slave_Pad[pdrv].Port<<4)|USART6_ID;
//            break;
//            case 202://����ֵ
//                if(pbuf[3])//�����
//                {
//                    for(i=0;i<pbuf[3]-1;i++)
//                    {memcpy(&buf[12+2*i],&pbuf[13+3*i],pbuf[0]-13-3*i);}
//                    buf[0] -= pbuf[3];
//                    buf[1] = (DLT634_5104Slave_Pad[pdrv].Port<<4)|USART6_ID;
//                }
//                else//��ȫ��
//                {
//                    buf[1] = (DLT634_5104Slave_Pad[pdrv].Port<<4)|USART6_ID;
//                }
//            break;
//            case 203://д��ֵ
//                if(pbuf[10]&0x80)//Ԥ��
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
//                else//�̻�
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

BYTE DLT634_5104_SLAVE_H_SOE(BYTE pdrv)//�ж��Ƿ���soe
{ 
//    switch(pdrv)
//    {
//        case 0:
//            return(DBCheck_SOE(DLT634_5104Slave_Pad[pdrv].Port));
//            default:
//        break;
//    }
    return(FALSE);
}

//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/Array(InfoAddr_L/InfoAddr_M/InfoAddr_H/Value/CP56Time2a)
void DLT634_5104_SLAVE_R_SOE(BYTE pdrv, BYTE *pbuf)//��soe
{ 
//    BYTE buf[256];
//    BYTE i;

//    memset(buf,0,sizeof(buf));

//    switch(pdrv)
//    {
//        case 0:
//            DBRead_SOE(DLT634_5104Slave_Pad[pdrv].Port,buf);
//            memcpy(pbuf,buf,buf[0]);
//            for(i=0;i<buf[3];i++)
//            {
//                memcpy(&pbuf[11+i*11],&buf[10+i*10],buf[0]-10-i*10);
//                pbuf[10+i*11] = 0;
//            }
//            pbuf[0] += buf[3];
//        break;
//        default:
//        break;
//    }
}

BYTE DLT634_5104_SLAVE_H_NVA(BYTE pdrv)//�ж��Ƿ���NVA
{ 
//    switch(pdrv)
//    {
//        case 0:
//            return(DBCheck_NVA(DLT634_5104Slave_Pad[pdrv].Port));
//        default:
//        break;
//    }
    return(FALSE);
}

//LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/Array(InfoAddr_L/InfoAddr_M/InfoAddr_H/Value/QDS)
void DLT634_5104_SLAVE_R_NVA(BYTE pdrv, BYTE *pbuf)//��NVA
{ 
//    BYTE buf[256];
//    BYTE i;

//    memset(buf,0,sizeof(buf));

//    switch(pdrv)
//    {
//        case 0:
//            DBRead_NVA(DLT634_5104Slave_Pad[pdrv].Port,buf);
//            memcpy(pbuf,buf,buf[0]);
//            for(i=0;i<buf[3];i++)
//            {
//                memcpy(&pbuf[11+i*8],&buf[10+i*7],buf[0]-10-i*7);
//                pbuf[10+i*8] = 0;
//            }
//            pbuf[0] += buf[3];
//        break;
//        default:
//        break;
//    }
}

BYTE DLT634_5104_SLAVE_H_FEvent(BYTE pdrv)//�ж��Ƿ���FEvent
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
void DLT634_5104_SLAVE_R_FEvent(BYTE pdrv, BYTE *pbuf)//��FEvent
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

bool DLT634_5104_SLAVE_C_REPLY(BYTE drvid, BYTE *pbuf)//�����豸�ظ�
{ 
//    BYTE buf[256];
//    BYTE i;
//    BYTE temp1,temp2;

//    memset(buf,0,sizeof(buf));
//    memcpy(buf,pbuf,pbuf[0]);
//    //ת����104,02��
//    bool res;
//    switch(drvid)
//    {
//        case NET1_ID:
//        switch(pbuf[2])
//        {
//            //LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/SCO_L/SCO_H
//            //LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/DCO_L/DCO_H
//            case 45:case 46://ң��
//                memcpy(&buf[11],&pbuf[10],pbuf[0]-10);
//                buf[10] = 0;
//                buf[0] += 1;
//            break;
//            //LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/CP56Time2a
//            case 103://��ʱ
//                memcpy(&buf[11],&pbuf[10],pbuf[0]-10);
//                buf[10] = 0;
//                buf[0] += 1;
//            break;
//            //LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/sty/Array
//            case 210://�ļ�����
//                memcpy(&buf[11],&pbuf[10],pbuf[0]-10);
//                buf[10] = 0;
//                buf[0] += 1;
//            break;
//            //LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/SN_L/SN_H
//            case 200://�л���ֵ����
//                memcpy(&buf[11],&pbuf[10],pbuf[0]-10);
//                buf[10] = 0;
//                buf[0] += 1;
//            break;
//            //LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/InfoAddr_L/InfoAddr_M/InfoAddr_H/SN0_L/SN0_H/SN1_L/SN1_H/SN2_L/SN2_H
//            case 201://����ǰ��ֵ����
//                memcpy(&buf[11],&pbuf[10],pbuf[0]-10);
//                buf[10] = 0;
//                buf[0] += 1;
//            break;
//            //LENTH/Lock_ID/TypeID/VSQ/COT_L/COT_H/PubAddr_L/PubAddr_H/SN_L/SN_H/PI//Array(InfoAddr_L/InfoAddr_M/InfoAddr_H/Tag/Len/Value)
//            case 202://����ֵ
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
//            case 203://д��ֵ
//                if(pbuf[10]&0x80)//Ԥ��
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
//                else//�̻�
//                {
//                }
//            break;
//        }
//        res = DLT634_5104_SLAVE_Reply(DLT634_5104_NET1_ID, buf); //�ظ�
//        break;
//        default:
//        break;
//    }
//    return(res);
    return false;//zi ji e wai jia de
}

/* -----------------------------------------------------------------------------           
** ��������: DLT634_5104_ParaInit
** ��������: DL/T634.5104��Լ������ʼ��
** �䡡  ��: ��
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Sun
** �ա�  ��: 2017.07.13
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
void DLT634_5104_ParaInit(BYTE pdrv)
{
    //OS_ERR err;
          
//    OSFlagCreate((OS_FLAG_GRP *)&DLT104SlaveApp_Event,
//                   (CPU_CHAR *)"DLT104SlaveApp_Event",
//                   (OS_FLAGS)0,
//                   (OS_ERR *)&err);

    DLT634_5104Slave_Pad[pdrv].Port = 1;//NET1_ID; // device�˿ں�

    DLT634_5104Slave_Pad[pdrv].LinkAddress = 0x01; // salve��·��ַ
    DLT634_5104Slave_Pad[pdrv].PubAddress  = 0x01; // ������ַ
        
    DLT634_5104Slave_Pad[pdrv].CotSize = 2;        // ����ԭ���ֽ���
    DLT634_5104Slave_Pad[pdrv].InfoAddrSize = 3;   // ��Ϣ���ַ�ֽ���
    DLT634_5104Slave_Pad[pdrv].LinkAddrSize = 2;   // ��·���ַ�ֽ���
    DLT634_5104Slave_Pad[pdrv].PubAddrSize = 2;    // ������ַ�ֽ���

    DLT634_5104Slave_Pad[pdrv].ClockTimers = 1;
    DLT634_5104Slave_Pad[pdrv].YX_AllNum = 10;
    DLT634_5104Slave_Pad[pdrv].YX_FirstAddr = 0x0001;
    DLT634_5104Slave_Pad[pdrv].YX_FrameNum = 24;
    DLT634_5104Slave_Pad[pdrv].YC_AllNum = 18;
    DLT634_5104Slave_Pad[pdrv].YC_FirstAddr = 0x4001;
    DLT634_5104Slave_Pad[pdrv].YC_FrameNum = 24;

    DLT634_5104Slave_Pad[pdrv].TickValue[0] = 3000;  // 30s ���ӽ����ĳ�ʱ
    DLT634_5104Slave_Pad[pdrv].TickValue[1] = 1500;  // 15s ���ͻ����APDU�ĳ�ʱ
    DLT634_5104Slave_Pad[pdrv].TickValue[2] = 1000;  // 10s �����ݱ���t2 t1״̬�·��Ͳ���֡�ĳ�ʱ
    DLT634_5104Slave_Pad[pdrv].TickValue[3] = 2000;  // 20s ����t3��δ���յ��κα��ģ�����Է����Ͳ�����·֡��
}

/* -----------------------------------------------------------------------------
** ��������: handle
** ��������: Timing is triggered.
** �䡡  ��: void
** �䡡  ��: void
** ȫ�ֱ���: ��
** ����ģ��: DLT634_5104_SLAVE_Clock();
** ����  ��: Mrs.Li
** �ա�  ��: 2017.09.01
** -----------------------------------------------------------------------------
** �� �� ��:
** �޸�����:
** �ա�  ��:
** ---------------------------------------------------------------------------*/
void handle()
{
    DLT634_5104_SLAVE_Clock(0);
}
/* -----------------------------------------------------------------------------
** ��������: DLT634_5104_SlaveTask
** ��������: 104��Լ��վ������.
** �䡡  ��: parg:�������
** �䡡  ��: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** ����  ��: Mr.Sun
** �ա�  ��: 2017.07.11
** -----------------------------------------------------------------------------
** �� �� ��: 
** �޸�����:
** �ա�  ��: 
** ---------------------------------------------------------------------------*/
//void DLT634_5104_SlaveInit(void* arg)
extern void DLT634_5104_SlaveInit()
{
    //OS_ERR err;
    BYTE pdrv;
 //   DWORD results = 0;

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



//    for (;;)
//    {
//        results = OSFlagPend(&DLT104SlaveApp_Event, TIME100MS+FBOOP+FCOS+FSOE+FTXAVAIL+FTXNEXT, 0, OS_OPT_PEND_FLAG_SET_ANY | OS_OPT_PEND_FLAG_CONSUME, 0, &err);

//        if (results & TIME100MS) // ��ʱ������(100MS)
//        {
           // DLT634_5104_SLAVE_Clock(pdrv);
//        }
//    }
}

//#endif /* END DLT634_5104_SLAVE_CFG */

/* END OF FILE ---------------------------------------------------------------*/
