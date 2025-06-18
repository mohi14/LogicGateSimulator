#include "Wire.h"
#include "Component.h"
#include "utils/Constants.h"


Wire::Wire(std::shared_ptr<Component> from, int fromPort, 
           std::shared_ptr<Component> to, int toPort)
    : m_fromComponent(from), m_toComponent(to), 
      m_fromPort(fromPort), m_toPort(toPort), m_value(false) {
    
    m_line.setPrimitiveType(sf::PrimitiveType::Lines);
    m_line.resize(2);
}

void Wire::update() {
    if (m_fromComponent) {
        m_value = m_fromComponent->getOutput(m_fromPort);
        if (m_toComponent) {
            m_toComponent->setInput(m_toPort, m_value);
        }
    }
    
    // Update visual representation
    if (m_fromComponent && m_toComponent) {
        Vector2f start = m_fromComponent->getOutputPoint(m_fromPort);
        Vector2f end = m_toComponent->getInputPoint(m_toPort);
        
        sf::Color wireColor = m_value ? Constants::ACTIVE_COLOR : Constants::WIRE_COLOR;
        
        m_line[0].position = sf::Vector2f(start.x, start.y);
        m_line[0].color = wireColor;
        m_line[1].position = sf::Vector2f(end.x, end.y);
        m_line[1].color = wireColor;
    }
}

void Wire::render(sf::RenderWindow& window) {
    window.draw(m_line);
}