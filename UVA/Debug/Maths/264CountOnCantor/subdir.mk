################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Maths/264CountOnCantor/264CountOnCantor.cpp 

OBJS += \
./Maths/264CountOnCantor/264CountOnCantor.o 

CPP_DEPS += \
./Maths/264CountOnCantor/264CountOnCantor.d 


# Each subdirectory must supply rules for building sources it contributes
Maths/264CountOnCantor/%.o: ../Maths/264CountOnCantor/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


