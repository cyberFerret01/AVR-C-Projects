/*
 * buttons.c
 *
 * Created: 27/10/2020 00:05:14
 * Author : bear
 */ 

#include <avr/io.h>

#define F_CPU 16000000UL
#include"util/delay.h"

int main(void)
{
	DDRB = 0x20;
	PORTD = 0xFF;
    /* Replace with your application code */
    while (1) 
    {
		_delay_ms(1000);
	//	if (PIND == 0b100)
		//{
			PORTB &= ~(1 << 5);
			_delay_ms(1000);
		//}else{
		
		PORTB |= (1 << 5);
		

	//	}
		}
		}

