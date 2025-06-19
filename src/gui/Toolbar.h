#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Toolbar {
public:
    Toolbar();
    void render(sf::RenderWindow& window);

private:
    sf::RectangleShape m_background;
    std::vector<sf::RectangleShape> m_buttons;
    std::vector<sf::Text> m_buttonLabels;
    sf::Font m_font;
};