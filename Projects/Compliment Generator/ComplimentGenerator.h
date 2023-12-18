// COMPLIMENT_GENERATOR.H
#ifndef COMPLIMENT_GENERATOR_H
#define COMPLIMENT_GENERATOR_H

#include <LiquidCrystal.h>

LiquidCrystal LCD(2, 3, 4, 5, 6, 7);

// Define buttons
const int btnPrevious = 8;
const int btnNext = 9;
const int btnLevel = 10;

// Two-dimensional array for compliments
const char* compliments[3][10] = {
    {"You have a nice smile :)", "I like listening to you talk :)", "You have a really nice jacket.", "You have a really attractive laugh.", "It's fun being around you.", "You're a good listener.","You have really nice outfits."},
    {"I find it hot that you used to dance.", "I really liked your top the first time we hung out :)", "You always smell really good.","Your Bengali accent is adorable :)", "You look good from every angle.", "I find it hot that you have ADHD."},
    {"You have massive tits.", "I wonder if your hair will look as good after I pull it.","I think it's really hot that you're brown.", "Your neck looks delicious.", ""}
};
const int levels = 3; // Total number of levels
const int complimentsPerLevel = 7; // Compliments per level

int currentLevel = 0;
int currentComplimentIndex = 0;
bool isScrolling = false;

#endif // COMPLIMENT_GENERATOR.H