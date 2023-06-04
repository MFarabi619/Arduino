#include <HCSR04.h>
#include <LiquidCrystal.h>

// LiquidCrystal(RS, E, D4, D5, D6, D7)
// RS, E, D4, D5, D6, D7 are the LCD pins.
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int ledContrast = 10;  // pin for contrast
int ledBacklight = 11; // pin for backlight
#define triggerPin 2
#define echoPin 3
UltraSonicDistanceSensor sensor(triggerPin, echoPin);
long a;

void setup()
{
    analogWrite(ledContrast, 80);
    analogWrite(ledBacklight, 255);
    lcd.begin(16, 2);
    Serial.begin(9600);
}

void loop()
{
    lcd.setCursor(0, 1);
    a = sensor.measureDistanceCm();
    Serial.print(a);
    lcd.print(a);
    Serial.println(" cm");
    lcd.print(" cm");
    delay(200);
    lcd.clear();
}