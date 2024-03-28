################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ST7735_Lcd_Library/Src/ST7735.c \
../ST7735_Lcd_Library/Src/font12.c \
../ST7735_Lcd_Library/Src/font16.c \
../ST7735_Lcd_Library/Src/font20.c \
../ST7735_Lcd_Library/Src/font24.c \
../ST7735_Lcd_Library/Src/font8.c 

OBJS += \
./ST7735_Lcd_Library/Src/ST7735.o \
./ST7735_Lcd_Library/Src/font12.o \
./ST7735_Lcd_Library/Src/font16.o \
./ST7735_Lcd_Library/Src/font20.o \
./ST7735_Lcd_Library/Src/font24.o \
./ST7735_Lcd_Library/Src/font8.o 

C_DEPS += \
./ST7735_Lcd_Library/Src/ST7735.d \
./ST7735_Lcd_Library/Src/font12.d \
./ST7735_Lcd_Library/Src/font16.d \
./ST7735_Lcd_Library/Src/font20.d \
./ST7735_Lcd_Library/Src/font24.d \
./ST7735_Lcd_Library/Src/font8.d 


# Each subdirectory must supply rules for building sources it contributes
ST7735_Lcd_Library/Src/%.o ST7735_Lcd_Library/Src/%.su ST7735_Lcd_Library/Src/%.cyclo: ../ST7735_Lcd_Library/Src/%.c ST7735_Lcd_Library/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/user/STM32CubeIDE/workspace_1.12.1/STM32F401CCU6_ST7735_TFT_LCD_APPLICATION/Clock_Library/Inc" -I"C:/Users/user/STM32CubeIDE/workspace_1.12.1/STM32F401CCU6_ST7735_TFT_LCD_APPLICATION/ST7735_Lcd_Library/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ST7735_Lcd_Library-2f-Src

clean-ST7735_Lcd_Library-2f-Src:
	-$(RM) ./ST7735_Lcd_Library/Src/ST7735.cyclo ./ST7735_Lcd_Library/Src/ST7735.d ./ST7735_Lcd_Library/Src/ST7735.o ./ST7735_Lcd_Library/Src/ST7735.su ./ST7735_Lcd_Library/Src/font12.cyclo ./ST7735_Lcd_Library/Src/font12.d ./ST7735_Lcd_Library/Src/font12.o ./ST7735_Lcd_Library/Src/font12.su ./ST7735_Lcd_Library/Src/font16.cyclo ./ST7735_Lcd_Library/Src/font16.d ./ST7735_Lcd_Library/Src/font16.o ./ST7735_Lcd_Library/Src/font16.su ./ST7735_Lcd_Library/Src/font20.cyclo ./ST7735_Lcd_Library/Src/font20.d ./ST7735_Lcd_Library/Src/font20.o ./ST7735_Lcd_Library/Src/font20.su ./ST7735_Lcd_Library/Src/font24.cyclo ./ST7735_Lcd_Library/Src/font24.d ./ST7735_Lcd_Library/Src/font24.o ./ST7735_Lcd_Library/Src/font24.su ./ST7735_Lcd_Library/Src/font8.cyclo ./ST7735_Lcd_Library/Src/font8.d ./ST7735_Lcd_Library/Src/font8.o ./ST7735_Lcd_Library/Src/font8.su

.PHONY: clean-ST7735_Lcd_Library-2f-Src

