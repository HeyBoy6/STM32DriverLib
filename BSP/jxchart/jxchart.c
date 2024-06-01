#include "jxchart.h"
#include "usart.h"
#include <string.h>

static JXCHART_Msg_t gMsg = {0};
static uint8_t gMsgBuf[256] = {0};

static uint8_t checkSum(uint8_t* buf, uint8_t len){
    uint8_t CS = 0;
    for(char i = 0;i< len;i++){
        CS += buf[i];
    }
    CS = ~(CS&0xff);
    return CS;
}

static uint8_t packaging(JXCHART_Msg_t* msg, uint8_t* buf)
{
    if(buf==NULL){
        return 1;
    }

    buf[0] = msg->head[0];
    buf[1] = msg->head[1];
    buf[2] = msg->cmd;
    buf[3] = msg->length;
    memcpy(&buf[4], msg->data, msg->length);
    
    uint8_t cs = checkSum(buf, 4+msg->length);
    buf[4+msg->length] = cs;    
    
    return 0;
}


void JXCHART_Send_UINT8_C(uint8_t ch, uint8_t data)
{
    
    gMsg.head[0] = HEAD1;
    gMsg.head[1] = HEAD2;
    gMsg.cmd = CMD_UINT_8_C;
    gMsg.length = 1+1;
    gMsg.data[0] = ch;
    gMsg.data[1] = data;
    
    packaging(&gMsg, gMsgBuf);
    HAL_UART_Transmit(&g_uart1_handle,gMsgBuf,5+gMsg.length,10);
}
void JXCHART_Send_UINT16_C(uint8_t ch, uint16_t data)
{
    gMsg.head[0] = HEAD1;
    gMsg.head[1] = HEAD2;
    gMsg.cmd = CMD_UINT_16_C;
    gMsg.length = 1+2;
    gMsg.data[0] = ch;
    memcpy(&gMsg.data[1], &data, 2);
    
    packaging(&gMsg, gMsgBuf);
    HAL_UART_Transmit(&g_uart1_handle,gMsgBuf,5+gMsg.length,10);
}

void JXCHART_Send_INT8_C(uint8_t ch, int8_t data)
{
    gMsg.head[0] = HEAD1;
    gMsg.head[1] = HEAD2;
    gMsg.cmd = CMD_INT_8_C;
    gMsg.length = 1+1;
    gMsg.data[0] = ch;
    memcpy(&gMsg.data[1], &data, 1);
    
    packaging(&gMsg, gMsgBuf);
    HAL_UART_Transmit(&g_uart1_handle,gMsgBuf,5+gMsg.length,10);
}

void JXCHART_Send_INT16_C(uint8_t ch, int16_t data)
{
{
    gMsg.head[0] = HEAD1;
    gMsg.head[1] = HEAD2;
    gMsg.cmd = CMD_INT_16_C;
    gMsg.length = 1+2;
    gMsg.data[0] = ch;
    memcpy(&gMsg.data[1], &data, 2);
    
    packaging(&gMsg, gMsgBuf);
    HAL_UART_Transmit(&g_uart1_handle,gMsgBuf,5+gMsg.length,10);
}
}