#include "pitches.h"

int potentiometer = A0; // potentiometer connected to analog pin 0
int buzzer = 12;        // buzzer connected to digital pin 11
const int G_MIXOLYDIAN_SCALE[] = {NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5};

void setup()
{
    pinMode(potentiometer, INPUT); // sets the pin as input
    pinMode(buzzer, OUTPUT);       // sets the pin as output
    Serial.begin(9600);            // starts the serial communication
}

void loop()
{
    int pitch = analogRead(potentiometer);       // reads the value of the potentiometer (value between 0 and 1023)
    pitch = map(pitch, 0, 1023, 0, 8);           // scale it to use it with the tone function (value between 100 and 1000)
    tone(buzzer, G_MIXOLYDIAN_SCALE[pitch % 8]); // plays the note in pitch
}