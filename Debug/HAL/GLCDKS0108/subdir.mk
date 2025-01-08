################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/GLCDKS0108/GLCDKS0108_program.c 

OBJS += \
./HAL/GLCDKS0108/GLCDKS0108_program.o 

C_DEPS += \
./HAL/GLCDKS0108/GLCDKS0108_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/GLCDKS0108/%.o: ../HAL/GLCDKS0108/%.c HAL/GLCDKS0108/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


