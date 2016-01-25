################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Kattis-5/D/srcD.cpp 

OBJS += \
./Kattis-5/D/srcD.o 

CPP_DEPS += \
./Kattis-5/D/srcD.d 


# Each subdirectory must supply rules for building sources it contributes
Kattis-5/D/%.o: ../Kattis-5/D/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


