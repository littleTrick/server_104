#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif

/* PUBLIC VARIABLES ----------------------------------------------------------*/
#ifndef  FALSE
#define  FALSE     0
#define  TRUE      !FALSE
#endif

//定义设备编号
typedef enum
{
    NULL_ID = 0,    //数据缓存区
    NET1_ID = 1,    //网口１，与１０４从站程序连接的设备（１０４主站）
    NET2_ID = 2,    //网口２，与１０４从站程序连接的设备（１０４主站）
    USART1_ID = 3,  //底层串口设备１与１０１主站程序连接的设备
    UART_ID = 4,    //１０１主站，与１０１从站程序连接的设备，
    N25QXXX_ID = 5, //文件存储
    MAX_DEV_MUN
}DEV_ID;

/* TI类型标识 ******************************************************************/
//监视方向过程信息
#define   _DATABASE_M_SP_NA_1   1            // 单点信息
#define   _DATABASE_M_DP_NA_1   3            // 双点信息
#define   _DATABASE_M_ME_NA_1   9            // 测量值，归一化值
#define   _DATABASE_M_ME_NB_1   11           // 测量值，标度化值
#define   _DATABASE_M_ME_NC_1   13           // 测量值，短浮点数
#define   _DATABASE_M_SP_TB_1   30           // 带时标的单点信息
#define   _DATABASE_M_DP_TB_1   31           // 带时标的双点信息
#define   _DATABASE_M_FT_NA_1   42           // 故障事件信息
#define   _DATABASE_M_IT_NB_1   206          // 累计量，短浮点数
#define   _DATABASE_M_IT_TC_1   207          // 带时标累计量，短浮点数

//控制方向过程信息
#define   _DATABASE_C_SC_NA_1   45            // 单点命令
#define   _DATABASE_C_SC_NB_1   46            // 双点命令

//监视方向的系统命令
#define   _DATABASE_M_EI_NA_1   70            // 初始化结束

//控制方向的系统命令
#define   _DATABASE_C_IC_NA_1   100            // 站总召唤命令
#define   _DATABASE_C_CI_NA_1   101            // 电能量召唤命令
#define   _DATABASE_C_CS_NA_1   103            // 时间同步命令
#define   _DATABASE_C_TS_NA_1   104            // 测试命令
#define   _DATABASE_C_RP_NA_1   105            // 复位进程命令
#define   _DATABASE_C_SR_NA_1   200            // 切换定值区
#define   _DATABASE_C_RR_NA_1   201            // 读定值区号
#define   _DATABASE_C_RS_NA_1   202            // 读参数和定值
#define   _DATABASE_C_WS_NA_1   203            // 写参数和定值
#define   _DATABASE_F_FR_NA_1   210            // 文件传输
#define   _DATABASE_F_SR_NA_1   211            // 软件升级

/* COT传送原因 ********************************************************************************/
#define   _DATABASE_COT_CYC         1           // 周期循环
#define   _DATABASE_COT_BACK        2           // 背景扫描
#define   _DATABASE_COT_SPONT       3           // 突发
#define   _DATABASE_COT_INIT        4           // 初始化
#define   _DATABASE_COT_REQ         5           // 请求或被请求
#define   _DATABASE_COT_ACT         6           // 激活
#define   _DATABASE_COT_ACTCON      7           // 激活确认
#define   _DATABASE_COT_DEACT       8           // 停止激活
#define   _DATABASE_COT_DEACTCON    9           // 停止激活确认
#define   _DATABASE_COT_ACCTTERM    10          // 激活终止
#define   _DATABASE_COT_FILE        13          // 文件传输
#define   _DATABASE_COT_INTROGEN    20          // 响应站召唤
#define   _DATABASE_COT_REQCOGEN    37          // 响应电能召唤

/* 应用层信息体元素定义 -------------------------------------------------------*/
#define  _DATABASE_YX_TOTAL_NUM     24
#define  _DATABASE_YC_TOTAL_NUM     24

/* 应用层信息体起始地址定义 ---------------------------------------------------*/
#define  _DATABASE_YX_START_ADDR   0x0001        // 遥信起始地址
#define  _DATABASE_YC_START_ADDR   0x4001       // 遥测起始地址

