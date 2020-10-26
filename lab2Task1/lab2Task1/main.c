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
	
	DDRB = 0x20;
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
 DDRD|=(1<<2)|(1<<3);
 PORTD=0x08;//OCR0A PWM, set PortD.6 output
 DDRD|=(1<<6);//set OCR0A PWM, fast PWM, no prescaler, non-inverted
 TCCR0B=0b101;
 TCCR0A=0x83;
 OCR0A=0xff;
 while(1);
 return 0;
}

