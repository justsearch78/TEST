cmake_minimum_required(VERSION 3.10)
project(TestApp VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(test_app 
    src/main.cpp
)

# Optional: Add include directories if needed
# target_include_directories(test_app 
#     PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
# )

# Optional: Link libraries
# target_link_libraries(test_app 
#     some_library
# )

# Enable testing
enable_testing()
add_test(NAME MainTest COMMAND test_app)
