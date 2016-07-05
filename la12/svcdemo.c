#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "rit128x96x4.h"

// You must write an exception handler for the SVC exception
// that calls handleSVC() with the 8-bit integer encoded in
// the SVC instruction.
void handleSVC(int code)
{
  // NOTE: iprintf() is a bad idea inside an exception
  // handler (exception handlers should be small and short).
  // But this is the easiest way to show we got it right.
  switch (code & 0xFF) {
    case 123:
      iprintf("Do the 123 thing\r\n");
      break;

    case 234:
      iprintf("Do the 234 thing\r\n");
      break;

    default:
      iprintf("UNKNOWN SVC CALL\r\n");
      break;
  }
}

void main(void)
{
  // Set the clocking to run directly from the crystal.
  SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                 SYSCTL_XTAL_8MHZ);

  // Initialize the OLED display and write status.
  RIT128x96x4Init(1000000);
  RIT128x96x4StringDraw("SVC Demo",       32,  0, 15);

  // Enable the peripherals used by this example.
  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

  // Set GPIO A0 and A1 as UART pins.
  GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

  // Configure the UART for 115,200, 8-N-1 operation.
  UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200,
                      (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                       UART_CONFIG_PAR_NONE));

  while (1) {
    int c;

    // Read characters from the keyboard and act on them. Requires _read()
    // syscall to be implemented.
    switch( (c = getchar()) ) {
      case EOF: // No characters are available
        clearerr(stdin);  // Must be used to clear EOF condition
        break;

      case '0':
        asm volatile ("svc #123");
        break;

      case '1':
        asm volatile ("svc #234");
        break;

      default:
        iprintf("Press 0 or 1\r\n");
        break;
    }
  }

  exit(0);
}

/*
 * Compile with:
 * ${CC} -o svcdemo.elf -I${STELLARISWARE} -L${STELLARISWARE}/driverlib/gcc 
 *     -Tlinkscript.x -Wl,-Map,svcdemo.map -Wl,--entry,ResetISR 
 *     svcdemo.c startup_gcc.c syscalls.c rit128x96x4.c 
 *     -ldriver
 *
 * NOTE: - syscalls.c has _read() implemented for UART
 */
// vim: expandtab ts=2 sw=2 cindent
