#include "wdg.h"

#include "usart.h"



/************************IWDG***************************/


static IWDG_HandleTypeDef g_iwdg_handle;

void iwdg_init(uint8_t prer, uint16_t rlr)
{

    g_iwdg_handle.Instance = IWDG;
    g_iwdg_handle.Init.Prescaler = prer;
    g_iwdg_handle.Init.Reload = rlr;
    HAL_IWDG_Init(&g_iwdg_handle);
}

void iwdg_feed(void)
{
    HAL_IWDG_Refresh(&g_iwdg_handle);
}


/*********************WWDG*****************************/


WWDG_HandleTypeDef g_wwdg_handle;

void wwdg_init(uint8_t tr, uint8_t wr, uint32_t fprer)
{
    g_wwdg_handle.Instance = WWDG;
    g_wwdg_handle.Init.Counter = tr;
    g_wwdg_handle.Init.Window = wr;
    g_wwdg_handle.Init.Prescaler = fprer;
    g_wwdg_handle.Init.EWIMode = WWDG_EWI_ENABLE;
    HAL_WWDG_Init(&g_wwdg_handle);
}

void HAL_WWDG_MspInit(WWDG_HandleTypeDef *hwwdg)
{
    __HAL_RCC_WWDG_CLK_ENABLE();
    
    HAL_NVIC_SetPriority(WWDG_IRQn, 2, 3);
    HAL_NVIC_EnableIRQ(WWDG_IRQn);
}

void WWDG_IRQHandler(void)
{
    HAL_WWDG_IRQHandler(&g_wwdg_handle);
}

void HAL_WWDG_EarlyWakeupCallback(WWDG_HandleTypeDef *hwwdg)
{

    
    HAL_WWDG_Refresh(&g_wwdg_handle);
    //printf("WWDG_EarlyWakeup\r\n");
}



/************************Function test**************************/
#ifdef WDG_TEST

#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"

#include "led.h"
#include "key.h"
#include "exti.h"
#include "wdg.h"


int main(void)
{
    HAL_Init();                         /* 初始化HAL库 */
    sys_stm32_clock_init(RCC_PLL_MUL9); /* 设置时钟, 72Mhz */
    delay_init(72);                     /* 延时初始化 */
    usart_init(115200);
    
    led_init();                         /* LED初始化 */
    key_init();
    exti_init();
    // iwdg_init(IWDG_PRESCALER_32, 1250); // 1s
    
    
    if(__HAL_RCC_GET_FLAG(RCC_FLAG_WWDGRST) != RESET){
        printf("WWDG Reset\r\n");
        __HAL_RCC_CLEAR_RESET_FLAGS();
    }
    else{
        printf("Other Reset\r\n");
    }
    delay_ms(500);
    wwdg_init(0x7f, 0x5f, WWDG_PRESCALER_8);

    HAL_GPIO_WritePin(GPIOB,  GPIO_PIN_3, 0);
    while(1)
    {
        delay_ms(45); 
        //HAL_WWDG_Refresh(&g_wwdg_handle);
    }
}






#endif

