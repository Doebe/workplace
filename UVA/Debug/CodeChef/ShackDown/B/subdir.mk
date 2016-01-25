################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CodeChef/ShackDown/B/B.cpp 

OBJS += \
./CodeChef/ShackDown/B/B.o 

CPP_DEPS += \
./CodeChef/ShackDown/B/B.d 


# Each subdirectory must supply rules for building sources it contributes
CodeChef/ShackDown/B/%.o: ../CodeChef/ShackDown/B/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


