#include "iic.h"

#include "delay.h"


void IIC_Soft_Init(void)
{
    IIC_Soft_SDA_GPIO_CLK_ENABLE();
    IIC_Soft_SCL_GPIO_CLK_ENABLE();
        
    GPIO_InitTypeDef GPIO_Init;
    
    GPIO_Init.Pin = IIC_Soft_SCL_Pin;
    GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_Init.Pull = GPIO_PULLUP;
    GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(IIC_Soft_SCL_Port, &GPIO_Init);
    
    GPIO_Init.Pin = IIC_Soft_SDA_Pin;
    GPIO_Init.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_Init.Pull = GPIO_PULLUP;
    GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(IIC_Soft_SDA_Port, &GPIO_Init);
    
}


void IIC_Soft_Start(void)
{
    IIC_Soft_SDA_Set(1);
    IIC_Soft_SCL_Set(1);
    delay_us(2);
    IIC_Soft_SDA_Set(0);
    delay_us(2);
    IIC_Soft_SCL_Set(0);
    delay_us(2);
    
}

void IIC_Soft_Stop(void)
{
    IIC_Soft_SDA_Set(0);
    IIC_Soft_SCL_Set(0);
    delay_us(2);
    IIC_Soft_SCL_Set(1);
    delay_us(2);
    IIC_Soft_SDA_Set(1);
    delay_us(2);
}

uint8_t IIC_Soft_WaitAck(void)
{
    uint8_t ack = 0;
    uint8_t timeOut = 0;
    
    IIC_Soft_SDA_Set(1);
    // delay_us(2);
    IIC_Soft_SCL_Set(1);
    delay_us(2);
    
    while(IIC_Soft_SDA_Get()){
        timeOut++;
        if(timeOut>250){
            IIC_Soft_Stop();
            ack = 1;
            break;
        }   
    }
    IIC_Soft_SCL_Set(0);
    delay_us(2);
    
    return ack;
}

void IIC_Soft_Reset(void)
{
    IIC_Soft_Start();
    
    IIC_Soft_SDA_Set(1);
    for(uint8_t i=0; i<9; ++i){
        IIC_Soft_SCL_Set(0);
        delay_us(2);
        IIC_Soft_SCL_Set(1);
        delay_us(2);
    }
    IIC_Soft_Start();
    IIC_Soft_Stop();
}


void IIC_Soft_SendByte(uint8_t data)
{
    for(uint8_t i=0; i<8; ++i){
        if((data&0x80u)!=0){
            IIC_Soft_SDA_Set(1);
        }
        else{
            IIC_Soft_SDA_Set(0);
        }
        delay_us(2);
        IIC_Soft_SCL_Set(1);
        delay_us(2);
        IIC_Soft_SCL_Set(0);
        data <<= 1;
    }
    
    IIC_Soft_SCL_Set(0);
}


void IIC_Soft_SendAck(void)
{
    IIC_Soft_SDA_Set(0);
    delay_us(2);
    IIC_Soft_SCL_Set(1);
    delay_us(2);
    IIC_Soft_SCL_Set(0);
    delay_us(2);
    IIC_Soft_SDA_Set(1);
    delay_us(2);
}

void IIC_Soft_SendNoAck(void)
{
    IIC_Soft_SDA_Set(1);
    delay_us(2);
    IIC_Soft_SCL_Set(1);
    delay_us(2);
    IIC_Soft_SCL_Set(0);
    delay_us(2);
}

uint8_t IIC_Soft_ReadByte(void)
{
    uint8_t data = 0;

    for(uint8_t i=0; i<8; ++i){
        data <<= 1;
        IIC_Soft_SCL_Set(1);
        delay_us(2);
        if(IIC_Soft_SDA_Get() != 0){
            data |= 0x01;
        }
        IIC_Soft_SCL_Set(0);
        delay_us(2);
    }
}