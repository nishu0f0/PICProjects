/* 
 * File:   main.c
 * Author: Nishanth
 *
 * Created on 29 June, 2014, 7:01 PM
 */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

#include "config.h"
//#include <plib/usart.h>
#include <plib/adc.h>
#include <plib/pwm.h>
#include <plib/delays.h>
/*
 * 
 */

//#define _XTAL_FREQ 48000000
#define CYC_FREQ 12000000
#define CYC_DELAY 197120

//unsigned int getADC1(){

//}
unsigned int ADCResult=0;
void main(void) {

    //unsigned char sendMessage[4];
    unsigned char channel=0x00,config1=0x00,config2=0x00,config3=0x00,portconfig=0x00,i=0;

    OSCCONbits.IRCF     = 0b111;
    OSCCONbits.SCS      = 0b11;
    
    
    //PORTC Bit 6 Is TX (PIN 25)
    //TRISCbits.TRISC6 = 0;
    //PORTC Bit 7 Is RX (PIN 26)
    //TRISCbits.TRISC7 = 1;
    //Short delay
    TRISA = 0;
    TRISBbits.TRISB0 = 1;
    while(1){
        LA0 = 0b00000000;
        Delay10KTCYx(250);
        LA0 = 0b00000011;
        Delay10KTCYx(250);
        LA0 = 0b00001100;
        Delay10KTCYx(250);
        LA0 = 0b00110000;
        Delay10KTCYx(250);
        LA0 = 0b11000000;
        Delay10KTCYx(250);
    }



    config1 = ADC_FOSC_2 | ADC_RIGHT_JUST | ADC_2_TAD ;
    config2 = ADC_CH5 | ADC_INT_ON | ADC_REF_VDD_VSS ;
    portconfig = ADC_12ANA ;
    OpenADC(config1,config2,portconfig);

    ADC_INT_ENABLE();
   
    /*
    while(1){
        ConvertADC();
        while(BusyADC());
        ADCResult = (unsigned int)ReadADC();
        ADCResult = ADCResult/4;
        LATA = ADCResult;
        Delay10KTCYx(10);
    }
    */
}

