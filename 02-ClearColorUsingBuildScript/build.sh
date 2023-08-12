#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Usage: ./build.sh <filename>"
    exit 1
fi

filename="$1"
echo "${filename} is being processed"

# Remove extension from file name
executable="${filename%.*}"
echo "${executable} Executable Generated"

# Compile and link the program
g++ "$filename" -o "$executable" \
    -I/opt/homebrew/Cellar/glfw/3.3.8/include \
    -I/opt/homebrew/Cellar/glew/2.2.0_1/include \
    -L/opt/homebrew/Cellar/glfw/3.3.8/lib -lglfw \
    -L/opt/homebrew/Cellar/glew/2.2.0_1/lib -lGLEW \
    -framework OpenGL

# Run the compiled program
# ./OpenGLApp
