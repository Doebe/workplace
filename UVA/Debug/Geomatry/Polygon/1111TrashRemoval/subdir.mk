################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Geomatry/Polygon/1111TrashRemoval/1111TrashRemoval.cpp 

OBJS += \
./Geomatry/Polygon/1111TrashRemoval/1111TrashRemoval.o 

CPP_DEPS += \
./Geomatry/Polygon/1111TrashRemoval/1111TrashRemoval.d 


# Each subdirectory must supply rules for building sources it contributes
Geomatry/Polygon/1111TrashRemoval/%.o: ../Geomatry/Polygon/1111TrashRemoval/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


