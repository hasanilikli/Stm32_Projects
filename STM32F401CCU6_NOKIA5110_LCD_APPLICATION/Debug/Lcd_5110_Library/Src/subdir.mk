################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lcd_5110_Library/Src/LCD_NOKIA5110.c 

OBJS += \
./Lcd_5110_Library/Src/LCD_NOKIA5110.o 

C_DEPS += \
./Lcd_5110_Library/Src/LCD_NOKIA5110.d 


# Each subdirectory must supply rules for building sources it contributes
Lcd_5110_Library/Src/%.o Lcd_5110_Library/Src/%.su Lcd_5110_Library/Src/%.cyclo: ../Lcd_5110_Library/Src/%.c Lcd_5110_Library/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/user/STM32CubeIDE/workspace_1.12.1/STM32F401CCU6_NOKIA5110_LCD_APPLICATION/Lcd_5110_Library/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Lcd_5110_Library-2f-Src

clean-Lcd_5110_Library-2f-Src:
	-$(RM) ./Lcd_5110_Library/Src/LCD_NOKIA5110.cyclo ./Lcd_5110_Library/Src/LCD_NOKIA5110.d ./Lcd_5110_Library/Src/LCD_NOKIA5110.o ./Lcd_5110_Library/Src/LCD_NOKIA5110.su

.PHONY: clean-Lcd_5110_Library-2f-Src

