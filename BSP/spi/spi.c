#include "spi.h"
#include "delay.h"


static SPI_HandleTypeDef gSpi1Handle;
static SPI_HandleTypeDef gSpiHandle;


void spi2_init(void)
{

    __HAL_RCC_SPI2_CLK_ENABLE();

    gSpiHandle.Instance = SPI2;
    gSpiHandle.Init.Mode = SPI_MODE_MASTER;
    gSpiHandle.Init.Direction = SPI_DIRECTION_2LINES;
    gSpiHandle.Init.DataSize = SPI_DATASIZE_8BIT;
    gSpiHandle.Init.CLKPolarity = SPI_POLARITY_HIGH;
    gSpiHandle.Init.CLKPhase = SPI_PHASE_2EDGE;
    gSpiHandle.Init.NSS = SPI_NSS_SOFT;
    gSpiHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
    gSpiHandle.Init.FirstBit = SPI_FIRSTBIT_MSB;
    gSpiHandle.Init.TIMode = SPI_TIMODE_DISABLE;
    gSpiHandle.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    gSpiHandle.Init.CRCPolynomial = 7;
    
    
    HAL_SPI_Init(&gSpiHandle);
    
    __HAL_SPI_ENABLE(&gSpiHandle);
    
}

void SPI1_Init(uint8_t cpol, uint8_t cpha)
{
    

    gSpi1Handle.Instance = SPI1;
    gSpi1Handle.Init.Mode = SPI_MODE_MASTER;
    gSpi1Handle.Init.Direction = SPI_DIRECTION_2LINES;
    gSpi1Handle.Init.DataSize = SPI_DATASIZE_8BIT;
    
    if(cpol==0){
        gSpi1Handle.Init.CLKPolarity = SPI_POLARITY_LOW;
    }
    else{
        gSpi1Handle.Init.CLKPolarity = SPI_POLARITY_HIGH;
    }
    
    if(cpha==0){
        gSpi1Handle.Init.CLKPhase = SPI_PHASE_1EDGE;
    }
    else{
        gSpi1Handle.Init.CLKPhase = SPI_PHASE_2EDGE;
    }
    
    gSpi1Handle.Init.NSS = SPI_NSS_SOFT;
    gSpi1Handle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
    gSpi1Handle.Init.FirstBit = SPI_FIRSTBIT_MSB;
    gSpi1Handle.Init.TIMode = SPI_TIMODE_DISABLE;
    gSpi1Handle.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    gSpi1Handle.Init.CRCPolynomial = 7;
    
    HAL_SPI_Init(&gSpi1Handle);
    
    //__HAL_SPI_ENABLE(&gSpi1Handle);

}


void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi)
{
    GPIO_InitTypeDef GPIO_Init;
    
    if(hspi->Instance==SPI2){

        SPI2_CS_GPIO_CLK_ENABLE();
        SPI2_MOSI_GPIO_CLK_ENABLE();
        SPI2_MISO_GPIO_CLK_ENABLE();
        SPI2_SCK_GPIO_CLK_ENABLE();
        
        GPIO_Init.Pin = SPI2_CS_Pin;
        GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_Init.Pull = GPIO_PULLUP;
        GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(SPI2_CS_Port, &GPIO_Init);
        
        GPIO_Init.Pin = SPI2_MOSI_Pin;
        GPIO_Init.Mode = GPIO_MODE_AF_PP;
        HAL_GPIO_Init(SPI2_MOSI_Port, &GPIO_Init);
        
        GPIO_Init.Pin = SPI2_MISO_Pin;
        HAL_GPIO_Init(SPI2_MISO_Port, &GPIO_Init);
        
        GPIO_Init.Pin = SPI2_SCK_Pin;
        HAL_GPIO_Init(SPI2_SCK_Port, &GPIO_Init);
    }
    else if(hspi->Instance==SPI1){
        __HAL_RCC_SPI1_CLK_ENABLE();
        
        SPI1_CS_GPIO_CLK_ENABLE();
        SPI1_MOSI_GPIO_CLK_ENABLE();
        SPI1_MISO_GPIO_CLK_ENABLE();
        SPI1_SCK_GPIO_CLK_ENABLE();
        
        GPIO_Init.Pin = SPI1_CS_Pin;
        GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_Init.Pull = GPIO_PULLUP;
        GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(SPI1_CS_Port, &GPIO_Init);
        
        GPIO_Init.Pin = SPI1_MOSI_Pin;
        GPIO_Init.Mode = GPIO_MODE_AF_PP;
        HAL_GPIO_Init(SPI1_MOSI_Port, &GPIO_Init);
        
        GPIO_Init.Pin = SPI1_MISO_Pin;
        HAL_GPIO_Init(SPI1_MISO_Port, &GPIO_Init);
        
        GPIO_Init.Pin = SPI1_SCK_Pin;
        HAL_GPIO_Init(SPI1_SCK_Port, &GPIO_Init);
    }
}

