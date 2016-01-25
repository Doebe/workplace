################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CodeChef/MayCookOff/C/C.cpp 

OBJS += \
./CodeChef/MayCookOff/C/C.o 

CPP_DEPS += \
./CodeChef/MayCookOff/C/C.d 


# Each subdirectory must supply rules for building sources it contributes
CodeChef/MayCookOff/C/%.o: ../CodeChef/MayCookOff/C/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


