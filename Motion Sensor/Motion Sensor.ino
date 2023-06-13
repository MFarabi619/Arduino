int LED_PIN = 13; // LED on Pin 13 of Arduino
int PIR_PIN = 7;  // Input for HC-S501 Motion Sensor

int pirValue; // Place to store read PIR Value

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    pinMode(PIR_PIN, INPUT);

    digitalWrite(LED_PIN, LOW);
}

void loop()
{
    pirValue = digitalRead(PIR_PIN);
    digitalWrite(LED_PIN, pirValue);
}
