#include "gui/Application.h"
#include <iostream>

int main() {
    try {
        Application app;
        app.test();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }
    
    return 0;
}