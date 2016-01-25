################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../zhenglin-pan-homework-1/tcpclient.c \
../zhenglin-pan-homework-1/tcpserver.c 

OBJS += \
./zhenglin-pan-homework-1/tcpclient.o \
./zhenglin-pan-homework-1/tcpserver.o 

C_DEPS += \
./zhenglin-pan-homework-1/tcpclient.d \
./zhenglin-pan-homework-1/tcpserver.d 


# Each subdirectory must supply rules for building sources it contributes
zhenglin-pan-homework-1/%.o: ../zhenglin-pan-homework-1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


