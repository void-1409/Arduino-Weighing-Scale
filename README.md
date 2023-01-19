# Arduino Weighing Scale
Automated Weighing Scale using HX711 loadcell and Arduino Uno. A 16X2 LCD display used to display readings.

## Project Description
A simple home project of Automated weighing machine using Arduino Uno and HX711 loadcell. It uses a 16X2 LCD display to show data. It has set-weight functionality which operates connected relay when set weight gets equal to weight on the scale(loadcell).

## Circuit Setup
- HX711 Loadcell (inputs)
>DOUT pin -> 3  
>CLK pin -> 2
- Keypad (inputs)
>Column pins -> (13, 12, 11, 19)  
>Row pins -> (18, 17, 16, 15)
- 16X2 Display (inputs)
>rs, en, d4, d5, d6, d7 -> 8, 9, 4, 5, 6, 7
- Relay (output)
>pin 14
- All 5V and GND pins(from cell, relay etc.) combined to 5V and GND of arduino respectively.  
`Note:` You can change pin configurations according to your need. Just remember to change values in Loadcell file.

## Installation
1. Download and following Arduino Libraries in your arduino software. You can download them directly from Arduino menu in **Tools** -> **Manage Libraries** or you can download them as zip file from given links and add them to Arduino using menu in **Sketch** -> **Include Library** -> **Add .ZIP Library**
  - [HX711](https://www.arduinolibraries.info/libraries/hx711) by Rob Tillaart
  - [LiquidCrystal](https://www.arduinolibraries.info/libraries/liquid-crystal) by Arduino, Adafruit
  - [Keypad](https://www.arduinolibraries.info/libraries/keypad) by Mark Stanley, Alexander Brevig
2. Download this code in zip file or clone this repo to your local machine using following command.
```
git clone https://github.com/void-1409/Arduino-Weighing-Scale
```
3. Upload and run **Calibration** code file to your Arduino to calibrate HX711 loadcell.
  -Check **readme.md** in [Calibration](/Calibration) for instructions.
4. `Important:`After successfull calibration, **update Loadcell** file with your obtained value of **calibration factor**.
5. Upload modified **Loadcell** program to your Arduino and you are good to go.

_This was a home project, sharing my code here to contribute to the community. Feel free to contact me if you have any doubts._
