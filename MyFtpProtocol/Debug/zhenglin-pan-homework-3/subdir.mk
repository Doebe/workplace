################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../zhenglin-pan-homework-3/gbnreceiver.c \
../zhenglin-pan-homework-3/gbnsender.c 

OBJS += \
./zhenglin-pan-homework-3/gbnreceiver.o \
./zhenglin-pan-homework-3/gbnsender.o 

C_DEPS += \
./zhenglin-pan-homework-3/gbnreceiver.d \
./zhenglin-pan-homework-3/gbnsender.d 


# Each subdirectory must supply rules for building sources it contributes
zhenglin-pan-homework-3/%.o: ../zhenglin-pan-homework-3/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


