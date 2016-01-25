################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Maths/12004BubbleSort/12004BubbleSort.cpp 

OBJS += \
./Maths/12004BubbleSort/12004BubbleSort.o 

CPP_DEPS += \
./Maths/12004BubbleSort/12004BubbleSort.d 


# Each subdirectory must supply rules for building sources it contributes
Maths/12004BubbleSort/%.o: ../Maths/12004BubbleSort/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


