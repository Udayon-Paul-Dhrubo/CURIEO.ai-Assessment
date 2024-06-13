#!/bin/bash

INPUT_GENERATOR="input_generator.cpp"
SOLUTION="solution.cpp"

# compile the input_generator.c file
g++ $INPUT_GENERATOR -o input_generator
if [ $? -ne 0 ]; then
    echo "Error compiling input_generator."
    exit 1
fi

# compile the solution.c file
g++ $SOLUTION -o solution
if [ $? -ne 0 ]; then
    echo "Error compiling solution."
    exit 1
fi

# run the input generator
./input_generator
if [ $? -ne 0 ]; then
    echo "Error running input_generator."
    exit 1
fi

# run the solution
./solution
if [ $? -ne 0 ]; then
    echo "Error running solution."
    exit 1
fi

# remove the compiled files
rm -f input_generator
rm -f solution