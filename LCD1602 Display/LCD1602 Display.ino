//https://www.youtube.com/watch?v=Mr9FQKcrGpA&ab_channel=CircuitBasics

#include <LiquidCrystal.h>

// LiquidCrystal(RS, E, D4, D5, D6, D7)
// RS, E, D4, D5, D6, D7 are the LCD pins.
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char text[] = "Arduino ";
char text2[] = "is ";
char text3[] = "pog.";
char text4[] = "Arduino is pog.";

void setup()
{
    lcd.begin(16, 2);
    lcd.clear();
    delay(1000);
    lcd.print(text);
    delay(1000);
    lcd.clear();
    lcd.print(text2);
    delay(1000);
    lcd.clear();
    lcd.print(text3);
    delay(1000);
    lcd.clear();
}

void loop()
{
    lcd.print(text);
    delay(500);
    lcd.print(text2);
    delay(500);
    lcd.print(text3);
    delay(500);

unsigned int i = 0; // counter for the while loop

    // arduino for loop
     while(text4[i]!='\0'){
   lcd.print(text4[i]);
   
 	if(i>=16)
	{
          lcd.command(0x18); //Scrolling text to Right
        }
   delay(10);
   i++;
   } 


  // clear screen for the next loop:
  lcd.clear();
}