TCS Library For Arduino
=======================

The TCS library allows an Arduino to read the TCS sensor. The TCS is a color sensor that can detect red, blue and green color.

## Installation
1. Click **Download ZIP**
2. Install the library, click `Sketch > Include Library > Add .ZIP Library...` on Arduino IDE

## Usage
#### Setup
First, you need to create a TCS object and set the TCS pins:
```c++
TCS tcs(int S0, int S1, int S2, int S3, int OE, int OUT);
```
Then you need to set the reading speed with:
```c++
tcs.setSpeed(speed_t speed);
```
The `setSpeed` method can take `OFF`, `SLOW`, `MEDIUM` and `FAST` parameter. The default is set to `OFF` speed, so the sensor stay in power down mode until you set another speed.

#### Calibration
You will need to calibrate the sensor using the `calibrate(long calibrationTime)` method. When the method is called, you should read the sensor to a white and black object.

For example, this method call
```c++
tcs.calibrate(5000);
```
will give you 5000 miliseconds to read the sensor to a white and black object.

You can also use the `setCalibrationValue(color_t color, int dark, int bright)` to manually set the calibration values.

#### Reading The Sensor
This library allow you to read the sensor and encode it to 8 bit color code. There are three method to read the sensor:

- `readRawInput(color_t color)` to read raw sensor input.
- `readColor(color_t color)` to read the sensor and encode it to 8 bit color code.
- `readGrayscale()` to read the sensor and encode it to 8 bit grayscale data.

The `color_t color` parameter takes `RED`, `GREEN`, `BLUE` or `CLEAR`.

## License
The TCS library is open source and licensed under the [MIT license](http://opensource.org/licenses/MIT).
