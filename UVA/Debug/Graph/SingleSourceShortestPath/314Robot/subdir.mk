################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/SingleSourceShortestPath/314Robot/314Robot.cpp 

OBJS += \
./Graph/SingleSourceShortestPath/314Robot/314Robot.o 

CPP_DEPS += \
./Graph/SingleSourceShortestPath/314Robot/314Robot.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/SingleSourceShortestPath/314Robot/%.o: ../Graph/SingleSourceShortestPath/314Robot/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


