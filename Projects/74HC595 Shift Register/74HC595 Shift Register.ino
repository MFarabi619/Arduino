int LATCHPIN = 11;
int CLOCKPIN = 9;
int DATAPIN = 12;
byte leds = 0;

void setup()
{
  pinMode(LATCHPIN, OUTPUT);
  pinMode(CLOCKPIN, OUTPUT);
  pinMode(DATAPIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println();
  leds = 0;
  updateShiftRegister();
  delay(500);
  for (int i = 0; i < 8; i++)
  {
    bitSet(leds, i);
    updateShiftRegister();
    delay(200);
  }
}

void updateShiftRegister()
{
  digitalWrite(LATCHPIN, LOW);
  shiftOut(DATAPIN, CLOCKPIN, LSBFIRST, leds);
  digitalWrite(LATCHPIN, HIGH);
}