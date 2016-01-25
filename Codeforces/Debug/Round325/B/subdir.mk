################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Round325/B/srcB.cpp 

OBJS += \
./Round325/B/srcB.o 

CPP_DEPS += \
./Round325/B/srcB.d 


# Each subdirectory must supply rules for building sources it contributes
Round325/B/%.o: ../Round325/B/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


