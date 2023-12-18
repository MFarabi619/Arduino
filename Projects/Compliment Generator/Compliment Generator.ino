#include <LiquidCrystal.h>

LiquidCrystal LCD(2, 3, 4, 5, 6, 7);

// Define buttons
const int btnPrevious = 8;
const int btnNext = 9;
const int btnLevel = 10;

// Two-dimensional array for compliments
const char* compliments[3][2] = {
    {"L1: You're amazing!", "L1: You light up the room!"},
    {"L2: You're charming!", "L2: Your presence is felt!"},
    {"L3: You're captivating!", "L3: Your allure is strong!"}
};
const int levels = 3; // Total number of levels
const int complimentsPerLevel = 2; // Compliments per level

int currentLevel = 0;
int currentComplimentIndex = 0;

void setup() {
    Serial.begin(9600);
    LCD.begin(16, 2);

    pinMode(btnPrevious, INPUT_PULLUP);
    pinMode(btnNext, INPUT_PULLUP);
    pinMode(btnLevel, INPUT_PULLUP);

    updateDisplay();
}

void loop() {
    if (digitalRead(btnPrevious) == LOW) {
        // Previous compliment
        currentComplimentIndex = (currentComplimentIndex - 1 + complimentsPerLevel) % complimentsPerLevel;
        Serial.print("Previous: ");
        Serial.println(currentComplimentIndex);
        updateDisplay();
        delay(200); // Debounce delay
    }
    if (digitalRead(btnNext) == LOW) {
        // Next compliment
        currentComplimentIndex = (currentComplimentIndex + 1) % complimentsPerLevel;
        Serial.print("Next: ");
        Serial.println(currentComplimentIndex);
        updateDisplay();
        delay(200); // Debounce delay
    }
    if (digitalRead(btnLevel) == LOW) {
        // Change level
        currentLevel = (currentLevel + 1) % levels;
        currentComplimentIndex = 0; // Reset to first compliment of the new level
        Serial.print("Level: ");
        Serial.println(currentLevel+1);
        updateDisplay();
        delay(200); // Debounce delay
    }
}

void updateDisplay() {
    LCD.clear();
    scrollText(compliments[currentLevel][currentComplimentIndex], 0, 16, 300);
}

void scrollText(const char* text, int row, int width, int delayTime) {
    int len = strlen(text);
    if (len <= width) {
        LCD.setCursor((width - len) / 2, row); // Center the text if it's short
        LCD.print(text);
    } else {
        for (int pos = 0; pos <= len - width; pos++) {
            LCD.setCursor(0, row);
            for (int i = 0; i < width; i++) {
                LCD.print(text[pos + i]);
            }
            delay(delayTime);
            LCD.clear();
        }
    }
}
