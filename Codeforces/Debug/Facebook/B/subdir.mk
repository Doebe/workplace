################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Facebook/B/srcB.cpp 

OBJS += \
./Facebook/B/srcB.o 

CPP_DEPS += \
./Facebook/B/srcB.d 


# Each subdirectory must supply rules for building sources it contributes
Facebook/B/%.o: ../Facebook/B/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


