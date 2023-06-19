#!/bin/bash
#
# Author: Mumtahin Farabi

# Main script flow
main() {
    check_projects_directory
    get_directory_name
    ask_lcd_requirement
    create_project_directory
    create_template_files
    generate_ino_file_content
    initialize_readme
    prompt_delete_directory
}

# Helper functions
check_projects_directory() {
    # Check if the 'Projects' directory exists
    if [ ! -d "$projects_dir" ]; then
        echo "'Projects' directory does not exist. Please create it or modify the script."
        exit 1
    fi
}

get_directory_name() {
    # Get the directory name
    read -p "Enter the directory name: " directory_name
}

ask_lcd_requirement() {
    # Ask if an LCD is necessary
    lcd_1602="- "
    read -p "Do you require an LCD1602 (non-i2c) with this project? (Y/N)" choice
    if [[ $choice == [Yy] ]]; then
        lcd_1602="- 1 x LCD1602 (non-i2c)
- 1 x 10k Potentiometer
- "
    fi
}

create_project_directory() {
    # Create the project directory inside the 'Projects' directory
    project_dir="$projects_dir/$directory_name"
    mkdir -p "$project_dir"
}

create_template_files() {
    # Create template files within the directory
    touch "$project_dir/$directory_name.ino"
    touch "$project_dir/README.md"
}

generate_ino_file_content() {
    # Generate the .ino file content
    if [[ $choice == [Yy] ]]; then
        cat >"$project_dir/$directory_name.ino" <<EOF
#include <LiquidCrystal.h>

// LiquidCrystal(RS, E, D4, D5, D6, D7)
// RS, E, D4, D5, D6, D7 are the LCD pins.
LiquidCrystal LCD(2, 3, 4, 5, 6, 7);
int LCD_BACKLIGHT_PIN = 8; // pin for LCD backlight

void setup()
{
    analogWrite(LCD_BACKLIGHT_PIN, 100);
    Serial.begin(9600);
    LCD.begin(16, 2);
}

void loop()
{
    LCD.setCursor(0, 0);
    LCD.print();
    LCD.setCursor(0, 1);
    LCD.print();
    Serial.println();
    delay(100);
    LCD.clear();
}
EOF
    else
        cat >"$project_dir/$directory_name.ino" <<EOF


void setup() {
  Serial.begin(9600);
}

void loop() {
    Serial.println();
}
EOF
    fi
}

initialize_readme() {
    # Initialize README.md with content
    readme_content=$(
        cat <<EOF
This project demonstrates the use of a 

## Live Demo
[comment]: # (insert video in the next line)


## Wiring Diagram
![Image of Circuit]()

## Circuit Schematic
![image]()

## Components:
- 1 x Arduino Mega 2560 R3
$lcd_1602

## Features:
- 

## Learning Log:
- 

EOF
    )
    echo -e "$readme_content" >"$project_dir/README.md"
}

delete_directory() {
    # Function to delete the directory
    read -p "Are you sure you want to delete the directory '$directory_name'? (Y/N): " choice
    if [[ $choice == [Yy] ]]; then
        rm -rf "$project_dir"
        echo "Directory '$directory_name' has been deleted."
    else
        echo "Deletion aborted."
    fi
}

prompt_delete_directory() {
    # Prompt to delete the directory if created by mistake
    read -p "Was the directory '$directory_name' created by mistake? Do you want to delete it? (Y/N): " delete_choice
    if [[ $delete_choice == [Yy] ]]; then
        delete_directory
    fi
}

# Get the directory of the script
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" &>/dev/null && pwd)"

# Determine the location of the 'Projects' directory relative to the script's location
projects_dir="$script_dir/../Projects"

# Call the main function
main
