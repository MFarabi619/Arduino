#!/bin/bash

# Find the latest commit that modified a file ending with 'Wiring Diagram.png'
commit_file=$(git log --pretty=format: --name-only --diff-filter=AM HEAD -- '*Wiring Diagram.png' | head -n 1)

if [[ -n "$commit_file" ]]; then
    echo "Wiring Diagram file found: $commit_file"

    # Extract the subdirectory name
    subdirectory=$(dirname "$commit_file")

    # Get the full path to the README.md file
    readme_file="$subdirectory/README.md"

    if [[ -f "$readme_file" ]]; then
        echo "README.md found: $readme_file"

        # Check if there is a section with '## Wiring Diagram' and empty space after it
        if grep -qPzo '## Wiring Diagram\n\n\n## Circuit Schematic' "$readme_file"; then
            # Insert the image file between the two sections
            image_line="![Wiring Diagram](./$(basename "$commit_file"))"
            sed -i "/## Wiring Diagram/a$image_line" "$readme_file"

            echo "Image file added to README.md between '## Wiring Diagram' and '## Circuit Schematic'"
        else
            echo "The space between '## Wiring Diagram' and '## Circuit Schematic' is not empty"
        fi
    else
        echo "README.md file not found in the subdirectory"
    fi
else
    echo "No Wiring Diagram file found in the latest commit"
    exit 1
fi
