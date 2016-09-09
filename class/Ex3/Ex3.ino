// Example 3
// Using Buttons

#include <Wire.h>
#include <SeeedOLED.h>

#define ButtonPin 2
int ButtonFlag  = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(ButtonPin,INPUT);
  attachInterrupt(0,ClickButton,FALLING);

  Wire.begin();
  SeeedOled.init();
  SeeedOled.clearDisplay();
  SeeedOled.setTextXY(0,0);
  SeeedOled.putString("Start!");
}


void loop() {
  // put your main code here, to run repeatedly:
  if (ButtonFlag == 1) {
    SeeedOled.clearDisplay();
    SeeedOled.setTextXY(0,0);
    SeeedOled.putString("BEEP!");
    delay(2000);
    SeeedOled.clearDisplay();
    ButtonFlag = 0;
  }
}


void ClickButton(){
  ButtonFlag = 1;
}
