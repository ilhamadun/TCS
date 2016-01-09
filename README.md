TCS Library For Arduino
=======================

The TCS library allows an Arduino to read the TCS sensor. The TCS is a color sensor that can detect red, blue and green color.

## Installation
1. Click **Download ZIP**
2. Install the library, click `Sketch > Include Library > Add .ZIP Library...` on Arduino IDE

## Usage
First, you need to create a TCS object and set the TCS pins:
```c++
TCS tcs(int S0, int S1, int S2, int S3, int OE, int OUT);
```
Then you need to set the reading speed with:
```c++
tcs.setSpeed(speed_t speed);
```
The `setSpeed` method can take `OFF`, `SLOW`, `MEDIUM` and `FAST` parameter. The default is set to `OFF` speed, so the sensor stay in power down mode until you set another speed.

After that you can start reading color:
```c++
tcs.getColor(color_t color);
```
The `getColor` method can take `RED`, `GREEN`, `BLUE` and `CLEAR` parameter.

## License
The TCS library is open source and licensed under the [MIT license](http://opensource.org/licenses/MIT).
