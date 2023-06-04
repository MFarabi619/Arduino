This project demonstrates the use of an Ultrasonic Sensor and Temperature + Humidity Sensor to measure distance.

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
- While most tutorials use libraries and show the distance measured in centimeters, and does not take into account that the speed of sound is affected by the density of the air. The density of air is determined by temperature, pressure, and humidity. This project uses a temperature sensor to take those factors into account, and provide a much more accurate measurement, in millimeters to two decimal places.
- The units of display can be changed between metric and imperial by the two buttons, with the top button changing distance and the buttom button changing temperature.
- A single potentiometer control the contrast on both LCD displays.

## Learning Log:
- If the delay within the loop is too short, the value on the LCD updates too quickly making it difficult to read. However a delay too high results in too long of wait for the value to update.
- Using solid core wires to make neater circuits instead of using dupont wires.
- The degree symbol cannot be displayed on the LCD 1602 display, and I'm still trying to find out why exactly. Instead, the letter 'C' is used to represent degrees Celsius.
  - I've tried making a custom symbol using the byte array and storing it in the LCD memory, but it displays '3' instead of the degree symbol.
- The anode pin (A) on the LCD1 is connected to LCD2 instead of taking up another arduino pin. This also eliminates 4 lines of code.
- Toggling between on/off states using a single push button, and keeping track of what the previous state was. Code can be found in the detectButton() function.
  - This was the most challenging part of the project. The buttons and their variables are stored in arrays, and the function takes in the array index as an argument. The function returns a boolean value, and the value is stored in the previous state variable. The previous state variable is then used to determine if the button was pressed or not.
  - This was also the most valuable takeaway from this project, as arrays are very useful for keeping track of many of the same component.
- This is first project where the standard line of PWM pins were not enough to control all the components.  
  - Instead of running the V0 pins of the LCDs into separate arduino pins, they are connected to the V0 pins of each other. A single potentiometer is connected in parallel to both V0 pins. This allows the to control the contrast of both LCDs at the same time. The brightness of LCD1 is also connected to LCD2. This saves 2 arduino pins.
  - I was also forced to switch over to Fritzing, as Tinkercad does not have the Arduino MEGA2560 R3.