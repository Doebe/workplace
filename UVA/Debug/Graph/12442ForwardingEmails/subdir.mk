################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/12442ForwardingEmails/12442ForwardingEmails.cpp 

OBJS += \
./Graph/12442ForwardingEmails/12442ForwardingEmails.o 

CPP_DEPS += \
./Graph/12442ForwardingEmails/12442ForwardingEmails.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/12442ForwardingEmails/%.o: ../Graph/12442ForwardingEmails/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


