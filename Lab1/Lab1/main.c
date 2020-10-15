/*
 * Lab1.c
 *
 * Created: 03/10/2020 13:40:01
 * Author : bear
 */ 

#include<avr/io.h>
#define F_CPU 16000000UL
#include"util/delay.h"
const int inital = (9 + 18) * 100;
//37.03 x10^-3
//0.0370 x10^-6

int main(void)
{

	//
	DDRB=0xFF;
	DDRB &= ~(1 << 5);
	
	while(1){
		
	OCR1A = 0x7A12;
	//OCR1AL = 0xCB;
	TCCR1A = 0;	//0b10;
	TCCR1B =0b01101; //0x05;	//0b0101;
	
	while ((TIFR1&(1<<OCF1A) )==0){
		
	}
		TCCR1B =0;
		TIFR1 = 1<<OCF1A;
		TIFR1 = 1<<TOV1;
		/*
		_delay_ms(inital);
				PORTB=0b00;
		for(int i = 0; i < 3; i++){
			_delay_ms(inital);
			PORTB |= (1 << i);
			
			*/
		PORTB ^= 1<<3;
		}
		

		
		
/*
		_delay_ms(inital);
		PORTB=0b00;
		_delay_ms(inital);
		*/
		
}

