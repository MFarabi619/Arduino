#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

const byte ROWS = 4; // four rows
const byte COLS = 4; // four columns

// Map the keypad buttons to the characters
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

// Connect keypad pins to the arduino pins
byte rowPins[ROWS] = {A7, A6, A5, A4}; // connect to the row pinouts of the keypad
byte colPins[COLS] = {A3, A2, A1, A0}; // connect to the column pinouts of the keypad

// Create a keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// LiquidCrystal(RS, E, D4, D5, D6, D7)
// RS, E, D4, D5, D6, D7 are the LCD pins.
LiquidCrystal LCD(11, 12, 7, 8, 9, 10);
int LCD_BACKLIGHT_PIN = 13; // pin for LCD backlight

void setup()
{
    LCD.begin(16, 2);
    analogWrite(LCD_BACKLIGHT_PIN, 100);
    Serial.begin(9600);
    // LCD.setCursor(0, 0);
    LCD.print("You pressed: ");
}
void loop()
{
    char key = keypad.getKey();

    if (key)
    {
        // LCD.clear();
        Serial.println(key);
        LCD.print(key);
    }
}