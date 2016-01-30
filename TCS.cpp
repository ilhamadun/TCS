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

#include "Arduino.h"
#include "TCS.h"

/**
 * Initialize TCS Sensor
 *
 * This function receive pin number and set it as IO
 */
TCS::TCS(int S0, int S1, int S2, int S3, int OE, int OUT):
	pinS0(S0), pinS1(S1), pinS2(S2), pinS3(S3), pinOE(OE), pinOUT(OUT)
{
	pinMode(pinS0, OUTPUT);
	pinMode(pinS1, OUTPUT);
	pinMode(pinS2, OUTPUT);
	pinMode(pinS3, OUTPUT);
	pinMode(pinOE, OUTPUT);
	pinMode(pinOUT, INPUT);

	brightest[RED] = 9999;
	brightest[GREEN] = 9999;
	brightest[BLUE] = 9999;
	brightest[CLEAR] = 9999;

	// Set OE in low impedance mode
	digitalWrite(pinOE, LOW);
}

/**
 * Set Output Frequency Scaling
 *
 * There are three possible parameter value:
 * - SLOW: 2%
 * - MEDIUM: 20%
 * - FAST: 100%
 * These speed will affect the output value
 * 
 * @param 	speed
 */
void TCS::setSpeed(speed_t speed)
{
	switch (speed)
	{
		case OFF:
			digitalWrite(pinS0, LOW);
			digitalWrite(pinS1, LOW);
			break;
			
		case SLOW:
			digitalWrite(pinS0, LOW);
			digitalWrite(pinS1, HIGH);
			break;

		case MEDIUM:
			digitalWrite(pinS0, HIGH);
			digitalWrite(pinS1, LOW);
			break;

		case FAST:
			digitalWrite(pinS0, HIGH);
			digitalWrite(pinS1, HIGH);
			break;
	}
}

/**
 * Sensor Calibration
 *
 * The sensor will read input for calibrationTime miliseconds and save
 * the highest and lowest value read
 */
void TCS::calibrate(long calibrationTime)
{
	int red, green, blue, clear;
	long startTime = millis();

	while (millis() - startTime < calibrationTime)
	{
		red = getColor(RED);
		if (red > darkest[RED])
			darkest[RED] = red;
		else if (red && red < brightest[RED])
			brightest[RED] = red;

		green = getColor(GREEN);
		if (green > darkest[GREEN])
			darkest[GREEN] = green;
		else if (green && green < brightest[GREEN])
			brightest[GREEN] = green;
		
		blue = getColor(BLUE);
		if (blue > darkest[BLUE])
			darkest[BLUE] = blue;
		else if (blue && blue < brightest[BLUE])
			brightest[BLUE] = blue;

		clear = getColor(CLEAR);
		if (clear > darkest[CLEAR])
			darkest[CLEAR] = clear;
		else if (clear && clear < brightest[CLEAR])
			brightest[CLEAR] = clear;
	}
}

/**
 * Get calibration value
 * 
 * @param  	type
 * @param  	color
 * @return	calibration value
 */
int TCS::getCalibratedValue(byte type, color_t color)
{
	if (type == DARKEST)
	{
		return darkest[color];
	}
	else
	{
		return brightest[color];
	}
}

/**
 * Color Selector
 *
 * There are four possible parameter value:
 * - RED
 * - GREEN
 * - BLUE
 * - CLEAR
 * These value will set the sensor to read the corresponding color
 * 
 * @param color
 */
void TCS::selectColor(color_t color)
{
	switch (color)
	{
		case RED:
			digitalWrite(pinS2, LOW);
			digitalWrite(pinS3, LOW);
			break;

		case GREEN:
			digitalWrite(pinS2, HIGH);
			digitalWrite(pinS3, HIGH);
			break;

		case BLUE:
			digitalWrite(pinS2, LOW);
			digitalWrite(pinS3, HIGH);
			break;

		case CLEAR:
			digitalWrite(pinS2, HIGH);
			digitalWrite(pinS3, LOW);
			break;
	}
}

/**
 * Read Color From Sensor
 * 
 * @param  color 	color to read 	RED, GREEN, BLUE or CLEAR
 * @return       	output signal period
 */
int TCS::getColor(color_t color)
{
	selectColor(color);
	return pulseIn(pinOUT, HIGH);
}