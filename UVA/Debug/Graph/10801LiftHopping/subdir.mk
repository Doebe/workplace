################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/10801LiftHopping/10801LiftHopping.cpp \
../Graph/10801LiftHopping/Dijkstra.cpp 

OBJS += \
./Graph/10801LiftHopping/10801LiftHopping.o \
./Graph/10801LiftHopping/Dijkstra.o 

CPP_DEPS += \
./Graph/10801LiftHopping/10801LiftHopping.d \
./Graph/10801LiftHopping/Dijkstra.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/10801LiftHopping/%.o: ../Graph/10801LiftHopping/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


