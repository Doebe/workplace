################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Round310/B/srcB.cpp 

OBJS += \
./Round310/B/srcB.o 

CPP_DEPS += \
./Round310/B/srcB.d 


# Each subdirectory must supply rules for building sources it contributes
Round310/B/%.o: ../Round310/B/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


