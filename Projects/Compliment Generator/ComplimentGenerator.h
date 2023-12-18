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
const char *compliments[3][10] = {
    {"1. You have a really nice smile :)", "2. I really like listening to you speak, it's fun and easy to talk to you :)", "3. That jacket looks really good on you.", "4. You have a really attractive laugh.", "5. It's fun being around you.", "6. You're a good listener.", "7. You have really nice outfits.", "8. You look good with earrings.", "9. I like your full name, it's unique and I've never heard it before."},
    {"1. I find it hot that you dance.", "2. I really liked your top the first time we hung out :)", "3. You always smell really good.", "4. Your accented Bengali is adorable :)", "4. You look good from every angle.", "5. I find it hot that you have ADHD.", "6. I think it's hot that you speak Bengali.", "7. You have nice brown eyes, well-kept eyebrows, and great hair.", "8. You have a good sense of humor.", "9. I like your confidence."},
    {"1. You have a really nice rack.", "2. I wonder if your hair will look as good after I pull it.", "3. I think it's really hot that you're brown.", "4. Your neck looks delicious.", "5. Out of all your outfits, I think you'd look best in your birthday suit.", "6. They don't allow snacks at movies, how'd you get in while being a full course meal? ;)", "7. You should be Jasmine without the 'Jas' ;)", "8. I wonder which bed you'd look best in at IKEA ;)", "9. Out of all the curves on your body, your smile is my favourite :)"}};

const int levels = 3; // Total number of levels
const int complimentsPerLevel = 9; // Compliments per level

int currentLevel = 0;
int currentComplimentIndex = -1; // Set to -1 so that first press increments to first compliment
bool isScrolling = false;

const int textDelay = 300; // Time in milliseconds to delay between words

#endif // COMPLIMENT_GENERATOR.H