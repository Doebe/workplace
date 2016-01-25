################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Round317/B/srcB.cpp 

OBJS += \
./Round317/B/srcB.o 

CPP_DEPS += \
./Round317/B/srcB.d 


# Each subdirectory must supply rules for building sources it contributes
Round317/B/%.o: ../Round317/B/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


