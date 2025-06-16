#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "utils/Vector2.h"

enum class ComponentType
{
    AND_GATE,
    OR_GATE,
    NOT_GATE,
    SWITCH,
    LED
};

class Wire;

class Component
{
public:
    Component(ComponentType type, Vector2f position);
    virtual ~Component() = default;

    virtual void update() = 0;
    virtual void render(sf::RenderWindow &window) = 0;
    virtual bool containsPoint(Vector2f point) const;

    // Input/Output management
    virtual void addInput(std::shared_ptr<Wire> wire);
    virtual void addOutput(std::shared_ptr<Wire> wire);
    virtual bool getOutput(int index = 0) const { return m_outputs[index]; }
    virtual void setInput(int index, bool value) { m_inputs[index] = value; }

    // Properties
    Vector2f getPosition() const { return m_position; }
    void setPosition(Vector2f position) { m_position = position; }
    ComponentType getType() const { return m_type; }

    // Connection points
    virtual Vector2f getInputPoint(int index) const;
    virtual Vector2f getOutputPoint(int index) const;
    virtual int getInputCount() const { return m_inputCount; }
    virtual int getOutputCount() const { return m_outputCount; }

protected:
    ComponentType m_type;
    Vector2f m_position;
    std::vector<bool> m_inputs;
    std::vector<bool> m_outputs;
    std::vector<std::shared_ptr<Wire>> m_inputWires;
    std::vector<std::shared_ptr<Wire>> m_outputWires;
    int m_inputCount;
    int m_outputCount;

    sf::RectangleShape m_shape;
    sf::Text m_label;
    sf::Font m_font;
};