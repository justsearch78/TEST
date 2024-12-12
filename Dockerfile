# Use an official build environment
FROM gcc:latest

# Set the working directory
WORKDIR /app

# Copy the source code into the container
COPY . .

# Install CMake
RUN apt-get update && apt-get install -y cmake

# Build the application
RUN cmake . && make

# Run the application
CMD ["./hello-world"]

