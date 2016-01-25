################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/SingleSourceShortestPath/1112MiceAndMaze/1112MiceAndMaze.cpp 

OBJS += \
./Graph/SingleSourceShortestPath/1112MiceAndMaze/1112MiceAndMaze.o 

CPP_DEPS += \
./Graph/SingleSourceShortestPath/1112MiceAndMaze/1112MiceAndMaze.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/SingleSourceShortestPath/1112MiceAndMaze/%.o: ../Graph/SingleSourceShortestPath/1112MiceAndMaze/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


