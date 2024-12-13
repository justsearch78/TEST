#include <iostream>
#include <string>

class TestApp {
private:
    std::string appName;

public:
    TestApp(const std::string& name = "TestApp") : appName(name) {}

    void run() {
        std::cout << "Running " << appName << std::endl;
        std::cout << "Hello from TEST repository!" << std::endl;
    }

    std::string getAppName() const {
        return appName;
    }
};

int main() {
    TestApp app("MyTestApp");
    app.run();
    
    // Infinite loop to keep the application running
    while (true) {
        // The app does nothing here, but it keeps the container alive
        // You can also add more functionality here if needed
    }
    
    return 0;
}

