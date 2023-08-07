#include <LiquidCrystal.h>

// LiquidCrystal(RS, E, D4, D5, D6, D7)
// RS, E, D4, D5, D6, D7 are the LCD pins.
LiquidCrystal LCD(2, 3, 4, 5, 6, 7);
int LCD_BACKLIGHT_PIN = 8; // pin for LCD backlight
int THERMISTOR_PIN = A0;   // pin for thermistor
const int THERMISTOR_RESISTOR = 10000; // resistance of fixed resistor
const double B_COEFFICIENT = 3950; // B value for thermistor
const double REFERENCE_TEMPERATURE = 298.15; // reference temperature in Kelvin

void setup()
{
    analogWrite(LCD_BACKLIGHT_PIN, 100);
    Serial.begin(9600);
    LCD.begin(16, 2);
}

void loop()
{
    int reading = analogRead(THERMISTOR_PIN);
    double resistance = (1023.0 / reading) - 1;
    resistance = THERMISTOR_RESISTOR / resistance;
    double temperature = 1.0 / (log(resistance / THERMISTOR_RESISTOR) / B_COEFFICIENT + 1.0 / REFERENCE_TEMPERATURE);
    temperature -= 273.15; // convert from Kelvin to Celsius
    
    Serial.println(temperature);
    
    LCD.setCursor(0, 0);
    LCD.print("Temperature (C): ");
    LCD.setCursor(0, 1);
    LCD.print(temperature);
    delay(2000);
    LCD.clear();
}