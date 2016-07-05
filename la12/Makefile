# Modify as appropriate
STELLARISWARE=C:/StellarisWare

CC=arm-none-eabi-gcc -Wall -Os -march=armv7-m -mcpu=cortex-m3 -mthumb -mfix-cortex-m3-ldrd -Wl,--gc-sections
	
# This creates the .BIN file once the .ELF file is created
svcdemo.bin: svcdemo.elf
	arm-none-eabi-objcopy -O binary svcdemo.elf svcdemo.bin

svcdemo.elf: svcdemo.c syscalls.c startup_gcc.c
	${CC} -o $@ -I${STELLARISWARE} -L${STELLARISWARE}/driverlib/gcc-cm3 -Tlinkscript.x -Wl,-Map,svcdemo.map -Wl,--entry,ResetISR svcdemo.c startup_gcc.c syscalls.c rit128x96x4.c -ldriver-cm3

.PHONY: clean
clean:
	rm -f *.elf *.map *.bin

# vim: noexpandtab  
