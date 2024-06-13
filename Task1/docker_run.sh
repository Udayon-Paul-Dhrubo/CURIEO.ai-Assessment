#!/bin/bash

# Build the docker image
docker build -t task1 .

# Run the Docker container interactively
docker run -it --name task1 task1

# Copy the input and output files to the host
SRC_DIR="/usr/src/app"
DEST_DIR="./log"

#delete the log folder if it exists
rm -rf $DEST_DIR

docker cp task1:$SRC_DIR $DEST_DIR

# Stop and remove the Docker container
docker stop task1
docker rm task1