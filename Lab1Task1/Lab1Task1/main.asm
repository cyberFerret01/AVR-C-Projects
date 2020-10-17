;
; Lab1Task1.asm
;
; Created: 16/10/2020 19:46:44
; Author : bear
;
;	ATMEGA328P Clock speed: 16MHZ
;	Delay: 2700x10^-3 = 2.7
;
;	16x10^6x(1/1024) = 15625
;	1/15625 = 6.4x10^-5
;	2.7/6.4x10^-5 = 42187.5
;	
;	0xA4CA OR 0b1010010011001010
;
		 LDI R23, 0b10100100 ; load R23 with calculated delay value
		 LDI R24, 0b11001010
		 LDI R16, 0b00000111
		 OUT DDRB, R16 ;PB3 as an output  

		 LDI R16,0;111 ;R16 = 0x08 
		 LDI R17,0b1
    
		 OUT PORTB,R16
		 		     
		 STS OCR1AH,R23      
		 STS OCR1AL,R24
BEGIN:	 LDI R20,0x00  
		 STS TCCR1A,R20       
		 LDI R20, 0b01101  
		 STS TCCR1B,R20     
AGAIN:   SBIS     TIFR1,OCF1A
		 RJMP AGAIN  
		 LDI R20,0x00 
		 STS TCCR1B,R20  
		 LDI R20,1<<OCF1A 
		 OUT TIFR1,R20   

		 OR R16,R17
		 LSL R17
		 OUT PORTB,R16  
	
		 RJMP  BEGIN