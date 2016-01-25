################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/ArticulationPointsAndBridges/10765DovesAndBombs/10765DovesAndBombs.cpp 

OBJS += \
./Graph/ArticulationPointsAndBridges/10765DovesAndBombs/10765DovesAndBombs.o 

CPP_DEPS += \
./Graph/ArticulationPointsAndBridges/10765DovesAndBombs/10765DovesAndBombs.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/ArticulationPointsAndBridges/10765DovesAndBombs/%.o: ../Graph/ArticulationPointsAndBridges/10765DovesAndBombs/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


