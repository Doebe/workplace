################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/SingleSourceShortestPath/SSSPunweighted.cpp \
../Graph/SingleSourceShortestPath/bellman-ford.cpp \
../Graph/SingleSourceShortestPath/dijkstra.cpp 

OBJS += \
./Graph/SingleSourceShortestPath/SSSPunweighted.o \
./Graph/SingleSourceShortestPath/bellman-ford.o \
./Graph/SingleSourceShortestPath/dijkstra.o 

CPP_DEPS += \
./Graph/SingleSourceShortestPath/SSSPunweighted.d \
./Graph/SingleSourceShortestPath/bellman-ford.d \
./Graph/SingleSourceShortestPath/dijkstra.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/SingleSourceShortestPath/%.o: ../Graph/SingleSourceShortestPath/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


