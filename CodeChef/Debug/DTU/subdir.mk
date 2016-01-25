################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DTU/Harmony.cpp \
../DTU/Matrix.cpp \
../DTU/Number.cpp 

OBJS += \
./DTU/Harmony.o \
./DTU/Matrix.o \
./DTU/Number.o 

CPP_DEPS += \
./DTU/Harmony.d \
./DTU/Matrix.d \
./DTU/Number.d 


# Each subdirectory must supply rules for building sources it contributes
DTU/%.o: ../DTU/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


