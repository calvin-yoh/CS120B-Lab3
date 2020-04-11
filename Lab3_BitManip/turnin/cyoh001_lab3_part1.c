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
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char tempA = 0x00;
	unsigned char tempB = 0x00;
	unsigned char tempCount = 0x00;
	unsigned char i = 0x01;

	while (1) {

		tempA = PINA;
		tempB = PINB;

		while (i < 0x80)
		{
			if ((tempA & i) == i)
			{
				tempCount = tempCount + 0x01;
			}
			if ((tempB & i) == i)
			{
				tempCount = tempCount + 0x01;
			}
			i = i + i;
		}
		if ((tempA & i) == i)
		{
			tempCount = tempCount + 0x01;
		}
		if ((tempB & i) == i)
		{
			tempCount = tempCount + 0x01;
		}

		PORTC = tempCount;
		tempCount = 0x00;
		i = 0x01;
	}
	return 0;
}