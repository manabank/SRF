
#include <xc.h>

#pragma config FOSC = INTIO67   /* Oscillator Selection bits (Internal oscillator block, port function on RA6 and RA7) */
#pragma config PWRT = OFF       /* Power-up Timer Enable bit (PWRT disabled) */
#pragma config WDTEN = OFF      /* Watchdog Timer Enable bit (WDT is controlled by SWDTEN bit of the WDTCON register) */

#define _XTAL_FREQ 16000000

unsigned char valor;

void configura_serial()
{
    //Configura oscilador interno para 16MHz
    OSCCONbits.IRCF = 0b111;
    
    SPBRG = 25; // Baud rate = 9600 bps; Fosc = 16MHz
    
    //Configura RX para 8N1
    RCSTA = 0b10010000;
    TXSTA = 0x00;
}

void main (void)
{
    configura_serial();
    
    // Configura RC7/RX como entrada
    TRISC |= 0b10000000;
    // Configura RD0,RD1,RD2,RD3 como sa?da
    TRISD &= 0b11110000;

    while(1){
        while (PIR1bits.RCIF ==0){};

        valor = RCREG;

        PORTD &= 0b11110000;
        switch(valor){
            case 0x61:
                PORTDbits.RD0 = 1;
                break;
            case 0x62:
                PORTDbits.RD1 = 1;
                break;
            case 0x63:
                PORTDbits.RD2 = 1;
                break;
            case 0x64:
                PORTDbits.RD3 = 1;
                break;
            default:
                break;
        }
    }
}