/**
 * Calibrate the TCS sensor
 * 
 * Copyright (c) 2016 Ilham Imaduddin
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
*/

#include "TCS.h"

TCS tcs(40, 41, 42, 43, 44, 45);

void setup() {
  Serial.begin(9600);
  tcs.setSpeed(FAST);

  // Calibrate for 5000 miliseconds
  tcs.calibrate(5000);

  // Show calibration values
  Serial.println("Darkest");

  Serial.print("R: ");
  Serial.print(tcs.getCalibratedValue(DARKEST, RED));

  Serial.print("\tG: ");
  Serial.print(tcs.getCalibratedValue(DARKEST, GREEN));

  Serial.print("\tB: ");
  Serial.print(tcs.getCalibratedValue(DARKEST, BLUE));

  Serial.print("\tC: ");
  Serial.println(tcs.getCalibratedValue(DARKEST, CLEAR));

  Serial.println("Brightest");

  Serial.print("R: ");
  Serial.print(tcs.getCalibratedValue(BRIGHTEST, RED));

  Serial.print("\tG: ");
  Serial.print(tcs.getCalibratedValue(BRIGHTEST, GREEN));

  Serial.print("\tB: ");
  Serial.print(tcs.getCalibratedValue(BRIGHTEST, BLUE));

  Serial.print("\tC: ");
  Serial.print(tcs.getCalibratedValue(BRIGHTEST, CLEAR));
}

void loop() {
  // Do nothing
}
