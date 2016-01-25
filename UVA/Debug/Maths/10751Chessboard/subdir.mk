################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Maths/10751Chessboard/10751Chessboard.cpp 

OBJS += \
./Maths/10751Chessboard/10751Chessboard.o 

CPP_DEPS += \
./Maths/10751Chessboard/10751Chessboard.d 


# Each subdirectory must supply rules for building sources it contributes
Maths/10751Chessboard/%.o: ../Maths/10751Chessboard/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


