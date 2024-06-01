#include "led.h"





void led_init(void)
{
    GPIO_InitTypeDef gpio_initstruct;
    
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    gpio_initstruct.Pin = LED_Green_Pin|LED_Red_Pin|LED_Blue_Pin;                      
    gpio_initstruct.Mode = GPIO_MODE_OUTPUT_PP;            /* 推挽输出 */
    gpio_initstruct.Pull = GPIO_PULLUP;                    /* 上拉 */
    gpio_initstruct.Speed = GPIO_SPEED_FREQ_HIGH;          /* 高速 */
    HAL_GPIO_Init(LED_Green_Port, &gpio_initstruct);                /* 初始化LED0引脚 */
    
    gpio_initstruct.Pin = LED_Yellow_Pin;                      
    gpio_initstruct.Mode = GPIO_MODE_OUTPUT_PP;            /* 推挽输出 */
    gpio_initstruct.Pull = GPIO_PULLUP;                    /* 上拉 */
    gpio_initstruct.Speed = GPIO_SPEED_FREQ_HIGH;          /* 高速 */
    HAL_GPIO_Init(LED_Yellow_Port, &gpio_initstruct);                /* 初始化LED0引脚 */
    
    LED_Green_Set(LED_OFF);
    LED_Red_Set(LED_OFF);
    LED_Blue_Set(LED_OFF);
    LED_Yellow_Set(LED_OFF);
}









