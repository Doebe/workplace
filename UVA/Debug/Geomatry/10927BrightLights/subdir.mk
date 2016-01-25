################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Geomatry/10927BrightLights/10927BrightLights.cpp 

OBJS += \
./Geomatry/10927BrightLights/10927BrightLights.o 

CPP_DEPS += \
./Geomatry/10927BrightLights/10927BrightLights.d 


# Each subdirectory must supply rules for building sources it contributes
Geomatry/10927BrightLights/%.o: ../Geomatry/10927BrightLights/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


