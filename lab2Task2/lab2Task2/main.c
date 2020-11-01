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
	
	ADMUX|=(1<<REFS0); //set reference voltage
	ADCSRA|=(1<<ADPS1)|(1<<ADPS0);//ADC clock prescaler/ 8
	ADCSRA|=(1<<ADEN);//enables the ADC
	
	int PWM = 0;
	int PWMPot = 0;
	int PWMPotMeasured = 0;
	
	 DDRB = 0b11;
	 DDRC = 0x00;
	 PORTB = 0b01; 
	 PORTD=0x08;
	 DDRD|=(1<<6);
 
	 TCCR0A=0x83;

	

	while (1) //initialize while loop

	{
		
		ADCSRA|=(1<<ADSC);//start ADC conversion
		while((ADCSRA&(1<<ADSC))){} // wait till the ADC is done
		uint8_t theLowADC=ADCL; //read lower bits
		PWMPotMeasured=ADCH << 8|theLowADC; //read upper bits
		
		//read pot and set it to PWMPotMeasured
		
		_delay_ms(10);
		if (PWMPot != PWMPotMeasured)
		{
			_delay_ms(10); //software debounce
					if (PWMPot > PWMPotMeasured+10 || PWMPot < PWMPotMeasured-10) //check to see if the pot has changed by a small amount
					{
					PWM = (PWMPotMeasured%1024)/4; //set pwm in range of 0 - 256
					PWMPot = PWMPotMeasured; //set new base value to compare aginst
					}
		}
		
		//poll switches
		for (int i = 1; i <6; i++)
		{
			//check if a button is pressed then use software debounce
			if(PINC & (1<<i) ) 

			{
				_delay_ms(10);
			}
			if(PINC & (1<<i) ) 
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

