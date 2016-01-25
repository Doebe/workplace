################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/BipartiteGraphCheck/11396ClawDecomposition/11396ClawDecomposition.cpp 

OBJS += \
./Graph/BipartiteGraphCheck/11396ClawDecomposition/11396ClawDecomposition.o 

CPP_DEPS += \
./Graph/BipartiteGraphCheck/11396ClawDecomposition/11396ClawDecomposition.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/BipartiteGraphCheck/11396ClawDecomposition/%.o: ../Graph/BipartiteGraphCheck/11396ClawDecomposition/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


