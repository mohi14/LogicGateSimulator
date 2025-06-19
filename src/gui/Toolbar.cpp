#include "Toolbar.h"
#include "utils/Constants.h"

Toolbar::Toolbar() {
    m_background.setSize(sf::Vector2f(Constants::WINDOW_WIDTH, Constants::TOOLBAR_HEIGHT));
    m_background.setFillColor(sf::Color(80, 80, 80));
    
    // Create buttons
    std::vector<std::string> buttonLabels = {"AND", "OR", "NOT", "SWITCH", "LED"};
    
    for (size_t i = 0; i < buttonLabels.size(); ++i) {
        sf::RectangleShape button;
        button.setSize(sf::Vector2f(90, 60));
        button.setPosition(sf::Vector2f(10 + i * 100, 10));
        button.setFillColor(sf::Color(120, 120, 120));
        button.setOutlineThickness(2);
        button.setOutlineColor(sf::Color::White);
        m_buttons.push_back(button);
        
        const sf::Font font("assets/fonts/arial.ttf");
        sf::Text label(font);
        label.setString(buttonLabels[i]);
        label.setCharacterSize(16);
        label.setFillColor(sf::Color::White);
        label.setPosition(sf::Vector2f(25 + i * 100, 35));
        m_buttonLabels.push_back(label);
    }
}

void Toolbar::render(sf::RenderWindow& window) {
    window.draw(m_background);
    
    for (size_t i = 0; i < m_buttons.size(); ++i) {
        window.draw(m_buttons[i]);
        window.draw(m_buttonLabels[i]);
    }
}