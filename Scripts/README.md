# Scripts 

This folder contains a bash script that I wrote from scratch to automate the process of creating a new project folder with boilerplate files.

To run the script, ensure that you are located in the Arduino directory. Open a terminal and type `./Scripts/create_project.sh` and press enter.

There's also a Python script that uses PyAutoGUI to automate the process of generating wiring diagrams and circuit schematics from the fritzing file. To run the script, ensure that you are located in the Arduino directory. Open a terminal and type `python ./Scripts/generate_images.py` and press enter.

## Features of the Bash Script

- Asks you what you want to name your project.
- Asks if you want an LCD display for your project.
- Creates a new project folder in the 'Projects' directory.
- Creates a README.md file with the project name, and with the conditional LCD component.
- Makes a copy of a Fritzing file with the project name. The LCD and breadboard inclusion depend on the your choice.
- Provides the option to delete the folder if you wish to start over.

## Features of the Python Script

- Opens the Fritzing file.
- Generates .png images of wiring diagram and circuit schematic.

## Learning Log for Bash Script

- Using the `cd` command to change directories.
- Using variables in bash to store values.
- Using the `read` command to get user input.
- Using the `if` and `else` statements to create conditional logic.
- Using the `mkdir` command to create a new directory.
- Using the `cp` command to copy files.
- Using the `rm` command to remove files and directories.
- Using the `echo` command to write text to a file.
- Using the `touch` command to create a new file.
- Using the `>` and `>>` operators to write to a file.
- Using the `&&` operator to run multiple commands in a single line.
- Using bash functions to make code more readable and modular.

## Learning Log for Python Script

- Using the (PyAutoGUI)[https://pyautogui.readthedocs.io/en/latest/] library to automate GUI interactions using the mouse and keyboard that would otherwise be tedious.
