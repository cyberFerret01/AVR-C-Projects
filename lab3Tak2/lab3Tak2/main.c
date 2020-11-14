/*
 * lab3Tak2.c
 *
 * Created: 13/11/2020 17:45:49
 * Author : bear
 */ 

#define D0 eS_PORTD0
#define D1 eS_PORTD1
#define D2 eS_PORTD2
#define D3 eS_PORTD3
#define D4 eS_PORTD4
#define D5 eS_PORTD5
#define D6 eS_PORTD6
#define D7 eS_PORTD7
#define RS eS_PORTB0
#define EN eS_PORTB1
#define F_CPU 16000000UL

#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU/(BAUDRATE*16UL)))-1)

#include <avr/io.h>
#include "lcd.h"
#include <util/delay.h>
#include <string.h>

void USART_send(unsigned char data){
	while(!(UCSR0A&(1<<UDRE0)));  // check if data is sent
	UDR0= data;
}


void USART_putstring(unsigned char* fullstring){
	
	while (*fullstring != 0x00)
	{
		USART_send(*fullstring ++);
	}
}

void USART_init(void){
	UBRR0H=(uint8_t)(BAUD_PRESCALLER>>8); //set baud rate
	UBRR0L=(uint8_t)(BAUD_PRESCALLER);
	UCSR0B=(1<<RXEN0)|(1<<TXEN0);//enable transmit
	UCSR0C=(3<<UCSZ00);//set 8-bit (default)
}

unsigned char USART_receive(void){
	while(!(UCSR0A&(1<<RXC0)));  // Wait to receive data
	return UDR0;// Read data from UDR
}


	
int  USART_getstring(unsigned char *phrase){
	
	char c = USART_receive();
	int j =0;
	
	while(c != '\n'){
		phrase[j] = c;
		j++;
		c = USART_receive();
	}
	phrase[j] = 0;

	return j+1;
}



int main(void){
	USART_init();

	int i = 3;
	DDRD=0xFF;
	DDRB=0xFF;
	unsigned char string [40] = "owo";
	string[0] = 'o';
	Lcd4_Init();
	Lcd4_Clear();
	while(1){
		
		
		
		
		
				if ((UCSR0A&(1<<RXC0))){
					
					
					i = USART_getstring(string);
					USART_putstring(string);
					_delay_ms(1000);
					for(int j = 0 ; j < i-1; j ++){
						Lcd4_Write_Char(string[j]);
						//
					}
					_delay_ms(40000);
					Lcd4_Clear();
					
				}
		
		
		
		
		
		
		
		
//		USART_putstring("ttoo");
	//		if (RXC0 == 1){
		//i = USART_getstring(string);
	//}
		
		//or (int j = 0 ; j <i ;j++)
		//{
			
		//}
		//delay_ms(6000);
		//Lcd8_Clear();
		//Lcd8_Set_Cursor(1,i);
			

		
		//_delay_ms(1000);
	
		/*
		for(i=0;i<strlen(string)-1;i++){
			_delay_ms(500);
			Lcd8_Shift_Left();
			}
			for(i=0;i<strlen(string)-1;i++){
				_delay_ms(500);
				Lcd8_Shift_Right();
				}
				Lcd8_Clear();
				// Lcd8_Write_Char('e');
				// Lcd8_Write_Char('S');
				_delay_ms(100);
				USART_getstring(string); */
				}
				}
/*				


int main(){
	
	unsigned char ReceivedChar [40];
	DDRB = 0x20;
	USART_init(); // USART initialization
	while(1){
		USART_getstring(ReceivedChar);// Wait until data is received
		if(ReceivedChar[1] == '0'){
			PORTB &= ~(1 << 5);// Clear bit 4 to turn off LED
			_delay_ms(200);
			USART_putstring("LED is off!\n");
		}
		if(ReceivedChar[0] == '1'){
			PORTB |= (1 << 5);// set bit 4 to turn on LED
			_delay_ms(200);
			USART_putstring("LED is on!\n");
		}
	}
	
	*/