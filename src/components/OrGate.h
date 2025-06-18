#pragma once
#include "Gate.h"

class OrGate : public Gate {
public:
    OrGate(Vector2f position);
    void update() override;
};