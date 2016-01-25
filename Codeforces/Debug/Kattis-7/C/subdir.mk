################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Kattis-7/C/srcC.cpp 

OBJS += \
./Kattis-7/C/srcC.o 

CPP_DEPS += \
./Kattis-7/C/srcC.d 


# Each subdirectory must supply rules for building sources it contributes
Kattis-7/C/%.o: ../Kattis-7/C/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


