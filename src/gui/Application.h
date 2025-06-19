#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "core/Circuit.h"
#include "Toolbar.h"
#include "Canvas.h"

enum class AppState {
    PLACING_COMPONENT,
    CONNECTING_WIRES,
    SELECTING
};

class Application {
public:
    Application();
    ~Application() = default;
    
    void run();
    void test();

private:
    void handleEvents();
    void update();
    void render();
    void renderGrid();
    
    sf::RenderWindow m_window;
    std::unique_ptr<Circuit> m_circuit;
    std::unique_ptr<Toolbar> m_toolbar;
    std::unique_ptr<Canvas> m_canvas;
    
    AppState m_state;
    ComponentType m_selectedComponentType;
    std::shared_ptr<Component> m_selectedComponent;
    Vector2f m_mousePosition;
    
    sf::Font m_font;
};