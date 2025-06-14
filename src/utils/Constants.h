#pragma once
#include <SFML/Graphics/Color.hpp>
namespace Constants
{
    constexpr int WINDOW_WIDTH = 1200;
    constexpr int WINDOW_HEIGHT = 800;
    constexpr int TOOLBAR_HEIGHT = 80;
    constexpr int COMPONENT_SIZE = 40;
    constexpr int GRID_SIZE = 20;

    // Colors

    const sf::Color BACKGROUND_COLOR(45, 45, 45);
    const sf::Color GRID_COLOR(70, 70, 70);
    const sf::Color WIRE_COLOR(255, 255, 0);
    const sf::Color COMPONENT_COLOR(200, 200, 200);
    const sf::Color ACTIVE_COLOR(0, 255, 0);
    const sf::Color INACTIVE_COLOR(128, 128, 128);
}