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


; This project computes average value of 16b numbers in array

; Include derivative-specific definitions
            INCLUDE 'derivative.inc'
            
;
; export symbols
;
            XDEF _Startup
            ABSENTRY _Startup

;
; variable/data section
;
            ORG    RAMStart         ; Insert your data definition here
array:		DS.W   10	;maximum 10 elements
length:		DS.B   1	;number of elements in array
average:	DS.W   1	;result

;
; code section
;
            ORG    ROMStart
            

_Startup:
            LDHX   #RAMEnd+1        ; initialize the stack pointer
            TXS
            CLI						; enable interrupts

			LDHX  #array
			LDA	  length
			JSR   ComputeAverage
			STHX  average			
mainLoop:
            NOP
            feed_watchdog
            BRA    mainLoop
            
; H:X -> array address
; A -> length
; computed average -> H:X
ComputeAverage:
			PSHA	;A to stack
			CLRA	;clear A
			PSHA	;index in array
			PSHA	
			PSHA	;new 16b variable for sum, 0
averageLoop:
			LDA ,X		;load upper 8b
			PSHA		;save on stack
			INCX		;move to lower 8b
			LDA ,X		;load them
			ADD 3,SP	;add temporary sum low byte
			STA 3,SP	;and store in sum L
			
			PULA		;load upper 8b from stack
			ADC 1,SP	;add temporary sum and carry
			STA 1,SP	;and store in sum H
			
			INCX		;next element
			LDA 3,SP	;load index
			INCA		;increment index
			STA 3,SP	;save back
			
			CMPA 4,SP	;compare with array length
			BNE averageLoop	;repeat
			
			;;;;;; divide sum by num of elements
			CLRH	  ;H=0
			LDA  1,SP ;upper byte to A
			LDX  4,SP ;divider to X
			DIV		  ;divide, result in A, remainder in H
			PSHA	  ;save upper byte of result on stack
			
			LDA  3,SP ;lower byte to A
			DIV		  ;divide, result in A, remainder in H
			
			LDHX 1,SP ;move upper byte of result to H
			TAX		  ;move lower byte of result to X
		
			AIS #5	  ;remove used data from stack
			RTS		  ;return
			
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
