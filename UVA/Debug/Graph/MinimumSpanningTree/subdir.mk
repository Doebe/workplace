################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/MinimumSpanningTree/Kruskal.cpp \
../Graph/MinimumSpanningTree/Prim.cpp 

OBJS += \
./Graph/MinimumSpanningTree/Kruskal.o \
./Graph/MinimumSpanningTree/Prim.o 

CPP_DEPS += \
./Graph/MinimumSpanningTree/Kruskal.d \
./Graph/MinimumSpanningTree/Prim.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/MinimumSpanningTree/%.o: ../Graph/MinimumSpanningTree/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


