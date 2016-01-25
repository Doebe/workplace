################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Maths/11718FantasyOfSummation/11718FantasyOfSummation.cpp 

OBJS += \
./Maths/11718FantasyOfSummation/11718FantasyOfSummation.o 

CPP_DEPS += \
./Maths/11718FantasyOfSummation/11718FantasyOfSummation.d 


# Each subdirectory must supply rules for building sources it contributes
Maths/11718FantasyOfSummation/%.o: ../Maths/11718FantasyOfSummation/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


