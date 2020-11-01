/*
 * lab2Task3.c
 *
 * Created: 26/10/2020 17:24:59
 * Author : Robert Nicoll rn37
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void){
	DDRB = 0b10;
	TCCR1A =0x82;
	TCCR1B =0x1A;
	ICR1=40000;
	while(1){
		
		
	
		_delay_ms(1000);
				OCR1A=1100; // -90 //offset from 999 as motor buzzed at 999
		_delay_ms(1000);
				OCR1A=2000; // -45
		_delay_ms(1000);
				OCR1A=3000; // 0
		_delay_ms(1000);
				OCR1A=4000; // 45
		_delay_ms(1000);
				OCR1A=5000; //90
		_delay_ms(1000);
			OCR1A=4000; // 45
		_delay_ms(1000);
			OCR1A=3000; // 0
		_delay_ms(1000);
			OCR1A=2000; // -45
				//loop back
		
/*
		
		_delay_ms(1000);
		OCR1A=1639;
		_delay_ms(1000);
		OCR1A=4914;
		_delay_ms(1000);
		
		_delay_ms(1000);
		OCR1A=8191;
	
		*/
		
		
	//	return 0;
	}
		}
