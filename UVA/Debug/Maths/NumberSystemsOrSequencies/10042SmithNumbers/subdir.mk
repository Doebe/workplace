################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Maths/NumberSystemsOrSequencies/10042SmithNumbers/10042SmithNumbers.cpp 

OBJS += \
./Maths/NumberSystemsOrSequencies/10042SmithNumbers/10042SmithNumbers.o 

CPP_DEPS += \
./Maths/NumberSystemsOrSequencies/10042SmithNumbers/10042SmithNumbers.d 


# Each subdirectory must supply rules for building sources it contributes
Maths/NumberSystemsOrSequencies/10042SmithNumbers/%.o: ../Maths/NumberSystemsOrSequencies/10042SmithNumbers/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


