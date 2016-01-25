################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/FloodFillAndFindingConnectedComponents/1103AncientMessages/1103AncientMessages.cpp 

OBJS += \
./Graph/FloodFillAndFindingConnectedComponents/1103AncientMessages/1103AncientMessages.o 

CPP_DEPS += \
./Graph/FloodFillAndFindingConnectedComponents/1103AncientMessages/1103AncientMessages.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/FloodFillAndFindingConnectedComponents/1103AncientMessages/%.o: ../Graph/FloodFillAndFindingConnectedComponents/1103AncientMessages/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


