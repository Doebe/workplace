################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Round315/A/srcA.cpp 

OBJS += \
./Round315/A/srcA.o 

CPP_DEPS += \
./Round315/A/srcA.d 


# Each subdirectory must supply rules for building sources it contributes
Round315/A/%.o: ../Round315/A/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


