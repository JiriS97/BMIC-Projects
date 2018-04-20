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

; This project uses two buttons to toggle state of two leds using polling method

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
ExampleVar: DS.B   1

;
; code section
;
            ORG    ROMStart
            

_Startup:
            LDHX   #RAMEnd+1        ; initialize the stack pointer
            TXS
            CLI			; enable interrupts
			
			LDA	#(mPTCDD_PTCDD5 | mPTCDD_PTCDD4)	;led pins as output PTCDD5,4 - 1
			STA PTCDD
			
			LDA #mPTAPE_PTAPE4	;pullup enable PTA4
			STA PTAPE
			
mainLoop:
            feed_watchdog
            
            BRCLR PTCD_PTCD7, PTCD, btn_down1 ;check PTC7 = low ?
            BSET PTCD_PTCD5, PTCD	;PTC5 -> 1 LED off
            BRA btnCheck2
btn_down1:
			BCLR PTCD_PTCD5, PTCD 	;PTC5 -> 0 LED on
            
btnCheck2:
			BRCLR PTAD_PTAD4, PTAD, btn_down2 ;check PTA4 = low ?
            BSET PTCD_PTCD4, PTCD	;PTC4 -> 1 LED off
            BRA btnCheck2
btn_down2:
			BCLR PTCD_PTCD4, PTCD 	;PTC4 -> 0 LED on
			
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
