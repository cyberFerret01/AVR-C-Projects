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

//send to serial port
void USART_send(unsigned char data){
	while(!(UCSR0A&(1<<UDRE0)));  // check if data is sent
	UDR0= data;
}

//send char array to serial port
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

//receive from serial port
unsigned char USART_receive(void){
	while(!(UCSR0A&(1<<RXC0)));  // Wait to receive data
	return UDR0;// Read data from UDR
}


//receive from serial port	
int  USART_getstring(unsigned char *phrase){
	
	// initialize function by getting first char from serial port and setting the length counter to 0
	char c = USART_receive();
	int j =0;
	
	//get next char until we get \n (denotes end of incomming string)
	while(c != '\n'){
		//store char in memory location
		phrase[j] = c;
		j++;
		c = USART_receive();
	}
	phrase[j] = 0;
	// return the length of the string
	return j+1;
}



int main(void){
	
	int i = 0;
	DDRD=0xFF;
	DDRB=0xFF;
	unsigned char string [40] = "ooo";
	//start lcd library and initialize the lcd as blank and start serial communication
	Lcd4_Init();
	Lcd4_Clear();
	USART_init();
	while(1){
				//check to see if the RXC flag is risen if it is there is incoming text on the serial port
				if ((UCSR0A&(1<<RXC0))){
					//clear for new message
					Lcd4_Clear();
					//get the length of the incoming string and modify the string memory location setting it to the new string
					i = USART_getstring(string);
					//parrot incoming string (used for debugging)
					USART_putstring(string);
					//wait a second then write the new string onto the lcd
					_delay_ms(1000);
					for(int j = 0 ; j < i-1; j ++){
						Lcd4_Write_Char(string[j]);
						//
					}

				}
	}
	}