################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/GraphTraversal/11906KightsInWarGrid/11906KightsInWarGrid.cpp 

OBJS += \
./Graph/GraphTraversal/11906KightsInWarGrid/11906KightsInWarGrid.o 

CPP_DEPS += \
./Graph/GraphTraversal/11906KightsInWarGrid/11906KightsInWarGrid.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/GraphTraversal/11906KightsInWarGrid/%.o: ../Graph/GraphTraversal/11906KightsInWarGrid/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


