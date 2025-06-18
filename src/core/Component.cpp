#include "Component.h"
#include "utils/Constants.h"
#include <cmath>

Component::Component(ComponentType type, Vector2f position) 
    : m_type(type), m_position(position), m_inputCount(2), m_outputCount(1) {
    
    m_shape.setSize(sf::Vector2f(Constants::COMPONENT_SIZE, Constants::COMPONENT_SIZE));
    m_shape.setFillColor(Constants::COMPONENT_COLOR);
    m_shape.setOutlineThickness(2);
    m_shape.setOutlineColor(sf::Color::Black);
    m_shape.setPosition(sf::Vector2f(position.x - Constants::COMPONENT_SIZE/2, 
                                     position.y - Constants::COMPONENT_SIZE/2));
    
    m_inputs.resize(m_inputCount, false);
    m_outputs.resize(m_outputCount, false);
}

bool Component::containsPoint(Vector2f point) const {
    return m_shape.getGlobalBounds().contains(sf::Vector2f(point.x, point.y));
}

void Component::addInput(std::shared_ptr<Wire> wire) {
    m_inputWires.push_back(wire);
}

void Component::addOutput(std::shared_ptr<Wire> wire) {
    m_outputWires.push_back(wire);
}

Vector2f Component::getInputPoint(int index) const {
    float spacing = Constants::COMPONENT_SIZE / (m_inputCount + 1);
    return Vector2f(m_position.x - Constants::COMPONENT_SIZE/2,
                   m_position.y - Constants::COMPONENT_SIZE/2 + spacing * (index + 1));
}

Vector2f Component::getOutputPoint(int index) const {
    float spacing = Constants::COMPONENT_SIZE / (m_outputCount + 1);
    return Vector2f(m_position.x + Constants::COMPONENT_SIZE/2,
                   m_position.y - Constants::COMPONENT_SIZE/2 + spacing * (index + 1));
}