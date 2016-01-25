################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Round319/E/srcE.cpp 

OBJS += \
./Round319/E/srcE.o 

CPP_DEPS += \
./Round319/E/srcE.d 


# Each subdirectory must supply rules for building sources it contributes
Round319/E/%.o: ../Round319/E/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


