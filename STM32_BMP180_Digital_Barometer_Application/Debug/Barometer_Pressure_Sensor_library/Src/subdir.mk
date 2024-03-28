################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Barometer_Pressure_Sensor_library/Src/bmp180.c 

OBJS += \
./Barometer_Pressure_Sensor_library/Src/bmp180.o 

C_DEPS += \
./Barometer_Pressure_Sensor_library/Src/bmp180.d 


# Each subdirectory must supply rules for building sources it contributes
Barometer_Pressure_Sensor_library/Src/%.o Barometer_Pressure_Sensor_library/Src/%.su Barometer_Pressure_Sensor_library/Src/%.cyclo: ../Barometer_Pressure_Sensor_library/Src/%.c Barometer_Pressure_Sensor_library/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/user/STM32CubeIDE/workspace_1.12.1/STM32_BMP180_Digital_Barometer_Application/Barometer_Pressure_Sensor_library/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Barometer_Pressure_Sensor_library-2f-Src

clean-Barometer_Pressure_Sensor_library-2f-Src:
	-$(RM) ./Barometer_Pressure_Sensor_library/Src/bmp180.cyclo ./Barometer_Pressure_Sensor_library/Src/bmp180.d ./Barometer_Pressure_Sensor_library/Src/bmp180.o ./Barometer_Pressure_Sensor_library/Src/bmp180.su

.PHONY: clean-Barometer_Pressure_Sensor_library-2f-Src

