################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../MayCookOff/A/10746CrimeWave.cpp \
../MayCookOff/A/A.cpp 

OBJS += \
./MayCookOff/A/10746CrimeWave.o \
./MayCookOff/A/A.o 

CPP_DEPS += \
./MayCookOff/A/10746CrimeWave.d \
./MayCookOff/A/A.d 


# Each subdirectory must supply rules for building sources it contributes
MayCookOff/A/%.o: ../MayCookOff/A/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


