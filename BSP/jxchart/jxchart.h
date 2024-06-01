#ifndef __JXCHART_H__
#define __JXCHART_H__


#include "stm32f1xx.h"

#define HEAD1               (0x4a)
#define HEAD2               (0x58)
#define CMD_UINT_8_C        (0x01)
#define CMD_UINT_16_C       (0x02)
#define CMD_UINT_32_C       (0x03)
#define CMD_INT_8_C         (0x04)
#define CMD_INT_16_C        (0x05)
#define CMD_INT_32_C        (0x06)
#define CMD_INT_16          (0x07)
#define CMD_INT_24          (0x08)
#define CMD_INT_40          (0x09)
#define CMD_FLOAT_24        (0x0a)
#define CMD_FLOAT_32        (0x0b)




typedef struct{

    uint8_t head[2];
    uint8_t cmd;
    uint8_t length;
    uint8_t data[251];
    uint8_t cs;    
    
}JXCHART_Msg_t;


void JXCHART_Send_UINT8_C(uint8_t ch, uint8_t data);
void JXCHART_Send_UINT16_C(uint8_t ch, uint16_t data);

void JXCHART_Send_INT8_C(uint8_t ch, int8_t data);
void JXCHART_Send_INT16_C(uint8_t ch, int16_t data);


#endif

