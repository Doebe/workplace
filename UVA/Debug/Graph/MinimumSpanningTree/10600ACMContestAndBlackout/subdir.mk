################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/MinimumSpanningTree/10600ACMContestAndBlackout/10600ACMContestAndBlackout.cpp 

OBJS += \
./Graph/MinimumSpanningTree/10600ACMContestAndBlackout/10600ACMContestAndBlackout.o 

CPP_DEPS += \
./Graph/MinimumSpanningTree/10600ACMContestAndBlackout/10600ACMContestAndBlackout.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/MinimumSpanningTree/10600ACMContestAndBlackout/%.o: ../Graph/MinimumSpanningTree/10600ACMContestAndBlackout/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


