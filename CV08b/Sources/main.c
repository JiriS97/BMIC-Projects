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

//This project uses 4 buttons to control 4 leds (button down -> led on) 

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

void main(void) {
  EnableInterrupts;
  PTCDD = PTCDD_PTCDD2_MASK | PTCDD_PTCDD3_MASK | PTCDD_PTCDD4_MASK | PTCDD_PTCDD5_MASK; //led outputs PTC2,3,4,5
  PTAPE = PTAPE_PTAPE4_MASK | PTAPE_PTAPE6_MASK | PTAPE_PTAPE7_MASK; //PTA4,6,7 pullup enable
  

  while(1) {
    __RESET_WATCHDOG();	
    PTCD_PTCD2 = PTAD_PTAD6;
    PTCD_PTCD3 = PTAD_PTAD7;
    PTCD_PTCD4 = PTAD_PTAD4;
    PTCD_PTCD5 = PTCD_PTCD7;
  }
}
