#!/bin/bash

# remove test files from 1 to 5
for i in {1..5}
do
    rm -f "input_$i.txt"
    rm -f "output_$i.txt"
done

rm -f "output_0.txt"

rm -rf "log"
