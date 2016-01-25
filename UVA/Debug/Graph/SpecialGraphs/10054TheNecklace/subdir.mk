################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/SpecialGraphs/10054TheNecklace/10054TheNecklace.cpp 

OBJS += \
./Graph/SpecialGraphs/10054TheNecklace/10054TheNecklace.o 

CPP_DEPS += \
./Graph/SpecialGraphs/10054TheNecklace/10054TheNecklace.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/SpecialGraphs/10054TheNecklace/%.o: ../Graph/SpecialGraphs/10054TheNecklace/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


