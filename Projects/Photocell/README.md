This project demonstrates the use of a photocell, also known as a photoresistor, or light-dependent resistor (LDR), or photoconductive cell, to measure the intensity of light. The photocell is connected to an analog input pin on the Arduino via a voltage divider configuration with a 10k resistor. The analog input pin is read and the value is displayed on an LCD1602 display.

## Live Demo

https://github.com/MFarabi619/Arduino/assets/54924158/2609c66f-19f2-4c51-a4ad-1a55ce264cfa

## Wiring Diagram

![Wiring Diagram](./Photocell%20Wiring%20Diagram.png)

## Circuit Schematic

![Circuit Schematic](./Photocell%20Circuit%20Schematic.png)

## Components

- 1 x Arduino Mega 2560 R3
- 1 x LCD1602 (non-i2c)
- 1 x 10k Potentiometer
- 1 x 10k Resistor
- 1 x Photocell

## Features

- The LCD display shows the analog value read from the photocell.

## Learning Log

- The photocell is a resistor that changes its resistance based on the intensity of light. The resistance decreases as the intensity of light increases. 
- The reason why a voltage divider configuration must be used is because the photocell is a variable resistor. If the photocell was connected directly to the analog input pin, the voltage would change based on the intensity of light. This would make it difficult to determine the intensity of light. By using a voltage divider configuration, the voltage is divided into a fixed ratio. This allows the analog input pin to read a fixed voltage value.
- Photocells have many applications, such as in automatic night lights, laser detection, solar panels, cameras, agricultural automation, and many more.
