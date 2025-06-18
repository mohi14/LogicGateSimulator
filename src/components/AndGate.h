#pragma once
#include "Gate.h"

class AndGate : public Gate
{
public:
    AndGate(Vector2f position);
    void update() override;
};