################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CF/Substrings/Substrings.cpp 

OBJS += \
./CF/Substrings/Substrings.o 

CPP_DEPS += \
./CF/Substrings/Substrings.d 


# Each subdirectory must supply rules for building sources it contributes
CF/Substrings/%.o: ../CF/Substrings/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


