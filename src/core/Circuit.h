#pragma once
#include <vector>
#include <memory>
#include "Component.h"
#include "Wire.h"

class Circuit
{
public:
    Circuit();
    ~Circuit() = default;

    void addComponent(std::shared_ptr<Component> component);
    void addWire(std::shared_ptr<Wire> wire);
    void removeComponent(std::shared_ptr<Component> component);
    void removeWire(std::shared_ptr<Wire> wire);

    void update();
    void render(sf::RenderWindow &window);

    std::shared_ptr<Component> getComponentAt(Vector2f position);
    void clear();

private:
    std::vector<std::shared_ptr<Component>> m_components;
    std::vector<std::shared_ptr<Wire>> m_wires;
};