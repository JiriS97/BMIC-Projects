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

//This project interprets commands sent via UART interface
//to control LEDs on PTC2-5
//Command examples:
// LED 2 ON: L2-1\r
// LED 2 OFF: L2-0\r

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include <string.h>

int ReadChar(char *c);
void SendChar(const char c);
void SendStrWithInterrupt(const char *str);
int ProcessCommand(const char *cmd);

#define BUFFER_SIZE 20

//rx and tx buffer
volatile char bufferRx[BUFFER_SIZE];
volatile char bufferTx[BUFFER_SIZE];
volatile int commandReady = 0;

void main(void) {
	//ports
	PTCDD = PTCDD_PTCDD2_MASK | PTCDD_PTCDD3_MASK | PTCDD_PTCDD4_MASK | PTCDD_PTCDD5_MASK; //led outputs PTC2,3,4,5
	PTCD = PTCD_PTCD2_MASK | PTCD_PTCD3_MASK | PTCD_PTCD4_MASK | PTCD_PTCD5_MASK; //leds off PTC2,3,4,5

	//UART
	SCI1BD = 31; //9600Bd
	SCI1C1 = 0;
	SCI1C2 = SCI1C2_TE_MASK | SCI1C2_RE_MASK | SCI1C2_RIE_MASK; //enable Tx, Rx and Rx interrupt

	EnableInterrupts; //global interrupt enable
	for(;;) {
		if(commandReady){
			commandReady = 0;
			if (ProcessCommand(bufferRx)) { //process the command, send response
				SendStrWithInterrupt("Ok\r\n");
			} else {
				SendStrWithInterrupt("Err\r\n");
			}
		}
		__RESET_WATCHDOG();
	}
}

//read one char
int ReadChar(char *c) {
	if (SCI1S1_RDRF) {
		*c = SCI1D;
		return 1;
	}
	return 0;
}

//send one char
void SendChar(const char c){
	while(SCI1S1_TDRE == 0); //wait till TX empty
	SCI1D = c;
}

//send string using Tx interrupt
void SendStrWithInterrupt(const char *str) {
	(void)strncpy(bufferTx, str, BUFFER_SIZE - 1); //copy string to TX buffer
	bufferTx[BUFFER_SIZE - 1] = '\0'; //add termination
	SCI1C2 |= SCI1C2_TIE_MASK; //enable tx int
}

//process LED commands, return 1 if ok, 0 otherwise
int ProcessCommand(const char *cmd) {
	if (strcmp(cmd, "L2-1\r") == 0) {
		PTCD_PTCD2 = 0;
		return 1;
	} else if (strcmp(cmd, "L2-0\r") == 0) {
		PTCD_PTCD2 = 1;
		return 1;
	} else if (strcmp(cmd, "L3-1\r") == 0) {
		PTCD_PTCD3 = 0;
		return 1;
	} else if (strcmp(cmd, "L3-0\r") == 0) {
		PTCD_PTCD3 = 1;
		return 1;
	} else if (strcmp(cmd, "L4-1\r") == 0) {
		PTCD_PTCD4 = 0;
		return 1;
	} else if (strcmp(cmd, "L4-0\r") == 0) {
		PTCD_PTCD4 = 1;
		return 1;
	} else if (strcmp(cmd, "L5-1\r") == 0) {
		PTCD_PTCD5 = 0;
		return 1;
	} else if (strcmp(cmd, "L5-0\r") == 0) {
		PTCD_PTCD5 = 1;
		return 1;
	}
	return 0;
}

//RX interrupt
interrupt VectorNumber_Vsci1rx void isrSCI1_RX() {
	static int bufferRxIndex = 0;
	if (!ReadChar(&bufferRx[bufferRxIndex])) return; //read and save char

	if (bufferRx[bufferRxIndex] == '\r' || bufferRxIndex >= BUFFER_SIZE - 2) { //data ready (received \r) or bufferRx full
		bufferRx[++bufferRxIndex] = '\0'; //add string termination
		commandReady = 1; //set flag
		bufferRxIndex = 0; //and clear index for next run
	} else {
		bufferRxIndex++; //normal character received, increment index only
	}
}

//TX interrupt
interrupt VectorNumber_Vsci1tx void isrSCI1_TX() {
	static int bufferTxIndex = 0;
	if (bufferTx[bufferTxIndex] != '\0') { //check for string termination
		SendChar(bufferTx[bufferTxIndex++]); //send char and move to the next one
	} else {
		SCI1C2 &= ~(unsigned char)SCI1C2_TIE_MASK; //disable tx int
		bufferTxIndex = 0; //clear buffer index
	}
}
