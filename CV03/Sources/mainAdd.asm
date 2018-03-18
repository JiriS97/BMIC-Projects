; The MIT License (MIT)
;
; Copyright (c) 2018 Jiri Sramek (https://github.com/JiriS97/)
;
; Permission is hereby granted, free of charge, to any person obtaining a copy
; of this software and associated documentation files (the "Software"), to deal
; in the Software without restriction, including without limitation the rights
; to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
; copies of the Software, and to permit persons to whom the Software is
; furnished to do so, subject to the following conditions:
;
; The above copyright notice and this permission notice shall be included in
; all copies or substantial portions of the Software.
;
; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
; IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
; FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
; AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
; LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
; OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
; THE SOFTWARE.

; This project sums two 32bit numbers and a 32bit constant

; Include derivative-specific definitions
            INCLUDE 'derivative.inc'
            
;
; export symbols
;
            XDEF _Startup
            ABSENTRY _Startup

;
; variable/data section Insert your data definition here
;
			;ORG	   RAMStart
            ORG    Z_RAMStart
Number1:	 	DS.L   1
Number2:	 	DS.L   1
Result: 		DS.L   1

;
; code section
;
            ORG    ROMStart
Constant:	EQU	   $A5		;constant - use IMM mode -> equ or in instruction directly
_Startup:
            LDHX   #RAMEnd+1        ; initialize the stack pointer
            TXS
            CLI						; enable interrupts
mainLoop:
            LDA Number1+3			;LOW Byte
            ADD Number2+3
            STA Result+3
            LDA Number1+2			;Next Byte
            ADC Number2+2
            STA Result+2
            LDA Number1+1			;Next Byte
            ADC Number2+1
            STA Result+1
            LDA Number1				;HIGH Byte
            ADC Number2
            STA Result
           
            ;add constant
            LDA Result+3			;LOW Byte
            ADD #Constant
            STA Result+3
            CLRA					;Next Byte
            ADC Result+2
            STA Result+2
            CLRA					;Next Byte
            ADC Result+1
            STA Result+1
            CLRA					;HIGH Byte
            ADC Result
            STA Result
            
            feed_watchdog
            BRA    mainLoop
			
;**************************************************************
;* spurious - Spurious Interrupt Service Routine.             *
;*             (unwanted interrupt)                           *
;**************************************************************

spurious:				; placed here so that security value
			NOP			; does not change all the time.
			RTI

;**************************************************************
;*                 Interrupt Vectors                          *
;**************************************************************

            ORG	$FFFA

			DC.W  spurious			;
			DC.W  spurious			; SWI
			DC.W  _Startup			; Reset
