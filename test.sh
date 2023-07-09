#!/bin/bash

# Find Wiring Diagram file
commit_file=$(git log --pretty=format: --name-only --diff-filter=AM HEAD -- '*Wiring Diagram.png' | head -n 1)
if [[ -n "$commit_file" ]]; then
  echo "Wiring Diagram file found: $commit_file"
else
  echo "No Wiring Diagram file found in the latest commit"
  exit 1
fi

# Extract subdirectory name
file_path="$commit_file"
subdirectory=$(dirname "$file_path")
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
  image_line="![Wiring Diagram](./$(basename "$commit_file"))"
  sed -i -e '/## Wiring Diagram/{:a;N;/## Circuit Schematic/!ba;N;s/\n/&&/2}' -e "s|## Circuit Schematic|$image_line\n&|" "$readme_file"
  echo "Image file added to README.md between '## Wiring Diagram' and '## Circuit Schematic'"
else
  echo "The space between '## Wiring Diagram' and '## Circuit Schematic' is not empty"
fi

# Commit changes
# git config user.name "GitHub Actions"
# git config user.email "<>"
# git add .
# git commit -m "Add Wiring Diagram to README" --author="GitHub Actions <>"
