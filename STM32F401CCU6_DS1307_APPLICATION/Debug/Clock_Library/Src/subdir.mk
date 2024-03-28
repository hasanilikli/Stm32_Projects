################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Clock_Library/Src/DS1307.c 

OBJS += \
./Clock_Library/Src/DS1307.o 

C_DEPS += \
./Clock_Library/Src/DS1307.d 


# Each subdirectory must supply rules for building sources it contributes
Clock_Library/Src/%.o Clock_Library/Src/%.su Clock_Library/Src/%.cyclo: ../Clock_Library/Src/%.c Clock_Library/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/user/STM32CubeIDE/workspace_1.12.1/STM32F401CCU6_DS1307_APPLICATION/Clock_Library/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Clock_Library-2f-Src

clean-Clock_Library-2f-Src:
	-$(RM) ./Clock_Library/Src/DS1307.cyclo ./Clock_Library/Src/DS1307.d ./Clock_Library/Src/DS1307.o ./Clock_Library/Src/DS1307.su

.PHONY: clean-Clock_Library-2f-Src

