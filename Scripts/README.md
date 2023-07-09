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

- Locates the Fritzing program on the taskbar and opens it.
- Generates .png images of wiring diagram and circuit schematic.
- Renames the images with the project name and appended suffixes pertaining to the image.

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
- Locating a image on the screen using the `locateCenterOnScreen()` function.
- Clicking on a location on the screen using the `click()` function.
- Keyboard shortcuts using the `hotkey()` function.
- Keypress using the `press()` function.
- Typing text using the `typewrite()` function.
- Adding delay using the `sleep()` function.

## Learning Log for Github Actions

- To my understanding thus far, Github Actions is merely a yaml file that contains instructions. These instructions can be triggered by events such as a push to the repository, or a pull request.
  - Github then spins up a virutal machine to run the instructions, and then destroys the virtual machine once the instructions are completed.
  - The virtual machine is called a runner. The runner is the host for the job. A job is a set of steps that execute on the same runner. The runner can be hosted by Github, or self-hosted. 
  - The operating system of the runner can be Windows, Linux, or MacOS.
  - If Linux, the actions will be defined with bash commands. If Windows, the actions will be defined with Powershell commands and so on and so forth.
- Using the `actions/checkout@v2` action to checkout the repository.
- Fetch depth is 1 by default, which fetches the most recent commit. Setting it to 0 fetches all history.
- 