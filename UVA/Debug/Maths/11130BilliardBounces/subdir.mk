################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Maths/11130BilliardBounces/11130BilliardBounces.cpp 

OBJS += \
./Maths/11130BilliardBounces/11130BilliardBounces.o 

CPP_DEPS += \
./Maths/11130BilliardBounces/11130BilliardBounces.d 


# Each subdirectory must supply rules for building sources it contributes
Maths/11130BilliardBounces/%.o: ../Maths/11130BilliardBounces/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


