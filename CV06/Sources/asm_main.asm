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

; export symbols
            XDEF calculateCircumference

            ; Include derivative-specific definitions
            INCLUDE 'derivative.inc'

; variable/data section
MY_ZEROPAGE: SECTION  SHORT
; Insert here your data definition. For demonstration, temp_byte is used.
temp_byte:  DS.B   1

; code section
MyCode:     SECTION
; this assembly routine is called the C/C++ application
asm_main:
            MOV    #1,temp_byte     ; just some demonstration code
            NOP                     ; Insert here your own code

            RTS                     ; return to caller
;width -> stack
;length -> H:X
;obvod -> H:X
calculateCircumference:
		    ;LDA    4,SP
		    ;ADD    ,X			;nejde?
		    
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
