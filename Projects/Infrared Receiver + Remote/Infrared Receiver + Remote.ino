#include <IRremote.h>
#include <LiquidCrystal.h>

int RECEIVER_PIN = 11; // Input pin for receiver
IRrecv irrecv(RECEIVER_PIN);
decode_results results;
String previous = ""; // Previous value of the IR remote

// LiquidCrystal(RS, E, D4, D5, D6, D7)
// RS, E, D4, D5, D6, D7 are the LCD pins.
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int BRIGHTNESS_PIN = 8;

void setup()
{
    pinMode(BRIGHTNESS_PIN, OUTPUT);
    analogWrite(BRIGHTNESS_PIN, 100);

    lcd.begin(16, 2);
    lcd.clear();
    Serial.begin(9600);

    irrecv.enableIRIn(); // Start the receiver
}
void loop()
{
    lcd.setCursor(0, 0);
    if (irrecv.decode(&results))
    {
        previous = String(results.value, HEX);
        Serial.println(results.value, HEX);
        lcd.clear();
        lcd.print(results.value, HEX);
        delay(100);
        irrecv.resume(); // Receive the next value
    }
}