################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DP/787MaximumSub-sequenceProduct/787MaximumSub-sequenceProduct.cpp 

OBJS += \
./DP/787MaximumSub-sequenceProduct/787MaximumSub-sequenceProduct.o 

CPP_DEPS += \
./DP/787MaximumSub-sequenceProduct/787MaximumSub-sequenceProduct.d 


# Each subdirectory must supply rules for building sources it contributes
DP/787MaximumSub-sequenceProduct/%.o: ../DP/787MaximumSub-sequenceProduct/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


