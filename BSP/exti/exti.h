#ifndef __EXTI_H__
#define __EXTI_H__



#include "stm32f1xx.h"


#define KEY1_Port   GPIOC
#define KEY1_Pin    GPIO_PIN_13

void exti_init(void);



#endif
