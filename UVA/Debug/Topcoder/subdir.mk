################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Topcoder/250.cpp 

OBJS += \
./Topcoder/250.o 

CPP_DEPS += \
./Topcoder/250.d 


# Each subdirectory must supply rules for building sources it contributes
Topcoder/%.o: ../Topcoder/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


