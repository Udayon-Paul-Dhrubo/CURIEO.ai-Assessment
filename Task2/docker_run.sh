#!/bin/bash

# Build the docker image
docker build -t task2 .

# Run the Docker container interactively
docker run -it --name task2 task2

# Copy the input and output files to the host
SRC_DIR="/usr/src/app"
DEST_DIR="./log"

#delete the log folder if it exists
rm -rf $DEST_DIR

docker cp task2:$SRC_DIR $DEST_DIR

# Stop and remove the Docker container
docker stop task2
docker rm task2