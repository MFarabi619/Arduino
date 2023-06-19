This project demonstrates the use of a servo motor.

## Live Demo
[comment]: # (insert video in the next line)


https://github.com/MFarabi619/Arduino/assets/54924158/814f29aa-af45-4e74-a39c-6d6cc8bfc253


https://github.com/MFarabi619/Arduino/assets/54924158/50c7830d-9980-455f-ab0e-d5dadb8f7c8a


![image](https://m.media-amazon.com/images/S/aplus-media/sc/ba887ddd-c43b-4093-b78c-631d86e73f5b.__CR0,0,970,600_PT0_SX970_V1___.jpg)
![image](https://components101.com/sites/default/files/component_pin/Servo-Motor-Wires.png)

## Wiring Diagram
![image](https://github.com/MFarabi619/Arduino/assets/54924158/9e0179b7-70b1-48e9-94dc-3e4b43386df0)

## [Circuit Schematic](https://github.com/MFarabi619/Arduino/blob/main/Servo%20Motor/Servo%20Motor%20Circuit%20Schematic.pdf)
![image](https://github.com/MFarabi619/Arduino/assets/54924158/8cde479a-755e-4aaf-84b2-755e8ae3c40f)

## Components:
- 1 X Arduino Mega 2560 R3
- 1 x SG90 Micro Servo Motor 
- 1 x Small Breadboard
- 1 x 10K Potentiometer 
- 7 x M-M wires

## Features:
- The servo motor can be controlled by the potentiometer.
- The servo motor can also be made to sweep side to side. The code is included. Simply comment out the potentiometer code and uncomment the sweep code.

## Learning Log:
- The position of the servo motor rotor is determined by the pulses of electricity sent to it. 
- The SG90 servo motor has a built-in closed-loop feedback system to consistenly correct the rotor's position. It continously checks if the current angle of the rotor is different from the target angle of the rotor. A potentiometer acts as the position feedback sensor and the output shaft of the servo is mechanically connected to this potentiometer. The internal control circuit receives the voltage from the potentiometer and adjusts the motor's power to ensure it stays on the target angle. However this is a very basic mechanism and does not provide as much precision as a well-tuned PID controller.