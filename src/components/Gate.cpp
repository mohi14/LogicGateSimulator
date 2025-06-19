#include "Gate.h"
#include "utils/Constants.h"

Gate::Gate(ComponentType type, Vector2f position) : Component(type, position) {
    m_shape.setFillColor(sf::Color(150, 150, 200));
}

void Gate::render(sf::RenderWindow& window) {
    window.draw(m_shape);
    window.draw(m_label);
}

void Gate::setupLabel(const std::string& text) {
    m_label.setString(text);
    m_label.setCharacterSize(12);
    m_label.setFillColor(sf::Color::Black);
    
    // Center the label
    sf::FloatRect textBounds = m_label.getLocalBounds();
    m_label.setPosition(
       sf::Vector2f( m_position.x - (textBounds.position.x + textBounds.size.x / 2.0f),  
        m_position.y - (textBounds.position.y + textBounds.size.y / 2.0f))
    );
}