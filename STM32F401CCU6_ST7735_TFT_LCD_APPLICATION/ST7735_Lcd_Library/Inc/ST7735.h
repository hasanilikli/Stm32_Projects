/*
 * ST7735.h
 *
 *  Created on: 9 Mar 2024
 *      Author: user
 */

#ifndef ST7735_H_
#define ST7735_H_
#include "stm32f4xx_hal.h"
#include "stdint.h"
#include "fonts.h"

extern SPI_HandleTypeDef hspi1;
#define ST7735	  		 &hspi1

/*
 * @defgroup Port and Pin Numbers to Which Display Pins Are Connected
 *
 */
#define RST_PORT  				GPIOB         /* Connection Port of Reset Pin       				   */
#define RST_PIN	  		    	GPIO_PIN_1    /* Pin number to which the Reset Pin is connected        */

#define DC_PORT	  				GPIOB         /* Connection Port of DC Pin							   */
#define DC_PIN	  				GPIO_PIN_0    /* Pin number to which the DC Pin is connected		   */

#define CS_PORT	  		    	GPIOB	      /* Connection Port of CS Pin                             */
#define CS_PIN	  				GPIO_PIN_2    /* Pin number to which the SCE Pin is connected          */

#define ST7735_LCD_ROW			162	   	 	  /* SCREEN 162 ROW OF LINES 							   */
#define ST7735_LCD_COLUMN		132		  	  /* SCREEN 132 COLUMN OF LINES  						   */

/*
 * System function Command List and Description
 * @defgroup System Function command List (1)
 */
#define SWRESET_REG_ADDR		0x01	/* Soft reset command address  												 */
#define RDDID_REG_ADDR			0x04	/* This read byte returns 24-bit display identification information			 */
#define RDDST_REG_ADDR			0x09	/* This command shows the entire current state of the 24-bit display		 */
#define RDDPM_REG_ADDR			0x0A	/* This command shows the current power mode status of the display		     */
#define RDD_MADCTL_REG_ADDR		0x0B	/* This command shows the status of the display in the MADCTL register		 */
#define RDD_COLMOD_REG_ADDR		0x0C	/* This command shows the pixel format selected for the screen			     */
#define RDDIM_REG_ADDR			0x0D	/* This command shows the current state of the screen in the IMAGE recording */
#define RDDSM_REG_ADDR			0X0E	/* This command shows the status of the display in the SIGNAL register		 */

/*
 * @defgroup System Function command List (2)
 */
#define SLPIN_REG_ADDR			0x10    /* This command causes the LCD module to enter sleep mode      				 */
#define SLPOUT_REG_ADDR			0x11    /* This command turns off sleep mode										 */
#define PTLON_REG_ADDR			0x12    /* This command turns on Partial mode  										 */
#define NORON_REG_ADDR 			0x13    /* This command returns the display to normal mode							 */
#define INVOFF_REG_ADDR			0x20    /* This command is used to recover from display inversion mode				 */
#define INVON_REG_ADDR			0x21	/* This command is used to enter into display inversion mode 				 */
#define GAMSET_REG_ADDR			0x26	/* This command is used to select the desired Gamma curve on the screen		 */
#define DISPOFF_REG_ADDR		0x28	/* This command is used to enter into DISPLAY OFF mode						 */
#define DISPON_REG_ADDR			0x29	/* This command is used to recover from DISPLAY OFF mode 					 */
#define CASET_REG_ADDR			0x2A	/* This command determines the desired column on the screen					 */
#define RASET_REG_ADDR			0x2B	/* This command determines the desired row on the screen					 */
#define RAMWR_REG_ADDR			0x2C	/* 132x162x18-bit memory can be written on this command 					 */
#define RAMRD_REG_ADDR			0x2E	/* This command is used to transfer data from frame memory to MCU		     */

/*
 * @defgroup System Function command List (3)
 */
