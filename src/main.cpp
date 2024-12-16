#include <iostream>
#include <string>
#include <thread>
#include <chrono>

class TestApp {
private:
    std::string appName;

public:
    TestApp(const std::string& name = "TestApp") : appName(name) {}

    void run() {
        std::cout << "Running " << appName << std::endl;
        std::cout << "Hello from TEST repository!" << std::endl;

        // Simulate a long-running process (e.g., server, worker)
        while (true) {
            // Simulate some work or waiting for a request
            std::this_thread::sleep_for(std::chrono::seconds(10)); // Sleep for 10 seconds
            std::cout << appName << " is still running..." << std::endl; // Output every 10 seconds
        }
    }

    std::string getAppName() const {
        return appName;
    }
};

int main() {
    TestApp app("MyTestApp");
    app.run(); // Start the app

    return 0; // This will never be reached as `run` has an infinite loop.
}

