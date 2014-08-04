#include <xc.h>
#include "config.h"
#include <plib/delays.h>
#include <plib/adc.h>
#include <stdio.h>

/* COMPILER DIRECTIVES FOR CHIP CONFIGURATION BITS*/


/*CONFIGURATION START*/
/*
//Register: CONFIG1H @ 0x300001
#pragma config IESO=OFF       //Internal/External Oscillator Switchover bit
#pragma config OSC=INTIO2     //Oscillator
#pragma config FCMEN=OFF      //Fail-Safe Clock Monitor Enable bit

//Register: CONFIG2L @ 0x300002
#pragma config BOR=OFF        //Brown-out Reset Enable bits
#pragma config BORV=3         //Brown-out Reset Voltage bits
#pragma config PWRT=OFF       //Power-up Timer Enable bit

//Register: CONFIG2H @ 0x300003
#pragma config WDTPS=32768    //Watchdog Timer Postscale Select bits
#pragma config WDT=OFF        //Watchdog Timer Enable bit

//Register: CONFIG3L @ 0x300004
//#pragma config PWMPIN=ON      //PWM Output Pins Reset State Control bit
//#pragma config HPOL=HIGH      //High Side Transistors Polarity bit (Odd PWM Output Polarity Control bit)
//#pragma config LPOL=HIGH      //Low-Side Transistors Polarity bit (Even PWM Output Polarity Control bit)

//Register: CONFIG3H @ 0x300005
#pragma config MCLRE=ON	      //Master Clear Enable bit
#pragma config FLTAMX=RA7     //FLTA Mux bit(Fault detect input for PWM)
#pragma config T1OSCMX=LOW    //(RB2)Timer1 oscillator output or Timer1 clock input

//Register: CONFIG4L @ 0x300006
#pragma config DEBUG = ON     //Background Debugger Enable bit
#pragma config STVREN = OFF   //Stack Overflow/Underflow Reset Enable bit
#pragma config XINST = OFF     //Extended Instruction Set Enable bit
#pragma config BBSIZ =BB512   //Boot Block Size Select bits

//Register: CONFIG5L @ 0x300008
#pragma config CP0 = OFF      //Code Protection bit Block 0 (000800-000FFF)
#pragma config CP1 = OFF      //Code Protection bit Block 1 (001000-001FFF)

//Register: CONFIG5H @ 0x300009
#pragma config CPB = OFF      //Code Protection bit (Boot Block Memory Area)
#pragma config CPD = OFF      //Code Protection bit (Data EEPROM)

//Register: CONFIG6L @ 0x30000A
#pragma config WRT0 = OFF     //Write Protection bit Block 0 (000800-000FFF)
#pragma config WRT1 = OFF     //Write Protection bit Block 1 (001000-001FFF)

//Register: CONFIG6H @ 0x30000B
#pragma config WRTB = OFF     //Write Protection bit (Boot Block Memory Area)
#pragma config WRTC = OFF     //Write Protection bit (Configuration Registers)
#pragma config WRTD = OFF     //Write Protection bit (Data EEPROM)

//Register: CONFIG7L @ 0x30000C
#pragma config EBTR0 =OFF     //Table Read Protection bit Block 0 (000800-000FFF)
#pragma config EBTR1 =OFF     //Table Read Protection bit Block 1 (001000-001FFF)

//Register: CONFIG7H @ 0x30000D
#pragma config EBTRB =OFF     //Table Read Protection bit (Boot Block Memory Area)
 */
/*CONFIGURATION END*/



#define _XTAL_FREQ 32000000
#define CYC_FREQ 8000000
#define CYC_DELAY 197120

void ConfigureOscillator(void) {
    OSCCONbits.IRCF = 0b111;
    OSCCONbits.SCS = 0b11;
    OSCTUNEbits.PLLEN = 0b1;
}

void delays(int n) {
    int i = 10 * n; // (n* CYC_FREQ) /CYC_DELAY;
    //int k= (CYC_DELAY * 1000) / CYC_FREQ;

    int j;
    for (j = 0; j < i; j++) {
        _delay(CYC_DELAY);
    }
}
//unsigned int ADCResult = 0;

//#define USE_OR_MASKS

void main(void) {
    ConfigureOscillator();

    TRISB0 = 0;
    TRISB1 = 0;
    TRISB4 = 1;
    TRISA1 = 1;
    
    //unsigned char channel = 0x00, config1 = 0x00, config2 = 0x00, config3 = 0x00, portconfig = 0x00, i = 0;
    //CloseADC();
    //config1 = ADC_FOSC_2 | ADC_RIGHT_JUST | ADC_2_TAD;
    //config2 = ADC_CH0 | ADC_INT_OFF | ADC_REF_VDD_VSS;
    //portconfig = ADC_4ANA;
    //OpenADC(config1, config2, portconfig);
    /*
    ADCON0bits.ADON = 0b1;
    ADCON0bits.CHS = 0b00;
    ADCON1bits.VCFG0 = 0b0;
    ADCON1bits.PCFG0 = 0b1;
    ADCON2bits.ADFM = 0b1;
    ADCON2bits.ADCS = 0b000;
     */
    //ADC_INT_ENABLE();
    while(1){
        
        //ConvertADC();
        //while (BusyADC());
        //ADCResult = PORTAbits.RA1;//(unsigned int) ReadADC();
       // if(ADCResult==1){
            LATB0 = 1; // RB-0 to High
            LATB1 = 1; // RB-1 to High
            Delay10KTCYx(30);
       // }else{
            LATB0 = 0; // RB-0 to High
            LATB1 = 0; // RB-1 to High
        //}
         Delay10KTCYx(30);

    }
    /*
    while (1) {


        //PORTBbits.RB1=0b1
        //if(PORTBbits.RB4==0){
        LATBbits.LATB0 = 1; // RB-0 to High
        LATBbits.LATB1 = 0; // RB-1 to High
        //delays(1);
        Delay10KTCYx(30);
        // }
        // if(PORTBbits.RB4==1){
        LATBbits.LATB0 = 0; // RB-0 to LOW
        LATBbits.LATB1 = 1; // RB-1 to LOW
        //delays(1);
        Delay10KTCYx(30);
        // }

   }*/ 
}
/* THE END */