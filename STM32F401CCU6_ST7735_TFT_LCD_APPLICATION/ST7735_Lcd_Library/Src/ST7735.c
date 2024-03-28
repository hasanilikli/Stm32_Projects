/*
 * ST7735.c
 *
 *  Created on: 9 Mar 2024
 *      Author: user
 */
#include "ST7735.h"
uint8_t new_row_number=0;
uint8_t new_column_number=0;

/*
 * @brief ST7735_Send_Command = Used to send commands to the screen
 *
 * @param command = Holds the registration address to be sent
 * @param value = Holds the value to be written into the record address
 * @param Transmission = Choosing whether to send a command or send a value to the registration address
 *
 * @retval None
 */
void ST7735_Send_Command(uint8_t command,uint8_t value,transmission_type_t Transmission)
{
	uint8_t Command[1]= {0};
	Command[0]=command;
	if (Transmission == Command_Transmit) {
		HAL_GPIO_WritePin(DC_PORT, DC_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_RESET);
		HAL_SPI_Transmit_DMA(ST7735, Command, 1);
		HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_SET);
	} else {
		HAL_GPIO_WritePin(DC_PORT, DC_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_RESET);
		HAL_SPI_Transmit_DMA(ST7735, Command, 1);
		HAL_GPIO_WritePin(DC_PORT, DC_PIN, GPIO_PIN_SET);
		HAL_SPI_Transmit_DMA(ST7735,&value,1);
		HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_SET);
	}
}

/*
 *@brief ST7735_Sending_Command_Data = Used to write multiple values to the register address
 *
 *@param command = holds the registration address to be written
 *@param data = holds the starting address of the values to be sent
 *@param number_of_bytes = Specifies the number of bytes to send
 *
 *@retval None
 */
void ST7735_Sending_Command_Data(uint8_t command, uint8_t *data,uint8_t number_of_bytes)
{
    uint8_t Command_write[1]={0};
    Command_write[0]=command;

	HAL_GPIO_WritePin(DC_PORT, DC_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_RESET);
	HAL_SPI_Transmit_DMA(ST7735,Command_write,1);
	HAL_GPIO_WritePin(DC_PORT, DC_PIN, GPIO_PIN_SET);
	HAL_SPI_Transmit_DMA(ST7735,&(*data),number_of_bytes);
	HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_SET);
}

/*
 * @brief ST7735_Reading_Command_Data = Shows the value written in the desired record address
 *
 * @param reg = Holds the register address to be read
 * @param data = Shows the variable that will hold the value read from the register address
 * @param number_of_bytes = Specifies the number of bytes to read
 *
 * @retval None
 */
void ST7735_Reading_Command_Data(uint8_t reg,uint8_t *data, uint8_t number_of_bytes)
{
	uint8_t Reg_Read[1]={0};
	Reg_Read[0]=reg;

	HAL_GPIO_WritePin(DC_PORT, DC_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_RESET);
	HAL_SPI_Transmit_DMA(ST7735,Reg_Read,1);
	HAL_GPIO_WritePin(DC_PORT, DC_PIN, GPIO_PIN_SET);
	HAL_SPI_Receive_DMA(ST7735,&(*data),number_of_bytes);
	HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_SET);
}

/* @brief ST7735_Background_Colour = Sets the screen background color
 * @param colour = Holds the background color value
 *
 * @retval None
 */
void ST7735_Background_Colour(uint16_t colour)
{
	for(uint8_t i=0; i<new_row_number; i++)
	{
		for(uint8_t j=0; j<new_column_number; j++)
		{
         ST7735_Draw_Pixel(j, i, colour);
		}
	}

}

/*
 * @brief ST7735_TFT_Init = Performs screen initialization
 *
 * @param starting_position = Gets the value to reflect the screen in the desired direction
 *
 * @retval None
 */
void ST7735_TFT_Init(Screen_Dırection_Select_t starting_position)
{
	uint8_t MADCTL_REG_VALUE=0;
    STT7735_Reset();
	ST7735_Send_Command(SLPOUT_REG_ADDR,0,Command_Transmit);
	ST7735_Send_Command(NORON_REG_ADDR,0,Command_Transmit);
	ST7735_Send_Command(INVOFF_REG_ADDR,0,Command_Transmit);
	ST7735_Send_Command(IDMOFF_REG_ADDR,0,Command_Transmit);
	ST7735_Send_Command(DISPON_REG_ADDR,0,Command_Transmit);
	ST7735_Send_Command(COLMOD_REG_ADDR,INTERFACE_16BIT_PIXEL_FORMAT,Data_Transmit);


	switch(starting_position)
	{
	case SCREEN_0_DEGREE_ROTATION:
		MADCTL_REG_VALUE = 0;
		new_column_number = ST7735_LCD_COLUMN;
		new_row_number = ST7735_LCD_ROW;
		break;

	case SCREEN_90_DEGREE_ROTATION:
		MADCTL_REG_VALUE = MADCTL_EXCHANGE_X_MIRROR;
		new_column_number = ST7735_LCD_ROW;
		new_row_number = ST7735_LCD_COLUMN;
		break;

	case SCREEN_180_DEGREE_ROTATION:
		MADCTL_REG_VALUE = MADCTL_XY_MIROR;
		new_column_number = ST7735_LCD_COLUMN;
		new_row_number = ST7735_LCD_ROW;
		break;

	case SCREEN_270_DEGREE_ROTATION:
		MADCTL_REG_VALUE = MADCTL_EXCHANGE_Y_MIRROR;
		new_column_number = ST7735_LCD_ROW;
		new_row_number = ST7735_LCD_COLUMN;
		break;

	case SCREEN_360_DEGREE_ROTATION:
		MADCTL_REG_VALUE = 0;
		new_column_number = ST7735_LCD_COLUMN;
		new_row_number = ST7735_LCD_ROW;
		break;
	}
	 ST7735_Send_Command(MADCTL_REG_ADDR,MADCTL_REG_VALUE, Data_Transmit);
}

