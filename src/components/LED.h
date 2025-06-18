#pragma once
#include "core/Component.h"

class LED : public Component {
public:
    LED(Vector2f position);
    void update() override;
    void render(sf::RenderWindow& window) override;
    int getOutputCount() const override { return 0; }

private:
    sf::CircleShape m_bulb;
    bool m_isLit;
};