################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/SingleSourceShortestPath/12047HighestPaidToll/12047HighestPaidToll.cpp 

OBJS += \
./Graph/SingleSourceShortestPath/12047HighestPaidToll/12047HighestPaidToll.o 

CPP_DEPS += \
./Graph/SingleSourceShortestPath/12047HighestPaidToll/12047HighestPaidToll.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/SingleSourceShortestPath/12047HighestPaidToll/%.o: ../Graph/SingleSourceShortestPath/12047HighestPaidToll/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


