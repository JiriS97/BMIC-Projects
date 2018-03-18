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

; This project multiplies two 16bit numbers, defaults are loaded: 30132*30124=907425252

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
tmp: 		DS.B   1
C1: 		DS.W   1
C2:			DS.W   1
Result:		DS.L   1

;
; code section
;
            ORG    ROMStart
            

_Startup:
            LDHX   #RAMEnd+1        ; initialize the stack pointer
            TXS
            CLI			; enable interrupts
            
            ;clear result and load operands
            CLRA
			STA   Result
			STA   Result+1
			STA   Result+2
			STA   Result+3
			LDA	  #$75
			STA   C1
			LDA	  #$AB
			STA   C1+1
			LDA	  #$75
			STA   C2
			LDA	  #$AC
			STA   C2+1
			;30132*30124=907425252
mainLoop:
            ;multiply C1L and C2L, store it
            LDA	   C1+1
            LDX	   C2+1
            MUL
            STA	   Result+3	;low result, 7:0
            STX	   Result+2	;high result, 15:8
            
            ;multiply C1H and C2L, store it
            LDA	   C1
            LDX	   C2+1
            MUL
            ADD	   Result+2	;low result, 15:8
            STA	   Result+2	;low
            TXA	   				;load X to accumulator
            ADC    #0
            STA	   Result+1	;high result, 23:16
            
            ;multiply C1L and C2H, store it
            LDA	   C1+1
            LDX	   C2
            MUL
            ADD	   Result+2	;low result, 15:8
            STA	   Result+2	;low
            TXA	   				;load X to accumulator
        	ADC	   Result+1
            STA	   Result+1	;high result, 23:16
            CLRA
            ADC    #0
            STA    Result		;carry to bits 31:24
            
            ;multiply C1H and C2H, store it
            LDA	   C1
            LDX	   C2
            MUL
            ADD	   Result+1	;low result, 23:16
            STA	   Result+1	;low
            TXA	   				;load X to accumulator    
            ADC	   Result
            STA	   Result		;high result, 31:24
            

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
