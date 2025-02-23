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

#define _XTAL_FREQ 6000000 // SETTING CLOCK FREQUENCY 

unsigned char value ; // for store the current value or status of the portB

void main(void){
    TRISB = 0xF0;  // 1111 0000 for RB4 TO RB7 AS INPUT AND RB3-RB0 AS OUTPUT
    PORTB = 0x00;  // 0000 0000 for starting state of the process 
    /*input does not take the program value only output can take the value
     * input only in read mode , output only in write mode */
    TRISC = 0x00;  /* 0000 0000 we need to set RC1 and RC6 as output 
                    * rest of the pins can be any state we doesn't take into 
                    * consider*/
    PORTC = 0X00;  /* 0000 0000 starting state led should be low*/
    while(1){
        value = PORTB ; // store the state of PORTB
        switch(value){  // USING SWITCH case for do respective action
            case 0xE0:  // 1110 0000 if RB4 PRESSED THEN WE NEED TO turn ON the RC1
                PORTC = 0x02; //0000 0010 it high the RC1 connected LED
            break;  // end this action
            case 0xD0:  //1101 0000 if RB5 PRESSED THEN WE NEED TO TURN ON BOTH LED
                PORTC = 0x42; //0100 0010 it high the RC6 & RC1
            break;
            case 0xB0:  //1011 0000 if RB6 PRESSED THEN WE NEED TO TURN ON RC6 LED
                PORTC = 0x40; //0100 0000 it high the RC6 connected LED
            break;
            case 0x70 : // 0111 0000 if RB7 PRESSED THEN WE NEED TO TURN OFF BOTH
                PORTC = 0x00; // it low both RC6 &RC1 CONNECT LED
            break;
            case 0xF0: //if no above case possible or none of the switch pressed
                PORTC = 0x00; // both should be low
            break;
                
        }
    }
}