#define  _DATABASE_SOELIMIT        32
#define  _DATABASE_SOESENDNUM      10
#define  _DATABASE_NVALIMIT        32
#define  _DATABASE_NVASENDNUM      2
#define  _DATABASE_EVENTLIMIT      32

#define  MAX_DEV_MUN               5            //最大外接设备数量

#define  MaxSize                   2048         //存储主站的循环队列

//主站的读写、链接处理

extern void DLT634_5104_SlaveInit();
extern int Readx(uint8_t *pbuf, uint16_t count, uint8_t port);
extern int WriteX(uint8_t *pbuf, uint16_t count,uint8_t port);
extern void ShutDown();

extern void DatabaseInit();
extern void DBWrite_YX(uint8_t *pBuf);
extern void DBWrite_YC(uint8_t *pBuf);
extern void DBWrite_SOE(uint8_t *pBuf);
extern void DBWrite_NVA(uint8_t *pBuf);
//定义报文结构体
#pragma pack(push,1)
typedef struct
{
    uint8_t Milliseconds_L;   // D7-D0
    uint8_t Milliseconds_H;   // D7-D0
    uint8_t Minutes;            // D5-D0
    uint8_t Hours;            // D4-D0
    uint8_t DayofWeekMonth;    // WEEK(D7-D5)MONTH(D4-D0)
    uint8_t Months;            // D3-D0
    uint8_t Years;            // D6-D0
}_DATABASE_CP56Time2a_t;

