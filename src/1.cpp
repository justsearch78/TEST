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
    return 0;
}
