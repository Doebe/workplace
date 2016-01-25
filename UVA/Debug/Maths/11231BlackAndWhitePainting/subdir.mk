################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Maths/11231BlackAndWhitePainting/11231BlackAndWhitePainting.cpp 

OBJS += \
./Maths/11231BlackAndWhitePainting/11231BlackAndWhitePainting.o 

CPP_DEPS += \
./Maths/11231BlackAndWhitePainting/11231BlackAndWhitePainting.d 


# Each subdirectory must supply rules for building sources it contributes
Maths/11231BlackAndWhitePainting/%.o: ../Maths/11231BlackAndWhitePainting/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


