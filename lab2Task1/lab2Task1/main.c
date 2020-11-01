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
	
	DDRB = 0x20; //pin 13 debug
	//5 high
	
    /* Replace with your application code */
 /*   while (1) 
    {
		PORTB |= (1<<5);
		_delay_ms(1000);
		PORTB &= ~(1<<5);
		_delay_ms(1000);
    }
	*/

 PORTD=0x08;//OCR0A PWM, set PortD.6 output
 DDRD|=(1<<6);//set OCR0A PWM, fast PWM, no prescaler, non-inverted
 
	TCCR0A=0x83;
	DDRC = 0x00; 

	while (1) //initialize while loop

	{
		//poll all the switches o check to see if any have been pressed
		for (int i = 2; i <6; i++)
		{
			
			if(PINC & (1<<i) ) //if PIN5 of port C is high

			{
				_delay_ms(10); //debounce
			}
			if(PINC & (1<<i))

			{

				switch(i){
					case 3:
					//0
					//0
					OCR0A=0x00;
					PORTB |= (1<<5);
					break;
					
					case 4:
					//25
					//63 -3f
					OCR0A=0x3f;
					break;
					
					case 5:
					//62.5
					//159 - 9f
					OCR0A=0x9f;
					break;
					
					case 2:
					//87.5
					//223 - df
					OCR0A=0xdf;
					
					break;
				}
				TCCR0B=0b101;

			}
			
		}
		


 


	/* 
	 if(PINB != buttonState){
		 _delay_ms(10);
		 if (PINB != buttonState)
		 {
		 
			 buttonState = PINB;
			 TCCR0B=0x00;
			 _delay_ms(1000);
		 
			 switch(PINB){
				 case 0b10:
				 //0
				 //0
				 OCR0A=0x00;
				 PORTB |= (1<<5);
					 break;
				 
				 case 0b100:
				 //25
				 //63 -3f
				 OCR0A=0x3f;
					 break;
				 
				 case 0b1000:
				 //62.5
				 //159 - 9f
				 OCR0A=0x9f;
					 break;
				 
				 case 0b10000:
				 //87.5
				 //223 - df
				 OCR0A=0xdf;
				 
					 break;
			 }
		 TCCR0B=0b101;
		 }
	 }
	 */
 }
 }
 
 
	/* 
	TCCR0B=0b101;
	OCR0A=0x10;
	_delay_ms(10000);
	TCCR0B = 0x00;
	_delay_ms(1000);
	TCCR0B=0b101;
	OCR0A=0xBF;
	_delay_ms(10000);
	 };
 return 0;
 */


