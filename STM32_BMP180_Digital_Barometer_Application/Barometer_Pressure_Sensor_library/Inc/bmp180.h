/*
 * bmp180.h
 *
 *  Created on: 30 Oca 2024
 *      Author: user
 */

#ifndef BMP180_H_
#define BMP180_H_
#include "stm32f4xx_hal.h"

/*
 * Connection pin numbers between BMP180 sensor stm32
 *
 * BMP180      STM32F401CCU6    DESCRIPTION
 * SCL	  		PB8(SCL)        I2C serial bus clock input
 * SDA          PB9(SDA)        I2C serial bus data
 * VCC    		3V3             Power supply
 * GND	        GND             Ground
 */

extern I2C_HandleTypeDef hi2c1;
#define BMP180_I2C_PERIPHERAL &hi2c1

/*
 * BMP180 Slave address and read write address
 */
#define BMP180_ADDRESS			0xEE
#define BMP180_WRITE_ADDRESS	0xEE
#define BMP180_READ_ADDRESS		0xEF

/*
 * Each calibration value is 16 bits.
 * A total of 11 bytes of calibration values ​​are read from the following addresses.
 * These values ​​read should not be 0x0000 or 0xFFFF.
 */
#define AC1_REG			0xAA
#define AC2_REG			0xAC
#define AC3_REG			0xAE
#define AC4_REG			0xB0
#define AC5_REG			0xB2
#define AC6_REG			0xB4
#define B1_REG			0xB6
#define B2_REG			0xB8
#define MB_REG			0xBA
#define MC_REG			0xBC
#define MD_REG			0xBE

/*
 * GLOBAL MEMORY MAP
 */
#define OUTPUT_XLSB_REG 	0xF8
#define OUTPUT_LSB_REG		0xF7
#define OUTPUT_MSB_REG		0xF6
#define CTRL_MEAS_REG		0xF4
#define SOFT_RST_REG		0xE0
#define ID_REG				0xD0

/*
 * Check recorded values ​​for different internal speed control setting (oss)
 * Write 0xF4 to the registry
 */
#define TEMPERATURE_CONTROL_VALUE	0x2E  // MAX CONVERSION TIME 4.5ms
#define OSS_0_CONTROL_VALUE         0x34  // MAX CONVERSION TIME 4.5ms
#define OSS_1_CONTROL_VALUE         0x74  // MAX CONVERSION TIME 7.5ms
#define OSS_2_CONTROL_VALUE         0xB4  // MAX CONVERSION TIME 13.5ms
#define OSS_3_CONTROL_VALUE         0xF4  // MAX CONVERSION TIME 25.5ms

/*
 * Temperature or pressure value UT or UP
 * 0xF6 (MSB), 0xF7 (LSB), optionally 0xF8 (XLSB) Reading Register Address
 */
#define UT_UP_MSB_READ_REG			0xF6
#define UT_UP_LSB_READ_REG			0xF7
#define UT_UP_XLSB_READ_REG			0xF8

HAL_StatusTypeDef BMP180_Init();
int32_t BMP180_Temperature_Reading();
float BMP180_Pressure_Reading();

#endif /* BMP180_H_ */
