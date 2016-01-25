################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Maths/NumberSystemsOrSequencies/443HumbleNumbers/443HumbleNumbers.cpp 

OBJS += \
./Maths/NumberSystemsOrSequencies/443HumbleNumbers/443HumbleNumbers.o 

CPP_DEPS += \
./Maths/NumberSystemsOrSequencies/443HumbleNumbers/443HumbleNumbers.d 


# Each subdirectory must supply rules for building sources it contributes
Maths/NumberSystemsOrSequencies/443HumbleNumbers/%.o: ../Maths/NumberSystemsOrSequencies/443HumbleNumbers/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


