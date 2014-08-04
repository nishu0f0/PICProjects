/* 
 * File:   main.c
 * Author: Nishanth
 *
 * Created on 7 June, 2014, 9:22 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
#include<p18f4550.h>                                //      [[[[Include the PIC18F550 Headers]]]]]]

/* COMPILER DIRECTIVES FOR CHIP CONFIGURATION BITS*/

#pragma config PLLDIV = 5 , CPUDIV = OSC1_PLL2 , USBDIV = 2 , FOSC = INTOSCIO_EC	// You can write this way

// OR
#pragma config FCMEN = OFF		  // OR this way
#pragma config IESO = OFF
#pragma config PWRT = OFF
#pragma config BOR = OFF
#pragma config BORV = 3
#pragma config VREGEN = OFF
#pragma config WDT = OFF
#pragma config CP0 = OFF, CP1 = OFF, CP2 = OFF, CP3 = OFF
#pragma config CPB = OFF
#pragma config CPD = OFF
#pragma config WRT0 = OFF, WRT1 = OFF, WRT2 = OFF, WRT3 = OFF

void delayzz(void)
{	int i, j;
	for(i=0;i<5000;i++)
     {
	for(j=0;j<2;j++)

             {       /* Well its Just a Timer */   }}}

void main(void)
{
	TRISB = 0xF0 ; // PORT B Setting: Set all the pins in port B to Output.
        LATB=0b00000000;
  while(1)
		{

		LATBbits.LATB0 = 1;   // RB-0 to High
		LATBbits.LATB1 = 1;   // RB-1 to High

		//delayzz();

		LATBbits.LATB0 = 0;    // RB-0 to LOW
		LATBbits.LATB1 = 0;    // RB-1 to LOW

		//delayzz();

	     }
}
/* THE END */

