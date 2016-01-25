################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/872Ordering/872Ordering.cpp 

OBJS += \
./Graph/872Ordering/872Ordering.o 

CPP_DEPS += \
./Graph/872Ordering/872Ordering.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/872Ordering/%.o: ../Graph/872Ordering/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


