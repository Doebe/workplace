################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Maths/10718BitMask/10718BitMask.cpp 

OBJS += \
./Maths/10718BitMask/10718BitMask.o 

CPP_DEPS += \
./Maths/10718BitMask/10718BitMask.d 


# Each subdirectory must supply rules for building sources it contributes
Maths/10718BitMask/%.o: ../Maths/10718BitMask/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


