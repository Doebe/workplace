################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Kattis-2/A/srcA.cpp 

OBJS += \
./Kattis-2/A/srcA.o 

CPP_DEPS += \
./Kattis-2/A/srcA.d 


# Each subdirectory must supply rules for building sources it contributes
Kattis-2/A/%.o: ../Kattis-2/A/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

