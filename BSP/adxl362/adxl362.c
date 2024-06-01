#include "adxl362.h"
#include "adxl362_def.h"

#include "spi.h"


const static uint8_t statusList[8][20] = {
    "DATA_READY\r\n",
    "FIFO_READY\r\n",
    "FIFO_WATERMARK\r\n",
    "FIFO_OVERRUN\r\n",
    "ACT-Activity\r\n",
    "INACT-Inactivity",
    "AWAKE\r\n",
    "ERR_USER_REGS\r\n"
};

static void write_Reg(uint8_t addr, uint8_t data)
{
    uint8_t tx[3] = {0};
    uint8_t rx[3] = {0};
    
    tx[0] = ADXL_WRITE_REG;
    tx[1] = addr;
    tx[2] = data;
    
    SPI_Soft_Transmit(tx, rx, 3);

}

uint8_t read_Reg(uint8_t addr)
{
    uint8_t tx[3] = {0};
    uint8_t rx[3] = {0};
    
    tx[0] = ADXL_READ_REG;
    tx[1] = addr;
    
    SPI_Soft_Transmit(tx, rx, 3);
    
    return rx[2];
}

void ADXL_Init(void)
{
    write_Reg(POWER_CTL, 0x1a);
    
    uint8_t status = ADXL_Get_Status();
    for(uint8_t i=0; i<8; ++i){
        if((status &(0x01u<<i))){
            ADXL_Debug("%s", statusList[i]);
        }
    }
    
}


uint8_t ADXL_Get_Status()
{
    uint8_t status = 0;
    status = read_Reg(STATUS);

    return status;
}

uint16_t ADXL_Get_Data(ADXL_Channel_t ch)
{
    uint16_t res = 0;
    if(ch<=ADXL_Z_Axis_8){
        if(ch==ADXL_X_Axis_8){
            res = read_Reg(XDATA);
        }
        else if(ch==ADXL_Y_Axis_8){
            res = read_Reg(YDATA);
        }
        else if(ch==ADXL_Z_Axis_8){
            res = read_Reg(ZDATA);
        }
    }
    return res;
}
