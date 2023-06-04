#include <LiquidCrystal.h>
#include <DHT.h>

// LiquidCrystal(RS, E, D4, D5, D6, D7)
// RS, E, D4, D5, D6, D7 are the LCD pins.
LiquidCrystal LCD1(33, 31, 29, 27, 25, 23);
LiquidCrystal LCD2(8, 9, 4, 5, 6, 7);

int LCD2_CONTRAST_PIN = 10;  // pin for LCD2 contrast
int LCD2_BACKLIGHT_PIN = 11; // pin for LCD2 backlight

// Custom character for the degree symbol
// byte degreeSymbol[8] = {
//     B00110,
//     B01001,
//     B01001,
//     B00110,
//     B00000,
//     B00000,
//     B00000,
//     B00000};

int TRIGGER_PIN = 12;                       // pin for distance sensor trigger
int ECHO_PIN = 13;                          // pin for distance sensor echo
float duration, distanceMm, distanceIn = 0; // Variables for distance sensor

int BUTTON_PIN[] = {39, 35};             // pins for buttons
int buttonState[] = {HIGH, HIGH};        // Variable for curent button state
int lastButtonState[] = {HIGH, HIGH};    // Variable for last button state
bool isOn[] = {false, false};            // Variable to check if button is on
bool isButtonPressed[] = {false, false}; // Variables to check if button is pressed
int reading[] = {HIGH, HIGH};            // Variable to read button state

int DHT_PIN = 3; // pin for DHT sensor
#define DHTTYPE DHT22
DHT dht(DHT_PIN, DHTTYPE);
int temperature, humidity = 0; // Variables for temperature and humidity
// const SPEEDOFSOUND = 0; // Speed of sound in air

void setup()
{
  LCD1.begin(16, 2);
  analogWrite(LCD2_CONTRAST_PIN, 80);
  analogWrite(LCD2_BACKLIGHT_PIN, 255);
  LCD2.begin(16, 2);
  // // Define the custom character for the degree symbol
  // LCD1.createChar(0, degreeSymbol);
  // LCD2.createChar(0, degreeSymbol);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(BUTTON_PIN[0], INPUT_PULLUP);
  pinMode(BUTTON_PIN[1], INPUT_PULLUP);
  pinMode(BUTTON_PIN[2], INPUT_PULLUP);

  dht.begin();

  Serial.begin(9600);
}

bool detectButton(int num)
{
  // Read the current state of the button
  reading[num] = digitalRead(BUTTON_PIN[num]);

  // Check if the button state has changed
  if (reading[num] != lastButtonState[num])
  {
    Serial.println("Button pressed. Button pin: " + String(BUTTON_PIN[num]));
    if (reading[num] == LOW)
    {
      isButtonPressed[num] = true; // Set the button press flag
    }
  }

  // Check if the button has been released
  if (isButtonPressed[num] && reading[num] == HIGH)
  {
    isButtonPressed[num] = false; // Reset the button press flag

    // Toggle the on/off state
    isOn[num] = !isOn[num];
  }

  // Update the last button state for comparison in the next iteration
  lastButtonState[num] = reading[num];

  Serial.println("Button state: " + String(isOn[num]));
  return isOn[num];
}

void loop()
{
  // Send a short 10 microsecond pulse to the trigger pin
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, HIGH);

  // Wait for pulse on echo pin
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance in millimeters (mm)
  distanceMm = duration * 0.034 / 2;
  // Calculate distance in inches (in)
  distanceIn = duration * 0.0133 / 2;

  // Determine with button if distance is in mm or in
  String distanceMmString = "Dist(mm): " + String(distanceMm);
  String distanceInString = "Dist(in): " + String(distanceIn);
  String displayDistanceString = detectButton(0) ? distanceInString : distanceMmString;

  // Read temperature as Celsius (the default)
  float tempCelcius = dht.readTemperature();
  float tempFahrenheit = dht.readTemperature() * 1.8 + 32.0;

  // Calculate temperature in degrees Celsius
  // char tempCelciusString[20];
  // sprintf(tempCelciusString, "Temp(%cC): %d", tempCelcius, byte(0));
  String tempCelciusString = "Temp(C): " + String(tempCelcius);
  String tempFahrenheitString = "Temp(F): " + String(tempFahrenheit);
  String displayTempString = !detectButton(1) ? tempCelciusString : tempFahrenheitString;

  // Print the measured distance, temperature, and humidity
  // Serial.print(displayDistanceString + "\n");

  LCD1.setCursor(0, 0);
  LCD1.print(displayDistanceString);
  LCD2.setCursor(0, 0);
  LCD2.print(displayTempString);
  delay(300);
  LCD1.clear();
  LCD2.clear();
}