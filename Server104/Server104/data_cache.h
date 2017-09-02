#include <stdlib.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"{
#endif

#define MaxSize 2048
typedef struct{
    unsigned char data[MaxSize];
    int rear;
    int front;
} Queue;

void AddQ(Queue *ptrQ,unsigned char item);
unsigned char DeleteQ(Queue *ptrQ);

extern int Readx(unsigned char *pbuf, unsigned short count, unsigned char port);
extern int WriteX(unsigned char *pbuf, unsigned short count,unsigned char port);
extern void ShutDown();

#ifdef __cplusplus
}
#endif
