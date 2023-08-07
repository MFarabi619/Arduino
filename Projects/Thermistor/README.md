This project demonstrates the use of a thermistor to measure temperature. 

## Live Demo

![ Pinout](./Thermistor%20Pinout.png)

## Wiring Diagram

![Wiring Diagram](./Thermistor%20Wiring%20Diagram.png)

## Circuit Schematic

![Circuit Schematic](./Thermistor%20Circuit%20Schematic.png)

## Components

- 1 x Arduino Mega 2560 R3
- 1 x LCD1602 (non-i2c)
- 1 x 10k Potentiometer
- 1 x Thermistor

## Features

- When the thermistor is pinched by the fingers, the temperature increases and the resistance of the thermistor decreases. This causes the voltage across the thermistor to increase. The Arduino measures the voltage across the thermistor and calculates the temperature using the Steinhart-Hart equation. The temperature is then displayed on the LCD.

## Learning Log

- A thermistor is a resistor whose resistance changes with temperature. There are two types of thermistors: NTC(Negative Temperature Coefficient) and PTC(Positive Temperature Coefficient). NTC thermistors are the most common type of thermistors. The resistance of an NTC thermistor decreases as the temperature increases. The resistance of a PTC thermistor increases as the temperature increases.
- Technicallly all resistors are thermistors as their resistance changes slighly with temperatere, however the changes are so small that they are not noticable. Thermistors are designed to have a large change in resistance with a small change in temperature, making them ideal for temperature sensing applications.
- PTC thermistors are often used as overcurrent protection devices. When the current flowing through a PTC thermistor exceeds a certain threshold, the resistance of the PTC thermistor increases dramatically, limiting the current flowing through it and thus protecting the circuit.
- The temperature can be calculated using the Steinhart-Hart equation. The Steinhart-Hart equation is an empirical mathematical model for the resistance of a thermistor as a function of temperature. The Steinhart-Hart equation is given by: `1/T = a + b*ln(R) + c*(ln(R))^3` where `T` is the temperature in Kelvin, `R` is the resistance of the thermistor in Ohms, and `a`, `b`, and `c` are the Steinhart-Hart coefficients. The Steinhart-Hart coefficients are unique to each thermistor and can be found in the thermistor's datasheet. The Steinhart-Hart equation can be rearranged to give the temperature in degrees Celsius: `T = 1/(a + b*ln(R) + c*(ln(R))^3) - 273.15`. The Steinhart-Hart equation can be rearranged to give the temperature in degrees Fahrenheit: `T = 1/(a + b*ln(R) + c*(ln(R))^3) - 459.67`.
