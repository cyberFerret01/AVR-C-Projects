;
; Lab1Task1.asm
;
; Created: 16/10/2020 19:46:44
; Author : bear
;


; Replace with your application code

;; toggleProject.asm;
	LDI R16,0x01
	OUT DDRB,R16
	LDI R16,0x01
L1:	OUT PORTB,R16
	LDI R20,0
	OUT PORTB,R20
	RJMP L1
