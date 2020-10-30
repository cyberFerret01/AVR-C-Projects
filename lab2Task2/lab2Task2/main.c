/*
 * lab2Task1.c
 *
 * Created: 26/10/2020 17:24:59
 * Author : Robert Nicoll rn37
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	
	int PWM = 0;
	int PWMPot = 0;
	int PWMPotMeasured = 0;
	
	DDRB = 0b11;
	PORTB = 0b01; 
 //DDRD|=(1<<2)|(1<<3);
 PORTD=0x08;//OCR0A PWM, set PortD.6 output
 DDRD|=(1<<6);//set OCR0A PWM, fast PWM, no prescaler, non-inverted
 
 TCCR0A=0x83;

	DDRB |= ( 1<<5) ; //Make pin 4 of port D as a output

	DDRC = 0x00; // Make pin 5 of port C as a input

	while (1) //initialize while loop

	{
		
		//read pot and set it to PWMPotMeasured
		
		if (PWMPot != PWMPotMeasured)
		{
			PWM = PWMPotMeasured;
			PWMPot = PWMPotMeasured;
		}
		
		
		for (int i = 1; i <6; i++)
		{
			
			if(PINC & (1<<i) ) //if PIN5 of port C is high

			{
				_delay_ms(10);
			}
			if(PINC & (1<<i) ) //if PIN5 of port C is high

			{

				switch(i){
					case 1:
						PORTB ^= 0b11;
										
					break;
					case 2:
					//87.5
					//223 - df
					PWM=0xdf;
															
					break;
					case 3:
					//0
					//0
					PWM=0x00;
					PORTB |= (1<<5);
					break;
					
					case 4:
					//25
					//63 -3f
					PWM=0x3f;
					break;
					
					case 5:
					//62.5
					//159 - 9f
					PWM=0x9f;
					break;
				}
				

			}
			
			
			
			OCR0A = PWM;
			TCCR0B=0b101;
			
			
		}
	}
 }

