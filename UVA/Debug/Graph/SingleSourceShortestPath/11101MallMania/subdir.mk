################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/SingleSourceShortestPath/11101MallMania/11101MallMania.cpp 

OBJS += \
./Graph/SingleSourceShortestPath/11101MallMania/11101MallMania.o 

CPP_DEPS += \
./Graph/SingleSourceShortestPath/11101MallMania/11101MallMania.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/SingleSourceShortestPath/11101MallMania/%.o: ../Graph/SingleSourceShortestPath/11101MallMania/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


