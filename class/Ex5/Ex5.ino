// Example 5
// Temperature Sensor

#include <Wire.h>
#include <SeeedOLED.h>
#include "Arduino.h"
#include "SI114X.h"
#include "DHT.h"

#define ButtonPin 2
int ButtonFlag = 0;

SI114X SI1145 = SI114X();

#define DHTPIN A0
#define DHTTYPE DHT11   // DHT 11 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:

  pinMode(ButtonPin,INPUT);
  attachInterrupt(0,ClickButton,FALLING);

  dht.begin();
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
    SeeedOled.setTextXY(3,0);
    SeeedOled.putString("Temp: ");
    SeeedOled.putNumber(dht.readTemperature());
    SeeedOled.putString("*C");
    SeeedOled.setTextXY(4,0);
    SeeedOled.putString("Humidity: ");
    SeeedOled.putNumber(dht.readHumidity());
    SeeedOled.putString("%");    
    ButtonFlag = 0; 
  }
}


void ClickButton(){
  ButtonFlag = 1;
}
