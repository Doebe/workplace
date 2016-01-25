################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/StronglyConnectedComponents/11838ComeAndGo/11838ComeAndGo.cpp 

OBJS += \
./Graph/StronglyConnectedComponents/11838ComeAndGo/11838ComeAndGo.o 

CPP_DEPS += \
./Graph/StronglyConnectedComponents/11838ComeAndGo/11838ComeAndGo.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/StronglyConnectedComponents/11838ComeAndGo/%.o: ../Graph/StronglyConnectedComponents/11838ComeAndGo/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


