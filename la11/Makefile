# Where the StellarisWare root directory is
STELLARISWARE=C:/StellarisWare

# -I flags for compilation
INCLUDES=-I${STELLARISWARE}/boards/ek-lm3s6965 -I${STELLARISWARE}

# Where the rit128x96x4.c OLED driver is
RITSRC=${STELLARISWARE}/boards/ek-lm3s6965/drivers/rit128x96x4.c

# Basic C flags for compilation
CC=arm-none-eabi-gcc -Wall -Os -march=armv7-m -mcpu=cortex-m3 -mthumb -mfix-cortex-m3-ldrd

# Linking flags
LDFLAGS=-Tlinkscript.x -Wl,--gc-sections -Wl,--entry,ResetISR -L${STELLARISWARE}/driverlib/gcc-cm3 -ldriver-cm3 -Wl,-Map,la11.map

# This creates the .BIN file once the .ELF file is created
la11.bin: la11.elf
	arm-none-eabi-objcopy -O binary la11.elf la11.bin

la11.elf: main.c startup_gcc.c syscalls.c linkscript.x Makefile
	${CC} ${INCLUDES} -o la11.elf main.c startup_gcc.c syscalls.c ${RITSRC} ${LDFLAGS}

# vim: noexpandtab
