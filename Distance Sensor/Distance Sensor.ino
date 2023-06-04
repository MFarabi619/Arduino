#include <LiquidCrystal.h>

// LiquidCrystal(RS, E, D4, D5, D6, D7)
// RS, E, D4, D5, D6, D7 are the LCD pins.
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int LED_CONTRAST_PIN = 10;  // pin for contrast
int LED_BACKLIGHT_PIN = 11; // pin for backlight
int TRIGGER_PIN = 12;    // pin for distance sensor trigger
int ECHO_PIN = 13;       // pin for distance sensor echo
int BUTTON_PIN = 53; // pin for button
// const SPEEDOFSOUND = 0;
float duration, distanceMm, distanceIn = 0; // Variables for distance sensor
int buttonState, lastButtonState = HIGH;    // Variables for button state
bool isOn, isButtonPressed = false;         // Variables to check if button is pressed


void setup()
{
  analogWrite(LED_CONTRAST_PIN, 80);
  analogWrite(LED_BACKLIGHT_PIN, 255);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

bool detectButton(){
  // Read the current state of the button
  int reading = digitalRead(BUTTON_PIN);

  // Check if the button state has changed
  if (reading != lastButtonState) {
    if (reading == LOW) {
      isButtonPressed = true;  // Set the button press flag
    }
  }

  // Check if the button has been released
  if (isButtonPressed && reading == HIGH) {
    isButtonPressed = false;  // Reset the button press flag
    
    // Toggle the on/off state
    isOn = !isOn;
  }

  // Update the last button state for comparison in the next iteration
  lastButtonState = reading;
  return isOn;
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
  String displayString = detectButton() ? distanceInString : distanceMmString;


  // Calculate temperature in degrees Celsius
  

  // Print the measured distance, temperature, and humidity
  Serial.print(displayString + "\n");
  // Serial.print(distanceInString + "\n");

  lcd.setCursor(0, 0);
  lcd.print(displayString);
  // lcd.setCursor(0, 1);
  // lcd.print(distanceInString);
  delay(300);
  lcd.clear();
}