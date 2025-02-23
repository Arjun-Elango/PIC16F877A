
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
/*task problem statement 
 led pattern take two pin RD1,RD7
     RD1   RD7
 1   ON(1) OFF(0)
 2  OFF(0) ON(1)
 3   ON(1) 0N((1)
 4  OFF(0) OFF(0)
 * with delay of three seconds for each state
 */
#include <xc.h>
//set clock frequence
#define _XTAL_FREQ 6000000

int main(void) {
    // WE ALL as output for PICSIMLAB later we change for proteus
    // PORTD ALL PINs SHOULD OUTPUT 
    //TRISD = 0x00; //00000000 it is for PICSIMLAB simulation software
    // we set for proteus only RD7 & RD1 should be output all others are inputs
    TRISD =0x7D; //01111101
    PORTD = 0x00; //00000000 All pin should initially low
    while (1) { //infinite loop because true condition always direct of 0ne
        PORTD = 0x02; //00000010 RD1 is high now but RD7 IS LOW
        __delay_ms(3000); //because of 3 seconds
        PORTD = 0x80; //10000000 RD7 is high but RD1 ID LOW
        __delay_ms(3000);
        PORTD = 0x82; //10000010 both RD7&RD2 IS HIGH
        __delay_ms(3000);
        PORTD = 0X00; //00000000 both are low
        __delay_ms(3000);
    }
}
