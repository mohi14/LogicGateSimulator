#include "Canvas.h"
#include "utils/Constants.h"

Canvas::Canvas() {
    m_background.setSize(sf::Vector2f(Constants::WINDOW_WIDTH, 
                                     Constants::WINDOW_HEIGHT - Constants::TOOLBAR_HEIGHT));
    m_background.setPosition(sf::Vector2f(0.f, Constants::TOOLBAR_HEIGHT));
    m_background.setFillColor(Constants::BACKGROUND_COLOR);
}

void Canvas::render(sf::RenderWindow& window) {
    window.draw(m_background);
}