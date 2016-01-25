################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Geomatry/Polygon/10652BoardWrapping/10652BoardWrapping.cpp 

OBJS += \
./Geomatry/Polygon/10652BoardWrapping/10652BoardWrapping.o 

CPP_DEPS += \
./Geomatry/Polygon/10652BoardWrapping/10652BoardWrapping.d 


# Each subdirectory must supply rules for building sources it contributes
Geomatry/Polygon/10652BoardWrapping/%.o: ../Geomatry/Polygon/10652BoardWrapping/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