#define PTLAR_REG_ADDR			0x30	/* This command defines the partial mode’s display area						 */
#define TEOFF_REG_ADDR			0x34	/* This command is to turn off Tear Effect Line 							 */
#define TEON_REG_ADDR			0x35	/* This command is to turn on Tear Effect Line								 */
#define MADCTL_REG_ADDR			0x36	/* This command defines read/ write scanning direction of frame memory		 */
#define IDMOFF_REG_ADDR			0x38	/* This command is used to recover from Idle mode on					     */
#define IDMON_REG_ADDR			0x39	/* This command is used to enter into Idle mode on							 */
#define COLMOD_REG_ADDR			0x3A	/* This command is used to define the RGB data format to be transferred		 */
#define RDID1_REG_ADDR			0xDA	/* This read byte returns 8-bit LCD module’s manufacturer ID				 */
#define RDID2_REG_ADDR			0xDB	/* This read byte returns 8-bit LCD module/driver version ID				 */
#define RDID3_REG_ADDR			0xDC	/* This read byte returns 8-bit LCD module/driver ID						 */

/*
 * @defgroup Panel Function Command List (1)
 */
#define FRMCTR1_REG_ADDR		0xB1	/* This command sets the frame frequency of Full color normal mode			 */
#define FRMCTR2_REG_ADDR		0xB2	/* This command sets the frame frequency of Standby mode					 */
#define FRMCTR3_REG_ADDR		0xB3	/* This command sets the frame colors of Partial mode/full colors			 */
#define INVCTR_REG_ADDR			0xB4	/* This command sets the Screen Inversion mode control						 */
#define DISSET5_REG_ADDR		0xB6	/* Adjusts the output waveform and the portion of the non-displayed area     */

/*
 * @defgroup Panel Function Command List (2)
 */
#define PWCTR1_REG_ADDR			0xC0	/* This command sets the GVDD voltage    									 			 */
#define PWCTR2_REG_ADDR			0xC1	/* This command sets the VGH and VGL supply power level						 			 */
#define PWCTR3_REG_ADDR		    0xC2	/* Adjusts the amount of current in the operational amplifier in normal mode/full colors */
#define PWCTR4_REG_ADDR			0xC3	/* Adjusts the amount of current in the operational amplifier in standby mode/8 colors 	 */
#define PWCTR5_REG_ADDR			0xC4	/* Adjusts the amount of current in the Op amplifier in partial mode/full colors		 */
#define VMCTR1_REG_ADDR			0xC5	/* This command Sets VCOMH Voltage														 */
#define VMOFCTR_REG_ADDR		0xC7	/* This command adjusts the VCOM Voltage level to reduce Flicker problem				 */
#define WRID2_REG_ADDR			0xD1	/* This command writes 7-bit data of LCD module version to save in EEPROM				 */

/*
 * @defgroup Panel Function Command List (3)
 */
#define WRID3_REG_ADDR			0xD2	/* This command writes the 8bit data of the project code module to save it in the EEPROM */
#define PWCTR6_REG_ADDR			0xFC	/* Partial mode +Sets the amount of current in the operational amplifier in Standby mode */
#define NVCTR1_REG_ADDR			0xD9	/* This command displays EEPROM check status											 */
#define NVCTR2_REG_ADDR			0xDE	/* This command performs EEPROM command reading					   						 */
#define NVCTR3_REG_ADDR			0xDF	/* This command writes commands to EEPROM												 */

/*
 * @defgroup Panel Function Command List (4)
 */
#define GAMCTRP1_REG_ADDR		0xE0	/* This command Gamma ('+'polarity) Correction Properties Setting			 */
#define GAMCTRN1_REG_ADDR		0xE1	/* This command Gamma ‘-’polarity Correction Properties Setting				 */
#define EXTCTRL_REG_ADDR		0xF0	/* When EXTC PIN =”L”, this command will enable extension command			 */
#define VCOM4L_REG_ADDR			0xFF	/* This command is Vcom 4 level control setting								 */


