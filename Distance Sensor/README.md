This project demonstrates the use of and Ultrasonic Sensor to detect distance.

## Live Demo
[comment]: # (insert video in the next line)


![image](https://howtomechatronics.com/wp-content/uploads/2022/02/HC-SR04-Ultrasonic-Sensor-Dimensions-768x750.png?ezimgfmt=ng:webp/ngcb2)
![image](https://howtomechatronics.com/wp-content/uploads/2022/02/HC-SR04-Ultrasonic-Sensor-Pinout.png?ezimgfmt=ng:webp/ngcb2)
![image](https://howtomechatronics.com/wp-content/uploads/2022/01/How-Ultrasonic-Sensor-Working-Principle-Explained-768x394.jpg?ezimgfmt=ng:webp/ngcb2)
![image](https://howtomechatronics.com/wp-content/uploads/2015/07/Ultrasonic-Sensor-Diagram.png?ezimgfmt=ng:webp/ngcb2)
![image](https://howtomechatronics.com/wp-content/uploads/2022/01/How-Ultrasonic-Sensor-calculates-distance-from-object-768x535.jpg?ezimgfmt=ng:webp/ngcb2)


## Wiring Diagram
![Image of Circuit]()

## [Circuit Schematic]()
![image]()

## Components:
- Arduino Mega2560 R3
- HC-SR04 Ultrasonic Sensor
- AM2302 (DHT22) SIP Packaged Temperature and Humidity Sensor
- 1 x Blue Backlight LCD 1602 (non-i2c).
- 1 x Breadboard
- 18 x M-M Wires

## Features:
- The distance detected by the ultrasonic sensor is shown on the LCD 1602 display.
- While most tutorials use libraries and show the distance measured in centimeters, and does not take into account that the speed of sound is affected by the density of the air. The density of air is determined by temperature, pressure, and humidity. This project uses a temperature sensor to take those factors into account, and provide a much more accurate measurement, in millimeters.

## Learning Log:
- If the delay within the loop is too short, the value on the LCD constantly updates too quickly making it difficult to read. However a delay too high results in too long of wait for the value to update.
- Using solid core wires to make neater circuits instead of using dupont wires.
- Toggling between on/off states using a single push button, code can be found in the detectButton() function.
- 