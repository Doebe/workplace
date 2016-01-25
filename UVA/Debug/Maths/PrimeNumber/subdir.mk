################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Maths/PrimeNumber/Prime.cpp \
../Maths/PrimeNumber/PrimeFactor.cpp 

OBJS += \
./Maths/PrimeNumber/Prime.o \
./Maths/PrimeNumber/PrimeFactor.o 

CPP_DEPS += \
./Maths/PrimeNumber/Prime.d \
./Maths/PrimeNumber/PrimeFactor.d 


# Each subdirectory must supply rules for building sources it contributes
Maths/PrimeNumber/%.o: ../Maths/PrimeNumber/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


