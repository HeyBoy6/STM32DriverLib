#ifndef AT24C02_H__
#define AT24C02_H__

#include "stm32f1xx.h"


#define AT24C02_Addr         0xA0u
#define AT24C02_Write        0x00u
#define AT24C02_Read         0x01u




void AT24C02_Init(void);

void AT24C02_Reset(void);

uint8_t AT24C02_WriteByte(uint8_t addr, uint8_t data);

uint8_t AT24C02_WritePage(uint8_t addr, uint8_t* data, uint16_t len);

uint8_t AT24C02_CurrentRead(uint8_t* data);

uint8_t AT24C02_RandomRead(uint8_t addr, uint8_t* data);

uint8_t AT24C02_SequenceRead(uint8_t addr, uint8_t* data);





#endif
