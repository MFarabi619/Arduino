This project is a simple demonstration of LEDs being controlled by digital output pins from the Arduino.

## [Live Demo]()

![Image of Circuit](https://github.com/MFarabi619/Arduino/blob/main/4%20LED%20Digital%20Output/4%20LED%20Digital%20Output.png)

## [Circuit Schematic](https://github.com/MFarabi619/Arduino/blob/main/4%20LED%20Digital%20Output/4%20LED%20Digital%20Output.pdf)

## Components:
- Arduino Uno.
- 4 x LED
  - 1 x red
  - 1 x green
  - 1 x yellow
  - 1 x white
- 5 x 3"(7.5cm) Male-Male Jumper wires/Solid Core Wires

## Features:

- Code can be modified to light up the LEDs for various durations and in various sequences.

## Learing Log:
- Followed [DRY](https://en.wikipedia.org/wiki/Don%27t_repeat_yourself) principle by creating a custom function called 'lightUpLEDs' which eliminates having to repeat the smae block of code 18 times.
- Used variables for pins that control the LEDs and the delay time, allowing for easier modification.
- Used a potentiometer to control the delay time by mapping the potentiometer resistance value to a lowerbound and upperbound.
