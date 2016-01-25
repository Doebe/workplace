################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Maths/10161AntOnAChessBoard/10161AntOnAChessBoard.cpp 

OBJS += \
./Maths/10161AntOnAChessBoard/10161AntOnAChessBoard.o 

CPP_DEPS += \
./Maths/10161AntOnAChessBoard/10161AntOnAChessBoard.d 


# Each subdirectory must supply rules for building sources it contributes
Maths/10161AntOnAChessBoard/%.o: ../Maths/10161AntOnAChessBoard/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


