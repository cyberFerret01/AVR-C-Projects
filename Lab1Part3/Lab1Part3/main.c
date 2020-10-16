/*
 * Lab1Part3.c
 *
 * Created: 16/10/2020 01:11:26
 * Author : bear
 */ 

#include<avr/io.h>
#include<avr/interrupt.h>
#include<stdlib.h>
#include<time.h>

#define F_CPU 16000000UL
#include"util/delay.h"
const int inital = (9 + 18) * 100;

unsigned long seed = 0;





//37.03 x10^-3
//0.0370 x10^-6

int main(void)
{

	//
	DDRB=0xFF;
	DDRB &= ~(1 << 5);
	OCR1A = 0x7A12;
	
	
		EIMSK = (1 << INT0);
		sei();
		
		while(1){}
		
/*
		_delay_ms(inital);
		PORTB=0b00;
		_delay_ms(inital);
		*/
		

}

ISR(INT0_vect){
	
	srand(89);
	
	int p = rand()%7;
	p++;

	
	for(int i = 0; i < 3; i++){
			
		PORTB |= (1 << i);
			
			OCR1A = p;
			TCCR1A = 0;
			TCCR1B =0b01101;
					
			while ((TIFR1&(1<<OCF1A) )==0){
						
			}
			TCCR1B =0;
			TIFR1 = 1<<OCF1A;

	}
	
	PORTB=0b00;
	
	
	seed++;
}




