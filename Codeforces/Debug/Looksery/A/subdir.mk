################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Looksery/A/srcA.cpp 

OBJS += \
./Looksery/A/srcA.o 

CPP_DEPS += \
./Looksery/A/srcA.d 


# Each subdirectory must supply rules for building sources it contributes
Looksery/A/%.o: ../Looksery/A/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


