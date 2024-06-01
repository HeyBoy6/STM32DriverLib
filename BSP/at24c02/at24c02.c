#include "at24c02.h"
#include "iic.h"

#include "delay.h"


void AT24C02_Init(void)
{
    IIC_Soft_Init();

    AT24C02_Reset();
}

void AT24C02_Reset(void)
{
    IIC_Soft_Reset();

}

uint8_t AT24C02_WriteByte(uint8_t addr, uint8_t data)
{
    IIC_Soft_Start();
    
    IIC_Soft_SendByte(AT24C02_Addr | AT24C02_Write);
    if(IIC_Soft_WaitAck() != 0){
        return 1;
    }
    
    IIC_Soft_SendByte(addr);
    if(IIC_Soft_WaitAck() != 0){
        return 1;
    }
    
    IIC_Soft_SendByte(data);
    if(IIC_Soft_WaitAck() != 0){
        return 1;
    }
    
    IIC_Soft_Stop();
    
    return 0;

}

uint8_t AT24C02_WritePage(uint8_t addr, uint8_t* data, uint16_t len)
{
    uint8_t res = 0;

    if(data==NULL){
        return 1;
    }

    IIC_Soft_Start();
    
    IIC_Soft_SendByte(AT24C02_Addr | AT24C02_Write);
    if(IIC_Soft_WaitAck() != 0){
        return 1;
    }
    
    IIC_Soft_SendByte(addr);
    if(IIC_Soft_WaitAck() != 0){
        return 1;
    }
    
    for(uint16_t i=0; i<len; ++i){
        
    }
    
    IIC_Soft_SendByte(data);
    if(IIC_Soft_WaitAck() != 0){
        return 1;
    }
    
    IIC_Soft_Stop();
    
    return 0;

}

uint8_t AT24C02_CurrentRead(uint8_t* data)
{
    uint8_t res = 0;

    if(data==NULL){
        return 1;
    }

    IIC_Soft_Start();
    
    IIC_Soft_SendByte(AT24C02_Addr | AT24C02_Read);
    if(IIC_Soft_WaitAck() != 0){
        return 1;
    }

    *data = IIC_Soft_ReadByte();
    IIC_Soft_SendNoAck();

    IIC_Soft_Stop();

    return 0;
}


uint8_t AT24C02_RandomRead(uint8_t addr, uint8_t* data)
{
    uint8_t res = 0;

    if(data==NULL){
        return 1;
    }

    IIC_Soft_Start();
    
    IIC_Soft_SendByte(AT24C02_Addr | AT24C02_Write);
    if(IIC_Soft_WaitAck() != 0){
        return 1;
    }

    IIC_Soft_SendByte(addr);
    if(IIC_Soft_WaitAck() != 0){
        return 1;
    }

    IIC_Soft_Start();

    IIC_Soft_SendByte(AT24C02_Addr | AT24C02_Read);
    if(IIC_Soft_WaitAck() != 0){
        return 1;
    }

    *data = IIC_Soft_ReadByte();
    IIC_Soft_SendNoAck();

    IIC_Soft_Stop();

    return 0;

}

uint8_t AT24C02_SequenceRead(uint8_t addr, uint8_t* data, uint16_t len)
{
    uint8_t res = 0;

    if(data==NULL || len==0){
        return 1;
    }

    IIC_Soft_Start();
    
    IIC_Soft_SendByte(AT24C02_Addr | AT24C02_Write);
    if(IIC_Soft_WaitAck() != 0){
        return 1;
    }

    IIC_Soft_SendByte(addr);
    if(IIC_Soft_WaitAck() != 0){
        return 1;
    }

    IIC_Soft_Start();

    IIC_Soft_SendByte(AT24C02_Addr | AT24C02_Read);
    if(IIC_Soft_WaitAck() != 0){
        return 1;
    }

    for(uint16_t i=0; i<len-1; ++i){
        data[i] = IIC_Soft_ReadByte();
        IIC_Soft_SendAck();
    }
    data[len-1] = IIC_Soft_ReadByte();
    IIC_Soft_SendNoAck();

    IIC_Soft_Stop();

    return 0;
}






