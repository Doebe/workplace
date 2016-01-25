################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/SingleSourceShortestPath/10278FireStation/10278FireStation.cpp 

OBJS += \
./Graph/SingleSourceShortestPath/10278FireStation/10278FireStation.o 

CPP_DEPS += \
./Graph/SingleSourceShortestPath/10278FireStation/10278FireStation.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/SingleSourceShortestPath/10278FireStation/%.o: ../Graph/SingleSourceShortestPath/10278FireStation/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


