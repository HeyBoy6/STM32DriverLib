#ifndef __ST7735_H__
#define __ST7735_H__


#include "stm32f1xx.h"


#define NOP         0x00u              // No Operation
#define SWRESET     0x01u              // Software Reset
#define RDDID       0x04u              // Read Display ID
#define RDDST       0x09u              // Read Display Status
#define RDDPM       0x0au              // Read Display Power Mode
#define RDDMADCTL   0x0bu              // Read Display MADCTL
#define RDDCOLMOD   0x0cu              // Read Display Pixel Format
#define RDDIM       0x0du              // Read Display Image Mode
#define RDDSM       0x0eu              // Read Display Signal Mode
#define RDDSDR      0x0fu              // Read Display Self-diagnostic result
#define SLPIN       0x10u              // Sleep In & Booster Off
#define SLPOUT      0x11u              // Sleep Out & Booster On
#define PTLON       0x12u              // Partial Mode On
#define NORON       0x13u              // Partial Off (Normal)
#define INVOFF      0x20u              // Display Inversion Off (Normal)
#define INVON       0x21u              // Display Inversion On
#define GAMSET      0x26u              // Gamma Curve Select
#define DISPOFF     0x28u              // Display Off
#define DISPON      0x29u              // Display On
#define CASET       0x2au              // Column Address Set
#define RASET       0x2bu              // Row Address Set
#define RAMWR       0x2cu              // Memory Write
#define RGBSET      0x2du              // LUT for 4k,65k,262k Color display
#define RAMRD       0x2eu              // Memory Read
#define PTLAR       0x30u              // Partial Start/End Address Set
#define SCRLAR      0x33u              // Scroll area set
#define TEOFF       0x34u              // Tearing effect line off
#define TEON        0x35u              // Tearing Effect Mode Set & on
#define MADCTL      0x36u              // Memory Data Access Control
#define VSCSAD      0x37u              // Scroll Start Address of RAM
#define IDMOFF      0x38u              // Idle Mode Off
#define IDMON       0x39u              // Idle Mode On
#define COLMOD      0x3au              // Interface Pixel Format
#define RDID1       0xdau              // Read ID1
#define RDID2       0xdbu              // Read ID2
#define RDID3       0xdcu              // Read ID3

#define FRMCTR1     0xb1u               // In Normal Mode (Full Colors)
#define FRMCTR2     0xb2u               // In Idle Mode (8-colors)
#define FRMCTR3     0xb3u               // In Partial Mode + Full Colors
#define INVCTR      0xb4u               // Display Inversion Control
#define PWCTR1      0xc0u               // Power Control Setting
#define PWCTR2      0xc1u               // Power Control Setting
#define PWCTR3      0xc2u               // In Normal Mode (Full Colors)
#define PWCTR4      0xc3u               // In Idle Mode (8-colors)
#define PWCTR5      0xc4u               // In Partial Mode + Full colors
#define VMCTR1      0xc5u               // VCOM Control 1
#define VMOFCTR     0xc7u               // Set VCOM Offset control
#define WRID2       0xd1u               // Set LCM Version Code
#define WRID3       0xd2u               // Customer Project Code
#define NVCTR1      0xd9u               // NVM Control Status
#define NVCTR2      0xdeu               // NVM Read Command
#define NVCTR3      0xdfu               // NVM Write Command Action Code


#define A0_Port     GPIOB
#define A0_Pin      GPIO_PIN_14

#define Reset_Port     GPIOB
#define Reset_Pin      GPIO_PIN_4

#define A0_CMD()       HAL_GPIO_WritePin(A0_Port, A0_Pin, GPIO_PIN_RESET)
#define A0_DATA()      HAL_GPIO_WritePin(A0_Port, A0_Pin, GPIO_PIN_SET)

#define A0_Port_Enable()      do{ __HAL_RCC_GPIOB_CLK_ENABLE(); }while(0)
#define Reset_Port_Enable()   do{ __HAL_RCC_GPIOB_CLK_ENABLE(); }while(0)



void st7735_init(void);

#endif
