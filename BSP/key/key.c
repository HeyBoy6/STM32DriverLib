#include "key.h"
#include "delay.h"

void key_init(void)
{
    GPIO_InitTypeDef gpio_init_struct;
    
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    
    gpio_init_struct.Pin = KEY1_Pin | KEY2_Pin | KEY3_Pin;
    gpio_init_struct.Mode = GPIO_MODE_INPUT;
    //gpio_init_struct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(KEY1_Port, &gpio_init_struct);

    gpio_init_struct.Pin = KEY4_Pin;
    HAL_GPIO_Init(KEY4_Port, &gpio_init_struct);
}

uint8_t key_scan(uint8_t keyIdx)
{
    uint8_t res = 0;
    
    if((keyIdx & KEY1) != 0){
        if(KEY_Read(1) == KEY_Down){
            delay_ms(10);
            if(KEY_Read(1) == KEY_Down){
                while(KEY_Read(1) == KEY_Down);
                res |= KEY1;
            }
        }
    }
    if((keyIdx & KEY2) != 0){
        if(KEY_Read(2) == KEY_Down){
            delay_ms(10);
            if(KEY_Read(2) == KEY_Down){
                while(KEY_Read(2) == KEY_Down);
                res |= KEY2;
            }
        }
    }
    if((keyIdx & KEY3) != 0){
        if(KEY_Read(3) == KEY_Down){
            delay_ms(10);
            if(KEY_Read(3) == KEY_Down){
                while(KEY_Read(3) == KEY_Down);
                res |= KEY3;
            }
        }
    }
    if((keyIdx & KEY4) != 0){
        if(KEY_Read(4) == KEY_Down){
            delay_ms(10);
            if(KEY_Read(4) == KEY_Down){
                while(KEY_Read(4) == KEY_Down);
                res |= KEY4;
            }
        }
    }
    return res;

}



