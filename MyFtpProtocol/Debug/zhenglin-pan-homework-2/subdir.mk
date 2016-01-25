################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../zhenglin-pan-homework-2/Peer.c \
../zhenglin-pan-homework-2/Tracker.c 

OBJS += \
./zhenglin-pan-homework-2/Peer.o \
./zhenglin-pan-homework-2/Tracker.o 

C_DEPS += \
./zhenglin-pan-homework-2/Peer.d \
./zhenglin-pan-homework-2/Tracker.d 


# Each subdirectory must supply rules for building sources it contributes
zhenglin-pan-homework-2/%.o: ../zhenglin-pan-homework-2/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


