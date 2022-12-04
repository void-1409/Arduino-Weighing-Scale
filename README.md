# Arduino Weighing Scale
Automated Weighing Scale using HX711 loadcell and Arduino Uno. A 16X2 LCD display used to display readings.

## Project Description
A simple home project of Automated weighing machine using Arduino Uno and HX711 loadcell. It uses a 16X2 LCD display to show data. It has set-weight functionality which operates connected relay when set weight gets equal to weight on the scale(loadcell).

## Circuit Diagrams

## Installation
1. Download and following Arduino Libraries in your arduino software. You can download them directly from Arduino menu in 'Tools' -> 'Manage Libraries' or you can download them as zip file from given links and add them to Arduino using menu in 'Sketch' -> 'Include Library' -> 'Add .ZIP Library'
  1. [HX711](https://www.arduinolibraries.info/libraries/hx711) by Rob Tillaart
  2. [LiquidCrystal](https://www.arduinolibraries.info/libraries/liquid-crystal) by Arduino, Adafruit
  3. [Keypad](https://www.arduinolibraries.info/libraries/keypad) by Mark Stanley, Alexander Brevig
2. Download this code in zip file or directly clone this repo to your local machine.
3. Upload and run 'Calibration' code file to your Arduino to calibrate HX711 loadcell.
4. `Important:`After successfull calibration, update 'Loadcell' file with your obtained 
5. Upload mdified 'Loadcell' program to your Arduino and your weighing machine is complete.
