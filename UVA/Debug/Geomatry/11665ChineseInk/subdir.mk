################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Geomatry/11665ChineseInk/11665ChineseInk.cpp 

OBJS += \
./Geomatry/11665ChineseInk/11665ChineseInk.o 

CPP_DEPS += \
./Geomatry/11665ChineseInk/11665ChineseInk.d 


# Each subdirectory must supply rules for building sources it contributes
Geomatry/11665ChineseInk/%.o: ../Geomatry/11665ChineseInk/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


