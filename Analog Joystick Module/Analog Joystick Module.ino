#include <LiquidCrystal.h>

// LiquidCrystal(RS, E, D4, D5, D6, D7)
// RS, E, D4, D5, D6, D7 are the LCD pins.
LiquidCrystal lcd(2,3,4,5,6,7);
int BRIGHTNESS_PIN = 8;

void setup(){

pinMode(BRIGHTNESS_PIN, OUTPUT);
analogWrite(BRIGHTNESS_PIN, 255);

lcd.begin(16, 2);
lcd.clear();
}

void loop(){
lcd.setCursor(0,0);
lcd.print("Hello World!");
delay(1000);
lcd.clear();
}