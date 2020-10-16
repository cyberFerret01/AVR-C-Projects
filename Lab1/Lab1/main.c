/*
 * Lab1.c
 *
 * Created: 03/10/2020 13:40:01
 * Author : Robert Nicoll (rn37)
 */ 

#include<avr/io.h>
#include<avr/interrupt.h>


#define F_CPU 16000000UL
#include"util/delay.h"
const int inital = (9 + 18) * 100;






//37.03 x10^-3
//0.0370 x10^-6

int main(void)
{


	DDRB=0xFF;
	DDRB &= ~(1 << 5);
	OCR1A = 0xA4CA;
	
		EIMSK = (1 << INT0);
		sei();
		while(1){}
}

ISR(INT0_vect){

	for(int i = 0; i < 3; i++){
			
		PORTB |= (1 << i);

			TCCR1A = 0;
			TCCR1B =0b01101;
					
			while ((TIFR1&(1<<OCF1A) )==0){
						
			}
			TCCR1B =0;
			TIFR1 = 1<<OCF1A;

	}
	
	PORTB=0b00;

}


