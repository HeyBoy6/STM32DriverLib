#ifndef __ADXL362_DEF_H__
#define __ADXL362_DEF_H__

#include "stm32f1xx.h"

/************CMD list************/
#define ADXL_WRITE_REG  0x0a
#define ADXL_READ_REG   0x0b
#define ADXL_READ_FIFO  0x0d

/************Register Address list************/
#define DEVID_AD        0x00
#define DEVID_MST       0x01
#define PARTID          0x02
#define REVID           0x03
#define XDATA           0x08
#define YDATA           0x09
#define ZDATA           0x0a
#define STATUS          0x0b
#define FIFO_ENTRIES_L  0x0c
#define FIFO_ENTRIES_H  0x0d
#define XDATA_L         0x0e
#define XDATA_H         0x0f
#define YDATA_L         0x10
#define YDATA_H         0x11
#define ZDATA_L         0x12
#define ZDATA_H         0x13
#define TEMP_L          0x14
#define TEMP_H          0x15
#define SOFT_RESET      0x1f
#define THRESH_ACT_L    0x20
#define THRESH_ACT_H    0x21
#define TIME_ACT        0x22
#define THRESH_INACT_L  0x23
#define THRESH_INACT_H  0x24
#define TIME_INACT_L    0x25
#define TIME_INACT_H    0x26
#define ACT_INACT_CTL   0x27
#define FIFO_CONTROL    0x28
#define FIFO_SAMPLES    0x29
#define INTMAP1         0x2a
#define INTMAP2         0x2b
#define FILTER_CTL      0x2c
#define POWER_CTL       0x2d
#define SELF_TEST       0x2e



#endif
