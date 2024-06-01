#ifndef __SPI_H__
#define __SPI_H__


#include "stm32f1xx.h"

//-----------------------SPI2-----------------------------

#define SPI2_CS_Port     GPIOB
#define SPI2_MOSI_Port   GPIOB
#define SPI2_MISO_Port   GPIOB
#define SPI2_SCK_Port    GPIOB

#define SPI2_CS_Pin     GPIO_PIN_12
#define SPI2_MOSI_Pin   GPIO_PIN_15
#define SPI2_MISO_Pin   GPIO_PIN_14
#define SPI2_SCK_Pin    GPIO_PIN_13

#define SPI2_CS_GPIO_CLK_ENABLE()       do{__HAL_RCC_GPIOB_CLK_ENABLE();}while(0)
#define SPI2_MOSI_GPIO_CLK_ENABLE()     do{__HAL_RCC_GPIOB_CLK_ENABLE();}while(0)
#define SPI2_MISO_GPIO_CLK_ENABLE()     do{__HAL_RCC_GPIOB_CLK_ENABLE();}while(0)
#define SPI2_SCK_GPIO_CLK_ENABLE()      do{__HAL_RCC_GPIOB_CLK_ENABLE();}while(0)


void spi2_init(void);
uint8_t SPI2_transmit(uint8_t tx);
void SPI2_send(uint8_t data);



//-----------------------SPI1------------------------------

#define SPI1_CS_Port     GPIOA
#define SPI1_MOSI_Port   GPIOA
#define SPI1_MISO_Port   GPIOA
#define SPI1_SCK_Port    GPIOA
           
#define SPI1_CS_Pin     GPIO_PIN_4
#define SPI1_MOSI_Pin   GPIO_PIN_7
#define SPI1_MISO_Pin   GPIO_PIN_6
#define SPI1_SCK_Pin    GPIO_PIN_5
           
#define SPI1_CS_GPIO_CLK_ENABLE()       do{__HAL_RCC_GPIOA_CLK_ENABLE();}while(0)
#define SPI1_MOSI_GPIO_CLK_ENABLE()     do{__HAL_RCC_GPIOA_CLK_ENABLE();}while(0)
#define SPI1_MISO_GPIO_CLK_ENABLE()     do{__HAL_RCC_GPIOA_CLK_ENABLE();}while(0)
#define SPI1_SCK_GPIO_CLK_ENABLE()      do{__HAL_RCC_GPIOA_CLK_ENABLE();}while(0)
           
#define SPI1_CS_Set(x)      do{HAL_GPIO_WritePin(SPI1_CS_Port, SPI1_CS_Pin, x);}while(0)
#define SPI1_MOSI_Set(x)    do{HAL_GPIO_WritePin(SPI1_MOSI_Port, SPI1_MOSI_Pin, x);}while(0)
#define SPI1_MISO_Get()     HAL_GPIO_ReadPin(SPI1_MISO_Port, SPI1_MISO_Pin)
#define SPI1_SCK_Set(x)     do{HAL_GPIO_WritePin(SPI1_SCK_Port, SPI1_SCK_Pin, x);}while(0)

void SPI1_Init(uint8_t cpol, uint8_t cpha);
uint8_t SPI1_Transmit_8(uint8_t* tx, uint8_t* rx, uint16_t len);
uint8_t SPI1_Transmit_16(uint16_t* tx, uint16_t* rx, uint16_t len);
uint8_t SPI1_Transmit_32(uint32_t* tx, uint32_t* rx, uint16_t len);

//------------------------Soft SPI-----------------------------

#define SPI_Soft_CS_Port     GPIOA
#define SPI_Soft_MOSI_Port   GPIOA
#define SPI_Soft_MISO_Port   GPIOA
#define SPI_Soft_SCK_Port    GPIOA

#define SPI_Soft_CS_Pin     GPIO_PIN_4
#define SPI_Soft_MOSI_Pin   GPIO_PIN_7
#define SPI_Soft_MISO_Pin   GPIO_PIN_6
#define SPI_Soft_SCK_Pin    GPIO_PIN_5

#define SPI_Soft_CS_GPIO_CLK_ENABLE()       do{__HAL_RCC_GPIOA_CLK_ENABLE();}while(0)
#define SPI_Soft_MOSI_GPIO_CLK_ENABLE()     do{__HAL_RCC_GPIOA_CLK_ENABLE();}while(0)
#define SPI_Soft_MISO_GPIO_CLK_ENABLE()     do{__HAL_RCC_GPIOA_CLK_ENABLE();}while(0)
#define SPI_Soft_SCK_GPIO_CLK_ENABLE()      do{__HAL_RCC_GPIOA_CLK_ENABLE();}while(0)

#define SPI_Soft_CS_Set(x)      do{HAL_GPIO_WritePin(SPI_Soft_CS_Port, SPI_Soft_CS_Pin, x);}while(0)
#define SPI_Soft_MOSI_Set(x)    do{HAL_GPIO_WritePin(SPI_Soft_MOSI_Port, SPI_Soft_MOSI_Pin, x);}while(0)
#define SPI_Soft_MISO_Get()     HAL_GPIO_ReadPin(SPI_Soft_MISO_Port, SPI_Soft_MISO_Pin)
#define SPI_Soft_SCK_Set(x)     do{HAL_GPIO_WritePin(SPI_Soft_SCK_Port, SPI_Soft_SCK_Pin, x);}while(0)


void SPI_Soft_Init(uint8_t cpol, uint8_t cpha);
void SPI_Soft_WriteData(uint8_t data);
void SPI_Soft_WriteData_16(uint16_t data);
uint8_t SPI_Soft_WriteReadData(uint8_t data);
uint16_t SPI_Soft_WriteReadData_16(uint16_t data);
void SPI_Soft_Transmit(uint8_t* tx, uint8_t* rx, uint16_t len);
#endif
