#include "AndGate.h"

AndGate::AndGate(Vector2f position) : Gate(ComponentType::AND_GATE, position) {
    setupLabel("AND");
}

void AndGate::update() {
    bool result = true;
    for (bool input : m_inputs) {
        result = result && input;
    }
    m_outputs[0] = result;
}