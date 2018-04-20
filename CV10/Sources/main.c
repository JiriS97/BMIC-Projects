/* The MIT License (MIT)
 *
 * Copyright (c) 2018 Jiri Sramek (https://github.com/JiriS97/)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

//This project uses TOD module to blink with LEDs
//Detailed description can be found in attached Word document

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

//Select one
#define TOD_USE_LPO
//#define TOD_USE_OSCOUT
//#define TOD_USE_ICSIRCLK

void main(void) {
  //ports
  PTCDD = PTCDD_PTCDD2_MASK | PTCDD_PTCDD3_MASK | PTCDD_PTCDD4_MASK; //led outputs PTC2,3,4
  PTCD = PTCD_PTCD2_MASK | PTCD_PTCD3_MASK | PTCD_PTCD4_MASK; //leds off PTC2,3,4
  
  //TOD module
#ifdef TOD_USE_LPO
  TODC = (0x1<<5) | 0x0; //LPO osc, 1kHz
#elif defined TOD_USE_OSCOUT
  ICSC2 |= ICSC2_EREFS_MASK | ICSC2_ERCLKEN_MASK; //erefs, erclken
  TODC = (0x0<<5) | 0x1; //OSCOUT osc, 32.768kHz
#elif defined TOD_USE_ICSIRCLK
  ICSC1 |= ICSC1_IRCLKEN_MASK; //irclken
  TODC = (0x2<<5) | 0x3; //ICSIRCLK osc, 38.4kHz
#else
	#error Please select clock source for TOD module
#endif
  TODC |= TODC_TODR_MASK; //reset count
  TODSC = TODSC_QSECF_MASK | TODSC_SECF_MASK | TODSC_MTCHF_MASK; //clear interrupts
  TODSC |= TODSC_QSECIE_MASK | TODSC_SECIE_MASK | TODSC_MTCHIE_MASK | TODSC_MTCHEN_MASK; //enable interrupts 
  TODM_TODM = 4; //4 seconds match
  TODC |= TODC_TODEN_MASK; //enable TOD module
  EnableInterrupts; //global interrupt enable
  
  while(1) {
	__RESET_WATCHDOG();	
  }
}


interrupt VectorNumber_Vtod void isrTOD(){
	if(TODSC & TODSC_QSECF_MASK){ //0.25s
		TODSC = TODSC & 0x9F; //clear 0.25s interrupt
		PTCD_PTCD2 = !PTCD_PTCD2; //toggle led
	}
	if(TODSC & TODSC_SECF_MASK){ //1s
		TODSC = TODSC & 0x5F; //clear 1s interrupt
		PTCD_PTCD3 = !PTCD_PTCD3; //toggle led
		
	}
	if(TODSC & TODSC_MTCHF_MASK){ //match
		TODSC = TODSC & 0x3F; //clear match interrupt
		PTCD_PTCD4 = !PTCD_PTCD4; //toggle led
	}
}

