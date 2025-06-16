#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "utils/Vector2.h"

class Component;

class Wire
{
public:
    Wire(std::shared_ptr<Component> from, int fromPort, std::shared_ptr<Component> to, int toPort);
    void update();
    void render(sf::RenderWindow &window);

    bool getValue() const { return m_value; }

private:
    std::shared_ptr<Component> m_fromComponent;
    std::shared_ptr<Component> m_toComponent;
    int m_fromPort;
    int m_toPort;
    bool m_value;

    sf::VertexArray m_line;
};