################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/10004Bicoloring/10004Bicoloring.cpp 

OBJS += \
./Graph/10004Bicoloring/10004Bicoloring.o 

CPP_DEPS += \
./Graph/10004Bicoloring/10004Bicoloring.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/10004Bicoloring/%.o: ../Graph/10004Bicoloring/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


