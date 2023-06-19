#!/bin/bash

# Get the directory of the script
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" &>/dev/null && pwd)"

# Determine the location of the 'Projects' directory relative to the script's location
projects_dir="$script_dir/../Projects"

# Check if the 'Projects' directory exists
if [ ! -d "$projects_dir" ]; then
    echo "'Projects' directory does not exist. Please create it or modify the script."
    exit 1
fi

# Get the directory name
read -p "Enter the directory name: " directory_name

# Ask if an LCD is necessary
lcd_1602="- "
# Function to add LCD1602 (non-i2c) display to README
add_lcd() {
    read -p "Do you require an LCD1602 (non-i2c) with this project? (Y/N)" choice
    if [[ $choice == [Yy] ]]; then
        lcd_1602=$(
            cat <<EOF
- 1 x LCD1602 (non-i2c)
- 1 x 10k Potentiometer
- 
EOF
        )
    fi
}

add_lcd

# Create the directory inside the 'Projects' directory
project_dir="$projects_dir/$directory_name"
mkdir -p "$project_dir"

# Create template files within the directory
# TODO: Insert boilerplate code to .ino file. Will vary depending on LCD.
touch "$project_dir/$directory_name.ino"
touch "$project_dir/README.md"

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

# Function to delete the directory
delete_directory() {
    read -p "Are you sure you want to delete the directory '$directory_name'? (Y/N): " choice
    if [[ $choice == [Yy] ]]; then
        rm -rf "$project_dir"
        echo "Directory '$directory_name' has been deleted."
    else
        echo "Deletion aborted."
    fi
}

# Prompt to delete the directory if created by mistake
read -p "Was the directory '$directory_name' created by mistake? Do you want to delete it? (Y/N): " delete_choice
if [[ $delete_choice == [Yy] ]]; then
    delete_directory
fi
