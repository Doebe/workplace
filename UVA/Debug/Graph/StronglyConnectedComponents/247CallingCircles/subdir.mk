################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/StronglyConnectedComponents/247CallingCircles/247CallingCircles.cpp 

OBJS += \
./Graph/StronglyConnectedComponents/247CallingCircles/247CallingCircles.o 

CPP_DEPS += \
./Graph/StronglyConnectedComponents/247CallingCircles/247CallingCircles.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/StronglyConnectedComponents/247CallingCircles/%.o: ../Graph/StronglyConnectedComponents/247CallingCircles/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


