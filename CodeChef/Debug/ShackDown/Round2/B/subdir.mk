################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ShackDown/Round2/B/srcB.cpp 

OBJS += \
./ShackDown/Round2/B/srcB.o 

CPP_DEPS += \
./ShackDown/Round2/B/srcB.d 


# Each subdirectory must supply rules for building sources it contributes
ShackDown/Round2/B/%.o: ../ShackDown/Round2/B/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


