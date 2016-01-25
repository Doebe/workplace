################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CF/DrazilAndFactorial/DrazilAndFactorial.cpp 

OBJS += \
./CF/DrazilAndFactorial/DrazilAndFactorial.o 

CPP_DEPS += \
./CF/DrazilAndFactorial/DrazilAndFactorial.d 


# Each subdirectory must supply rules for building sources it contributes
CF/DrazilAndFactorial/%.o: ../CF/DrazilAndFactorial/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


