// #include "FontManager.h"
// #include <stdexcept>

// sf::Font& FontManager::GetFont() {
//     static sf::Font font;
//     static bool loaded = false;

//     if (!loaded) {
//         if (!font.openFromFile("assets/fonts/arial.ttf")) {
//             throw std::runtime_error("Failed to load arial.ttf");
//         }
//         loaded = true;
//     }

//     return font;
// }

// utils/FontManager.cpp
#include "FontManager.h"
// Other includes if needed, e.g., for error handling or file paths

// Static member definitions (IMPORTANT!)
std::unique_ptr<sf::Font> FontManager::m_font = nullptr; // Or load it directly here if desired
bool FontManager::m_initialized = false; // Example

sf::Font& FontManager::GetFont() {
    if (!m_initialized) {
        m_font = std::make_unique<sf::Font>();
        // You need to load your font file here!
        if (!m_font->openFromFile("assets/fonts/arial.ttf")) { // <<< IMPORTANT: Replace with your actual font path
            // Handle error: e.g., print to console, throw exception, etc.
            // For now, let's assume it's critical.
            // std::cerr << "Error loading font!" << std::endl;
            // You might want to return a default font or throw an exception.
        }
        m_initialized = true;
    }
    return *m_font;
}

// Other FontManager function implementations if any