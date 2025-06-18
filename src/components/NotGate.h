#pragma once
#include "Gate.h"

class NotGate : public Gate {
public:
    NotGate(Vector2f position);
    void update() override;
    int getInputCount() const override { return 1; }
};