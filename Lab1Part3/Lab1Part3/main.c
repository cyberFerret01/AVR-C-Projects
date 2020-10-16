/*
 * Lab1Part3.c
 *
 * Created: 16/10/2020 01:11:26
 * Author : bear
 */ 

#include<avr/io.h>
#include<avr/interrupt.h>
#include<stdlib.h>

#define F_CPU 16000000UL
#include"util/delay.h"
const int inital = (9 + 18) * 100;


int main(void)
{
	
	TCCR0A = 0;
	TCCR0B = 0x05;

	//
	DDRB=0xFF;
	DDRB &= ~(1 << 5);
	OCR1A = 0xA4CA;
	
	
		EIMSK = (1 << INT0);
		sei();
		
		while(1){}
		

}

ISR(INT0_vect){
	
	srand(TCNT0);


	switch(rand()%6)
	{
		case 0:
		PORTB = 0b1;
		break;
		
		case 1:
		PORTB = 0b10;
		break;
		
		case 2:
		PORTB = 0b11;
		break;
		
		case 3:
		PORTB = 0b1010;
		break;
		
		case 4:
		PORTB = 0b1011;
		break;
		
		case 5:
		PORTB = 0b1110;
		break;
		
		
		
		default:
			PORTB = 0b1111;
	}
			TCCR1A = 0;
			TCCR1B =0b01101;
					
			while ((TIFR1&(1<<OCF1A) )==0){
						
			}
			TCCR1B =0;
			TIFR1 = 1<<OCF1A;

	
	
	PORTB=0b00;
}




