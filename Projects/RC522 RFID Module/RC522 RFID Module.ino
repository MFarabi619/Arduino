#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>
#include <LiquidCrystal.h>

#define SS_PIN 10
#define RST_PIN 9

//LiquidCrystal(RS, E, D4, D5, D6, D7)
LiquidCrystal LCD(2, 3, 4, 5, 6, 7);
int LCD_BACKLIGHT_PIN = 8; // pin for LCD backlight

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

void setup() 
{
    Serial.begin(9600);    // Initialize serial communications with the PC
    while (!Serial);       // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
    SPI.begin();           // Init SPI bus
    mfrc522.PCD_Init();    // Init MFRC522 card

    // initialize the LCD
    LCD.begin(16, 2);
    analogWrite(LCD_BACKLIGHT_PIN, 100);
}

void loop() 
{
    // Look for new cards
    if ( ! mfrc522.PICC_IsNewCardPresent()) 
    {
        return;
    }

    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial()) 
    {
        return;
    }

    // Show some details of the PICC (that is: the tag/card)
    Serial.print(F("Card UID:"));    //Dump UID
    for (byte i = 0; i < mfrc522.uid.size; i++) 
    {
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i], HEX);
    } 
    Serial.println();

    // Prepare key - all keys are set to FFFFFFFFFFFFh at chip delivery from the factory.
    MFRC522::MIFARE_Key key;
    for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;

    // Dump the whole card's data
    mfrc522.PICC_DumpToSerial(&(mfrc522.uid));

    // Print UID to LCD
    LCD.setCursor(0, 0);
    LCD.print("UID:");
    for (byte i = 0; i < mfrc522.uid.size; i++) 
    {
        LCD.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        LCD.print(mfrc522.uid.uidByte[i], HEX);
    }
    LCD.setCursor(0, 1);
    LCD.print("This is working");
    delay(1000);
    LCD.clear();
}