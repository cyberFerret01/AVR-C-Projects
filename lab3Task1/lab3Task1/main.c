#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU/(BAUDRATE*16UL)))-1)

void USART_init(void){
	UBRR0H=(uint8_t)(BAUD_PRESCALLER>>8); //set baud rate
	UBRR0L=(uint8_t)(BAUD_PRESCALLER);
	UCSR0B=(1<<RXEN0)|(1<<TXEN0);//enable transmit
	UCSR0C=(3<<UCSZ00);//set 8-bit (default)
}
void USART_send(unsigned char data){
	while(!(UCSR0A&(1<<UDRE0)));  // check if data is sent
	UDR0= data;
	}

	unsigned char USART_receive(void){
		while(!(UCSR0A&(1<<RXC0)));  // Wait to receive data
		return UDR0;// Read data from UDR
	}

void USART_putstring(char* fullstring){
	//keep sending until the next char has value 0 (it's null)
	while (*fullstring != 0x00)
	{
		USART_send(*fullstring ++);
	}
}

int main(){
	//initialize received char as 9 as it isn't a valid result
	char ReceivedChar = '9';
	DDRB = 0x20; //initialize pin 13 as an output for lamp
	USART_init(); //start USART 
	while(1){
		ReceivedChar=USART_receive();// Wait until data is received
		if(ReceivedChar=='0'){
			PORTB &= ~(1 << 5);// turn off lamp 13
			_delay_ms(200);
			USART_putstring("LED is off!\n");
		}
		if(ReceivedChar=='1'){
			PORTB |= (1 << 5);// turn on lamp 13
			_delay_ms(200);
			USART_putstring("LED is on!\n");
		}
	}
	

	}
