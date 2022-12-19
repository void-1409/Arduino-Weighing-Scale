#include "HX711.h"
#define DOUT  3
#define CLK  2
HX711 scale(DOUT, CLK);
float calibration_factor = -14697.895;
float weight;
float reading;
//=============================================================================================
//                         SETUP
//=============================================================================================
void setup() {
  Serial.begin(9600);
  scale.tare(); //Reset the scale to 0
  Serial.println("Enter weight: ");
  while (Serial.available() == 0){
    weight = Serial.parseInt();
  }
}

//=============================================================================================
//                         LOOP
//=============================================================================================
void loop() {

  scale.set_scale(calibration_factor); //Adjust to this calibration factor
  reading = scale.get_units()
  Serial.print("Scale Reading: ");
  Serial.print(reading);
  Serial.print(" kg"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor);
  Serial.println();
}
//=============================================================================================
