################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/AllPairsShortestPath/10171MeetingProfMiguel/10171MeetingProfMiguel.cpp 

OBJS += \
./Graph/AllPairsShortestPath/10171MeetingProfMiguel/10171MeetingProfMiguel.o 

CPP_DEPS += \
./Graph/AllPairsShortestPath/10171MeetingProfMiguel/10171MeetingProfMiguel.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/AllPairsShortestPath/10171MeetingProfMiguel/%.o: ../Graph/AllPairsShortestPath/10171MeetingProfMiguel/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


