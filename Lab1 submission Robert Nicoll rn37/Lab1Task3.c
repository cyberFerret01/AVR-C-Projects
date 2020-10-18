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
	TCCR0B = 0x05; //initialize timer for use as a counter for random seed

	//
	DDRB=0xFF;
	DDRB &= ~(1 << 5); //setup IO pins
	OCR1A = 0xA4CA; //Set timer1's delay value
	
	
	EIMSK = (1 << INT0); //setup interrupt 0 and start listening for interrupt on pin 2
	sei();
	
	while(1){} //main loop (do nothing)
		

}

ISR(INT0_vect){
	
	srand(TCNT0); //seed random generator with counter 0's value
	
	TCCR0A = 0; //stop counter 0 
	TCCR0B = 0;

//--- generate random number and take its modulo to make it in the dice range then light the lamps according to the random value
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
		
			//start timer 1 to hold value on the lamp display
	
			TCCR1A = 0;
			TCCR1B =0b01101;
					
			while ((TIFR1&(1<<OCF1A) )==0){
						
			}
			
			//stop timer 1 once the delay length has been reached
			TCCR1B =0;
			TIFR1 = 1<<OCF1A;

	
	//turn off lamp display 
	PORTB=0b00;
	
	TCCR0A = 0;
	TCCR0B = 0x05; //restart counter 0
}




