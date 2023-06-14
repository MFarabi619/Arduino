This project demonstrates the use of an HC-SR501 PIR Motion Sensor.

## Live Demo
[comment]: # (insert video in the next line)


https://github.com/MFarabi619/Arduino/assets/54924158/2912fd46-f548-4a37-a1fc-792a34e10e8b


![image](https://github.com/MFarabi619/Arduino/assets/54924158/38beda4c-3217-4157-b14e-236093a2a07f)
![image](https://github.com/MFarabi619/Arduino/assets/54924158/eb08eac8-16f4-4749-9cec-2339f13409f0)
![image](https://github.com/MFarabi619/Arduino/assets/54924158/f82ae13f-492d-4dcf-a9d1-b08c4fa7e94b)
![image](https://github.com/MFarabi619/Arduino/assets/54924158/7c12cb8b-d6b0-4134-8d35-94ec1c8fc2d4)
![image](https://github.com/MFarabi619/Arduino/assets/54924158/a43dd391-f31e-471b-93bf-b619e02178c4)
![image](https://github.com/MFarabi619/Arduino/assets/54924158/59c82f05-05de-439e-b6d7-b195e1ea35af)


## Wiring Diagram
![Image of Circuit](https://github.com/MFarabi619/Arduino/blob/main/Motion%20Sensor/Motion%20Sensor%20Wiring%20Diagram.png?raw=true)

## Circuit Schematic
![image](https://github.com/MFarabi619/Arduino/blob/main/Motion%20Sensor/Motion%20Sensor%20Circuit%20Schematic.png?raw=true)

## Components:
- 1 x Arduino Mega 2560 R3
- 1 x HC-SR501 PIR Motion Sensor

## Features:
- The sensor detects motion and can be calibrated to different distances and durations for detection.

## Learning Log:
- PIR stands for 'Passive Infrared Sensor'. Living beings emit heat in the form of infrared radiation/light, which is detected by the sensor. It is called passive because the sensor isn't outputting any energy to detect the objects, but rather receiving emitted energy from other objects to detect them.
- The white cover on the module is called a 'Fresnel Lens', which focuses the infrared signals onto the piezo-electric sensor. 
- Upon receiving power, the sensor will take 1 minute to calibrate. During this time, the sensor will be very sensitive to motion and will trigger the output pin. This is normal and should be expected.
- At the repeat trigger selector area, the pins are soldered. Not really sure how to use it.
