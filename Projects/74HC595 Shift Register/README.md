This project demonstrates the use of a 74HC595 Serial-In, Parallel-Out Shift Register to control 8 LEDs. The purpose of a shift register is to reduce the number of pins required to control multiple devices. In this case, the shift register is used to control 8 LED's, but only 3 pins are used on the Arduino.

## Live Demo

![74HC595 Shift Register Pinout](./74HC595 Shift Register%20Pinout.png)

## Wiring Diagram

![Wiring Diagram](./74HC595%20Shift%20Register%20Wiring%20Diagram.png)

## Circuit Schematic

![Circuit Schematic](./74HC595%20Shift%20Register%20Circuit%20Schematic.png)

## Components

- 1 x Arduino Mega 2560 R3
- 1 x 74HC595/SN74HC595N Serial-In, Parallel-Out Shift Register
- 2 x 5 mm LED (Green)
- 2 x 5 mm LED (Red)
- 2 x 5 mm LED (Yellow)
- 2 x 5 mm LED (Blue)
- 8 x 220 Ω Resistor

## Features

- The 74HC595 Shift Register is used to control 8 LED's using only 3 pins on the Arduino. 
- The LED's light up one at a time, in a sequence, from left to right. When all 8 LED's are lit, they all turn off and the sequence starts over again.

## Learning Log

- A shift register is a type of sequential data logic circuit that works with binary numbers. It can "shift" the binary bits stored in its memory(register) to the left or right. It can also load binary data into its memory.
- The shift register is connected to the Arduino Mega 2560 R3 using 3 pins: `Data`, `Clock`, and `Latch`. The `Data` pin is used to send the data to the shift register, the `Clock` pin is used to tell the shift register when to read the data, and the `Latch` pin is used to tell the shift register when to output the data to the LED's.
- The clock pin needs to receive 8 pulses. At each pulse, if the data pin is high, then a 1 gets pushed into the shift register; otherwise, a 0. When all eight pulses have been received, enabling the 'Latch' pin copies those 8 values to the latch register. This is necessary; otherwise, the wrong LEDs would flicker as the data is being loaded into the shift register. The chip also has an output enable (OE) pin, which is used to enable or disable the outputs all at once. It is active low by default, and can be PWM controlled to adjust the brightness of the LED's.
- Serial Data Input means that the data is sent one bit at a time, in a sequence, over a single wire. Since the shift register is 8-bit, it takes 8 clock cycles to load up all the bits. Due to this, the LED's can only be changed about 500,000 times per second instead of 8,000,000 times per second, which is the maximum speed of the Arduino.
- Parallel Data Output means that the data is sent all at once, over multiple wires. In this case, 8 wires are used to send the data to the LED's.
