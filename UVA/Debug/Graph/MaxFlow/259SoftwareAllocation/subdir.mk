################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/MaxFlow/259SoftwareAllocation/259SoftwareAllocation.cpp 

OBJS += \
./Graph/MaxFlow/259SoftwareAllocation/259SoftwareAllocation.o 

CPP_DEPS += \
./Graph/MaxFlow/259SoftwareAllocation/259SoftwareAllocation.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/MaxFlow/259SoftwareAllocation/%.o: ../Graph/MaxFlow/259SoftwareAllocation/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


