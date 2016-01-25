################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CodeChef/ShackDown/A/10746CrimeWave.cpp \
../CodeChef/ShackDown/A/A.cpp 

OBJS += \
./CodeChef/ShackDown/A/10746CrimeWave.o \
./CodeChef/ShackDown/A/A.o 

CPP_DEPS += \
./CodeChef/ShackDown/A/10746CrimeWave.d \
./CodeChef/ShackDown/A/A.d 


# Each subdirectory must supply rules for building sources it contributes
CodeChef/ShackDown/A/%.o: ../CodeChef/ShackDown/A/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


