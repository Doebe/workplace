################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/BipartiteGraphCheck/11080PlaceTheGuards/11080PlaceTheGuards.cpp 

OBJS += \
./Graph/BipartiteGraphCheck/11080PlaceTheGuards/11080PlaceTheGuards.o 

CPP_DEPS += \
./Graph/BipartiteGraphCheck/11080PlaceTheGuards/11080PlaceTheGuards.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/BipartiteGraphCheck/11080PlaceTheGuards/%.o: ../Graph/BipartiteGraphCheck/11080PlaceTheGuards/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


