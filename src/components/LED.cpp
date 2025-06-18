#include "LED.h"
#include "utils/Constants.h"

LED::LED(Vector2f position) 
    : Component(ComponentType::LED, position), m_isLit(false) {
    
    m_outputCount = 0;
    m_outputs.clear();
    
    m_bulb.setRadius(Constants::COMPONENT_SIZE / 3);
    m_bulb.setPosition(sf::Vector2f(
        position.x - Constants::COMPONENT_SIZE/3,
        position.y - Constants::COMPONENT_SIZE/3
    ));
    
    m_shape.setFillColor(sf::Color(200, 100, 100));
}

void LED::update() {
    m_isLit = false;
    for (bool input : m_inputs) {
        if (input) {
            m_isLit = true;
            break;
        }
    }
    
    m_bulb.setFillColor(m_isLit ? sf::Color::Red : sf::Color(100, 50, 50));
}

void LED::render(sf::RenderWindow& window) {
    window.draw(m_shape);
    window.draw(m_bulb);
}