/* 
 * File:   main.c
 * Author: Nishanth
 *
 * Created on 20 July, 2014, 8:15 PM
 */
#define _XTAL_FREQ 32000000
#define CYC_FREQ 8000000
#define CYC_DELAY 197120
#include <xc.h> 
#include <stdio.h>
#include <stdlib.h>
#include <plib/delays.h>
#include "user.h"
#include "system.h"
//#include <plib/adc.h>
#include <plib/pwm.h>
#include <plib/delays.h>




/*
 * 
 */
unsigned int ADCValue = 0;
unsigned int flag = 0;
int i = 0;
int j = 0;
int angle = 0;


//void incrementDelay(unsigned int value){
//    do {
//        _delay(500);
//    } while(--value != 0);
//}

Transmitter(){
    while(1){



        
    }
}
Receiver(){
    while(1){
        
        
        
        
    }
}


void main(void) {
    ConfigureOscillator();
    InitApp();
    Delay10KTCYx(3);
    while(1){

       

        /*
        ADCON0bits.GO = 1;
        while(ADCON0bits.GO);
        ADCValue = (unsigned)(((unsigned int)ADRESH)<<8)|(ADRESL);
        ADCValue = ADCValue>>2;

        if(ADCValue>31){
            LATAbits.LA1 = 0b1;
        }else{
            LATAbits.LA1 = 0b0;
        }

        if(ADCValue>63){
            LATAbits.LA2 = 0b1;
        }else{
            LATAbits.LA2 = 0b0;
        }
        if(ADCValue>91){
            LATAbits.LA3 = 0b1;
        }else{
            LATAbits.LA3 = 0b0;
        }
        if(ADCValue>127){
            LATAbits.LA4 = 0b1;
        }else{
            LATAbits.LA4 = 0b0;
        }
        if(ADCValue>159){
            LATAbits.LA5 = 0b1;
        }else{
            LATAbits.LA5 = 0b0;
        }
        if(ADCValue>191){
            LATAbits.LA6 = 0b1;
        }else{
            LATAbits.LA6 = 0b0;
        }
        if(ADCValue>223){
            LATAbits.LA7 = 0b1;
        }else{
            LATAbits.LA7 = 0b0;
        }
        */




        /* PWM Code
        if(flag == 0){
            flag = 1;
            CCP1CONbits.DC1B = 0b00;
            CCPR1L = 0b01000000;
        }else if(flag == 1){
            flag = 0;
            CCP1CONbits.DC1B = 0b00;
            CCPR1L = 0b11110000;
        }
        */






        //Delay10KTCYx(200);
        
    }    
}

