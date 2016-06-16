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
   -I${ROOT} -I${OLEDDIR} -L${DRIVERLIBDIR}

# What directories contain sources and targets (besides the
# current directory)
#VPATH=${OLEDDIR}

# This creates the .BIN file once the .AXF file is created
gcc/hello.bin: gcc/hello.axf
	arm-none-eabi-objcopy -O binary gcc/hello.axf gcc/hello.bin

# This creates the .AXF file if any of the dependencies change
gcc/hello.axf: hello.c startup_gcc.c hello.ld
	${CC} -o gcc/hello.axf \
	      -Wl,-T,hello.ld \
	      -Wl,--entry,ResetISR \
	      -Wl,--gc-sections \
	      hello.c startup_gcc.c \
		  ${OLEDDIR}/drivers/rit128x96x4.c \
	      -ldriver-cm3

# This "pseudo-target" removes the target and intermediate files
.PHONY: clean
clean:
	rm -rf gcc
	mkdir gcc

# vim: noexpandtab
