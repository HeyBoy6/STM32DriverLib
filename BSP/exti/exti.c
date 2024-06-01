#include "exti.h"

#include "delay.h"
#include "led.h"

void exti_init(void)
{
    GPIO_InitTypeDef gpio_init_struct;
    __HAL_RCC_GPIOC_CLK_ENABLE();

    gpio_init_struct.Pin = KEY1_Pin;
    gpio_init_struct.Mode = GPIO_MODE_IT_FALLING;
    gpio_init_struct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(KEY1_Port, &gpio_init_struct);
    
    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(KEY1_Pin);
    __HAL_GPIO_EXTI_CLEAR_IT(KEY1_Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    delay_ms(20);
    
    if(GPIO_Pin == KEY1_Pin)
    {
        if(HAL_GPIO_ReadPin(KEY1_Port, KEY1_Pin)==0)
        {
            LED_Toggle(Red);
        }
    }
}


