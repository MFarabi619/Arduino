#define BLUE 3 // Define Pins in Arduino that will be used for corresponding colors in the RGB LED
#define GREEN 5
#define RED 6

#define delayTime 10 // fading time between colors in milliseconds

void setup()
{
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
}

// define variables
int redValue;
int greenValue;
int blueValue;

// main loop
void loop()
{

    redValue = 255; // Starting value for the colors
    greenValue = 0;
    blueValue = 0;

    for (int i = 0; i < 255; i += 1) // fades out red bring green full when i=255
    {
        redValue -= 1;
        greenValue += 1;
        analogWrite(RED, redValue);
        analogWrite(GREEN, greenValue);
        delay(delayTime);
    } // At this point, redValue = 0, greenValue = 255, blueValue = 0

    for (int i = 0; i < 255; i += 1) // fades out green bring blue full when i=255
    {
        greenValue -= 1;
        blueValue += 1;
        analogWrite(GREEN, greenValue);
        analogWrite(BLUE, blueValue);
        delay(delayTime);
    } // At this point, redValue = 0, greenValue = 0, blueValue = 255

    for (int i = 0; i < 255; i += 1) // fades out blue bring red full when i=255
    {
        blueValue -= 1;
        redValue += 1;
        analogWrite(BLUE, blueValue);
        analogWrite(RED, redValue);
        delay(delayTime);
    } // At this point, redValue = 255, greenValue = 0, blueValue = 0
}