################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ShackDown/A/10746CrimeWave.cpp \
../ShackDown/A/A.cpp 

OBJS += \
./ShackDown/A/10746CrimeWave.o \
./ShackDown/A/A.o 

CPP_DEPS += \
./ShackDown/A/10746CrimeWave.d \
./ShackDown/A/A.d 


# Each subdirectory must supply rules for building sources it contributes
ShackDown/A/%.o: ../ShackDown/A/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


