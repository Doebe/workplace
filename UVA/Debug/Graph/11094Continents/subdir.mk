################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/11094Continents/11094Continents.cpp 

OBJS += \
./Graph/11094Continents/11094Continents.o 

CPP_DEPS += \
./Graph/11094Continents/11094Continents.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/11094Continents/%.o: ../Graph/11094Continents/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


