cmake_minimum_required(VERSION 3.10)
project(LogicGateSimulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML
find_package(SFML 3 REQUIRED COMPONENTS Graphics Audio Network)

# Include directories
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.cpp")


# Main executable
add_executable(LogicGateSimulator ${SOURCES})

# Link SFML
target_link_libraries(LogicGateSimulator PRIVATE SFML::Graphics SFML::Audio SFML::Network)

# Copy assets to build directory
add_custom_command(TARGET LogicGateSimulator POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/assets)

   
