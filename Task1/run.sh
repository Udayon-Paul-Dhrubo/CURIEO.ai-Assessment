#!/bin/bash

INPUT_GENERATOR="input_generator.cpp"
SOLUTION="solution.cpp"

# Compile the input_generator.cpp file
echo "Compiling $INPUT_GENERATOR..." | tee -a run.log
g++ $INPUT_GENERATOR -o input_generator 2>&1 | tee -a run.log
if [ $? -ne 0 ]; then
    echo "Error compiling $INPUT_GENERATOR." | tee -a run.log
    exit 1
fi

# Compile the solution.cpp file
echo "Compiling $SOLUTION..." | tee -a run.log
g++ $SOLUTION -o solution 2>&1 | tee -a run.log
if [ $? -ne 0 ]; then
    echo "Error compiling $SOLUTION." | tee -a run.log
    exit 1
fi

# Run the input generator
echo "Running input_generator..." | tee -a run.log
./input_generator 2>&1 | tee -a run.log
if [ $? -ne 0 ]; then
    echo "Error running input_generator." | tee -a run.log
    exit 1
fi

# Run the solution
echo "Running solution..." | tee -a run.log
./solution 2>&1 | tee -a run.log
if [ $? -ne 0 ]; then
    echo "Error running solution." | tee -a run.log
    exit 1
fi

# List generated files
echo "Listing generated files..." | tee -a run.log
ls -la | tee -a run.log
