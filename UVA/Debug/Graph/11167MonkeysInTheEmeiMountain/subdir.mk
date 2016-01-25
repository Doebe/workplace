################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/11167MonkeysInTheEmeiMountain/11167MonkeysInTheEmeiMountain.cpp 

OBJS += \
./Graph/11167MonkeysInTheEmeiMountain/11167MonkeysInTheEmeiMountain.o 

CPP_DEPS += \
./Graph/11167MonkeysInTheEmeiMountain/11167MonkeysInTheEmeiMountain.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/11167MonkeysInTheEmeiMountain/%.o: ../Graph/11167MonkeysInTheEmeiMountain/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


