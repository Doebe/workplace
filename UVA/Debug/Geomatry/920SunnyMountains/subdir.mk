################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Geomatry/920SunnyMountains/920SunnyMountains.cpp 

OBJS += \
./Geomatry/920SunnyMountains/920SunnyMountains.o 

CPP_DEPS += \
./Geomatry/920SunnyMountains/920SunnyMountains.d 


# Each subdirectory must supply rules for building sources it contributes
Geomatry/920SunnyMountains/%.o: ../Geomatry/920SunnyMountains/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


