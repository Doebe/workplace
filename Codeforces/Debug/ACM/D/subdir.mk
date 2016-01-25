################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ACM/D/srcD.cpp 

OBJS += \
./ACM/D/srcD.o 

CPP_DEPS += \
./ACM/D/srcD.d 


# Each subdirectory must supply rules for building sources it contributes
ACM/D/%.o: ../ACM/D/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


