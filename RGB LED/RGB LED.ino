//Define Pins
#define BLUE 3
#define GREEN 5
#define RED 6

void setup(){
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