#ifndef __LED_H
#define __LED_H

#include "stm32f1xx.h"
#include "stm32f1xx_hal_gpio.h"


#define LED_Green_Port      GPIOC
#define LED_Red_Port        GPIOC
#define LED_Blue_Port       GPIOC
#define LED_Yellow_Port     GPIOA

#define LED_Green_Pin       GPIO_PIN_8
#define LED_Red_Pin         GPIO_PIN_7
#define LED_Blue_Pin        GPIO_PIN_10
#define LED_Yellow_Pin      GPIO_PIN_12


#define LED_ON      (0u)
#define LED_OFF     (1u)

#define LED_Green_Set(cmd)  HAL_GPIO_WritePin(LED_Green_Port,   LED_Green_Pin,  cmd);
#define LED_Red_Set(cmd)    HAL_GPIO_WritePin(LED_Red_Port,     LED_Red_Pin,    cmd);
#define LED_Blue_Set(cmd)   HAL_GPIO_WritePin(LED_Blue_Port,    LED_Blue_Pin,   cmd);
#define LED_Yellow_Set(cmd) HAL_GPIO_WritePin(LED_Yellow_Port,  LED_Yellow_Pin, cmd);

#define LED_Set(led, cmd)   HAL_GPIO_WritePin(LED_##led##_Port,  LED_##led##_Pin, cmd);

#define LED_ALL_Set(cmd) \
    LED_Green_Set(cmd) \
    LED_Red_Set(cmd) \
    LED_Blue_Set(cmd) \
    LED_Yellow_Set(cmd)


#define LED_Toggle(led) HAL_GPIO_TogglePin(LED_##led##_Port,  LED_##led##_Pin)

void led_init(void);











#endif
