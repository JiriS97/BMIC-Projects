/*
* The MIT License (MIT)
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

//This project calculates the circumference of a rectangle using asm subroutine and C

#include <hidef.h> 		//for EnableInterrupts macro
#include "derivative.h" //include peripheral declarations
#include "main_asm.h" 	//interface to the assembly module


extern unsigned calculateCircumference(unsigned width, unsigned length);
unsigned CcalculateCircumference(unsigned width, unsigned length);

void main(void) {
	unsigned width=0x1234, length=0x56F8, circumference, circumferenceC;
	
	circumference = calculateCircumference(width, length);
	circumferenceC = CcalculateCircumference(width, length);
	
	for(;;) {
		__RESET_WATCHDOG();	//feeds the dog
	} // loop forever
	//please make sure that you never leave main
}

unsigned CcalculateCircumference(unsigned width, unsigned length){
	return 2*(width+length);
}
