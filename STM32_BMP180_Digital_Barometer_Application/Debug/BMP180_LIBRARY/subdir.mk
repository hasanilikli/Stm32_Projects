################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BMP180_LIBRARY/bmp180.c 

OBJS += \
./BMP180_LIBRARY/bmp180.o 

C_DEPS += \
./BMP180_LIBRARY/bmp180.d 


# Each subdirectory must supply rules for building sources it contributes
BMP180_LIBRARY/%.o BMP180_LIBRARY/%.su BMP180_LIBRARY/%.cyclo: ../BMP180_LIBRARY/%.c BMP180_LIBRARY/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BMP180_LIBRARY

clean-BMP180_LIBRARY:
	-$(RM) ./BMP180_LIBRARY/bmp180.cyclo ./BMP180_LIBRARY/bmp180.d ./BMP180_LIBRARY/bmp180.o ./BMP180_LIBRARY/bmp180.su

.PHONY: clean-BMP180_LIBRARY

