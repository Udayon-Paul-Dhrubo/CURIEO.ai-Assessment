# Use an official GCC compiler image as a parent image
FROM gcc:latest

# Set the working directory in the container
WORKDIR /usr/src/app

# Copy the current directory contents into the container at /usr/src/app
COPY . .

# Install any necessary packages
RUN apt-get update && apt-get install -y \
    cmake \
    make \
    && rm -rf /var/lib/apt/lists/*

# Run the executable via the run.sh script
CMD ["./run.sh"]
