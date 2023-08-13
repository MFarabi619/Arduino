#include <LiquidCrystal.h>

// LiquidCrystal(RS, E, D4, D5, D6, D7)
// RS, E, D4, D5, D6, D7 are the LCD pins.
LiquidCrystal LCD(2, 3, 4, 5, 6, 7);
int LCD_BACKLIGHT_PIN = 8; // pin for LCD backlight
int PHOTOCELL_PIN = A0;    // analog pin for the photocell

void setup()
{
    pinMode(PHOTOCELL_PIN, INPUT);     // Set the photocell pin as input
    analogWrite(LCD_BACKLIGHT_PIN, 100); // Set LCD backlight
    Serial.begin(9600);                 // Begin serial communication for debugging
    LCD.begin(16, 2);                   // Start the LCD
}

void loop()
{
    int photocellValue = analogRead(PHOTOCELL_PIN); // Read the value from the photocell

    LCD.setCursor(0, 0);
    LCD.print("Photocell Value:"); // Display text on the first line
    LCD.setCursor(0, 1);
    LCD.print(photocellValue);     // Display the value on the second line

    Serial.println(photocellValue); // Print the value to the serial monitor

    delay(1000);                   // Wait for a second
    LCD.clear();                   // Clear the display
}