typedef struct
{
    struct STATUS
    {
        uint8_t Length;
        union SYMBOL
        {
            uint8_t priority; //任务处理优先级
            uint8_t Lock_ID; //目标设备号
        }symbol;
    }status;

    struct HEAD
    {
        uint8_t TypeID;
        uint8_t VSQ;
        uint8_t COT_L;
        uint8_t COT_H;
        uint8_t PubAddr_L;
        uint8_t PubAddr_H;
    }Head;

    union
       {
           uint8_t    buff[256-sizeof(struct STATUS)-sizeof(struct HEAD)];
           struct
           {
               uint8_t InfoAddr_L;
               uint8_t InfoAddr_H;
               uint8_t QOI;
           }C_100;

           struct
           {
               uint8_t InfoAddr_L;
               uint8_t InfoAddr_H;
               _DATABASE_CP56Time2a_t CP56Time2a;
           }C_103;

           struct
           {
               uint8_t InfoAddr_L;
               uint8_t InfoAddr_H;
               uint8_t QRP;
           }C_105;
           struct
           {
               uint8_t InfoAddr_L;
               uint8_t InfoAddr_H;
               uint8_t COI;
           }C_70;

           struct
           {
               uint8_t InfoAddr_L;
               uint8_t InfoAddr_H;
               uint8_t FBP_L;
               uint8_t FBP_H;
           }C_104;

           union
           {
               struct
               {
                   struct
                   {
                       uint8_t InfoAddr_L;
                       uint8_t InfoAddr_H;
                       uint8_t Value;
                   }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/3];
               }SQ0;

               struct
               {
                   uint8_t InfoAddr_L;
                   uint8_t InfoAddr_H;
                   struct
                   {
                       uint8_t Value;
                   }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/1];
               }SQ1;
           }C_1;

           union
           {
               struct
               {
                   struct
                   {
                       uint8_t InfoAddr_L;
                       uint8_t InfoAddr_H;
                       uint8_t Value;
                   }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/3];
               }SQ0;

               struct
               {
                   uint8_t InfoAddr_L;
                   uint8_t InfoAddr_H;
                   struct
                   {
                       uint8_t Value;
                   }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/1];
               }SQ1;
           }C_3;

           union
           {
               struct
               {
                   struct
                   {
                       uint8_t InfoAddr_L;
                       uint8_t InfoAddr_H;
                       uint8_t Value;
                       _DATABASE_CP56Time2a_t CP56Time2a;
                   }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/10];
               }SQ0;

               struct
               {
                   uint8_t InfoAddr_L;
                   uint8_t InfoAddr_H;
                   struct
                   {
                       uint8_t Value;
                       _DATABASE_CP56Time2a_t CP56Time2a;
                   }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/8];
               }SQ1;
           }C_30;

           union
           {
               struct
               {
                   struct
                   {
                       uint8_t InfoAddr_L;
                       uint8_t InfoAddr_H;
                       uint8_t Value;
                       _DATABASE_CP56Time2a_t CP56Time2a;
                   }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/10];
               }SQ0;

               struct
               {
                   uint8_t InfoAddr_L;
                   uint8_t InfoAddr_H;
                   struct
                   {
                       uint8_t Value;
                       _DATABASE_CP56Time2a_t CP56Time2a;
                   }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/8];
               }SQ1;
           }C_31;

           union
           {
               struct
               {
                   struct
                   {
                       uint8_t InfoAddr_L;
                       uint8_t InfoAddr_H;
                       uint32_t Value;
                       uint8_t QDS;
                   }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/7];
               }SQ0;

               struct
               {
                   uint8_t InfoAddr_L;
                   uint8_t InfoAddr_H;
                   struct
                   {
                       uint32_t Value;
                       uint8_t QDS;
                   }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/5];
               }SQ1;
           }C_9;

           union
           {
               struct
               {
                   struct
                   {
                       uint8_t InfoAddr_L;
                       uint8_t InfoAddr_H;
                       uint32_t Value;
                       uint8_t QDS;
                   }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/7];
               }SQ0;

               struct
               {
                   uint8_t InfoAddr_L;
                   uint8_t InfoAddr_H;
                   struct
                   {
                       uint32_t Value_L;
                       uint8_t QDS;
                   }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/5];
               }SQ1;

           }C_11;

           union
           {
               struct
               {
                   struct
                   {
                       uint8_t InfoAddr_L;
                       uint8_t InfoAddr_H;
                       float Value;
                       uint8_t QDS;
                   }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))/7];
               }SQ0;

               struct
               {
                   uint8_t InfoAddr_L;
                   uint8_t InfoAddr_H;
                   struct
                   {
                       uint32_t Value;
                       uint8_t QDS;
                   }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/5];
               }SQ1;
           }C_13;

           struct
           {
               uint8_t InfoAddr_L;
               uint8_t InfoAddr_H;
               uint8_t SCO_L;
               uint8_t SCO_H;
           }C_45;

           struct
           {
               uint8_t InfoAddr_L;
               uint8_t InfoAddr_H;
               uint8_t DCO_L;
               uint8_t DCO_H;
           }C_46;

           struct
           {
               uint8_t Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD))];
           }C_42;

           struct
           {
               uint8_t InfoAddr_L;
               uint8_t InfoAddr_H;
               uint8_t SN_L;
               uint8_t SN_H;
           }C_200;

           union
           {
               struct
               {
                   uint8_t InfoAddr_L;
                   uint8_t InfoAddr_H;
               }Down;

               struct
               {
                   uint8_t InfoAddr_L;
                   uint8_t InfoAddr_H;
                   uint8_t SN1_L;
                   uint8_t SN1_H;
                   uint8_t SN2_L;
                   uint8_t SN2_H;
                   uint8_t SN3_L;
                   uint8_t SN3_H;
               }Up;
           }C_201;

           union
           {
               struct
               {
                   uint8_t SN1_L;
                   uint8_t SN1_H;
                   uint32_t Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-2)/4];
               }Down;

               struct
               {
                   uint8_t SN_L;
                   uint8_t SN_H;
                   uint8_t PI_L;
                   uint8_t PI_H;
                   struct
                   {
                       uint8_t InfoAddr_L;
                       uint8_t InfoAddr_H;
                       uint8_t Tag;
                       uint8_t Len;
                       uint32_t Value;
                   }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-4)/8];
               }Up;
           }C_202;

           union
           {
               uint8_t SN_L;
               uint8_t SN_H;
               uint8_t PI_L;
               uint8_t PI_H;
               struct
               {
                   uint8_t InfoAddr_L;
                   uint8_t InfoAddr_H;
                   uint8_t Tag;
                   uint8_t Len;
                   uint32_t Value;
               }Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-4)/8];
           }C_203;

           struct
           {
               uint8_t Array[(256-sizeof(struct STATUS)-sizeof(struct HEAD)-4)/1];
           }C_210;
    }Data;
}_DATABASE_PASDU;

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

