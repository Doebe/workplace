################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/11831StickerCollectorRobot/11831StickerCollectorRobot.cpp 

OBJS += \
./Graph/11831StickerCollectorRobot/11831StickerCollectorRobot.o 

CPP_DEPS += \
./Graph/11831StickerCollectorRobot/11831StickerCollectorRobot.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/11831StickerCollectorRobot/%.o: ../Graph/11831StickerCollectorRobot/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


