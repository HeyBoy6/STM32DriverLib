#include "st7735.h"
#include "spi.h"
#include "delay.h"



static uint8_t st7735_send_cmd(uint8_t cmd)
{
    A0_CMD();
    // SPI2_send(cmd);    
    // SPI2_transmit(cmd);  
    SPI_Soft_WriteData(cmd);
}


static uint8_t st7735_send_data(uint8_t data)
{
    A0_DATA();
    // SPI2_send(data);    
    // SPI2_transmit(data);
    SPI_Soft_WriteData(data);
}


// void st7735_init(void)
// {
//     GPIO_InitTypeDef GPIO_Init;
    
//     GPIO_Init.Pin = A0_Pin;
//     GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
//     GPIO_Init.Pull = GPIO_PULLUP;
//     GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
//     HAL_GPIO_Init(A0_Port, &GPIO_Init);

//     GPIO_Init.Pin = Reset_Pin;
//     HAL_GPIO_Init(Reset_Port, &GPIO_Init);

//     A0_Port_Enable();
//     Reset_Port_Enable();

//     st7735_send_cmd(SWRESET);
//     delay_ms(120);

//     st7735_send_cmd(SLPOUT);

//     st7735_send_cmd(NORON);

//     st7735_send_cmd(INVOFF);

//     st7735_send_cmd(GAMSET);
//     st7735_send_data(0x01);

//     st7735_send_cmd(IDMOFF);

//     st7735_send_cmd(COLMOD);
//     st7735_send_data(0x05);

//     st7735_send_cmd(GAMSET);
//     st7735_send_data(0x01);

//     st7735_send_cmd(DISPON);

//     st7735_send_cmd(CASET);
//     st7735_send_data(0x00);
//     st7735_send_data(0x00);
//     st7735_send_data(0x00);
//     st7735_send_data(0x0f);

//     st7735_send_cmd(RASET);
//     st7735_send_data(0x00);
//     st7735_send_data(0x00);
//     st7735_send_data(0x00);
//     st7735_send_data(0x0f);

//     st7735_send_cmd(RAMWR);

//     for(uint8_t i=0; i<16; ++i){
//         for(uint8_t j=0; j<16; ++j){
//             st7735_send_data(0xaa);

//         }

//     }

// }



void st7735_init(void)
{
    
     GPIO_InitTypeDef GPIO_Init;
    
     GPIO_Init.Pin = A0_Pin;
     GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
     GPIO_Init.Pull = GPIO_PULLUP;
     GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
     HAL_GPIO_Init(A0_Port, &GPIO_Init);

     GPIO_Init.Pin = Reset_Pin;
     HAL_GPIO_Init(Reset_Port, &GPIO_Init);

     A0_Port_Enable();
     Reset_Port_Enable();
    
    
	st7735_send_cmd(0x11);		//sleep out
	delay_ms(120);

	//------------------------------------ST7735S Frame Rate-----------------------------------------// 
	st7735_send_cmd(0xB1); 
	st7735_send_data(0x05); 
	st7735_send_data(0x3C); 
	st7735_send_data(0x3C); 
	st7735_send_cmd(0xB2); 
	st7735_send_data(0x05); 
	st7735_send_data(0x3C); 
	st7735_send_data(0x3C); 
	st7735_send_cmd(0xB3); 
	st7735_send_data(0x05); 
	st7735_send_data(0x3C); 
	st7735_send_data(0x3C); 
	st7735_send_data(0x05); 
	st7735_send_data(0x3C); 
	st7735_send_data(0x3C); 
	//------------------------------------End ST7735S Frame Rate-----------------------------------------// 
	st7735_send_cmd(0xB4); //Dot inversion 
	st7735_send_data(0x03); 

	//------------------------------------ST7735S Power Sequence-----------------------------------------// 
	st7735_send_cmd(0xC0); 
	st7735_send_data(0x28); 
	st7735_send_data(0x08); 
	st7735_send_data(0x04); 
	st7735_send_cmd(0xC1); 
	st7735_send_data(0XC0); 
	st7735_send_cmd(0xC2); 
	st7735_send_data(0x0D); 
	st7735_send_data(0x00); 
	st7735_send_cmd(0xC3); 
	st7735_send_data(0x8D); 
	st7735_send_data(0x2A); 
	st7735_send_cmd(0xC4); 
	st7735_send_data(0x8D); 
	st7735_send_data(0xEE); 
	//---------------------------------End ST7735S Power Sequence-------------------------------------// 
	 
	st7735_send_cmd(0xC5); //VCOM 
	st7735_send_data(0x1A); 
	 
	st7735_send_cmd(0x36); //MX, MY, RGB mode 
	st7735_send_data(0x08); 
	//------------------------------------ST7735S Gamma Sequence-----------------------------------------// 
	 
	st7735_send_cmd(0xE0); 
	st7735_send_data(0x04); 
	st7735_send_data(0x22); 
	st7735_send_data(0x07); 
	st7735_send_data(0x0A); 
	st7735_send_data(0x2E); 
	st7735_send_data(0x30); 
	st7735_send_data(0x25); 
	st7735_send_data(0x2A); 
	st7735_send_data(0x28); 
	st7735_send_data(0x26); 
	st7735_send_data(0x2E); 
	st7735_send_data(0x3A); 
	st7735_send_data(0x00); 

	st7735_send_data(0x01); 
	st7735_send_data(0x03); 
	st7735_send_data(0x13); 
	st7735_send_cmd(0xE1); 
	st7735_send_data(0x04); 
	st7735_send_data(0x16); 
	st7735_send_data(0x06); 
	st7735_send_data(0x0D); 
	st7735_send_data(0x2D); 
	st7735_send_data(0x26); 
	st7735_send_data(0x23); 
	st7735_send_data(0x27); 
	st7735_send_data(0x27); 
	st7735_send_data(0x25); 
	st7735_send_data(0x2D); 
	st7735_send_data(0x3B); 
	st7735_send_data(0x00); 
	st7735_send_data(0x01); 
	st7735_send_data(0x04); 
	st7735_send_data(0x13); 
	//------------------------------------End ST7735S Gamma Sequence-----------------------------------------// 

	st7735_send_cmd(0x3A); //65k mode 
	st7735_send_data(0x05); 
	st7735_send_cmd(0x29); //Display on 
	st7735_send_cmd(0x2c);

delay_ms(1000);

        st7735_send_cmd(CASET);
    st7735_send_data(0x00);
    st7735_send_data(0x00);
    st7735_send_data(0x00);
    st7735_send_data(0x80);

    st7735_send_cmd(RASET);
    st7735_send_data(0x00);
    st7735_send_data(0x00);
    st7735_send_data(0x00);
    st7735_send_data(0x80);

    st7735_send_cmd(RAMWR);

    for(uint8_t i=0; i<128; ++i){
        for(uint8_t j=0; j<128; ++j){
            st7735_send_data(0xAA);

        }

    }


}