/*
 * @defgroup Color codes in RGB565 format
 */
#define BLACK_COLOUR			0x0000
#define WHITE_COLOUR			0xFFFF
#define RED_COLOUR				0xF800
#define GREEN_COLOUR			0x07E0
#define BLUE_COLOUR				0x001F
#define YELLOW_COLOUR			0xFFE0
#define PINK_COLOUR				0xF81F
#define ORANGE_COLOUR			0xFCE0
#define TURQUOISE_COLOUR		0x07FF
#define PURPLE_COLOUR			0x6013
#define BROWN_COLOUR			0x9360


/******************  Bit definition for GAMSET register  **************/
#define GAMSET_GAMMA_CURVE_1	0x01
#define GAMSET_GAMMA_CURVE_2	0x02
#define GAMSET_GAMMA_CURVE_3	0x04
#define GAMSET_GAMMA_CURVE_4	0x08

/******************  Bit definition for TEON register  ****************/
#define TEON_TELOM_ON			0x01
#define TEON_TELOM_OFF			0x00

/******************  Bit definition for MADCTL register  **************/
#define MADCTL_NORMAL	 				0x00
#define MADCTL_Y_MIROR					0x80
#define MADCTL_X_MIROR					0x40
#define MADCTL_XY_MIROR					0xC0
#define MADCTL_EXCHANGE					0x20
#define MADCTL_EXCHANGE_Y_MIRROR		0xA0
#define MADCTL_EXCHANGE_X_MIRROR		0x60
#define MADCTL_EXCHANGE_X_Y_MIRROR		0xE0
#define MADCTL_TOP_TO_BOTTOM_REFRESH	0x00
#define MADCTL_BOTTOM_TO_TOP_REFRESH	0x16
#define MADCTL_RGB_COLOR_SELECTOR		0x00
#define MADCTL_BGR_COLOR_SELECTOR		0x08
#define MADCTL_LEFT_TO_RIGHT_REFRESH	0x00


/******************  Bit definition for COLMOD register  **************/
#define INTERFACE_12BIT_PIXEL_FORMAT	0x03
#define INTERFACE_16BIT_PIXEL_FORMAT	0x05
#define INTERFACE_18BIT_PIXEL_FORMAT	0x06

/**
  * @brief display orientation definition
  */
typedef enum
{
  SCREEN_0_DEGREE_ROTATION   = 0, /* Displaying the screen with the starting position direction */
  SCREEN_90_DEGREE_ROTATION  = 1, /* Rotate the screen 90 degrees  */
  SCREEN_180_DEGREE_ROTATION = 2, /* Rotate the screen 180 degrees */
  SCREEN_270_DEGREE_ROTATION = 3, /* Rotate the screen 270 degrees */
  SCREEN_360_DEGREE_ROTATION = 4, /* Rotate the screen 360 degrees */
}Screen_Dırection_Select_t;

typedef enum
{
	Command_Transmit = 0,
	Data_Transmit = 1
}transmission_type_t;

void ST7735_Send_Command(uint8_t command,uint8_t value,transmission_type_t Transmission);
void ST7735_Sending_Command_Data(uint8_t command, uint8_t *data,uint8_t number_of_bytes);
void ST7735_Reading_Command_Data(uint8_t command,uint8_t *data, uint8_t number_of_bytes);
void ST7735_TFT_Init(Screen_Dırection_Select_t starting_position);
void ST7735_Background_Colour(uint16_t colour);
void ST7735_Rectangle_Drawing(uint8_t start_x,uint8_t start_y,uint8_t end_x,uint8_t end_y,uint16_t colour);
void ST7735_Draw_Pixel(uint8_t x,uint8_t y,uint16_t colour);
void ST7735_String(uint8_t starting_column , uint8_t starting_row, char*string, sFONT*Font_select, uint16_t String_colour,uint16_t Background_Colour);
void STT7735_Reset(void);

#endif /* ST7735_H_ */
