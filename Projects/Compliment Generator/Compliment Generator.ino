#include "ComplimentGenerator.h"

void setup() {
    Serial.begin(9600);
    LCD.begin(16, 2);

    pinMode(btnPrevious, INPUT_PULLUP);
    pinMode(btnNext, INPUT_PULLUP);
    pinMode(btnLevel, INPUT_PULLUP);

    displayWrappedText("Press to be rizzed :)", 300);
}

void loop() {
    if (!isScrolling && digitalRead(btnPrevious) == LOW) {
        currentComplimentIndex = (currentComplimentIndex - 1 + complimentsPerLevel) % complimentsPerLevel;
        Serial.println(currentComplimentIndex);
        updateDisplay();
        delay(200);
    }

    if (!isScrolling && digitalRead(btnNext) == LOW) {
        currentComplimentIndex = (currentComplimentIndex + 1) % complimentsPerLevel;
        Serial.println(currentComplimentIndex);
        updateDisplay();
        delay(200);
    }

    if (digitalRead(btnLevel) == LOW) {
        currentLevel = (currentLevel + 1) % levels;
        currentComplimentIndex = 0;
        Serial.println(currentLevel);
        showLevelInfo();
        delay(1000);
        LCD.clear();
    }
}

void updateDisplay() {
    isScrolling = true;
    LCD.clear();
    displayWrappedText(compliments[currentLevel][currentComplimentIndex], 300);
    isScrolling = false;
}

void displayWrappedText(const char* text, int delayTime) {
    int len = strlen(text);
    int pos = 0;
    int line = 0;
    int cursorPos = 0;
    LCD.clear();

    while (pos < len) {
        int nextSpace = pos;
        while (nextSpace < len && text[nextSpace] != ' ') nextSpace++;
        
        if (cursorPos + (nextSpace - pos) > 16 && cursorPos > 0) {
            line++;
            cursorPos = 0;
            if (line > 1) {
                delay(delayTime);
                LCD.clear();
                line = 0;
            }
        }

        LCD.setCursor(cursorPos, line);
        while (pos < nextSpace) {
            LCD.print(text[pos++]);
            cursorPos++;
        }

        if (pos < len) {
            LCD.print(' ');
            cursorPos++;
            if (cursorPos >= 16) {
                line++;
                cursorPos = 0;
                if (line > 1) {
                    delay(delayTime);
                    LCD.clear();
                    line = 0;
                }
            }
        }
        pos++;
    }
    delay(delayTime);
}


void showLevelInfo() {
    LCD.clear();
    LCD.setCursor(0, 0);
    LCD.print("Level: ");
    LCD.print(currentLevel + 1);
    LCD.setCursor(0, 1);
    switch (currentLevel) {
        case 0:
            LCD.print("Nice & romantic :)");
            break;
        case 1:
            LCD.print("Welcome to Rizztown ;)");
            break;
        case 2:
            LCD.print("You asked for it o.O");
            break;
    }
    delay(1000);
}
