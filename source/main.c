/*	Author: Steven Rodriguez
 *  Partner(s) Name: Anthony Pham
 *	Lab Section: 21
 *	Assignment: Lab #3  Exercise #2
 *	Exercise Description: A car has a fuel-level sensor that sets PA3..PA0 to a value between 0 (empty) and 15 (full). 
 *  A series of LEDs connected to PC5..PC0 should light to graphically indicate the fuel level. 
 *  If the fuel level is 1 or 2, PC5 lights. If the level is 3 or 4, PC5 and PC4 light. Level 5-6 lights PC5..PC3. 7-9 lights PC5..PC2. 10-12 lights PC5..PC1. 13-15 lights PC5..PC0. Also, PC6 connects to a "Low fuel" icon, which should light if the level is 4 or less. 
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

//setbit from zybooks, function definition is confusing but it works
//will read up on tertiary operator
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
   return (b ?  (x | (0x01 << k))  :  (x & ~(0x01 << k)) );
              //   Set bit to 1           Set bit to 0
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; //inputs
    //DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00; //output portc

    unsigned char C = 0x00; // to set portC
    /* Insert your solution below */
    while (1) {
        unsigned char A = PINA & 0xFF;

        /* opting for switch/case statement method from lab partner */
        if ((A == 0x01) || (A == 0x02)){ //if A = 1 or 2 turn on PC5 / also below 4 so PC6
            //C = 0x60; // 01100000
            C = SetBit(C, 6, 1);
            C = SetBit(C, 5, 1);

            //setbit does not seem that much more efficient

        }

        if ((A == 0x03) || (A == 0x04)){ //if A = 3 or 4 turn on PC45 / also below 4 so PC6
            C = 0x70; // 01110000
        }

        //low fuel sets P6
        //*/


        PORTC = C;
        C = 0x00;


    	
    }
    return 1;
}
