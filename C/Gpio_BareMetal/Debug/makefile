################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Gpio_BareMetal.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Gpio_BareMetal.list \

OBJCOPY_BIN += \
Gpio_BareMetal.bin \


# All Target
all: Gpio_BareMetal.elf secondary-outputs

# Tool invocations
Gpio_BareMetal.elf: $(OBJS) $(USER_OBJS) C:\Users\Israel\STM32CubeIDE\workspace_1.2.0\Gpio_BareMetal\STM32F411RETX_FLASH.ld
	arm-none-eabi-gcc -o "Gpio_BareMetal.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Israel\STM32CubeIDE\workspace_1.2.0\Gpio_BareMetal\STM32F411RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Gpio_BareMetal.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Gpio_BareMetal.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Gpio_BareMetal.list"
	@echo 'Finished building: $@'
	@echo ' '

Gpio_BareMetal.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Gpio_BareMetal.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
