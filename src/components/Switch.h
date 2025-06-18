#pragma once
#include "core/Component.h"

class Switch : public Component {
public:
    Switch(Vector2f position);
    void update() override;
    void render(sf::RenderWindow& window) override;
    void toggle() { m_isOn = !m_isOn; }
    bool isOn() const { return m_isOn; }
    int getInputCount() const override { return 0; }

private:
    bool m_isOn;
    sf::CircleShape m_indicator;
};