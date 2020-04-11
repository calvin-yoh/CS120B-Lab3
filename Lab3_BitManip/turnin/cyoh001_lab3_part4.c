/*	Author: cyoh001
 *  Partner(s) Name:
 *	Lab Section 22
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#include <stdlib.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif	

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char upper = 0x00;
	unsigned char lower = 0x00;
	unsigned char upperShifted = 0x00;
	unsigned char lowerShifted = 0x00;
	unsigned char tempB = 0x00;
	unsigned char tempC = 0x00;

	while (1) {

		upper = PINA & 0xF0;
		lower = PINA & 0x0F;

		upperShifted = upper >> 4;
		lowerShifted = lower << 4;
		tempB = upperShifted;
		tempC = lowerShifted;

		PORTB = tempB;
		PORTC = tempC;
		upper = 0x00;
		lower = 0x00;
		upperShifted = 0x00;
		lowerShifted = 0x00;
		tempB = 0x00;
		tempC = 0x00;
	}
	return 0;
}