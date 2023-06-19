#include <LiquidCrystal.h>

// LiquidCrystal(RS, E, D4, D5, D6, D7)
// RS, E, D4, D5, D6, D7 are the LCD pins.
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int BRIGHTNESS_PIN = 8;

const int SW_PIN = A2; // Digital pin connected to switch output
const int Y_PIN = 1; // Analog pin connected to Y output
const int X_PIN = 0; // Analog pin connected to X output

void setup()
{

    pinMode(BRIGHTNESS_PIN, OUTPUT);
    analogWrite(BRIGHTNESS_PIN, 255);

    lcd.begin(16, 2);
    lcd.clear();

    Serial.begin(9600);
}

void loop()
{
    lcd.setCursor(0, 0);
    lcd.print("Switch: ");
    lcd.print(digitalRead(SW_PIN));
    lcd.setCursor(0, 1);
    lcd.print("X: ");
    lcd.print(analogRead(X_PIN));
    lcd.print(", Y: ");
    lcd.print(analogRead(Y_PIN));
    delay(100);
    lcd.clear();
}