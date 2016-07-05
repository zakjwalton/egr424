# The C:/StellarisWare directory
ROOT=C:/StellarisWare

# Where the driver library is
DRIVERLIBDIR=${ROOT}/driverlib/gcc-cm3

# Where the OLED driver is
OLEDDIR=${ROOT}/boards/ek-lm3s6965

# The basic compiler command and flags
CC=arm-none-eabi-gcc \
   -Wall \
   -Os \
   -march=armv7-m -mcpu=cortex-m3 -mthumb -mfix-cortex-m3-ldrd \
   -ffunction-sections -fdata-sections \
   -std=c99 -Wall -pedantic -DPART_LM3S6965 -Dgcc \
   -I${ROOT} \
   -I${OLEDDIR} \
   -L${DRIVERLIBDIR}

# What directories contain sources and targets (besides the
# current directory)
#VPATH=${OLEDDIR}


# This creates the .BIN file once the .ELF file is created
gcc/gpio.bin: gcc/gpio.elf
	arm-none-eabi-objcopy -O binary gcc/gpio.elf gcc/gpio.bin
	

# This creates the .ELF file if any of the dependencies change
gcc/gpio.elf: gpio.c startup_gcc.c gpio.ld
	${CC} -o gcc/gpio.elf \
	      gpio.c startup_gcc.c \
	      ${OLEDDIR}/drivers/rit128x96x4.c \
            -ldriver-cm3 \
	      -T gpio.ld \
	      --entry ResetISR \
	      -Wl,--gc-sections \
	     

# This "pseudo-target" removes the target and intermediate files
.PHONY: clean
clean:
	rm -rf gcc
	mkdir gcc

# vim: noexpandtab
