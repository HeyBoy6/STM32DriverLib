#ifndef __KEY_H
#define __KEY_H

#include "stm32f1xx.h"


#define KEY1_Port   GPIOC
#define KEY2_Port   KEY1_Port
#define KEY3_Port   KEY1_Port
#define KEY4_Port   GPIOD

#define KEY1_Pin    GPIO_PIN_13
#define KEY2_Pin    GPIO_PIN_11
#define KEY3_Pin    GPIO_PIN_12
#define KEY4_Pin    GPIO_PIN_2

#define KEY1    ((uint8_t)0x01u)
#define KEY2    ((uint8_t)0x02u)
#define KEY3    ((uint8_t)0x04u)
#define KEY4    ((uint8_t)0x08u)
#define KEY_ALL ((uint8_t)(KEY1 | KEY2 | KEY3 | KEY4))

#define KEY_Down    (0u)
#define KEY_Up      (1u)

#define KEY_Read(idx) HAL_GPIO_ReadPin(KEY##idx##_Port, KEY##idx##_Pin)


void key_init(void);
uint8_t key_scan(uint8_t keyIdx);

#endif

