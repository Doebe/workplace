################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Round309/B/srcB.cpp 

OBJS += \
./Round309/B/srcB.o 

CPP_DEPS += \
./Round309/B/srcB.d 


# Each subdirectory must supply rules for building sources it contributes
Round309/B/%.o: ../Round309/B/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


