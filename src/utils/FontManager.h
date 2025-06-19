#pragma once
// #include <SFML/Graphics.hpp>

// class FontManager {
// public:
//     static sf::Font& GetFont();
// };
#include <SFML/Graphics/Font.hpp>
#include <memory>

class FontManager {
public:
    static sf::Font& GetFont(); // Make sure this declaration exists
    // Other static methods/members if any
private:
    static std::unique_ptr<sf::Font> m_font; // Example private member for the font
    static bool m_initialized; // Example
};