# Use an official Ubuntu runtime as a parent image
FROM ubuntu:20.04

# Avoid prompts from apt
ENV DEBIAN_FRONTEND=noninteractive

# Install necessary dependencies
RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    make \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory in the container
WORKDIR /app

# Copy the project files
COPY . .

# Build the application
RUN mkdir -p build \
    && cd build \
    && cmake .. \
    && make

# Expose port if your application runs a server
EXPOSE 5000

# Define environment variable
ENV APP_NAME "TestApp"

# Run the executable and keep container running
CMD ["/bin/bash", "-c", "./build/test_app && tail -f /dev/null"]