uint8_t SPI2_transmit(uint8_t tx)
{
    uint8_t rx = 0;
    
    HAL_GPIO_WritePin(SPI2_CS_Port, SPI2_CS_Pin, GPIO_PIN_RESET);
    HAL_SPI_TransmitReceive(&gSpiHandle, &tx, &rx, 1, 100);
    HAL_GPIO_WritePin(SPI2_CS_Port, SPI2_CS_Pin, GPIO_PIN_SET);
    
    return rx;
}

void SPI2_send(uint8_t data)
{
    HAL_GPIO_WritePin(SPI2_CS_Port, SPI2_CS_Pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&gSpiHandle, &data, 1, 100);
    HAL_GPIO_WritePin(SPI2_CS_Port, SPI2_CS_Pin, GPIO_PIN_SET);
}


uint8_t SPI1_Transmit_8(uint8_t* tx, uint8_t* rx, uint16_t len)
{
    if(tx==NULL || rx==NULL){
        return 1;
    }

    for(uint16_t i=0; i<len; ++i){
        HAL_GPIO_WritePin(SPI1_CS_Port, SPI2_CS_Pin, GPIO_PIN_RESET);
        HAL_SPI_TransmitReceive(&gSpi1Handle, &tx[i], &rx[i], 1, 1);
        HAL_GPIO_WritePin(SPI1_CS_Port, SPI2_CS_Pin, GPIO_PIN_SET); 
    }
    
    return 0;
}

uint8_t SPI1_Transmit_16(uint16_t* tx, uint16_t* rx, uint16_t len)
{
    if(tx==NULL || rx==NULL){
        return 1;
    }

    for(uint16_t i=0; i<len; ++i){
        HAL_GPIO_WritePin(SPI1_CS_Port, SPI2_CS_Pin, GPIO_PIN_RESET);
        HAL_SPI_TransmitReceive(&gSpi1Handle, (uint8_t*)(&tx[i]), (uint8_t*)(&rx[i]), 2, 1);
        HAL_GPIO_WritePin(SPI1_CS_Port, SPI2_CS_Pin, GPIO_PIN_SET); 
    }
    
    return 0;
}

uint8_t SPI1_Transmit_32(uint32_t* tx, uint32_t* rx, uint16_t len)
{
    if(tx==NULL || rx==NULL){
        return 1;
    }

    for(uint16_t i=0; i<len; ++i){
        HAL_GPIO_WritePin(SPI1_CS_Port, SPI2_CS_Pin, GPIO_PIN_RESET);
        HAL_SPI_TransmitReceive(&gSpi1Handle, (uint8_t*)(&tx[i]), (uint8_t*)(&rx[i]), 4, 1);
        HAL_GPIO_WritePin(SPI1_CS_Port, SPI2_CS_Pin, GPIO_PIN_SET); 
    }
    
    return 0;
}


static uint8_t CPOL = 0;
static uint8_t CPHA = 0;

void SPI_Soft_Init(uint8_t cpol, uint8_t cpha)
{

    GPIO_InitTypeDef GPIO_Init;
    
    SPI_Soft_CS_GPIO_CLK_ENABLE();
    SPI_Soft_MOSI_GPIO_CLK_ENABLE();
    SPI_Soft_MISO_GPIO_CLK_ENABLE();
    SPI_Soft_SCK_GPIO_CLK_ENABLE();
    
    GPIO_Init.Pin = SPI_Soft_CS_Pin;
    GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_Init.Pull = GPIO_PULLUP;
    GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(SPI_Soft_CS_Port, &GPIO_Init);
    
    GPIO_Init.Pin = SPI_Soft_MOSI_Pin;
    HAL_GPIO_Init(SPI_Soft_MOSI_Port, &GPIO_Init);
    
    GPIO_Init.Pin = SPI_Soft_SCK_Pin;
    HAL_GPIO_Init(SPI_Soft_SCK_Port, &GPIO_Init);
    
    GPIO_Init.Pin = SPI_Soft_MISO_Pin;
    GPIO_Init.Mode = GPIO_MODE_INPUT;
    HAL_GPIO_Init(SPI_Soft_MISO_Port, &GPIO_Init);

    CPOL = cpol;
    CPHA = cpha;
    if(CPOL == 0){
        SPI_Soft_SCK_Set(0);
    }
    else{
        SPI_Soft_SCK_Set(1);
    }  
}

