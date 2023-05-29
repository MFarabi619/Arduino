int LED0 = 2;       // Use pin 2 to control the white LED
int LED1 = 3;       // Use pin 3 to control the yellow LED
int LED2 = 4;       // Use pin 4 to control the green LED
int LED3 = 5;       // Use pin 5 to control the red LED
int delayTime = 50; // Delay time between each LED change in milliseconds

void setup()
{
    // initialize digital pins 2 to 5 as output:
    pinMode(LED0, OUTPUT);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
}

void lightUpLEDs(int LED, int delayTime)
{
    digitalWrite(LED, HIGH); // turn on the white LED
    delay(delayTime);
    digitalWrite(LED, LOW); // turn off the white LED
};

void loop()
{
    lightUpLEDs(LED0, delayTime);
    lightUpLEDs(LED1, delayTime);
    lightUpLEDs(LED2, delayTime);
    lightUpLEDs(LED3, delayTime);
    lightUpLEDs(LED2, delayTime);
    lightUpLEDs(LED1, delayTime);
}
