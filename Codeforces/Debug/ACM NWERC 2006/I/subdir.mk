################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ACM\ NWERC\ 2006/I/srcI.cpp 

OBJS += \
./ACM\ NWERC\ 2006/I/srcI.o 

CPP_DEPS += \
./ACM\ NWERC\ 2006/I/srcI.d 


# Each subdirectory must supply rules for building sources it contributes
ACM\ NWERC\ 2006/I/srcI.o: ../ACM\ NWERC\ 2006/I/srcI.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"ACM NWERC 2006/I/srcI.d" -MT"ACM\ NWERC\ 2006/I/srcI.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

