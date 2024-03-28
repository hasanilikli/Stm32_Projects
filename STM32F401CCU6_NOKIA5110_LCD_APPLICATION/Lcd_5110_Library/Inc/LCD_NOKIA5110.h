/*
 * NOKIA5110.h
 *
 *  Created on: Feb 15, 2024
 *      Author: embedded software engineer candidate
 */

#ifndef LCD_NOKIA5110_H_
#define LCD_NOKIA5110_H_

#include "stm32f4xx_hal.h"


extern SPI_HandleTypeDef hspi1;
#define lcd_5510		&hspi1

/*
 * Port and Pin Numbers to Which Display Pins Are Connected
 *
 */
#define RST_PORT		GPIOB         /*    Connection Port of Reset Pin             		        */
#define RST_PIN			GPIO_PIN_0    /*    Pin number to which the Reset Pin is connected          */

#define DC_PORT			GPIOB         /*    Connection Port of DC Pin                 		        */
#define DC_PIN			GPIO_PIN_10   /*    Pin number to which the DC Pin is connected             */

#define SCE_PORT		GPIOB         /*    Connection Port of SCE Pin                		        */
#define SCE_PIN			GPIO_PIN_1    /*    Pin number to which the SCE Pin is connected            */

#define LED_PORT		GPIOB         /*    Connection Port of LED Pin                		        */
#define LED_PIN			GPIO_PIN_2    /*    Pin number to which the LED Pin is connected            */

/*
 * @defgroup Base Addresses of Instruction Sets to control LCD Display
 *
 */
#define Function_Base_Address			0x20   /* Function Set Base Address                        */
#define Y_Base_Address					0x40   /* Y-Address of RAM Base Address                    */
#define X_Base_Address					0x80   /* X-Address of RAM Base Address                    */
#define Temp_Base_Address				0x04   /* temperature Coefficient Base Address             */
#define Bias_Base_Address				0x10   /* Bias Voltage Level Base Address                  */
#define Vop_Base_Address				0x80   /* VOP(Voltage Operation) Base Address              */
#define Display_Config_Base_Address		0x08   /* Display Configuration Base Address               */

/******** Bit definition for Function set register **********************************/

#define Chip_Active_Mode				0x00   /* Function register chip active Macro              */
#define Chip_Powerdown_Mode				0x04   /* Function register chip power down Macro          */
#define Horizontal_Addressing			0x00   /* Function register horizontal Addressing Macro    */
#define Vertical_Addressing				0x02   /* Function register vertical Addressing Macro      */
#define Basic_Instruction_Mode			0x00   /* Function register basic instruction Macro        */
#define Extended_Instruction_Mode		0x01   /* Function register extended instruction Macro     */

/******** Bit definition for Display Control register *******************************/

#define Display_Blank_Mode				0x00   /* Display Control register blank mode Macro        */
#define Display_Normal_Mode				0x04   /* Display Control register normal mode Macro       */
#define Display_Segments_Mode			0x01   /* Display Control register segments mode Macro     */
#define Display_Inverse_Mode			0x05   /* Display Control register inverse mode Macro      */

/******* Bit definition for Temperature Control register ****************************/

#define Vlcd_Temp_Coefficient_0		    0x00   /* Temperature Control register coefficient0 Macro  */
#define Vlcd_Temp_Coefficient_1		    0x01   /* Temperature Control register coefficient1 Macro  */
#define Vlcd_Temp_Coefficient_2		    0x02   /* Temperature Control register coefficient2 Macro  */
#define Vlcd_Temp_Coefficient_3		    0x03   /* Temperature Control register coefficient3 Macro  */

/******** Bit definition for Bias System register **********************************/

#define Bias_System_N7					0x00   /* Bias System register n = 7 value Macro           */
#define Bias_System_N6					0x01   /* Bias System register n = 6 value Macro           */
#define Bias_System_N5					0x02   /* Bias System register n = 5 value Macro           */
#define Bias_System_N4					0x03   /* Bias System register n = 4 value Macro           */
#define Bias_System_N3					0x04   /* Bias System register n = 3 value Macro           */
#define Bias_System_N2					0x05   /* Bias System register n = 2 value Macro           */
#define Bias_System_N1					0x06   /* Bias System register n = 1 value Macro           */
#define Bias_System_N0					0x07   /* Bias System register n = 0 value Macro           */

/******** Bit definition for Voltage Operation register ****************************/

#define Voltage_Operation_0				0x01   /* Voltage Operation Register Vop0 Macro            */
#define Voltage_Operation_1				0x02   /* Voltage Operation Register Vop1 Macro            */
#define Voltage_Operation_2				0x04   /* Voltage Operation Register Vop2 Macro            */
#define Voltage_Operation_3				0x08   /* Voltage Operation Register Vop3 Macro            */
#define Voltage_Operation_4				0x10   /* Voltage Operation Register Vop4 Macro            */
#define Voltage_Operation_5				0x20   /* Voltage Operation Register Vop5 Macro            */
#define Voltage_Operation_6				0x40   /* Voltage Operation Register Vop6 Macro            */

/*
 * Receiving LCD parameters from the user
 *
 */
typedef struct
{
	uint8_t Opertion_Mode;
	uint8_t Addressing_Mode;
	uint8_t Display_Control;
	uint8_t Temperature_Value;
	uint8_t Bias_Value;
	uint8_t Vop_Value;
}LCD_5110_Config;

/*
 * Display Function Prototypes
 *
 */
void lcd_5110_Init(LCD_5110_Config*Lcd_InitStructure);
void Turn_On_Backlight();
void Turn_Off_Backlight();
void lcd_5110_SetCursor(uint8_t row,uint8_t column);
void lcd_5110_String();
void lcd_5110_Clear();
void lcd_5110_command(uint8_t *command,uint8_t length);
void lcd_5110_data(uint8_t *Data,uint8_t length);
void lcd_5110_draw_pixel(uint8_t *pixel);



#endif /* LCD_NOKIA5110_H_ */
