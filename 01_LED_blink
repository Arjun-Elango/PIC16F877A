
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

// set clock frequency
#define _XTAL_FREQ 6000000

/*class task problem statement : connect a LED To pin RD2 and blink it with a delay of 1 second*/
int main(void) {
    //EXCEPT pin RD2 all should be act as input but i can't get correct output all leds are high in PICSIMLAB
     TRISD = 0xfb; //11111011 RD2 is now act as output all other pin are inputs it is for proteus software
    // so i changed 
    //TRISD = 0x00; //00000000 RD2 is now act as output all other pin are also output it is for PICSIMLAB simulation software

    PORTD = 0x00; //00000000 at initial stage all should be low

    while (1) { // Infinite loop runs continuously ,we know "while" execute a set of code until Condition satisfied.
        //to turn on or HIGH a pin RD2 for led on bit2 should one
        PORTD = 0x04; //00000100
        __delay_ms(1000);
        PORTD = 0x00; //00000000 it turn off led connected to RD2
        __delay_ms(1000);
    }
}
