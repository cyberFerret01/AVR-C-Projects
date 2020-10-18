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
const int inital = 14 +18 (9 + 18) * 100;






//37.03 x10^-3
//0.0370 x10^-6

int main(void)
{


	DDRB=0xFF;
	DDRB &= ~(1 << 5); //initialize IO pins
	OCR1A = 0xC350;	//initialize delay value 
	
		EIMSK = (1 << INT0); //setup interrupt 0 listening on pin 2 of arduino 
		sei();
		while(1){} //do nothing while waiting on interrupt
}

ISR(INT0_vect){
	
	//loop 3 times (for the 3 lamps)
	for(int i = 0; i < 3; i++){
		
		//set bit high bit high bit moves left every time for loop iterates 	
		PORTB |= (1 << i);

			//setup timer1 in CTC 1/1024 mode
			TCCR1A = 0;
			TCCR1B =0b01101;
					
			//Do nothing till delay threshold is met		
			while ((TIFR1&(1<<OCF1A) )==0){
						
			}
			//stop timer1
			TCCR1B =0;
			TIFR1 = 1<<OCF1A;

	}
	//turn off lamps
	PORTB=0b00;

}


