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
/*problem statement PULL UP CONCEPT INTERFACING USER PUSHBUTTON FOR CONTROL LED
         |  RD3   |  RD5   |
 * RC0=0 | Off(0) |  ON(1) |
 * RC1=0 | ON(1)  |  OFF(0)|
 * RC2=0 | ON(1)  |  ON(1) |
 * RC3=0 | OFF(0) | OFF(0) |
  default state both should off 
 */

#include <xc.h>
// set clock frequency 
#define _XTAL_FREQ 6000000

unsigned char status; // to store the status of the PORTC

void main(void){
    TRISC = 0x0F; // 0000 1111 TO make the RC0 - RC3 as input and RC4-RC7 as output
    PORTC = 0x00; // 0000 0000 for initial process of state it is not take 
    TRISD = 0x00; // 0000 0000 which make RD3 AND RD5 as output rest not considered
    PORTD = 0x00; // 0000 0000 initial state shloud be low before any action done
    while(1){     // loop , continous runing the block of code
        status = PORTC;
        switch(status){
            case 0x0E: // 0000 1110 if RC0 is pressed then RD5 should turn on
                PORTD= 0x20; //0010 0000  it high the RD5
                break;
            case 0x0D: // 0000 1101 if RC1 is pressed then RD3 should turn on
                PORTD= 0x08; //0000 1000 it high the RD3
                break;
            case 0x0B: // 0000 1011 if RC2 is pressed then both should be turn on
                PORTD= 0x28; //0010 1000 it high the RD5 & RD3
                break;
            case 0x07: // 0000 0111 if RC3 is pressed then both should be turn off
                PORTD= 0x00; // 0000 0000  it low the LED 
                break;
            case 0x0F: // IF none of the switch is pressed both led should be low
                PORTD= 0x00; // 0000 0000 it low the LED
                break;
        }
        
    }
    
}