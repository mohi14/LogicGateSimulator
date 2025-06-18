#include "NotGate.h"

NotGate::NotGate(Vector2f position) : Gate(ComponentType::NOT_GATE, position) {
    m_inputCount = 1;
    m_inputs.resize(1);
    setupLabel("NOT");
}

void NotGate::update() {
    m_outputs[0] = !m_inputs[0];
}