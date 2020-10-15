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

int main(void)
{
	DDRB=0xFF;//make port B as output port
	DDRB &= ~(1 << 5);
	//5th
	while(1){
		PORTB=0b111;
		_delay_ms(inital);
		PORTB=0b00;
		_delay_ms(inital);
		}}

