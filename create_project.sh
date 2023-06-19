#!/bin/bash

# Get the script's directory
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" &>/dev/null && pwd)"

# Check if a directory name was provided as an argument
if [ -z "$1" ]; then
    read -p "Enter the directory name: " directory_name
else
    directory_name="$1"
fi

# Create the directory
mkdir -p "${script_dir}/${directory_name}"

# Create example files within the directory
touch "${script_dir}/${directory_name}/file1.txt"
touch "${script_dir}/${directory_name}/file2.txt"

# Grant execution permissions to the script
chmod +x "${BASH_SOURCE[0]}"