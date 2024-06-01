#ifndef IIC_H__
#define IIC_H__

#include "stm32f1xx.h"


#define IIC_Soft_SDA_Pin        GPIO_PIN_11
#define IIC_Soft_SCL_Pin        GPIO_PIN_10

#define IIC_Soft_SDA_Port       GPIOB
#define IIC_Soft_SCL_Port       GPIOB


#define IIC_Soft_SDA_GPIO_CLK_ENABLE()       do{__HAL_RCC_GPIOB_CLK_ENABLE();}while(0)
#define IIC_Soft_SCL_GPIO_CLK_ENABLE()       do{__HAL_RCC_GPIOB_CLK_ENABLE();}while(0)


#define IIC_Soft_SDA_Set(x)         do{HAL_GPIO_WritePin(IIC_Soft_SDA_Port, IIC_Soft_SDA_Pin, x);}while(0)
#define IIC_Soft_SCL_Set(x)         do{HAL_GPIO_WritePin(IIC_Soft_SCL_Port, IIC_Soft_SCL_Pin, x);}while(0)
#define IIC_Soft_SDA_Get()          HAL_GPIO_ReadPin(IIC_Soft_SDA_Port, IIC_Soft_SDA_Pin)


#define AT24C02_Addr         0xA0u
#define AT24C02_Write        0x00u
#define AT24C02_Read         0x01u



void IIC_Soft_Init(void);

void IIC_Soft_Reset(void);

void IIC_Soft_Start(void);

void IIC_Soft_Stop(void);

uint8_t IIC_Soft_WaitAck(void);

void IIC_Soft_SendAck(void);

void IIC_Soft_SendNoAck(void);

void IIC_Soft_SendByte(uint8_t data);

uint8_t IIC_Soft_ReadByte(void);

#endif
