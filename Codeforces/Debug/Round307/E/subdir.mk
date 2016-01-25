################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Round307/E/srcE.cpp 

OBJS += \
./Round307/E/srcE.o 

CPP_DEPS += \
./Round307/E/srcE.d 


# Each subdirectory must supply rules for building sources it contributes
Round307/E/%.o: ../Round307/E/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


