#include <LiquidCrystal.h>

// LiquidCrystal(RS, E, D4, D5, D6, D7)
// RS, E, D4, D5, D6, D7 are the LCD pins.
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int ledContrast = 10;  // pin for contrast
int ledBacklight = 11; // pin for backlight

void setup()
{
    analogWrite(ledContrast, 40);
    analogWrite(ledBacklight, 255);
    lcd.begin(16, 2);
}

void loop()
{
    lcd.setCursor(0, 0);
    lcd.print("Text1");
    lcd.setCursor(0, 1);
    lcd.print("Text2");
}