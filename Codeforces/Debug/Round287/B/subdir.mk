################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Round287/B/B.cpp 

OBJS += \
./Round287/B/B.o 

CPP_DEPS += \
./Round287/B/B.d 


# Each subdirectory must supply rules for building sources it contributes
Round287/B/%.o: ../Round287/B/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


