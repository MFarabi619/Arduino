# Arduino
 A collection of both major and minor projects using Arduino platforms. While most of the projects right now are pretty simple and only use a few components, they act as modular pieces of documentation and code snippets than can be put together for larger, more complex projects. The code snippets are particularly useful for testing individual modules and components. 
 
## Tooling
While the Arduino IDEs 1 and 2 are great in their simplicity, they didn't feel very modern. So I simply used VScode with the [Arduino extension](https://marketplace.visualstudio.com/items?itemName=vsciot-vscode.vscode-arduino) for development. If you're doing the same, ensure to do the following first:
- Set programmer to AVRISP mkII.
- Select the sketch you wish to run.
- Select the right board.
- Select the right port. The port on your machine may be different.
- Import the necessary libraries.
- All options can found by doing: F1 -> type 'Arduino' to see available options. 
![image](https://user-images.githubusercontent.com/54924158/231327984-95a65182-3c7b-4cb9-a78a-b0e8d6f90ba3.png)


- [Tinkercad](https://www.tinkercad.com) was initially used for the following:
  - Visualizing project setup with wiring diagram.
  - Creating circuit schematic.
  - Running simulations.
  - Generating electrical design files (.bsd).

- Tinkercad does not have an Arduino Mega2560 R3 component, it only has Arduino Uno R3. Therefore, the wiring diagrams and schematics for older projects using the Mega will show the Uno. This is completely fine as the pins used are still the same, and therefore the same code will run fine on both boards.

- [Fritzing](https://fritzing.org/download/) was used from the [Distance Sensor](https://github.com/MFarabi619/Arduino/tree/main/Distance%20Sensor) project onwards, as Tinkercad is missing multiple components and modules, including Arduino Mega2560.
  
## [Distance Sensor](https://github.com/MFarabi619/Arduino/tree/main/Projects/Distance%20Sensor)

https://github.com/MFarabi619/Arduino/assets/54924158/8fe3bead-c41e-4541-ba90-a2ac9c383b3b

  
## [LCD 1602](https://github.com/MFarabi619/Arduino/tree/main/LCD1602%20Display)

https://user-images.githubusercontent.com/54924158/231330322-2b5b7fa4-daf5-4e01-8ea5-95d3f4cfc350.mp4

![Image of LCD 1602](https://github.com/MFarabi619/Arduino/blob/main/LCD1602%20Display/LCD%201602%20Display.png)

## [4 LED Digital Output](https://github.com/MFarabi619/Arduino/tree/main/4%20LED%20Digital%20Output)

https://github.com/MFarabi619/Arduino/assets/54924158/e07f13b3-4df9-41dc-9b0b-30ab8398520f

![Image of 4 LED Digital Output](https://github.com/MFarabi619/Arduino/blob/main/4%20LED%20Digital%20Output/4%20LED%20Digital%20Output.png)

## [Push Button Switch LED](https://github.com/MFarabi619/Arduino/tree/main/Push%20Button%20Switch%20LED)

https://user-images.githubusercontent.com/54924158/232171713-8efb37fe-c0d2-45df-a8a4-03ae87954c85.mp4

![image](https://user-images.githubusercontent.com/54924158/232171820-d6178fe3-2c39-4130-a487-02f989d90e91.png)

## [RGB LED](https://github.com/MFarabi619/Arduino/tree/main/RGB%20LED)

https://user-images.githubusercontent.com/54924158/232158642-ada9c5c4-f8f6-4044-a5dd-5fd247b1f05f.mp4

![image](https://user-images.githubusercontent.com/54924158/232158956-50b3b435-29e4-4c6f-ae85-a42f2e9bf9e3.png)
