#include "base_timer.h"

#include "led.h"

TIM_HandleTypeDef g_timex_handle;

void base_timer_init(uint16_t arr, uint16_t psc)
{
    
    g_timex_handle.Instance = TIM6;
    g_timex_handle.Init.Prescaler = psc;
    g_timex_handle.Init.Period = arr;
    
    HAL_TIM_Base_Init(&g_timex_handle);
    
    HAL_TIM_Base_Start_IT(&g_timex_handle);
    
}


void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == TIM6) {
        __HAL_RCC_TIM6_CLK_ENABLE();
        HAL_NVIC_SetPriority(TIM6_IRQn, 1, 3);
        HAL_NVIC_EnableIRQ(TIM6_IRQn);
    }
    
}


void TIM6_IRQHandler(void)
{

    HAL_TIM_IRQHandler(&g_timex_handle);

}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == TIM6) {
        LED_Toggle(Red);
    }

}


