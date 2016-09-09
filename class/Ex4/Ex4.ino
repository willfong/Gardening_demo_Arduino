// Example 4
// Light Sensor

#include <Wire.h>
#include <SeeedOLED.h>
#include "Arduino.h"
#include "SI114X.h"

#define ButtonPin 2
int ButtonFlag  = 0;

SI114X SI1145 = SI114X();

void setup() {
  // put your setup code here, to run once:

  pinMode(ButtonPin,INPUT);
  attachInterrupt(0,ClickButton,FALLING);

  Wire.begin();
  SeeedOled.init();
  SeeedOled.clearDisplay();
  SeeedOled.setTextXY(0,0);
  
  while (!SI1145.Begin()) {
    delay(1000);
  }
  SeeedOled.putString("Push button!");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (ButtonFlag == 1) {
    SeeedOled.clearDisplay();
    SeeedOled.setTextXY(0,0);
    SeeedOled.putString("Current Reading:");
    SeeedOled.setTextXY(1,0);
    SeeedOled.putString("VL: ");
    SeeedOled.putNumber(SI1145.ReadVisible());
    SeeedOled.setTextXY(2,0);
    SeeedOled.putString("IR: ");
    SeeedOled.putNumber(SI1145.ReadIR());    
    ButtonFlag = 0; 
  }
}


void ClickButton(){
  ButtonFlag = 1;
}
