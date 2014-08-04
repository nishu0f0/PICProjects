/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#include <xc.h>         /* XC8 General Include File */
#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */
#include "user.h"
//#include <plib/adc.h>

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
    /* TODO Initialize User Ports/Peripherals/Project here */
    TRISA = 0b00000001;
    TRISCbits.RC2 = 0b0;
    TRISDbits.RD0 = 0b0;
    LATCbits.LATC2 = 0b0;
    LATDbits.LATD0 = 0b0;

    /* Setup analog functionality and port direction */
    ADCON0bits.ADON = 0b1;
    ADCON0bits.CHS = 0b0000;
    ADCON1bits.PCFG = 0b1110;
    ADCON1bits.VCFG0 = 0b0;
    ADCON1bits.VCFG1 = 0b0;
    ADCON2bits.ADCS = 0b010;
    ADCON2bits.ACQT = 0b001;
    ADCON2bits.ADFM = 0b1;
    
    /* Initialize peripherals */
    //Set Timer 1 prescale to 1 , Period to 255,
    PR2 = 0b1111011;//0b11111111;
    T2CONbits.T2CKPS = 0b11;//0b00;
    T2CONbits.TMR2ON = 0b1;
    //Enable PWM Mode in CCP1
    CCP1CONbits.CCP1M = 0b1111;
    //initialize PWM DutyCycle with 0
    CCP1CONbits.DC1B = 0b00;
    CCPR1L = 0b00000000;


    /* Configure the IPEN bit (1=on) in RCON to turn on/off int priorities */

    /* Enable interrupts */
}

