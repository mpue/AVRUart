################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
AVRUart.lss \

FLASH_IMAGE += \
AVRUart.hex \

EEPROM_IMAGE += \
AVRUart.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: AVRUart.elf secondary-outputs

# Tool invocations
AVRUart.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AVRUart.map -mmcu=atmega328p -o "AVRUart.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AVRUart.lss: AVRUart.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AVRUart.elf  >"AVRUart.lss"
	@echo 'Finished building: $@'
	@echo ' '

AVRUart.hex: AVRUart.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AVRUart.elf  "AVRUart.hex"
	@echo 'Finished building: $@'
	@echo ' '

AVRUart.eep: AVRUart.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex AVRUart.elf  "AVRUart.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AVRUart.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p AVRUart.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AVRUart.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
