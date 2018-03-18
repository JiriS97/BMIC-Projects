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

; This project calculates the circumference of a rectangle

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
width: 			DS.W   1
length: 		DS.W   1
circumference:  DS.W   1

;
; code section
;
            ORG    ROMStart
            

_Startup:
            LDHX   #RAMEnd+1        ; initialize the stack pointer
            TXS
            CLI			; enable interrupts

mainLoop:
            ; Insert your code here
            LDHX   length
            PSHX
            PSHH					;length -> stack
            LDHX   width			;width -> H:X
            JSR    calculateCircumference	
            STHX   circumference	;H:X -> circumference
            AIS    #2				;stack pointer+2
            
            feed_watchdog
            BRA    mainLoop
			
;length -> stack
;width -> H:X
;circumference -> H:X
calculateCircumference:
		    ;LDA    4,SP
		    ;ADD    ,X			;?
		    
		    ;length+width
		    PSHX				;X -> SP
		    PULA				;SP -> A
		    ADD    4,SP			;add LOW byte of length
		    PSHA				;store on stack
		    
		    PSHH				;H -> SP
		    PULA				;SP -> A
		    ADC    4,SP			;add HIGH byte of length (offset 3+1 stored)
		    PSHA				;store on stack
		    
		    ;*2
		    LSL    2,SP			;rotate LOW byte of result left
		    ROL    1,SP			;rotate HIGH byte of result left with carry
		    
		    LDHX   1,SP			;load H:X from stack
		    AIS    #2			;delete result from stack
		    
		    RTS					;return
		    
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
