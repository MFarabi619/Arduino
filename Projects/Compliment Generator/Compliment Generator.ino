#include <LiquidCrystal.h>

LiquidCrystal LCD(2, 3, 4, 5, 6, 7);

// Define buttons
const int btnPrevious = 8;
const int btnNext = 9;
const int btnLevel = 10;

// Two-dimensional array for compliments
const char* compliments[3][10] = {
    {"You have a nice smile :)", "I like listening to you talk :)", "You have a really nice jacket.", "You have a really attractive laugh.", "It's fun being around you."},
    {"I find it hot that you used to dance.", "I really liked the top the first time we hung out :)", "You always smell really good.","Your Bengali accent is adorable :)", "You look good from every angle."},
    {"You have massive tits.", "I wonder if your hair will look as good after I pull it.","I think it's really hot that you're brown.", "Your neck looks delicious.", ""}
};
const int levels = 3; // Total number of levels
const int complimentsPerLevel = 5; // Compliments per level

int currentLevel = 0;
int currentComplimentIndex = 0;
bool isScrolling = false;

void setup() {
    Serial.begin(9600);
    LCD.begin(16, 2);

    pinMode(btnPrevious, INPUT_PULLUP);
    pinMode(btnNext, INPUT_PULLUP);
    pinMode(btnLevel, INPUT_PULLUP);

    LCD.print("Press to be rizzed.");
}

void loop() {
    if (!isScrolling && digitalRead(btnPrevious) == LOW) {
        // Previous compliment
        currentComplimentIndex = (currentComplimentIndex - 1 + complimentsPerLevel) % complimentsPerLevel;
        Serial.println(currentComplimentIndex);
        updateDisplay();
        // delay(200); // Debounce delay
    }
    if (!isScrolling && digitalRead(btnNext) == LOW) {
        // Next compliment
        currentComplimentIndex = (currentComplimentIndex + 1) % complimentsPerLevel;
        Serial.println(currentComplimentIndex);
        updateDisplay();
        // delay(200); // Debounce delay
    }
    if (digitalRead(btnLevel) == LOW) {
        // Change level
        currentLevel = (currentLevel + 1) % levels;
        currentComplimentIndex = 0; // Reset to first compliment of the new level
        Serial.println(currentLevel);
        showLevelInfo();
        // delay(200); // Debounce delay
        delay(1000);
        LCD.clear();
    }
}

void updateDisplay() {
    isScrolling = true;
    LCD.clear();
    scrollText(compliments[currentLevel][currentComplimentIndex], 0, 16, 300);
    isScrolling = false;
}

void scrollText(const char* text, int row, int width, int delayTime) {
    int len = strlen(text);
    if (len <= width) {
        LCD.setCursor((width - len) / 2, row); // Center the text if it's short
        LCD.print(text);
    } else {
        for (int pos = 0; pos <= len - width; pos++) {
            if (!isScrolling) return; // Interrupt scrolling if needed
            LCD.setCursor(0, row);
            for (int i = 0; i < width; i++) {
                LCD.print(text[pos + i]);
            }
            delay(delayTime);
            LCD.clear();
        }
    }
}

void showLevelInfo() {
    LCD.clear();
    LCD.setCursor(0, 0);
    LCD.print("Level: ");
    LCD.print(currentLevel + 1);
    LCD.setCursor(0, 1);
    switch (currentLevel) {
        case 0:
            LCD.print("Nice and Romantic :)");
            break;
        case 1:
            LCD.print("Welcome to Rizztown ;)");
            break;
        case 2:
            LCD.print("You asked for it o.O");
            break;
    }
    delay(1000); // Display level info for 2 seconds
}
