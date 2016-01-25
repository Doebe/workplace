################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ShackDown/D/D.cpp 

OBJS += \
./ShackDown/D/D.o 

CPP_DEPS += \
./ShackDown/D/D.d 


# Each subdirectory must supply rules for building sources it contributes
ShackDown/D/%.o: ../ShackDown/D/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


