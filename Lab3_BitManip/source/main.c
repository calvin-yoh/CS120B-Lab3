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
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char tempA = 0x00;
	unsigned char tempC = 0x00;
	unsigned char checkSeatbeltSign = 0x00;
	unsigned char tempEnd = 0x00;


	while (1) {

		tempA = PINA;

		if (tempA == 0x00)
		{
			tempC = 0x40;
		}
		else if (tempA == 0x01 || tempA == 0x02)
		{
			tempC = 0x60;
		}
		else if (tempA == 0x03 || tempA == 0x04)
		{
			tempC = 0x70;
		}
		else if (tempA == 0x05 || tempA == 0x06)
		{
			tempC = 0x38;
		}
		else if (tempA == 0x07 || tempA == 0x08 || tempA == 0x09)
		{
			tempC = 0x3C;
		}
		else if (tempA == 0x0A || tempA == 0x0B || tempA == 0x0C)
		{
			tempC = 0x3E;
		}
		else
		{
			tempC = 0x3F;
		}

		if ((tempA & 0x30) == 0x30)
		{
			checkSeatbeltSign = 0x80;
		}
		else
		{
			checkSeatbeltSign = 0x00;
		}

		tempEnd = checkSeatbeltSign | tempC;

		PORTC = tempEnd;
		tempEnd = 0x00;
		tempC = 0x00;
		checkSeatbeltSign = 0x00;
	}
	return 0;
}