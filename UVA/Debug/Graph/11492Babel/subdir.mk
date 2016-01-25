################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/11492Babel/11492Babel.cpp 

OBJS += \
./Graph/11492Babel/11492Babel.o 

CPP_DEPS += \
./Graph/11492Babel/11492Babel.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/11492Babel/%.o: ../Graph/11492Babel/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


