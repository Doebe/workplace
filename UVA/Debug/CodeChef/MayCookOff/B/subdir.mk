################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CodeChef/MayCookOff/B/B.cpp 

OBJS += \
./CodeChef/MayCookOff/B/B.o 

CPP_DEPS += \
./CodeChef/MayCookOff/B/B.d 


# Each subdirectory must supply rules for building sources it contributes
CodeChef/MayCookOff/B/%.o: ../CodeChef/MayCookOff/B/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


