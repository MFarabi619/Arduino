#include <LiquidCrystal.h>

// LiquidCrystal(RS, E, D4, D5, D6, D7)
// RS, E, D4, D5, D6, D7 are the LCD pins.
LiquidCrystal LCD(2, 3, 4, 5, 6, 7);
int LCD_BACKLIGHT_PIN = 8; // pin for LCD backlight
int THERMISTOR_PIN = A0;   // pin for thermistor

void setup()
{
    analogWrite(LCD_BACKLIGHT_PIN, 100);
    Serial.begin(9600);
    LCD.begin(16, 2);
}

void loop()
{
    int reading = analogRead(THERMISTOR_PIN);
    Serial.println(reading);

    LCD.setCursor(0, 0);
    LCD.print("Thermistor Value: ");
    LCD.setCursor(0, 1);
    LCD.print(reading);
    delay(200);
    LCD.clear();
}
