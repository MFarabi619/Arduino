This project demonstrates the use of an infrared receiver module with a remote control. 

## Live Demo
[comment]: # (insert video in the next line)


https://github.com/MFarabi619/Arduino/assets/54924158/3ebdb722-29e9-4874-bfde-6082d0be79ff


## Wiring Diagram
![Image of Circuit](https://github.com/MFarabi619/Arduino/blob/main/Infrared%20Receiver%20+%20Remote/Infrared%20Receiver%20+%20Remote%20Wiring%20Diagram.png?raw=true)

## Circuit Schematic
![image](https://github.com/MFarabi619/Arduino/blob/main/Infrared%20Receiver%20+%20Remote/Infrared%20Receiver%20+%20Remote%20Schematic.png?raw=true)

## Components:
- 1 x Arduino Mega 2560 R3
- 1 x Infrared Receiver Module
- 1 x Infrared Remote Control

## Features:
- The Arduino can detect the signal sent by the remote control and perform an action based on the signal received.
- The received and de-modulated hex code is displayed on the LCD screen.

## Learning Log:
- IR receivers and transmitters can easily be thrown off with interferences from sunlight, and other light sources such as screens and LEDs. It is important to shield them as much as possible. 
- In this case, I've tried to eliminate as many interferences as possible, yet the hex outputs are still inconsistent.  
