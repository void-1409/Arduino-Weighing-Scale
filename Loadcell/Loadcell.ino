#include "HX711.h"
#include <LiquidCrystal.h>
#include <Keypad.h>

//HX711 pins
#define DOUT 3
#define CLK 2

float final_wt = 300.0;   //max. weight

//define keypad
char keys[4][4] = {
  {'D', 'P', '0', '*'},
  {'C', '9', '8', '7'},
  {'B', '6', '5', '4'},
  {'A', '3', '2', '1'}
};

//keypad pins
byte pin_col[4] = {13, 12, 11, 19};
byte pin_row[4] = {18, 17, 16, 15};

//variables
int ctr = 0;
int result = 0;

//initialization
HX711 scale(DOUT, CLK);
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);    //LCD Pins: rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
Keypad keypad = Keypad(makeKeymap (keys), pin_row, pin_col, 4, 4);

//when decimal button is pressed
float AfterDecimal(float setwt){
  float mul = 0.1;
  while(1){
    char key = keypad.getKey();
    if (key == '1'){
      setwt = setwt + 1*mul;
      mul /= 10;
    }
    else if (key == '2'){
      setwt = setwt + 2*mul;
      mul /= 10;
    }
    else if (key == '3'){
      setwt = setwt + 3*mul;
      mul /= 10;
    }
    else if (key == '4'){
      setwt = setwt + 4*mul;
      mul /= 10;
    }
    else if (key == '5'){
      setwt = setwt + 5*mul;
      mul /= 10;
    }
    else if (key == '6'){
      setwt = setwt + 6*mul;
      mul /= 10;
    }
    else if (key == '7'){
      setwt = setwt + 7*mul;
      mul /= 10;
    }
    else if (key == '8'){
      setwt = setwt + 8*mul;
      mul /= 10;
    }
    else if (key == '9'){
      setwt = setwt + 9*mul;
      mul /= 10;
    }
    else if (key == '0'){
      setwt = setwt + 0*mul;
      mul /= 10;
    }
    else if (key == 'A'){
      lcd.setCursor(0,0);
      lcd.print("Final wt: ");
      lcd.print(setwt);
      return setwt;
    }
    else if (key == 'B'){
      lcd.setCursor(0,0);
      lcd.print("                ");
      setwt = 0;
      return setwt;
    }
    lcd.setCursor(0,0);
    lcd.print("Set Wt: ");
    lcd.print(setwt);
  }
}

//when set-weight button is pressed
float KeyFunction(){
  float setwt = 0, mul = 1;
  while(1){
    char key = keypad.getKey();
    if (setwt > 300)
      setwt = 300;
    if (key == '1'){
      setwt = setwt*mul + 1;
      mul = 10;
    }
    else if (key == '2'){
      setwt = setwt*mul + 2;
      mul = 10;
    }
    else if (key == '3'){
      setwt = setwt*mul + 3;
      mul = 10;
    }
    else if (key == '4'){
      setwt = setwt*mul + 4;
      mul = 10;
    }
    else if (key == '5'){
      setwt = setwt*mul + 5;
      mul = 10;
    }
    else if (key == '6'){
      setwt = setwt*mul + 6;
      mul = 10;
    }
    else if (key == '7'){
      setwt = setwt*mul + 7;
      mul = 10;
    }
    else if (key == '8'){
      setwt = setwt*mul + 8;
      mul = 10;
    }
    else if (key == '9'){
      setwt = setwt*mul + 9;
      mul = 10;
    }
    else if (key == '0'){
      setwt = setwt*mul + 0;
      mul = 10;
    }
    else if (key == 'P'){
      result = (int)setwt;
      if (result%25 != 0){
        setwt = 0;
      }
      setwt = setwt + 25;
    }
    else if (key == '*'){
      setwt = AfterDecimal(setwt);
      if (setwt > 0)
        return setwt;
    }
    else if (key == 'A'){
      lcd.setCursor(0,0);
      lcd.print("Final wt: ");
      lcd.print(setwt);
      return setwt;
    }
    else if (key == 'B'){
      lcd.setCursor(0,0);
      lcd.print("                ");
      setwt = 0;
    }
    lcd.setCursor(0,0);
    lcd.print("Set wt: ");
    lcd.print(setwt);
  }
}


//setup-initialization
void setup(){
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Hariom Industry");
  lcd.setCursor(0,1);
  lcd.print("Wt:");
  digitalWrite(14, HIGH);
  pinMode(10, OUTPUT); //relay pin
  pinMode(14, OUTPUT);
  Serial.begin(9600);
  scale.set_scale(-14697.895);
  scale.tare();
}

//void (* resetFunc) (void) = 0;  //reset-function

//main loop
void loop(){
  float weight = scale.get_units(3);
  lcd.setCursor(3,1);
  lcd.print(weight, 2);
  lcd.print(" kg ");
  char key = keypad.getKey();
  if (key == 'A'){
    lcd.setCursor(0,0);
    lcd.print("                ");
    final_wt = KeyFunction();
  }
  else if (key == 'C')
    scale.tare();   //tare weight scale
 
  else if (key == 'D')
    digitalWrite(14, LOW);  //hard-resets arduino(reset-function can be used instead as defined above)
 
  if (weight > final_wt){
    digitalWrite(10, LOW);
    Serial.println("HIGH");
  }
  else{
    digitalWrite(10, HIGH);
    Serial.println("LOW");
  }
}
