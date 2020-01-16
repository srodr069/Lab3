/*	Author: Steven Rodriguez
 *  Partner(s) Name: Anthony Pham
 *	Lab Section: 21
 *	Assignment: Lab #3  Exercise #1
 *	Exercise Description: Count the number of 1s on ports A and B and output that number on port C.
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; //inputs
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00; //output portc

    unsigned char cnt = 0x00; //1 count
    /* Insert your solution below */
    while (1) {
    	cnt = (PINA & 0x01) + ((PINA >> 1) & 0x01) + ((PINA >> 2) & 0x01) + ((PINA >> 3) & 0x01) + ((PINA >> 4) & 0x01) + ((PINA >> 5) & 0x01) + ((PINA >> 6) & 0x01) + ((PINA >> 7) & 0x01) + ((PINA >> 8) & 0x01);
        //and 0x01 focuses on lsb , shift 8 times to check total count
    	cnt = cnt + (PINB & 0x01) + ((PINB >> 1) & 0x01) + ((PINB >> 2) & 0x01) + ((PINB >> 3) & 0x01) + ((PINB >> 4) & 0x01) + ((PINB >> 5) & 0x01) + ((PINB >> 6) & 0x01) + ((PINB >> 7) & 0x01) + ((PINB >> 8) & 0x01);
        // same process for portb just adding to itself
    	PORTC = cnt; // set portc to cnt
    	cnt = 0x00;
    }
    return 1;
}
