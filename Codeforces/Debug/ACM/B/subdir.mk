################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ACM/B/srcB.cpp 

OBJS += \
./ACM/B/srcB.o 

CPP_DEPS += \
./ACM/B/srcB.d 


# Each subdirectory must supply rules for building sources it contributes
ACM/B/%.o: ../ACM/B/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


