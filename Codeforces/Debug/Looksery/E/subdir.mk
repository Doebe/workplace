################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Looksery/E/srcE.cpp 

OBJS += \
./Looksery/E/srcE.o 

CPP_DEPS += \
./Looksery/E/srcE.d 


# Each subdirectory must supply rules for building sources it contributes
Looksery/E/%.o: ../Looksery/E/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


