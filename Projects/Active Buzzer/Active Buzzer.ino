int buzzer = 12; // Assign pin 12 for buzzer
int potentiometer = 0; // Variable to store the value from the potentiometer
int delayTime = 200; // Set delay in milliseconds

void setup()
{
    pinMode(buzzer, OUTPUT); // Initialize the buzzer pin as an output
    pinMode(A0, INPUT); // Initialize analog pin as input

    Serial.begin(9600);
}

void loop()
{
    potentiometer = analogRead(A0); //read the input from the potentiometer on analog pin 0

    //Set delay time based on potentiometer value
    delayTime = map(potentiometer, 0, 1023, 1, 500);

    Serial.println(delayTime); // Print out the value of delayTime

    // Output a tone. Active buzzers can only output a single tone.
    digitalWrite(buzzer, HIGH);
    delay(delayTime); 
    digitalWrite(buzzer, LOW);
    delay(delayTime); 
}
