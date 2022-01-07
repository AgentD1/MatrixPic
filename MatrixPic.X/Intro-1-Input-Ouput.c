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

void sendBit(unsigned char theBit);

#define MatrixChipSelectPin H2OUT
#define MatrixDataInPin     H1OUT
#define MatrixClockPin      H3OUT

void sendMatrixData(unsigned char data, unsigned char address);

int main(void) {
    MatrixChipSelectPin = 1;
    OSC_config();
    UBMP4_config();
    
    MatrixChipSelectPin = 0;
    
    sendMatrixData(0b10000000, 0x0C);
    sendMatrixData(0xFF, 0x0A);
    sendMatrixData(0xFF, 0x0B);
    
    
    while(1) {
        sendBit(1);
        if(SW2 == 0) {
            MatrixChipSelectPin = 1;
            sendMatrixData(0, 0xff);
        }
        
        if(SW1 == 0) {
            RESET();
        }
    }
}


void sendMatrixData(unsigned char data, unsigned char address) {
    TRISC &= 0b00000000;
    MatrixChipSelectPin = 0;
    
    sendBit(0);
    sendBit(0);
    sendBit(0);
    sendBit(0);
    
    sendBit(address & 0b00001000);
    sendBit(address & 0b00000100);
    sendBit(address & 0b00000010);
    sendBit(address & 0b00000001);
    
    sendBit(data & 0b10000000);
    sendBit(data & 0b01000000);
    sendBit(data & 0b00100000);
    sendBit(data & 0b00010000);
    sendBit(data & 0b00001000);
    sendBit(data & 0b00000100);
    sendBit(data & 0b00000010);
    sendBit(data & 0b00000001);
    
    MatrixChipSelectPin = 1;
}

void sendBit(unsigned char theBit) {
    if(theBit == 0) {
        MatrixDataInPin = 0;
    } else {
        MatrixDataInPin = 1;
    }
    NOP();
    MatrixClockPin = 1;
    NOP();
    MatrixClockPin = 0;
    NOP();
}
