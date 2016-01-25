################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/SingleSourceShortestPath/10449Traffic/10449Traffic.cpp 

OBJS += \
./Graph/SingleSourceShortestPath/10449Traffic/10449Traffic.o 

CPP_DEPS += \
./Graph/SingleSourceShortestPath/10449Traffic/10449Traffic.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/SingleSourceShortestPath/10449Traffic/%.o: ../Graph/SingleSourceShortestPath/10449Traffic/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


