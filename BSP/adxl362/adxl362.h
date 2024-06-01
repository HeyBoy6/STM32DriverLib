#ifndef __ADXL362_H__
#define __ADXL362_H__

#include "stm32f1xx.h"


#define ADXL362_DEBUG

#ifdef ADXL362_DEBUG
#define ADXL_Debug(fmt, ...) printf("ADXL:"fmt"\r\n", ##__VA_ARGS__)
#else
#define ADXL_Debug(x)
#endif


typedef enum{
    ADXL_X_Axis_8 = 0,
    ADXL_Y_Axis_8,
    ADXL_Z_Axis_8,
    ADXL_X_Axis_12,
    ADXL_Y_Axis_12,
    ADXL_Z_Axis_12,
}ADXL_Channel_t;



void ADXL_Init(void);
uint8_t read_Reg(uint8_t addr);

uint8_t ADXL_Get_Status();

uint16_t ADXL_Get_Data(ADXL_Channel_t ch);


#endif


//#include "./SYSTEM/sys/sys.h"
//#include "./SYSTEM/usart/usart.h"
//#include "./SYSTEM/delay/delay.h"

//#include "led.h"
//#include "key.h"
//#include "exti.h"
//#include "wdg.h"
//#include "base_timer.h"
//#include "spi.h"
//#include "adxl362.h"
//#include "adxl362_def.h"
//#include "jxchart.h"

//int main(void)
//{
//    HAL_Init();                         /* 初始化HAL库 */
//    sys_stm32_clock_init(RCC_PLL_MUL9); /* 设置时钟, 72Mhz */
//    delay_init(72);                     /* 延时初始化 */
//    usart_init(115200);
//    
//    led_init();                         /* LED初始化 */
//    key_init();
//    // spi2_init();
//    SPI_Soft_Init(0, 0);
//    // st7735_init();
//    ADXL_Init();

//    printf("init functions finish\r\n");
//    HAL_GPIO_WritePin(GPIOB,  GPIO_PIN_3, 0);
//    
//    
//    uint8_t xdata = 0;
//    uint8_t ydata = 0;
//    uint8_t zdata = 0;
//    
//    while(1)
//    {
//        xdata = (uint8_t)ADXL_Get_Data(ADXL_X_Axis_8);
//        ydata = (uint8_t)ADXL_Get_Data(ADXL_Y_Axis_8);
//        zdata = (uint8_t)ADXL_Get_Data(ADXL_Z_Axis_8);
//        
//        JXCHART_Send_UINT8_C(1, xdata);
//        JXCHART_Send_UINT8_C(2, ydata);
//        JXCHART_Send_UINT8_C(3, zdata);

////        uint8_t res = read_Reg(STATUS);
////        printf("STATUS: 0x%02x\r\n", res);

////        res = read_Reg(XDATA);
////        printf("XDATA: 0x%02x\r\n", res);
////        res = read_Reg(YDATA);
////        printf("YDATA: 0x%02x\r\n", res);
////        res = read_Reg(ZDATA);
////        printf("ZDATA: 0x%02x\r\n", res);
//        
//        delay_ms(50);        
//    }
//}