/*
 * @brief ST7735_Rectangle_Drawing = It is used to draw rectangles in the desired color and size
 *
 * @param start_x = Specifies the starting x value
 * @param start_y = Specifies the starting y value
 * @param end_x = Specifies the ending x value
 * @param end_y = Specifies the ending y value
 * @param colour = Gets the specified color value
 *
 * @retval None
 */
void ST7735_Rectangle_Drawing(uint8_t start_x,uint8_t start_y,uint8_t end_x,uint8_t end_y,uint16_t colour)
{
	if((end_x > new_column_number) || (end_y > new_row_number))
		return;

	for(uint8_t i=start_y; i<end_y+1;)
	{
		for(uint8_t j=start_x; j<end_x+1; j++)
		{
		  ST7735_Draw_Pixel(j, i, colour);
		}
		i+=end_y-start_y;
	}
	for(uint8_t i=start_x; i<end_x+1;)
	{
		for(uint8_t j=start_y; j<end_y+1; j++)
		{
		  ST7735_Draw_Pixel(i,j,colour);
		}
		i+=end_x-start_x;
	}
}

/*
 * @brief ST7735_Draw_Pixel = Fills the specified pixel value with the desired color
 *
 * @param x = Specifies the x address of the pixel
 * @param y = Specifies the y address of the pixel
 * @param colour = pixel gets the desired color value
 *
 * @retval None
 */
void ST7735_Draw_Pixel(uint8_t x,uint8_t y,uint16_t colour)
{
	uint8_t row[4],column[4], colour_select[2];
	colour_select[0] = ((colour & 0xff00)>>8);
	colour_select[1] = ((colour & 0x00ff)<<0);
	((uint32_t*) row)[0] = (((y & 0xFF) << 24) | ((y & 0xFF00) << 8)| ((y & 0xFF) << 8) | ((y & 0xFF00) >> 8));
	ST7735_Sending_Command_Data(RASET_REG_ADDR, row, 4);
	((uint32_t*) column)[0] = (((x & 0xFF) << 24) | ((x & 0xFF00) << 8)| ((x & 0xFF) << 8) | ((x & 0xFF00) >> 8));
	ST7735_Sending_Command_Data(CASET_REG_ADDR, column, 4);
	ST7735_Sending_Command_Data(RAMWR_REG_ADDR,colour_select,2);
}

/*
 * @brief ST7735_String = String printing function on the screen
 *
 * @param starting_column = holds the starting x address
 * @param starting_row = holds the starting y address
 * @param string = string holds the expression
 * @param Font_select = holds the desired font value
 * @param String_colour = holds the string color value to be printed
 * @param Background_Colour = Keeps the background color value of the screen
 *
 * @retval None
 *
 */
void ST7735_String(uint8_t starting_column, uint8_t starting_row, char*string, sFONT*Font_select, uint16_t String_colour,uint16_t Background_Colour)
{
	uint8_t x,y,counter,x_update,size_definiton;
	uint16_t pixel_value,character_index;
	x=starting_column,y=starting_row;
	while(*string != '\0')
	{
		character_index=(*string)-32;
		character_index*=(Font_select->Height*Font_select->Size);
		for(uint8_t _y=y; _y<(y+Font_select->Height); _y++)
		{
			size_definiton=1;
			x_update=x;
			run:
			counter = 7;

			for(uint8_t i=0 ; i<8; i++)
			{
				if(Font_select->table[character_index] & (0x01<<counter))
					pixel_value=String_colour;
				else
					pixel_value=Background_Colour;

				ST7735_Draw_Pixel(x_update, _y, pixel_value);
				counter--;
				x_update++;
			}
			character_index++;
			if((Font_select->Size>1) && (Font_select->Size != size_definiton) )
			{
				size_definiton++;
			    goto run;
			}
		}
		string++;
		x+=Font_select->Width;

	}
}

/* @brief STT7735_Reset = Used to reset the screen
 *
 * @param none
 *
 * @retval None
 */
void STT7735_Reset(void)
{
	ST7735_Send_Command(SWRESET_REG_ADDR,0,Command_Transmit);
	HAL_Delay(120);
}

