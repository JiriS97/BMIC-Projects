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

//This project sends back strings sent over UART interface using RX interrupt ands RX buffer

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

int ReadChar(char *c);
void SendChar(const char c);
void SendStr(const char *ptr);

#define BUFFER_SIZE 20

char buffer[BUFFER_SIZE];
int bufferReady = 0;

void main(void) {  
  SCI1BD = 31; //9600Bd
  SCI1C1 = 0;
  SCI1C2 = SCI1C2_TE_MASK | SCI1C2_RE_MASK | SCI1C2_RIE_MASK;
  
  EnableInterrupts; //global interrupt enable
  while(1) {
	if(bufferReady){
		bufferReady=0;
		SendStr(buffer);
	}
	__RESET_WATCHDOG();
  }
}

int ReadChar(char *c){
	if(SCI1S1_RDRF){
		*c = SCI1D;
		return 1;
	}
	return 0;
}

void SendChar(const char c){
	while(SCI1S1_TDRE == 0); //wait till TX empty
	SCI1D = c;
}

void SendStr(const char *ptr){
	while(*ptr){
		if(*ptr == '\n') SendChar('\r');
		SendChar(*ptr++);
	}
}

interrupt VectorNumber_Vsci1rx void isrSCI1_RX(){
	static int bufferIndex = 0;
	if(!ReadChar(&buffer[bufferIndex])) return; //read and save char
	
	if(buffer[bufferIndex] == '\r' || bufferIndex >= BUFFER_SIZE - 2){ //data ready (received endChar) or buffer full
		if(buffer[bufferIndex] == '\r') buffer[bufferIndex] = '\n'; //replace carriage return with new line
		buffer[++bufferIndex] = '\0'; //add string termination
		bufferReady = 1; //set flag
		bufferIndex = 0; //and clear index for next run
	} else {
		bufferIndex++; //normal character received, increment index only
	}
}

