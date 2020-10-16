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
		 LDI R16, 0b0000111
		 OUT DDRB, R16 ;PB3 as an output  

		 LDI R16,0b0000111 ;R16 = 0x08  

		 LDI R17,0    
		 OUT PORTB,R17
		 		     
		 STS OCR1AH,R23      
		 STS OCR1AL,R24
BEGIN:	 LDI R20,0x00 ;TCCR0A=0x02  
		 STS TCCR1A,R20       ;CTC mode 
		 LDI R20, 0b01101  ;TCCR0B = 1  
		 STS TCCR1B,R20       ;int. clk
AGAIN:   SBIS     TIFR1,OCF1A;if OCF0 is set skip next
		 RJMP AGAIN  
		 LDI R20,0x00 
		 STS TCCR1B,R20 ;stop Timer0 
		 LDI R20,1<<OCF0A 
		 OUT TIFR1,R20 ;clear OCF0A flag   
		 EOR R17,R16  ;toggle D3 of R17  
		 OUT PORTB,R17 ;toggle PB3  
		 RJMP  BEGIN