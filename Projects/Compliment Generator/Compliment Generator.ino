#include "ComplimentGenerator.h"
const int textDelay = 300; // Time in milliseconds to delay between words

void setup() {
    Serial.begin(9600);
    LCD.begin(16, 2);

    pinMode(btnPrevious, INPUT_PULLUP);
    pinMode(btnNext, INPUT_PULLUP);
    pinMode(btnLevel, INPUT_PULLUP);

    displayWrappedText("Press to be rizzed :)");
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
    displayWrappedText(compliments[currentLevel][currentComplimentIndex]);
    isScrolling = false;
}

void displayWrappedText(const char* text) {
    int len = strlen(text);
    char line1[17], line2[17];
    memset(line1, ' ', 16); line1[16] = '\0';
    memset(line2, ' ', 16); line2[16] = '\0';
    int line1Pos = 0, line2Pos = 0;

    for (int pos = 0; pos < len; pos++) {
        // Find the end of the current word
        int wordEnd = pos;
        while (wordEnd < len && text[wordEnd] != ' ' && text[wordEnd] != '\n') {
            wordEnd++;
        }

        // Check if the word fits in the current line
        int wordLen = wordEnd - pos;
        if (line2Pos + wordLen > 16) {
            // Shift line2 to line1 and clear line2
            strncpy(line1, line2, 17);
            memset(line2, ' ', 16); line2[16] = '\0';
            line2Pos = 0;
        }

        // Print the word
        while (pos < wordEnd) {
            if (line2Pos < 16) {
                line2[line2Pos++] = text[pos];
            }
            pos++;
        }

        // Add a space after the word if there's space and it's not the end
        if (line2Pos < 16 && pos < len) {
            line2[line2Pos++] = ' ';
        }

        // Update the LCD
        LCD.clear();
        LCD.setCursor(0, 0);
        LCD.print(line1);
        LCD.setCursor(0, 1);
        LCD.print(line2);

        delay(textDelay); // Delay for readability
    }
}



void showLevelInfo() {
    LCD.clear();
    LCD.setCursor(0, 0);
    LCD.print(currentLevel + 1);
    switch (currentLevel) {
        case 0:
            displayWrappedText("Level 1: Nice & romantic :)");
            break;
        case 1:
            displayWrappedText("Level 2: Welcome to Rizztown ;)");
            break;
        case 2:
            displayWrappedText("Level 3: You asked for it o.O");
            break;
    }
    delay(1000);
}
