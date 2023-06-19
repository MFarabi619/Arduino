int LED0 = 2;       // Use pin 2 to control the white LED
int LED1 = 3;       // Use pin 3 to control the yellow LED
int LED2 = 4;       // Use pin 4 to control the green LED
int LED3 = 5;       // Use pin 5 to control the red LED
int delayTime = 50; // Delay time between each LED change in milliseconds
int sensorValue = 0; // Variable to store the value coming from the potentiometer

void setup()
{
    // initialize digital pins 2 to 5 as output:
    pinMode(LED0, OUTPUT);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);

    //initialize analog pin as input:
    pinMode(A0, INPUT);

    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600); 
}

void lightUpLEDs(int LED, int delayTime)
{
    digitalWrite(LED, HIGH); // turn on the white LED
    delay(delayTime);
    digitalWrite(LED, LOW); // turn off the white LED
};

void loop()
{
    sensorValue = analogRead(A0); // read the input on analog pin 0
    delayTime = map(sensorValue, 0, 1023, 30, 255); // Set delay time based on the potentiometer value
    Serial.println(delayTime); // print out the value of delayTime

    lightUpLEDs(LED0, delayTime);
    lightUpLEDs(LED1, delayTime);
    lightUpLEDs(LED2, delayTime);
    lightUpLEDs(LED3, delayTime);
    lightUpLEDs(LED2, delayTime);
    lightUpLEDs(LED1, delayTime);
}
