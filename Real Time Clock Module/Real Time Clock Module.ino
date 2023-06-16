#include <LiquidCrystal.h>
#include <Wire.h>
#include <DS3231.h>

// LiquidCrystal(RS, E, D4, D5, D6, D7)
// RS, E, D4, D5, D6, D7 are the LCD pins.
LiquidCrystal LCD(2, 3, 4, 5, 6, 7);
int LCD_BACKLIGHT_PIN = 8; // pin for LCD backlight
String date = "";
String time = "";

DS3231 clock;
RTCDateTime dt;

void setup()
{
    analogWrite(LCD_BACKLIGHT_PIN, 100);
    LCD.begin(16, 2);

    Wire.begin(); // Initiate the Wire library

    Serial.println("Initialize RTC module");
    // Initialize DS3231
    clock.begin();

    // Manual (YYYY, MM, DD, HH, II, SS
    // clock.setDateTime(2016, 12, 9, 11, 46, 00);

    // Send sketch compiling time to Arduino
    clock.setDateTime(__DATE__, __TIME__);
    /*
    Tips:This command will be executed every time when Arduino restarts.
         Comment this line out to store the memory of DS3231 module
    */
    delay(2000);
    Serial.begin(9600);
}

void loop()
{
    dt = clock.getDateTime();
    date = "Date: " + String(dt.year) + "-" + String(dt.month) + "-" + String(dt.day);
    time = "Time: " + String(dt.hour) + ":" + String(dt.minute) + ":" + String(dt.second);

    // Serial.print(dt.year+"-"+dt.month+"-"+dt.day+" "+dt.hour+":"+dt.minute+":"+dt.second);
    Serial.print(date + " " + time);

    LCD.setCursor(0, 0);
    LCD.print(date);
    LCD.setCursor(0, 1);
    LCD.print(time);
    delay(100);
    LCD.clear();
}