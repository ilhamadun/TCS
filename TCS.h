/**
 * TCS RGB Sensor Library For Arduino
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

#ifndef _TCS_H_
#define _TCS_H_

#define		DARKEST 	0
#define		BRIGHTEST 	1

enum color_t {RED, GREEN, BLUE, CLEAR};
enum speed_t {OFF, SLOW, MEDIUM, FAST};

class TCS
{
private:
	int pinS0, pinS1, pinS2, pinS3, pinOE, pinOUT;
	void selectColor(color_t color);

	// Calibration values
	int darkest[4];
	int brightest[4];

public:
	TCS();
	TCS(int S0, int S1, int S2, int S3, int OE, int OUT);
	void setup(int S0, int S1, int S2, int S3, int OE, int OUT);
	void setSpeed(speed_t speed);
	void calibrate(long calibrationTime);
	void setCalibrationValue(color_t color, int dark, int bright);
	void getCalibratedArray(byte type, int data[4]);
	int getCalibratedValue(byte type, color_t color);
	int readRawInput(color_t color);
	byte readColor(color_t color);
	byte readGrayscale();
};

#endif