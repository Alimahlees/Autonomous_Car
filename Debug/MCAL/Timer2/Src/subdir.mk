################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Timer2/Src/PWM2.c 

OBJS += \
./MCAL/Timer2/Src/PWM2.o 

C_DEPS += \
./MCAL/Timer2/Src/PWM2.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Timer2/Src/%.o: ../MCAL/Timer2/Src/%.c MCAL/Timer2/Src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/home/ali/eclipse-workspace/testing/00-Lib" -I"/home/ali/eclipse-workspace/testing/MCAL/Timer2/Inc" -I"/home/ali/eclipse-workspace/testing/MCAL/ICP/Inc" -I"/home/ali/eclipse-workspace/testing/HAL/ULTRA_SONIC/Inc" -I"/home/ali/eclipse-workspace/testing/MCAL/GLBL_INT/Inc" -I"/home/ali/eclipse-workspace/testing/MCAL/DIO/Inc" -I"/home/ali/eclipse-workspace/testing/HAL/LCD/Inc" -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


