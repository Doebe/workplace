################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Geomatry/Polygon/Polygon.cpp 

OBJS += \
./Geomatry/Polygon/Polygon.o 

CPP_DEPS += \
./Geomatry/Polygon/Polygon.d 


# Each subdirectory must supply rules for building sources it contributes
Geomatry/Polygon/%.o: ../Geomatry/Polygon/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


