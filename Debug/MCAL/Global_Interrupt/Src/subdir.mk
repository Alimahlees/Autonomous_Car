################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Global_Interrupt/Src/GLB_IN.c 

OBJS += \
./MCAL/Global_Interrupt/Src/GLB_IN.o 

C_DEPS += \
./MCAL/Global_Interrupt/Src/GLB_IN.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Global_Interrupt/Src/%.o: ../MCAL/Global_Interrupt/Src/%.c MCAL/Global_Interrupt/Src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/home/ali/eclipse-workspace/testing/00-Lib" -I"/home/ali/eclipse-workspace/testing/MCAL/Global_Interrupt/Inc" -I"/home/ali/eclipse-workspace/testing/HAL/ULTRA_SONIC/Inc" -I"/home/ali/eclipse-workspace/testing/MCAL/DIO/Inc" -I"/home/ali/eclipse-workspace/testing/HAL/LCD/Inc" -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


