
int potentiometer = A0; // Set pin for potentiometer input
int servo = 2;          // Set pin for servo output
int angle = 0;          // Set initial angle to 0

void setup()
{
    pinMode(potentiometer, INPUT); // Set pin as input
    Serial.begin(9600);            // Start serial communication
    pinMode(servo, OUTPUT);        // Set pin as output
}
void loop()
{
    angle = analogRead(potentiometer);   // Read potentiometer value
    angle = map(angle, 0, 1023, 0, 270); // Scale it to use it with the servo (value between 0 and 180)
    Serial.println(angle);               // Print potentiometer value
    analogWrite(servo, angle);           // Write potentiometer value to servo
}