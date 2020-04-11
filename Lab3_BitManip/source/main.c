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
	DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0xFE; PORTB = 0x01;

	unsigned char mostSigD = 0x00;
	unsigned char tempD = 0x00;
	unsigned char tempB = 0x00;
	unsigned short tempWeight = 0x0000;
	unsigned char answer = 0x00;

	while (1) {

		mostSigD = PIND & 0x80;
		tempD = PIND << 1;
		tempB = PINB;

		tempWeight = tempWeight + tempD;
		if (mostSigD == 0x80)
		{
			tempWeight = tempWeight + 0x0100;
		}
		if (tempB == 0x01)
		{
			tempWeight = tempWeight + 1;
		}

		if (tempWeight >= 0x0046)
		{
			answer = 0x02;
		}
		else if (tempWeight > 0x0005)
		{
			answer = 0x04;
		}

		PORTB = answer;
		mostSigD = 0x00;
		tempD = 0x00;
		tempB = 0x00;
		tempWeight = 0x0000;
		answer = 0x00;
	}
	return 0;
}