void SPI_Soft_WriteData(uint8_t data)
{
    SPI_Soft_CS_Set(0);
    delay_us(5);
    for(uint8_t i=0; i<8; ++i){
        if((data & 0x80) == 0){
            SPI_Soft_MOSI_Set(0);
        }
        else{
            SPI_Soft_MOSI_Set(1);
        }
        if(CPOL == 0){
            SPI_Soft_SCK_Set(1);
            delay_us(10);
            SPI_Soft_SCK_Set(0);
        }
        else{
            SPI_Soft_SCK_Set(0);
            delay_us(10);
            SPI_Soft_SCK_Set(1);
        }  
        delay_us(10);
        data <<= 1;
    }
    SPI_Soft_CS_Set(1);
}


void SPI_Soft_WriteData_16(uint16_t data)
{
    SPI_Soft_CS_Set(0);
    delay_us(5);
    for(uint8_t i=0; i<16; ++i){
        if((data & 0x8000) == 0){
            SPI_Soft_MOSI_Set(0);
        }
        else{
            SPI_Soft_MOSI_Set(0);
        }
        SPI_Soft_SCK_Set(0);
        delay_us(10);
        SPI_Soft_SCK_Set(1);
        delay_us(10);
        data <<= 1;
    }
    SPI_Soft_CS_Set(1);
}


uint8_t SPI_Soft_WriteReadData(uint8_t data)
{
    uint8_t res = 0;
    SPI_Soft_CS_Set(0);
    delay_us(5);
    for(uint8_t i=0; i<8; ++i){
        res <<= 1;
        if((data & 0x80) == 0){
            SPI_Soft_MOSI_Set(0);
        }
        else{
            SPI_Soft_MOSI_Set(1);
        }
        if(CPOL == 0){
            SPI_Soft_SCK_Set(1);
            if(CPHA == 0){
                res |= SPI_Soft_MISO_Get() & 0x01;
            }
            delay_us(10);
            SPI_Soft_SCK_Set(0);
            if(CPHA == 1){
                res |= SPI_Soft_MISO_Get() & 0x01;
            }
        }
        else{
            SPI_Soft_SCK_Set(0);
            if(CPHA == 0){
                res |= SPI_Soft_MISO_Get() & 0x01;
            }
            delay_us(10);
            SPI_Soft_SCK_Set(1);
            if(CPHA == 1){
                res |= SPI_Soft_MISO_Get() & 0x01;
            }
        } 
        delay_us(10);
        data <<= 1;
    }
    SPI_Soft_CS_Set(1);
    
    return res;
}

uint16_t SPI_Soft_WriteReadData_16(uint16_t data)
{
    uint16_t res = 0;
    res |= SPI_Soft_WriteReadData((uint8_t)((data>>8)&0x00ff));
    res <<= 8;
    res |= SPI_Soft_WriteReadData((uint8_t)(data&0x00ff));
    
    return res;
}

void SPI_Soft_Transmit(uint8_t* tx, uint8_t* rx, uint16_t len)
{
    SPI_Soft_CS_Set(0);
    delay_us(5);
    for(uint16_t k=0; k<len; ++k){
        for(uint8_t i=0; i<8; ++i){
            rx[k] <<= 1;
            if((tx[k] & 0x80) == 0){
                SPI_Soft_MOSI_Set(0);
            }
            else{
                SPI_Soft_MOSI_Set(1);
            }
            if(CPOL == 0){
                SPI_Soft_SCK_Set(1);
                if(CPHA == 0){
                    rx[k] |= SPI_Soft_MISO_Get() & 0x01;
                }
                delay_us(10);
                SPI_Soft_SCK_Set(0);
                if(CPHA == 1){
                    rx[k] |= SPI_Soft_MISO_Get() & 0x01;
                }
            }
            else{
                SPI_Soft_SCK_Set(0);
                if(CPHA == 0){
                    rx[k] |= SPI_Soft_MISO_Get() & 0x01;
                }
                delay_us(10);
                SPI_Soft_SCK_Set(1);
                if(CPHA == 1){
                    rx[k] |= SPI_Soft_MISO_Get() & 0x01;
                }
            } 
            delay_us(10);
            tx[k] <<= 1;
        }
    }
    
    SPI_Soft_CS_Set(1);


}



