################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Round322/E/srcE.cpp 

OBJS += \
./Round322/E/srcE.o 

CPP_DEPS += \
./Round322/E/srcE.d 


# Each subdirectory must supply rules for building sources it contributes
Round322/E/%.o: ../Round322/E/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


