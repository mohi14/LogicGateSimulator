#pragma once
#include "core/Component.h"

class Gate : public Component
{
public:
    Gate(ComponentType type, Vector2f position);
    virtual ~Gate() = default;

    void render(sf::RenderWindow &window) override;

protected:
    void setupLabel(const std::string &text);
};