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
** File name:               dlt634_5101master_config.h
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
#ifndef	_DLT634_5101MASTER_CONFIG_H_
#define _DLT634_5101MASTER_CONFIG_H_


/* PUBLIC VARIABLE -----------------------------------------------------------*/
enum
{
    DLT634_5101MASTER_DISK0 = 0,
    _DLT634_5101MASTER_VOLUMES
};
/* Number of volumes (logical drives) to be used.*/
#define _DLT634_5101MASTER_LPDUSIZE  256
#define _DLT634_5101MASTER_STOREDATA1NUM	20

#define  _DLT634_5101MASTER_NUMOF_MAXRETRY              0x03 // 默认DL/T634.5101_2002规约链路建立最多连接次数

//LINK_FLAG
#define  _DLT634_5101MASTER_REQSTATUS                   0x00000001
#define  _DLT634_5101MASTER_RECONFIRM                   0x00000002
#define  _DLT634_5101MASTER_ASKSTATUS               	0x00000004
#define  _DLT634_5101MASTER_ASKRELINK               	0x00000008
#define  _DLT634_5101MASTER_INITEND                 	0x00001000

#define  _DLT634_5101MASTER_SENDABLE                   0x10000000// 平衡

//APP_FLAG
#define  _DLT634_5101MASTER_CALLALLDATA                0x00000001
#define  _DLT634_5101MASTER_LINKTEST                   0x00000002
#define  _DLT634_5101MASTER_READTIME                   0x00000004

/*************************************************************************************************************************************/
//DL/T634.5101_2002规约

/* 链路层帧修饰词***************************************************************/
#define  _DLT634_5101MASTER_STARTCODE10	                     0x10	// 起始码
#define  _DLT634_5101MASTER_STARTCODE68	                     0x68	// 起始码
#define  _DLT634_5101MASTER_ENDCODE                           0x16	// 终止码

/* 链路层控制域定义************************************************************/
//前4位
#define  _DLT634_5101MASTER_FUNCODE                       0x0F // 功能码
#define  _DLT634_5101MASTER_FCV                           0x10 // 帧计数有效位 
#define  _DLT634_5101MASTER_DFC                           0x10 // 数据流控制
#define  _DLT634_5101MASTER_FCB                           0x20 // 帧计数位
#define  _DLT634_5101MASTER_ACD                           0x20 // 要求访问位 
#define  _DLT634_5101MASTER_PRM                           0x40 // 启动报文位
#define  _DLT634_5101MASTER_DIR                           0x80 // 传输方向位

//链路层主站向子站传输功能码定义
#define   _DLT634_5101MASTER_M_FUN0             	0           // 复位远方链路
#define   _DLT634_5101MASTER_M_FUN2              2           // 测试链路功能 
#define   _DLT634_5101MASTER_M_FUN3              3	          // 发送确认命令
#define   _DLT634_5101MASTER_M_FUN4             	4	          // 发送不确认命令
#define   _DLT634_5101MASTER_M_FUN8              8	          // 请求响应确定访问状态
#define   _DLT634_5101MASTER_M_FUN9             	9	          // 召唤链路状态
#define   _DLT634_5101MASTER_M_FUN10             10	        // 召唤1级用户数据 
#define   _DLT634_5101MASTER_M_FUN11             11          // 召唤2级用户数据

//*链路层子站向主站传输功能码定义 
#define   _DLT634_5101MASTER_S_FUN0              0            // 确认
#define   _DLT634_5101MASTER_S_FUN1              1            // 确认链路忙未接收报文
#define   _DLT634_5101MASTER_S_FUN8              8            // 以数据响应请求帧
#define   _DLT634_5101MASTER_S_FUN9              9            // 无所召唤的数据
#define   _DLT634_5101MASTER_S_FUN11             11           // 响应链路状态或回答请求帧
 
/* TI类型标识 ********************************************************************************/ 
//监视方向过程信息
#define   _DLT634_5101MASTER_M_SP_NA_1              1            // 单点信息
#define   _DLT634_5101MASTER_M_DP_NA_1              3            // 双点信息
#define   _DLT634_5101MASTER_M_ME_NA_1              9            // 测量值，归一化值
#define   _DLT634_5101MASTER_M_ME_NB_1              11           // 测量值，标度化值
#define   _DLT634_5101MASTER_M_ME_NC_1              13           // 测量值，短浮点数
#define   _DLT634_5101MASTER_M_SP_TB_1              30           // 带时标的单点信息
#define   _DLT634_5101MASTER_M_DP_TB_1              31           // 带时标的双点信息
#define   _DLT634_5101MASTER_M_FT_NA_1              42           // 故障事件信息
#define   _DLT634_5101MASTER_M_IT_NB_1              206          // 累计量，短浮点数
#define   _DLT634_5101MASTER_M_IT_TC_1              207          // 带时标累计量，短浮点数

//控制方向过程信息
#define   _DLT634_5101MASTER_C_SC_NA_1              45            // 单点命令
#define   _DLT634_5101MASTER_C_SC_NB_1              46            // 双点命令

//监视方向的系统命令
#define   _DLT634_5101MASTER_M_EI_NA_1              70            // 初始化结束

//控制方向的系统命令
#define   _DLT634_5101MASTER_C_IC_NA_1              100            // 站总召唤命令
#define   _DLT634_5101MASTER_C_CI_NA_1              101            // 电能量召唤命令
#define   _DLT634_5101MASTER_C_CS_NA_1              103            // 时间同步命令
#define   _DLT634_5101MASTER_C_TS_NA_1              104            // 测试命令
#define   _DLT634_5101MASTER_C_RP_NA_1              105            // 复位进程命令
#define   _DLT634_5101MASTER_C_SR_NA_1              200            // 切换定值区
#define   _DLT634_5101MASTER_C_RR_NA_1              201            // 读定值区号
#define   _DLT634_5101MASTER_C_RS_NA_1              202            // 读参数和定值
#define   _DLT634_5101MASTER_C_WS_NA_1              203            // 写参数和定值
#define   _DLT634_5101MASTER_F_FR_NA_1              210            // 文件传输
#define   _DLT634_5101MASTER_F_SR_NA_1              211            // 软件升级

/* COT传送原因 ********************************************************************************/ 
#define   _DLT634_5101MASTER_COT_CYC              1            // 周期循环
#define   _DLT634_5101MASTER_COT_BACK             2            // 背景扫描
#define   _DLT634_5101MASTER_COT_SPONT            3            // 突发
#define   _DLT634_5101MASTER_COT_INIT             4            // 初始化
#define   _DLT634_5101MASTER_COT_REQ              5            // 请求或被请求
#define   _DLT634_5101MASTER_COT_ACT              6            // 激活
#define   _DLT634_5101MASTER_COT_ACTCON           7            // 激活确认
#define   _DLT634_5101MASTER_COT_DEACT            8            // 停止激活
#define   _DLT634_5101MASTER_COT_DEACTCON         9            // 停止激活确认
#define   _DLT634_5101MASTER_COT_ACCTTERM         10            // 激活终止
#define   _DLT634_5101MASTER_COT_FILE             13            // 文件传输
#define   _DLT634_5101MASTER_COT_INTROGEN         20            // 响应站召唤
#define   _DLT634_5101MASTER_COT_REQCOGEN         37            // 响应电能召唤

#endif /* END _DLT634_5101_APP_H_ */
    

/* END OF FILE ---------------------------------------------------------------*/
