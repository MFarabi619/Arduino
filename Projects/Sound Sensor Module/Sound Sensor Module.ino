#include <LiquidCrystal.h>

// LiquidCrystal(RS, E, D4, D5, D6, D7)
// RS, E, D4, D5, D6, D7 are the LCD pins.
LiquidCrystal LCD(2, 3, 4, 5, 6, 7);
int LCD_BACKLIGHT_PIN = 8; // pin for LCD backlight
int SENSOR_ANALOG_PIN = A0;    // Analog pin for sound sensor

void setup()
{
    analogWrite(LCD_BACKLIGHT_PIN, 100);
    Serial.begin(9600);
    LCD.begin(16, 2);
    pinMode(SENSOR_ANALOG_PIN, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    int analogValue = analogRead(SENSOR_ANALOG_PIN);
    if (analogValue > 300)
    {
        digitalWrite(LED_BUILTIN, HIGH);
    }
    else
    {
        digitalWrite(LED_BUILTIN, LOW);
    }
    LCD.setCursor(0, 0);
    LCD.print("Analog: "+String(analogValue));
    LCD.setCursor(0, 1);
    Serial.print("Analog: "+String(analogValue));
    Serial.println();
    delay(200);
    LCD.clear();
}
