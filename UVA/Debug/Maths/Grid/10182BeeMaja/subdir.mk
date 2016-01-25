################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Maths/Grid/10182BeeMaja/10182BeeMaja.cpp 

OBJS += \
./Maths/Grid/10182BeeMaja/10182BeeMaja.o 

CPP_DEPS += \
./Maths/Grid/10182BeeMaja/10182BeeMaja.d 


# Each subdirectory must supply rules for building sources it contributes
Maths/Grid/10182BeeMaja/%.o: ../Maths/Grid/10182BeeMaja/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


