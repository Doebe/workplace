################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Round274/C/C.cpp 

OBJS += \
./Round274/C/C.o 

CPP_DEPS += \
./Round274/C/C.d 


# Each subdirectory must supply rules for building sources it contributes
Round274/C/%.o: ../Round274/C/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

