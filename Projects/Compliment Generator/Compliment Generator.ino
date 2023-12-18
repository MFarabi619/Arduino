#include "ComplimentGenerator.h"

bool firstPress = true;

void setup() {
    Serial.begin(9600);
    LCD.begin(16, 2);

    pinMode(btnPrevious, INPUT_PULLUP);
    pinMode(btnNext, INPUT_PULLUP);
    pinMode(btnLevel, INPUT_PULLUP);

    displayWrappedText("Press a button to be rizzed :)");
}

void loop() {
    if (!isScrolling && digitalRead(btnPrevious) == LOW) {
        if (firstPress) {
            showLevelInfo();
            firstPress = false;
        }
        else{
        Serial.println(currentComplimentIndex);
        updateDisplay();
        currentComplimentIndex = (currentComplimentIndex - 1 + complimentsPerLevel) % complimentsPerLevel;
        delay(200);
    }
    }

    if (!isScrolling && digitalRead(btnNext) == LOW) {
        if (firstPress) {
            showLevelInfo();
            firstPress = false;
        }
        else{
        Serial.println(currentComplimentIndex);
        updateDisplay();
        currentComplimentIndex = (currentComplimentIndex + 1) % complimentsPerLevel;
        delay(200);
        }
    }

    if (digitalRead(btnLevel) == LOW) {
        if (firstPress) {
            showLevelInfo();
            firstPress = false;
        }
        else{
        currentLevel = (currentLevel + 1) % levels;
        currentComplimentIndex = 0;
        Serial.println(currentLevel);
        showLevelInfo();
        delay(1000);
        }
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
    memset(line1, '\0', 17);
    memset(line2, '\0', 17);
    int line1Pos = 0, line2Pos = 0;

    for (int pos = 0; pos < len; ) {
        // Find the end of the current word or handle newline
        int wordEnd = pos;
        while (wordEnd < len && text[wordEnd] != ' ' && text[wordEnd] != '\n') {
            wordEnd++;
        }

        // Check if the word fits in the current line
        int wordLen = wordEnd - pos;
        if (line2Pos + wordLen >= 16) {
            // Shift the contents of line 2 to line 1, and clear line 2
            strcpy(line1, line2);
            memset(line2, '\0', 17);
            line2Pos = 0;
        }

        // Print the word
        while (pos < wordEnd) {
            if (line2Pos < 16) {
                line2[line2Pos++] = text[pos++];
            }
        }

        // Add a space after the word if there's space and it's not the end
        if (pos < len && line2Pos < 16) {
            line2[line2Pos++] = ' ';
            pos++;
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
            displayWrappedText("Level 3: You asked for it...");
            break;
    }
}
