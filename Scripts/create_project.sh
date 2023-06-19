#!/bin/bash

# Get the directory of the script
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" &>/dev/null && pwd)"

# Check if a directory name was provided as an argument
if [ -z "$1" ]; then
    read -p "Enter the directory name: " directory_name
else
    directory_name="$1"
fi

# Create the directory
mkdir -p "${script_dir}/${directory_name}"

# Set permissions for the directory
chmod 755 "${script_dir}/${directory_name}"

# Create example files within the directory
touch "${script_dir}/${directory_name}/${directory_name}.ino"
touch "${script_dir}/${directory_name}/README.md"

# Set permissions for the example files
chmod 644 "${script_dir}/${directory_name}/${directory_name}.ino"
chmod 644 "${script_dir}/${directory_name}/README.md"

# Initialize README.md with content
# readme_content="## ${directory_name} \n\nWelcome to the ${directory_name} directory!"

readme_content="This project demonstrates the use of a 

## Live Demo
[comment]: # (insert video in the next line)


## Wiring Diagram
![Image of Circuit]()

## Circuit Schematic
![image]()

## Components:
- 1 x Arduino Mega 2560 R3
- 

## Features:
- 

## Learning Log:
- "

echo -e "$readme_content" > "${script_dir}/${directory_name}/README.md"

# Function to delete the directory
delete_directory() {
    read -p "Are you sure you want to delete the directory '${directory_name}'? (Y/N): " choice
    if [[ $choice == [Yy] ]]; then
        rm -rf "${script_dir}/${directory_name}"
        echo "Directory '${directory_name}' has been deleted."
    else
        echo "Deletion aborted."
    fi
}

# Prompt to delete the directory if created by mistake
read -p "Was the directory '${directory_name}' created by mistake? Do you want to delete it? (Y/N): " delete_choice
if [[ $delete_choice == [Yy] ]]; then
    delete_directory
fi