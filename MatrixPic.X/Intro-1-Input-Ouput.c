/*==============================================================================
 Project: Intro-1-Input-Output
 Date:    May 16, 2021
 
 This example UBMP4 input and output program demonstrates pushbutton input, LED
 (bit) output, port latch (byte) output, time delay functions, and simple 'if'
 condition structures.
 
 Additional program analysis and programming activities demonstrate byte output,
 logical condition operators AND and OR, using delay functions to create sound,
 and simulated start-stop button functionality.
==============================================================================*/

#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP4.h"           // Include UBMP4 constants and functions

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

int main(void) {
    OSC_config();
    UBMP4_config();
	
    while(1) {
        if(SW2 == 0) {
            LED3 = 1;
            __delay_ms(100);
            LED4 = 1;
            __delay_ms(100);
            LED5 = 1;
            __delay_ms(100);
            LED6 = 1;
            __delay_ms(100);
            LED3 = 0;
            __delay_ms(100);
            LED4 = 0;
            __delay_ms(100);
            LED5 = 0;
            __delay_ms(100);
            LED6 = 0;
            __delay_ms(100);
        }
        
        if(SW1 == 0) {
            RESET();
        }
    }
}
