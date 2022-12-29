# Arduino Weighing Scale
Automated Weighing Scale using HX711 loadcell and Arduino Uno. A 16X2 LCD display used to display readings.

## Project Description
A simple home project of Automated weighing machine using Arduino Uno and HX711 loadcell. It uses a 16X2 LCD display to show data. It has set-weight functionality which operates connected relay when set weight gets equal to weight on the scale(loadcell).

## Circuit Setup
1. HX711 Loadcell(in)
```
DOUT pin -> 3
CLK pin -> 2
```
2. Keypad(in)
```
Column pins -> (13, 12, 11, 19)
Row pins -> (18, 17, 16, 15)
```
3. 16X2 Display(in)
```
rs, en, d4, d5, d6, d7 -> 8, 9, 4, 5, 6, 7
```
4. Relay(out)
```
pin 14
```
5. All 5V and GND pins(from cell, relay etc.) combined to 5V and GND of arduino respectively.

## Installation
1. Download and following Arduino Libraries in your arduino software. You can download them directly from Arduino menu in 'Tools' -> 'Manage Libraries' or you can download them as zip file from given links and add them to Arduino using menu in 'Sketch' -> 'Include Library' -> 'Add .ZIP Library'
  - [HX711](https://www.arduinolibraries.info/libraries/hx711) by Rob Tillaart
  - [LiquidCrystal](https://www.arduinolibraries.info/libraries/liquid-crystal) by Arduino, Adafruit
  - [Keypad](https://www.arduinolibraries.info/libraries/keypad) by Mark Stanley, Alexander Brevig
2. Download this code in zip file or directly clone this repo to your local machine.
3. Upload and run **Calibration** code file to your Arduino to calibrate HX711 loadcell.
4. `Important:`After successfull calibration, **update Loadcell** file with your obtained value of **calibration factor**.
5. Upload mdified **Loadcell** program to your Arduino and your weighing machine is complete.

_This was a home project, sharing my code here to contribute to the community. Feel free to contact me if you have any doubts._
