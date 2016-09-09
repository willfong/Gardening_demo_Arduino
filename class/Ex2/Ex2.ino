// Example 2
// OLED Display

#include <Wire.h>
#include <SeeedOLED.h>


// Start the counter at 0
int counter = 0;


void setup() {
  // put your setup code here, to run once:

  // This is to set up the screen
  Wire.begin();
  SeeedOled.init();

  // This is to clear the display
  SeeedOled.clearDisplay();

  // This is to print the first line
  SeeedOled.setTextXY(0,0);
  SeeedOled.putString("First line");

  // This is to print the second line
  SeeedOled.setTextXY(1,0);
  SeeedOled.putString("Second line");
}


void loop() {
  // put your main code here, to run repeatedly:

  // Increase the counter by one
  counter += 1;

  // This is to print the the fourth line
  SeeedOled.setTextXY(4,0);
  SeeedOled.putNumber(counter);

  // This is to sleep the computer for 1 second
  delay(1000);
}
