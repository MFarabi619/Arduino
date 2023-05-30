int buzzer = 12; // Assign pin 12 for buzzer
int delayTime = 200; // Set delay in milliseconds

void setup()
{
    pinMode(buzzer, OUTPUT); // Initialize the buzzer pin as an output
}

void loop()
{
    // Output a tone. Active buzzers can only output a single tone.
    digitalWrite(buzzer, HIGH);
    delay(delayTime); 
    digitalWrite(buzzer, LOW);
    delay(delayTime); 
}
