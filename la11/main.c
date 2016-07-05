#include <stdio.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_nvic.h"
#include "inc/lm3s6965.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "drivers/rit128x96x4.h"

void delay()
{
    unsigned long int i;
    for(i=0;i<2999999999;i++);
}

int main(void)
{
    volatile unsigned count = 0;
    volatile unsigned long ulLoop;
    //
    // Set the clocking to run directly from the crystal.
    //
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                   SYSCTL_XTAL_8MHZ);


    // Uart config stuff
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;
    ulLoop = SYSCTL_RCGC2_R;
    GPIO_PORTF_DIR_R = 0x01;
    GPIO_PORTF_DEN_R = 0x01;

    //
    // Enable the peripherals used by this example.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    //
    // Set GPIO A0 and A1 as UART pins.
    //
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    //
    // Configure the UART for 115,200, 8-N-1 operation.
    //
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200,
                        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                         UART_CONFIG_PAR_NONE));

    //
    // Prompt for text to be entered.
    //

    //
    // Loop forever echoing data through the UART.
    //
    while(1)
    {
        printf("Count is %d\r\n", count); // or something.....
        delay();
        count++;
    }
}
