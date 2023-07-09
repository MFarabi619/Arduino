#!/bin/bash

# Find Wiring Diagram file
commit_file=$(git log --pretty=format: --name-only --diff-filter=AM -- '**/*Wiring Diagram.png' | grep -m 1 -F 'Wiring Diagram.png')
if [[ -n "$commit_file" ]]; then
  echo "Wiring Diagram file found: $commit_file"
else
  echo "No Wiring Diagram file found"
  exit 1
fi

# Extract subdirectory name
subdirectory=$(dirname "$commit_file")
echo "Subdirectory extracted: $subdirectory"

# Check if README.md exists
readme_file="$subdirectory/README.md"
if [[ -f "$readme_file" ]]; then
  echo "README.md file found: $readme_file"
else
  echo "README.md file not found in the subdirectory"
  exit 1
fi

# Insert Wiring Diagram image
if grep -qPzo '## Wiring Diagram\s*\n\s*\n\s*## Circuit Schematic' "$readme_file"; then
  image_path="./$(basename "$commit_file")"
  image_path="${image_path// /%20}"  # Replace spaces with %20
  image_line="![Wiring Diagram]($image_path)"
  sed -i -e '/## Wiring Diagram/{:a;N;/## Circuit Schematic/!ba;N;s/\n/&&/2}' -e "s|## Circuit Schematic|$image_line\n&|" "$readme_file"
  echo "Wiring Diagram file added to README.md between '## Wiring Diagram' and '## Circuit Schematic'"
else
  echo "The space between '## Wiring Diagram' and '## Circuit Schematic' is not empty"
fi

# Find Circuit Schematic file
circuit_schematic_file=$(find "$subdirectory" -maxdepth 1 -type f -iname '*Circuit Schematic*' | head -n 1)
if [[ -n "$circuit_schematic_file" ]]; then
  echo "Circuit Schematic file found: $circuit_schematic_file"
else
  echo "No Circuit Schematic file found"
  exit 1
fi

# Insert Circuit Schematic image
if grep -qPzo '## Circuit Schematic\s*\n\s*\n\s*## Components' "$readme_file"; then
  schematic_path="./$(basename "$circuit_schematic_file")"
  schematic_path="${schematic_path// /%20}"  # Replace spaces with %20
  schematic_line="![Circuit Schematic]($schematic_path)"
  sed -i -e '/## Circuit Schematic/{:a;N;/## Components/!ba;N;s/\n/&&/2}' -e "s|## Components|$schematic_line\n\n## Components|" "$readme_file"
  echo "Circuit Schematic file added to README.md after '## Circuit Schematic'"
else
  echo "The space between '## Circuit Schematic' and '## Components' is not empty"
fi
