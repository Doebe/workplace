################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Maths/382Perfection/382Perfection.cpp 

OBJS += \
./Maths/382Perfection/382Perfection.o 

CPP_DEPS += \
./Maths/382Perfection/382Perfection.d 


# Each subdirectory must supply rules for building sources it contributes
Maths/382Perfection/%.o: ../Maths/382Perfection/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


