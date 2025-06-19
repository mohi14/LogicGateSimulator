#pragma once
#include <SFML/Graphics.hpp>

class Canvas {
public:
    Canvas();
    void render(sf::RenderWindow& window);

private:
    sf::RectangleShape m_background;
};