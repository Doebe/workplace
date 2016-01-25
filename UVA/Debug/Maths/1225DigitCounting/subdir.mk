################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Maths/1225DigitCounting/1225DigitCounting.cpp 

OBJS += \
./Maths/1225DigitCounting/1225DigitCounting.o 

CPP_DEPS += \
./Maths/1225DigitCounting/1225DigitCounting.d 


# Each subdirectory must supply rules for building sources it contributes
Maths/1225DigitCounting/%.o: ../Maths/1225DigitCounting/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


