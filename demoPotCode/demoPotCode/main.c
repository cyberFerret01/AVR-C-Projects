#include<avr/io.h>
void initADC(void){
	ADMUX|=(1<<REFS0);//|(1<<MUX0);//reference voltage on AVCC, and use ADC1
	ADCSRA|=(1<<ADPS1)|(1<<ADPS0);//ADC clock prescaler/ 8
	ADCSRA|=(1<<ADEN);//enables the ADC
	}
	int main(){
		uint16_t potentiometerValue;
		uint16_t threshold_level;
		DDRB|=(1<< 5);//Data Direction Register B: writing a 1 to the bit enables output
		threshold_level=0b11100000;
		initADC();
		while(1){ADCSRA|=(1<<ADSC);//start ADC conversion
			while((ADCSRA&(1<<ADSC)))//wait until ADSC bit is clear, i.e., ADC conversion is done
			{} //read ADC value in
				uint8_t theLowADC=ADCL;
				potentiometerValue=ADCH << 8|theLowADC;
				// potentiometerValue= ADC;
				if(potentiometerValue>threshold_level){
					PORTB|=(1<< 5);;//turn on LED attached to port PB2
					 }else{PORTB&=~(1<< 5);;//turn off LED attached to port PB2 
						 }}}