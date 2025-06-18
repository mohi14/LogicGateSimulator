#include "Switch.h"
#include "utils/Constants.h"

Switch::Switch(Vector2f position) 
    : Component(ComponentType::SWITCH, position), m_isOn(false) {
    
    m_inputCount = 0;
    m_inputs.clear();
    
    m_indicator.setRadius(Constants::COMPONENT_SIZE / 4);
    m_indicator.setPosition(sf::Vector2f(
        position.x - Constants::COMPONENT_SIZE/4, 
        position.y - Constants::COMPONENT_SIZE/4
    ));
    
    m_shape.setFillColor(sf::Color(100, 100, 200));
}

void Switch::update() {
    m_outputs[0] = m_isOn;
    m_indicator.setFillColor(m_isOn ? Constants::ACTIVE_COLOR : Constants::INACTIVE_COLOR);
}

void Switch::render(sf::RenderWindow& window) {
    window.draw(m_shape);
    window.draw(m_indicator);
}