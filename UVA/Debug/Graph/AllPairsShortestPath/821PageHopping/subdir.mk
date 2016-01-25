################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/AllPairsShortestPath/821PageHopping/821PageHopping.cpp 

OBJS += \
./Graph/AllPairsShortestPath/821PageHopping/821PageHopping.o 

CPP_DEPS += \
./Graph/AllPairsShortestPath/821PageHopping/821PageHopping.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/AllPairsShortestPath/821PageHopping/%.o: ../Graph/AllPairsShortestPath/821PageHopping/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


