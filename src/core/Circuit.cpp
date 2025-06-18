#include "Circuit.h"
#include <algorithm>

Circuit::Circuit() {}

void Circuit::addComponent(std::shared_ptr<Component> component) {
    m_components.push_back(component);
}

void Circuit::addWire(std::shared_ptr<Wire> wire) {
    m_wires.push_back(wire);
}

void Circuit::removeComponent(std::shared_ptr<Component> component) {
    m_components.erase(
        std::remove(m_components.begin(), m_components.end(), component),
        m_components.end()
    );
}

void Circuit::removeWire(std::shared_ptr<Wire> wire) {
    m_wires.erase(
        std::remove(m_wires.begin(), m_wires.end(), wire),
        m_wires.end()
    );
}

void Circuit::update() {
    // Update all components
    for (auto& component : m_components) {
        component->update();
    }
    
    // Update all wires
    for (auto& wire : m_wires) {
        wire->update();
    }
}

void Circuit::render(sf::RenderWindow& window) {
    // Render components first
    for (auto& component : m_components) {
        component->render(window);
    }
    
    // Then render wires on top
    for (auto& wire : m_wires) {
        wire->render(window);
    }
}

std::shared_ptr<Component> Circuit::getComponentAt(Vector2f position) {
    for (auto& component : m_components) {
        if (component->containsPoint(position)) {
            return component;
        }
    }
    return nullptr;
}

void Circuit::clear() {
    m_components.clear();
    m_wires.clear();
}