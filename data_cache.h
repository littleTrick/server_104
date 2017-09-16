#ifndef DATA_CACHE_H
#define DATA_CACHE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void DatabaseInit();
//从网络读取数据,从从循环队列中读取数据
int readTCP(unsigned char *pbuf, unsigned short size);
//网络写数
int writeTCP(const char *data, int sz);
//关闭与主站的链接
void ShutDown();
int readSerialPort1(unsigned char *pbuf, unsigned short size);
int writeSerialPort1(const char *data, int sz);
int Readx(unsigned char *pbuf, unsigned short count, unsigned char port);
//写入数据到外设中
int WriteX(uint8_t *pbuf, unsigned short count, unsigned char port);
//写入总召唤的遥信报文
void DBWrite_YX( uint8_t *pBuf);
//读取总召唤遥信报文,信息地址为addr+num,存储到pbuf指向的地方,重组１０４报文
uint8_t DBRead_YX(unsigned short addr,uint8_t num,uint8_t *pbuf);
//写入遥测报文
void DBWrite_YC(uint8_t *pBuf);
//读取遥测报文
uint8_t DBRead_YC(uint32_t addr,uint8_t num,uint8_t *pbuf);
//写入ＳＯＥ
void DBWrite_SOE(uint8_t *pBuf);
//判断ＳＯＥ是否有数值
uint8_t DBCheck_SOE(uint8_t ID);
//读取ＳＯＥ数值，设备ＩＤ读取ＳＯＥ数据至pbuf中
uint8_t DBRead_SOE(uint8_t ID,uint8_t *pbuf);
void DBWrite_NVA(uint8_t *pBuf);
uint8_t DBCheck_NVA(uint8_t ID);
uint8_t DBReset_NVA(uint8_t ID);
uint8_t DBRead_NVA(uint8_t ID,uint8_t *pbuf);
uint8_t DBSend(uint8_t *pbuf);

#ifdef __cplusplus
}
#endif

#endif
