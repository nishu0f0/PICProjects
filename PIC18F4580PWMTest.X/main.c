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

void delayHigh(int angle){
    angle = angle<<1;
    _delay(1100);
    Delay10TCYx(angle);

}
void delayLow(int angle){
    angle = angle<<1;
    _delay(35600);
    Delay10TCYx(320-angle);
}

void doPWMPeriod(){
    LATDbits.LD0 = 0b1;
    delayHigh(angle);

    LATDbits.LD0 = 0b0;
    delayLow(angle);
}

void main(void) {
    ConfigureOscillator();
    InitApp();
    Delay10KTCYx(3);
    while(1){

        if(flag == 0){
            flag = 1;
            angle = 10;
        }else if(flag == 1){
            flag = 0;
            angle = 90;
        }

        for(j=0;j<50;j++){
            doPWMPeriod();
        }
  
    }
}

