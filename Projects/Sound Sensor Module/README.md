This project demonstrates the use of a KY-037 High Sensitivity Sound Sensor Module to detect sound and display the sound level on an LCD1602.

## Live Demo
[comment]: # (insert video in the next line)

![Sound Sensor Module Pinout](./Sound%20Sensor%20Module%20Pinout.png)

## Wiring Diagram


![Wiring Diagram](./Sound%20Sensor%20Module%20Wiring%20Diagram.png)
## Circuit Schematic


![Circuit Schematic](./Sound%20Sensor%20Module%20Circuit%20Schematic.png)

## Components:
- 1 x Arduino Mega 2560 R3
- 1 x LCD1602 (non-i2c)
- 1 x 10k Potentiometer
- 1 x KY-037 High Sensitivity Sound Sensor Module

## Features:
- The Analog value of the sound level is displayed on the LCD1602.

## Learning Log:
- The A0 Analog output provides the real time sound level in analog voltage. The higher the sound level, the higher the voltage.
- The D0 Digital output provides a digital signal when the sound level exceeds the threshold set by the potentiometer. The threshold can be adjusted by turning the potentiometer.
- The module turned out to be defective :(. I've tested a KS0035 microphone from keyestudio which works. I've ordered a new one from ELEGOO and will move on from this project for now.
