#include <LiquidCrystal.h>

// LiquidCrystal(RS, E, D4, D5, D6, D7)
// RS, E, D4, D5, D6, D7 are the LCD pins.
LiquidCrystal LCD(2, 3, 4, 5, 6, 7);
int LCD_BACKLIGHT_PIN = 8; // pin for LCD backlight

int SENSOR_PIN = A0; // pin for water level sensor
int sensorValue = 0;
void setup()
{
    analogWrite(LCD_BACKLIGHT_PIN, 100);
    Serial.begin(9600);
    LCD.begin(16, 2);
}

void loop()
{
    sensorValue = analogRead(SENSOR_PIN);
    LCD.setCursor(0, 0);
    LCD.print("Water Level: ");
    LCD.setCursor(0, 1);
    LCD.print(sensorValue);
    Serial.println(sensorValue);
    delay(100);
    LCD.clear();
}
