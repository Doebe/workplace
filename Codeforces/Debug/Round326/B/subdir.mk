################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Round326/B/srcB.cpp 

OBJS += \
./Round326/B/srcB.o 

CPP_DEPS += \
./Round326/B/srcB.d 


# Each subdirectory must supply rules for building sources it contributes
Round326/B/%.o: ../Round326/B/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


