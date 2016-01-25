################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Ulticoder/EfficiencyOverload.cpp 

OBJS += \
./Ulticoder/EfficiencyOverload.o 

CPP_DEPS += \
./Ulticoder/EfficiencyOverload.d 


# Each subdirectory must supply rules for building sources it contributes
Ulticoder/%.o: ../Ulticoder/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


