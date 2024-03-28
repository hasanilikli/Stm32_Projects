/*
 * DS1307.c
 *
 *  Created on: Feb 4, 2024
 *      Author: Hasan Hüseyin İlikli
 */
#include "DS1307.h"

/**
  * @brief  DS1307_Init to get time date values
  * @param User_Value = Time date values received from the user
  *
  * @retval HAL_StatusTypeDef
  */
HAL_StatusTypeDef DS1307_Init(RTC_TypeDef_t*User_Value)
{
  uint8_t Control_data[8] = {0},Ctrl_Value=0;

  Control_data[0] = Decimal_to_BCD(User_Value->SECOND);
  Control_data[1] = Decimal_to_BCD(User_Value->MINUTE);
  if(User_Value->AM_PM_SELECT == Clock_pm_mode)
  {
	   Control_data[2] |=PM_ENABLE;
  }
  else
  {
	  Control_data[2] &= ~(AM_ENABLE);
  }

  Control_data[2] |= Decimal_to_BCD(User_Value->HOURS);
  Control_data[3]  = User_Value->DAY;
  Control_data[4]  = Decimal_to_BCD(User_Value->DATE);
  Control_data[5]  = Decimal_to_BCD(User_Value->MONTH);
  Control_data[6]  = Decimal_to_BCD(User_Value->YEAR);
  Ctrl_Value      |= (User_Value->Freq | SQUARE_WAVE_ENABLE);
  Control_data[7]  = Decimal_to_BCD(Ctrl_Value);

  if(HAL_I2C_Mem_Write(DS1307,DS1307_ADDRES, SECOND_REG,1,Control_data,8,HAL_MAX_DELAY)==HAL_OK)
	  return HAL_OK;
  else
	  return HAL_ERROR;

}

/**
  * @brief  DS1307 STOP DS1307 to stop counting
  * @param  none
  *
  * @retval HAL_StatusTypeDef
  */
HAL_StatusTypeDef DS1307_STOP()
{
  uint8_t CH_stop=0;
   CH_stop = Register_Value_Reading(SECOND_REG);
   CH_stop |= CH_BIT;
  if(HAL_I2C_Mem_Write(DS1307,DS1307_ADDRES, SECOND_REG,1,&CH_stop,1,HAL_MAX_DELAY)==HAL_OK)
  	  return HAL_OK;

    else
  	  return HAL_ERROR;
}

/**
  * @brief  DS1307_START DS1307 to start counting
  * @param  none
  *
  * @retval HAL_StatusTypeDef
  */
HAL_StatusTypeDef DS1307_START()
{
	  uint8_t CH_start=0;
	  CH_start = Register_Value_Reading(SECOND_REG);
	  CH_start &= ~(CH_BIT);

	  if(HAL_I2C_Mem_Write(DS1307,DS1307_ADDRES, SECOND_REG,1,&CH_start,1,HAL_MAX_DELAY)==HAL_OK)
	  	  return HAL_OK;

	    else
	    {
	  	  return HAL_ERROR;
	    }
}

/**
  * @brief  DS1307 Reading To read the current time and date from the DS1307 module
  * @param  Value = Classroom where reading times and dates are recorded
  *
  * @retval HAL_StatusTypeDef
  */
HAL_StatusTypeDef DS1307_Reading(RTC_TypeDef_t* Value)
{
	uint8_t data[7] = {0},state_flag=0;
  if(HAL_I2C_Mem_Read(DS1307,DS1307_ADDRES,SECOND_REG,1,data,7,HAL_MAX_DELAY)== HAL_OK)
    state_flag = 1;

  Value->SECOND = BCD_to_Decimal(data[0]);
  Value->MINUTE = BCD_to_Decimal(data[1]);
  Value->HOURS  = BCD_to_Decimal(data[2]);
  Value->DAY    = BCD_to_Decimal(data[3]);
  Value->DATE   = BCD_to_Decimal(data[4]);
  Value->MONTH  = BCD_to_Decimal(data[5]);
  Value->YEAR   = BCD_to_Decimal(data[6]);

  if(state_flag)
	 return HAL_OK;

     return HAL_ERROR;
}

/**
  * @brief  Register_Value_Reading module to read the desired register address
  * @param  Reg = Writing the register address that the user wants to read
  *
  * @retval uint8_t
  */
uint8_t Register_Value_Reading(uint8_t Reg)
{
	uint8_t Reg_Value=0;

	  if(HAL_I2C_Mem_Read(DS1307,DS1307_ADDRES,Reg,1,&Reg_Value,1,HAL_MAX_DELAY) == HAL_OK)
	  {
		 return Reg_Value;
	  }
	  else
	  {
		 return 0;
	  }
}

/**
  * @brief  Decimal_to_BCD for converting incoming data to binary decimal number
  * @param  uint8_t value = Converting received data to binary code decimal
  *
  * @retval uint8_t
  */
uint8_t Decimal_to_BCD(uint8_t value)
{
	uint8_t m=0,n=0,BCD_value=0;
	BCD_value = value;

	if(value >= 10)
   {
	  m = value / 10;
      n =  value % 10;
      BCD_value = (uint8_t)((m << 4) | n);
   }

	return BCD_value;
}

/**
  * @brief  BCD_to_Decimal converting the data to be sent from decimal to binary
  * @param  uint8_t value = Converting received data to binary code decimal
  *
  * @retval uint8_t
  */
uint8_t BCD_to_Decimal(uint8_t value)
{
	uint8_t m=0,n=0,Bcd_value=0;

	  Bcd_value = value;
	  m = (value >> 4) * 10;
	  n = value & (uint8_t)0x0F;
	  Bcd_value = (uint8_t)(m + n);

   return Bcd_value;
}
