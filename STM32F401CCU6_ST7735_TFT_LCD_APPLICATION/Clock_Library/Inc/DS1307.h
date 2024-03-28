/*
 * DS1307.h
 *
 *  Created on: Feb 4, 2024
 *      Author: Hasan Hüseyin ilikli
 */
#include "stm32f4xx_hal.h"
extern I2C_HandleTypeDef hi2c1;

#define DS1307						&hi2c1
#define DS1307_ADDRES				0xD0	 /*   DS1307 slave address            		  				  */

#define CH_BIT						0x80	 /*   Oscillator enable bit Address    		  				  */
#define SECOND_REG					0x00	 /*   Seconds Reading register Address        				  */
#define MINUTE_REG					0x01	 /*   Minutes Reading register Address        				  */
#define HOURS_REG					0x02	 /*   Hours Reading register Address          				  */
#define DAY_REG						0x03	 /*   Days Reading register Address           				  */
#define DATE_REG					0x04	 /*   Dates Reading register Address          				  */
#define MONTH_REG					0x05	 /*   Months Reading register Address         				  */
#define YEAR_REG					0x06	 /*   Years Reading register Address                          */
#define CONTROL_REG					0x07	 /*   Control  register Address                               */

#define OUTPUT_FREQUENCY_1hz		0x00	 /*   Bit value for setting Output Frequency 1 Hz             */
#define OUTPUT_FREQUENCY_4096khz	0x01	 /*   Bit value for setting Output Frequency 4096 kHz         */
#define OUTPUT_FREQUENCY_8192khz	0x02	 /*   Bit value for setting Output Frequency 8192 kHz         */
#define OUTPUT_FREQUENCY_32768khz	0x03	 /*   Bit value for setting Output Frequency 32768 KHz        */
#define SQUARE_WAVE_ENABLE			0x10	 /*   Enabling square wave output             				  */
#define OUTPUT_CONTROL_ENABLE		0x80	 /*   Output enable bit value                       		  */
#define	PM_ENABLE					0x60	 /*   Enabling PM time mode                        			  */
#define AM_ENABLE					0x40	 /*   Enabling AM time mode                   				  */

typedef enum {Clock_am_mode=0,Clock_pm_mode=1} AMPM_TypeDef_t;
typedef enum {Monday=1, Tuesday=2, Wednesday=3, Thursday=4, Friday=5, Saturday=6, Sunday=7} Weekdays_TypeDef_t;

typedef struct
{
	uint8_t SECOND;
	uint8_t MINUTE;
	uint8_t HOURS;
	uint8_t DATE;
	uint8_t MONTH;
	uint8_t YEAR;
	uint8_t Freq;
	AMPM_TypeDef_t AM_PM_SELECT;
    Weekdays_TypeDef_t DAY;
} RTC_TypeDef_t;

HAL_StatusTypeDef DS1307_Init(RTC_TypeDef_t*User_Value);
HAL_StatusTypeDef DS1307_START();
HAL_StatusTypeDef DS1307_STOP();
HAL_StatusTypeDef DS1307_Reading();
uint8_t Register_Value_Reading(uint8_t Reg);
uint8_t Decimal_to_BCD(uint8_t value);
uint8_t BCD_to_Decimal(uint8_t value);
