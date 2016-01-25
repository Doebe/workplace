################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include ShackDown/Round2/F/subdir.mk
-include ShackDown/Round2/E/subdir.mk
-include ShackDown/Round2/D/subdir.mk
-include ShackDown/Round2/C/subdir.mk
-include ShackDown/Round2/B/subdir.mk
-include ShackDown/Round2/A/subdir.mk
-include ShackDown/D/subdir.mk
-include ShackDown/C/subdir.mk
-include ShackDown/B/subdir.mk
-include ShackDown/A/subdir.mk
-include MayCookOff/D/subdir.mk
-include MayCookOff/C/subdir.mk
-include MayCookOff/B/subdir.mk
-include MayCookOff/A/subdir.mk
-include JulyCookOff/D/subdir.mk
-include JulyCookOff/C/subdir.mk
-include JulyCookOff/B/subdir.mk
-include JulyCookOff/A/subdir.mk
-include JulyChallenge/subdir.mk
-include DTU/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: CodeChef

# Tool invocations
CodeChef: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross G++ Linker'
	g++  -o "CodeChef" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(C_DEPS)$(CPP_DEPS) CodeChef
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
