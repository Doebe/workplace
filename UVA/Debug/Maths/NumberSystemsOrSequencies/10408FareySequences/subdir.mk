################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Maths/NumberSystemsOrSequencies/10408FareySequences/10408FareySequences.cpp 

OBJS += \
./Maths/NumberSystemsOrSequencies/10408FareySequences/10408FareySequences.o 

CPP_DEPS += \
./Maths/NumberSystemsOrSequencies/10408FareySequences/10408FareySequences.d 


# Each subdirectory must supply rules for building sources it contributes
Maths/NumberSystemsOrSequencies/10408FareySequences/%.o: ../Maths/NumberSystemsOrSequencies/10408FareySequences/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


