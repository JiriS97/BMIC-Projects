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

; This project searches an array for min and max values using a subroutine

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
arrLen:		DC.B   10
array:		DC.B   5,1,7,20,0,50,7,12,15,25
index: 		DS.B   1
MIN: 		DS.B   1
MAX:		DS.B   1

;
; code section
;
            ORG    ROMStart
            

_Startup:
            LDHX   #RAMEnd+1        ; initialize the stack pointer
            TXS
            CLI				; enable interrupts
            
            AIS   #-2		;reserve space for min, max on stack
            LDHX  #array	;load array address
            LDA	  arrLen	;load array length
            JSR	  FindMinMax
            PULA
            STA	  MAX		;store MAX from stack
            PULA
            STA   MIN		;store MIN from stack
            
mainLoop:
           	feed_watchdog
			NOP				;loop
			BRA   mainLoop
			
;H:X -> array address
;A -> num elements
;MAX, MIN -> stack (x,x+1)
FindMinMax:
			PSHA			;store num elements on stack
			
			CLRA
			PSHA  			;clear index, index is on stack
            
            LDA	  ,X		;load default values for MIN, MAX
            STA   6,SP
            STA   5,SP
    MyLoop:
			LDA   ,X		;load array element to accumulator
            CMP   6,SP		;compare with MIN
            BHS	  TestMax	;branch if higher or same
            STA	  6,SP
	TestMax:
			CMP   5,SP		;compare with MAX
			BLS   LoopEnd	;branch if lower or same
			STA   5,SP
	LoopEnd:
			INCX			;increment X
			LDA   1,SP		;increment index
			INCA
			STA   1,SP
			CMP	  2,SP		;compare index with array length
			BNE   MyLoop
			
			AIS   #2		;delete index and number of elements from stack
		    RTS				;return
			
			
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
