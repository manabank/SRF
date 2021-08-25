
#include <xc.h>

#pragma config FOSC = INTIO67   /* Oscillator Selection bits (Internal oscillator block, port function on RA6 and RA7) */
#pragma config PWRT = OFF       /* Power-up Timer Enable bit (PWRT disabled) */
#pragma config WDTEN = OFF      /* Watchdog Timer Enable bit (WDT is controlled by SWDTEN bit of the WDTCON register) */
#pragma config PBADEN = OFF 

#define _XTAL_FREQ 16000000

void configura_serial()
{
    //Configura oscilador interno para 16MHz
    OSCCONbits.IRCF = 0b111;
    
    SPBRG = 25; // Baud rate = 9600 bps; Fosc = 16MHz
    
    //Configura RX e TX para 8N1
    RCSTA = 0b10010000;
    TXSTA = 0b00100000;
}

void main (void)
{
    configura_serial();
    
    //Habilitar as interrup��es
    INTCONbits.PEIE = 1; // Habilita interrup��es perif�ricas
    INTCONbits.GIE = 1; // Habilita interrup��o geral
    
    // Configura RC6/TX como sa�da
    TRISC &= 0b10111111;
    
    // Configura RB0 como entrada (Bot�o)
    TRISB |= 0b00000001;
    
    while(1){
        if (PORTBbits.RB0 == 1){
            TXREG = 0x49; // Enviar '1' para ligar o LED
        } else{
            TXREG = 0x48; // Enviar '0' para ligar o LED
        }
        
        // Espera concluir a transmiss�o do byte
        while (!(PIR1 & 0b00010000)){};
    }
}