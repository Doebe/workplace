################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/1103AncientMessages/1103AncientMessages.cpp 

OBJS += \
./Graph/1103AncientMessages/1103AncientMessages.o 

CPP_DEPS += \
./Graph/1103AncientMessages/1103AncientMessages.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/1103AncientMessages/%.o: ../Graph/1103AncientMessages/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


