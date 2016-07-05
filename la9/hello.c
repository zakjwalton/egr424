//*****************************************************************************
//
// hello.c - Simple hello world example.
//
// Copyright (c) 2006-2011 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 8264 of the EK-LM3S6965 Firmware Package.
//
//*****************************************************************************

#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "drivers/rit128x96x4.h"
#include "inc/lm3s6965.h"

//*****************************************************************************
//
//! \addtogroup example_list
//! <h1>Hello World (hello)</h1>
//!
//! A very simple ``hello world'' example.  It simply displays ``hello world''
//! on the OLED and is a starting point for more complicated applications.
//
//*****************************************************************************

volatile char toggle = 0;
volatile char service = 0;

//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, unsigned long ulLine)
{
}
#endif

void SysTickISR(void)
{
    service = 1;
}

//*****************************************************************************
//
// Print "Hello world!" to the OLED on the Stellaris evaluation board.
//
//*****************************************************************************
int main(void)
{
    //
    // Set the clocking to run directly from the crystal.
    //
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                   SYSCTL_XTAL_8MHZ);

    //
    // Initialize the OLED display.
    //
    RIT128x96x4Init(1000000);

    //Set up timer
    NVIC_ST_CTRL_R = 0;
    NVIC_ST_RELOAD_R = 2000000;
    NVIC_ST_CURRENT_R = 0;
    NVIC_ST_CTRL_R = 0x7;

    while(1)
    {
        if(service)
        {
            //Toggle stuff
            if(toggle)
            {
                //Draw hello world
                RIT128x96x4StringDraw("Hello Karl!", 30, 24, 15);
            }
            else
            {
                //Erase Hello world
                RIT128x96x4Clear();
            }
            toggle ^= 1;
            service = 0;
        }
    }
}
