#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************
# sources.mk - List of source files and include directories for the project

# General source files
SOURCES = \
    src/main.c \
    src/memory.c

# Platform-specific source files (for MSP432)
ifeq ($(PLATFORM),MSP432)
    SOURCES += \
        src/system_msp432p401r.c \
        src/interrupts_msp432p401r_gcc.c \
        src/startup_msp432p401r_gcc.c
endif

# Include directories
INCLUDES = \
    -Iinclude \
    -Iinclude/CMSIS \
    -Iinclude/common \
    -Iinclude/msp432
