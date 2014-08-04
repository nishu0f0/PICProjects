/* 
 * File:   main.c
 * Author: Nishanth
 *
 * Created on 29 June, 2014, 7:01 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <plib/usart.h>
#include <plib/adc.h>
#include <plib/pwm.h>
#include <plib/delays.h>
/*
 * 
 */

//Register: CONFIG1L @ 0x300000
//Register: CONFIG1H @ 0x300001
#pragma config IESO = OFF
#pragma config FOSC = INTOSCIO_EC
#pragma config #pragma config FCMEN=OFF      //Fail-Safe Clock Monitor Enable bit

//Register: CONFIG2L @ 0x300002
#pragma config BOR=OFF        //Brown-out Reset Enable bits
#pragma config BORV=3         //Brown-out Reset Voltage bits
#pragma config PWRT=OFF       //Power-up Timer Enable bit

//Register: CONFIG2H @ 0x300003
#pragma config WDTPS=32768    //Watchdog Timer Postscale Select bits
#pragma config WDT=OFF        //Watchdog Timer Enable bit

//Register: CONFIG3H @ 0x300005
#pragma config CCP2MX = ON   //CCP2 input/output is multiplexed with RB3
#pragma config PBADEN = OFF  //PORTB<4:0> pins are configured as digital I/O on Reset
#pragma config LPT1OSC = OFF //Timer1 configured for higher power operation
#pragma config MCLRE  = ON //

//Register: CONFIG4L @ 0x300006
#pragma config DEBUG = ON //
#pragma config STVREN = ON //Stack full/underflow will cause Reset
#pragma config ICPRT = ON  //Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit
#pragma config XINST = ON
#pragma config LVP = OFF

//Register: CONFIG5L @ 0x300008
#pragma config CP1 = OFF
#pragma config CP2 = OFF
#pragma config CP3 = OFF
#pragma config CP0 = OFF

#pragma config CPD = OFF
#pragma config CPB = OFF
#pragma config WRT0 = OFF
#pragma config WRT1 = OFF
#pragma config WRT2 = OFF
#pragma config WRT4 = OFF
#pragma config WRTB = OFF
#pragma config WRTC = OFF
#pragma config WRTD = OFF
#pragma config EBTR0 = OFF
#pragma config EBTR1 = OFF
#pragma config EBTR2 = OFF
#pragma config EBTR3 = OFF
#pragma config EBTRB = OFF


#define _XTAL_FREQ 48000000
#define CYC_FREQ 12000000
#define CYC_DELAY 197120

unsigned int getADC1(){

}

void main(void) {

    unsigned char sendMessage[4];
    //PORTC Bit 6 Is TX (PIN 25)
    TRISCbits.TRISC6 = 0;
    //PORTC Bit 7 Is RX (PIN 26)
    TRISCbits.TRISC7 = 1;
    //Short delay
    Delay10KTCYx(250);
    CloseUSART();

    OpenUSART( USART_TX_INT_OFF  &
             USART_RX_INT_OFF  &
             USART_ASYNCH_MODE &
             USART_EIGHT_BIT   &
             USART_CONT_RX     &
             USART_BRGH_LOW, 207 );

    while(1){

        sendMessage[0]=0b00000000;
        sendMessage[1]=0b0000;
        sendMessage[2]=0b00000000;
        sendMessage[3]=0b00000000;

        while(BusyUSART());
        putcUSART(sendMessage[0]);
        while(BusyUSART());
        putcUSART(sendMessage[1]);
        while(BusyUSART());
        putcUSART(sendMessage[2]);
        while(BusyUSART());
        putcUSART(sendMessage[3]);

        Delay10KTCYx(10);
    }
    return (EXIT_SUCCESS);
}

