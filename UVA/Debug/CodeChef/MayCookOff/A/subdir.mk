################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CodeChef/MayCookOff/A/10746CrimeWave.cpp \
../CodeChef/MayCookOff/A/A.cpp 

OBJS += \
./CodeChef/MayCookOff/A/10746CrimeWave.o \
./CodeChef/MayCookOff/A/A.o 

CPP_DEPS += \
./CodeChef/MayCookOff/A/10746CrimeWave.d \
./CodeChef/MayCookOff/A/A.d 


# Each subdirectory must supply rules for building sources it contributes
CodeChef/MayCookOff/A/%.o: ../CodeChef/MayCookOff/A/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


