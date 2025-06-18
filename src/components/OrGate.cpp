#include "OrGate.h"

OrGate::OrGate(Vector2f position) : Gate(ComponentType::OR_GATE, position) {
    setupLabel("OR");
}

void OrGate::update() {
    bool result = false;
    for (bool input : m_inputs) {
        result = result || input;
    }
    m_outputs[0] = result;
}