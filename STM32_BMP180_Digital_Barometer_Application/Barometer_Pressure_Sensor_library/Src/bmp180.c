/*
 *  Created on: 30 Oca 2024
 *      Author: Hasan Hüseyin İlikli
 */
#include "bmp180.h"
uint8_t Calibration_values[2] = {0};
int16_t UT=0,UP=0;
int32_t Temperature=0,X1=0,X2=0,X3,T,B3,B5,B6,P,AC1,AC2,AC3,AC4,AC5,AC6,B1,B2,MB,MC,MD;
unsigned long B4,B7;
uint32_t UncomPresure;
float presure,presureATM;
HAL_StatusTypeDef BMP180_Init()
{
  HAL_I2C_Mem_Read(BMP180_I2C_PERIPHERAL, BMP180_WRITE_ADDRESS,AC1_REG, 1,Calibration_values,2,5);
  AC1 = (int16_t)((Calibration_values[0] << 8) | Calibration_values[1]);
  HAL_I2C_Mem_Read(BMP180_I2C_PERIPHERAL, BMP180_WRITE_ADDRESS,AC2_REG, 1,Calibration_values,2,5);
  AC2 = (int16_t)((Calibration_values[0] << 8) | Calibration_values[1]);
  HAL_I2C_Mem_Read(BMP180_I2C_PERIPHERAL, BMP180_WRITE_ADDRESS,AC3_REG, 1,Calibration_values,2,5);
  AC3 = (int16_t)((Calibration_values[0] << 8) | Calibration_values[1]);
  HAL_I2C_Mem_Read(BMP180_I2C_PERIPHERAL, BMP180_WRITE_ADDRESS,AC4_REG, 1,Calibration_values,2,5);
  AC4 = (int16_t)((Calibration_values[0] << 8) | Calibration_values[1]);
  HAL_I2C_Mem_Read(BMP180_I2C_PERIPHERAL, BMP180_WRITE_ADDRESS,AC5_REG, 1,Calibration_values,2,5);
  AC5 = (int16_t)((Calibration_values[0] << 8) | Calibration_values[1]);
  HAL_I2C_Mem_Read(BMP180_I2C_PERIPHERAL, BMP180_WRITE_ADDRESS,AC6_REG, 1,Calibration_values,2,5);
  AC6 = (int16_t)((Calibration_values[0] << 8) | Calibration_values[1]);
  HAL_I2C_Mem_Read(BMP180_I2C_PERIPHERAL, BMP180_WRITE_ADDRESS,B1_REG, 1,Calibration_values,2,5);
  B1 = (int16_t)((Calibration_values[0] << 8) | Calibration_values[1]);
  HAL_I2C_Mem_Read(BMP180_I2C_PERIPHERAL, BMP180_WRITE_ADDRESS,B2_REG, 1,Calibration_values,2,5);
  B2 = (int16_t)((Calibration_values[0] << 8) | Calibration_values[1]);
  HAL_I2C_Mem_Read(BMP180_I2C_PERIPHERAL, BMP180_WRITE_ADDRESS,MB_REG, 1,Calibration_values,2,5);
  MB = (int16_t)((Calibration_values[0] << 8) | Calibration_values[1]);
  HAL_I2C_Mem_Read(BMP180_I2C_PERIPHERAL, BMP180_WRITE_ADDRESS,MC_REG, 1,Calibration_values,2,5);
  MC = (int16_t)((Calibration_values[0] << 8) | Calibration_values[1]);
  HAL_I2C_Mem_Read(BMP180_I2C_PERIPHERAL, BMP180_WRITE_ADDRESS,MD_REG, 1,Calibration_values,2,5);
  MD = (int16_t)((Calibration_values[0] << 8) | Calibration_values[1]);

   return HAL_OK;
}

int32_t BMP180_Temperature_Reading()
{
  uint8_t Data_write[1];
  uint8_t UT_Data[2];
  Data_write[0] = 0x2E;
  HAL_I2C_Mem_Write(BMP180_I2C_PERIPHERAL,BMP180_WRITE_ADDRESS,CTRL_MEAS_REG,1,Data_write,1,10);
  HAL_Delay(5);
  HAL_I2C_Mem_Read(BMP180_I2C_PERIPHERAL, BMP180_READ_ADDRESS,UT_UP_MSB_READ_REG, 1,&UT_Data[0],1,5);
  HAL_I2C_Mem_Read(BMP180_I2C_PERIPHERAL, BMP180_READ_ADDRESS,UT_UP_LSB_READ_REG, 1,&UT_Data[1],1,5);
  UT = (int16_t)((UT_Data[0] << 8) | UT_Data[1]);
  X1 = (UT - AC6)*AC5/32768;
  X2 = (MC*2048)/(X1 + MD);
  B5 = X1 + X2;
  T  = (B5 + 8)/16;
  Temperature = T*0.1;
  return Temperature;
}

float BMP180_Pressure_Reading()
{
  uint8_t Data_read[3] = {0};
  uint8_t Data_write[1];
  Data_write[0] = (0x34 |(0x03<<6));
  HAL_I2C_Mem_Write(BMP180_I2C_PERIPHERAL, BMP180_WRITE_ADDRESS,CTRL_MEAS_REG,1,Data_write,1,100);
  HAL_Delay(26);
  HAL_I2C_Mem_Read(BMP180_I2C_PERIPHERAL, BMP180_READ_ADDRESS, UT_UP_MSB_READ_REG, 1,Data_read, 3, 100);
  UncomPresure = ((Data_read[0]<<16) | (Data_read[1]<<8)| Data_read[2])>> (8-(uint8_t)(0x03));
  B6 = B5-4000;
  X1 = (B2*(B6*B6/4096))/2048;
  X2 = AC2 * B6/2048;
  X3 = X1+X2;
  B3 = (((AC1*4 + X3)<<(uint8_t)0x03)+2)/4;
  X1 = AC3 * B6/8192;
  X2 = (B1*(B6*B6/4096))/65536;
  X3 = ((X1+X2)+2)/4;
  B4 = AC4 * (unsigned long)(X3+32768)/32768;
  B7 = ((unsigned long)UP-B3)*(50000 >> (uint8_t)0x03);
  if(B7<0x80000000)
	  presure=(B7*2)/B4;
  else
	  presure=(B7/ B4)*2;
  X1=(presure/256)*(presure/256);
  X1=(X1*3038)/65536;
  X2=(-7357*presure)/65536;
  presure= presure+(X1+X2+3791)/16; // hpa cinsinden değeri
  presureATM = presure*0.00000986923;
  return presureATM;


}
