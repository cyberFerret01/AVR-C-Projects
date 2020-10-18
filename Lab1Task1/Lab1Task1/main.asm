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
		 LDI R23, 0b11000011 ;load R23 with upper 8 bits of calculated delay value
		 STS OCR1AH,R23      ;load r23 into OCR1AH (HIGH must be written below OCR1AL)
		 LDI R23, 0b01010000 ;load R32 with the lower 8 bits of calculated delay values
		 STS OCR1AL,R23

		 LDI R16, 0b00000111
		 OUT DDRB, R16 ;PB0,PB1 and PB3 as outputs

		 LDI R16,0
		 LDI R17,0b1
    
		 OUT PORTB,R16 ;initialize all lamps as off
		 		     

BEGIN:	 LDI R20,0x00  
		 STS TCCR1A,R20       
		 LDI R20, 0b01101  
		 STS TCCR1B,R20   ;start ctc timer in 1/1024 mode  
AGAIN:   SBIS     TIFR1,OCF1A	;wait till timer reaches threshold
		 RJMP AGAIN  
		 LDI R20,0x00 
		 STS TCCR1B,R20  ;Stop the timer
		 LDI R20,1<<OCF1A 
		 OUT TIFR1,R20   

		 OR R16,R17	;do a or operation on R17 and R16 and save into R16 (so for the 1st look R16 goes from 0 to 0b00000001)
		 LSL R17	;shift r17 to the lest one to allow the lamps to increment
		 OUT PORTB,R16  ;set the high bits in R16 to the PORTB to light the lamps
		 RJMP  BEGIN