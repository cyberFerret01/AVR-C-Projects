/*
 * buttons.c
 *
 * Created: 27/10/2020 00:05:14
 * Author : bear
 */ 

#include <avr/io.h>

#define F_CPU 16000000UL
#include"util/delay.h"
/*
int main(void)
{
	DDRB = 0x20;
	DDRB &= ~(1<<0);
	//PORTB = 0xFF;

    while (1) 
    {
		_delay_ms(1000);
		if (PINB & (1<<0))
		{
			PORTB ^= (1 << 5);
			_delay_ms(1000);

		}
		}
}
*/
	
int main(void) //main starts

{

	DDRB |= ( 1<<5) ; //Make pin 4 of port D as a output

	DDRC = 0x00; // Make pin 5 of port C as a input

	while (1) //initialize while loop

	{
		
		for (int i = 2; i <6; i++)
		{
			
					if(PINC & (1<<i) ) //if PIN5 of port C is high

					{
						_delay_ms(10);
					}
					if(PINC & (1<<i) ) //if PIN5 of port C is high

					{

						PORTB ^= ( 1<<5); //PIN4 of port D is high

					}
			
		}
		




		

	} // while loop ends

} //main end