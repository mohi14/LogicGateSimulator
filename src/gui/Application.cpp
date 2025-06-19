#include "Application.h"
#include "utils/Constants.h"
#include "components/AndGate.h"
#include "components/OrGate.h"
#include "components/NotGate.h"
#include "components/Switch.h"
#include "components/LED.h"
#include <optional>
#include <iostream>



Application::Application() 
    : m_window(sf::VideoMode({Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT}), 
               "Digital Logic Simulator"),
      m_state(AppState::SELECTING),
      m_selectedComponentType(ComponentType::AND_GATE) {
    
    m_window.setFramerateLimit(60);
    
    m_circuit = std::make_unique<Circuit>();
    m_toolbar = std::make_unique<Toolbar>();
    m_canvas = std::make_unique<Canvas>();
}

void Application::run() {
    while (m_window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void Application::test(){
    std::cout<<"Hello"<<std::endl;
}

void Application::handleEvents() {
    while (const std::optional<sf::Event> event = m_window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            m_window.close();
            continue;
        }
        
        if (const auto& mouseEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
            if (mouseEvent->button == sf::Mouse::Button::Left) {
                Vector2f mousePos(static_cast<float>(mouseEvent->position.x), 
                                    static_cast<float>(mouseEvent->position.y));
                
                if (mousePos.y < Constants::TOOLBAR_HEIGHT) {
                    // Handle toolbar clicks
                    if (mousePos.x < 100) m_selectedComponentType = ComponentType::AND_GATE;
                    else if (mousePos.x < 200) m_selectedComponentType = ComponentType::OR_GATE;
                    else if (mousePos.x < 300) m_selectedComponentType = ComponentType::NOT_GATE;
                    else if (mousePos.x < 400) m_selectedComponentType = ComponentType::SWITCH;
                    else if (mousePos.x < 500) m_selectedComponentType = ComponentType::LED;
                    
                    m_state = AppState::PLACING_COMPONENT;
                } else {
                    // Handle canvas clicks
                    if (m_state == AppState::PLACING_COMPONENT) {
                        std::shared_ptr<Component> newComponent;
                        
                        switch (m_selectedComponentType) {
                            case ComponentType::AND_GATE:
                                newComponent = std::make_shared<AndGate>(mousePos);
                                break;
                            case ComponentType::OR_GATE:
                                newComponent = std::make_shared<OrGate>(mousePos);
                                break;
                            case ComponentType::NOT_GATE:
                                newComponent = std::make_shared<NotGate>(mousePos);
                                break;
                            case ComponentType::SWITCH:
                                newComponent = std::make_shared<Switch>(mousePos);
                                break;
                            case ComponentType::LED:
                                newComponent = std::make_shared<LED>(mousePos);
                                break;
                        }
                        
                        if (newComponent) {
                            m_circuit->addComponent(newComponent);
                        }
                        
                        m_state = AppState::SELECTING;
                    } else if (m_state == AppState::SELECTING) {
                        auto component = m_circuit->getComponentAt(mousePos);
                        if (component && component->getType() == ComponentType::SWITCH) {
                            auto switchComp = std::static_pointer_cast<Switch>(component);
                            switchComp->toggle();
                        }
                    }
                }
            }
        }
        
        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->scancode == sf::Keyboard::Scan::Escape) {
                m_state = AppState::SELECTING;
            }
            if (keyPressed->scancode == sf::Keyboard::Scan::C) {
                m_circuit->clear();
            }
        }
        
        if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>()) {
            m_mousePosition = Vector2f(mouseMoved->position.x, mouseMoved->position.y);
        }
    }
}

void Application::update() {
    m_circuit->update();
}

void Application::render() {
    m_window.clear(Constants::BACKGROUND_COLOR);
    
    renderGrid();
    m_circuit->render(m_window);
    m_toolbar->render(m_window);
    
    // Show preview of component being placed
    if (m_state == AppState::PLACING_COMPONENT && m_mousePosition.y > Constants::TOOLBAR_HEIGHT) {
        sf::RectangleShape preview;
        preview.setSize(sf::Vector2f(Constants::COMPONENT_SIZE, Constants::COMPONENT_SIZE));
        preview.setFillColor(sf::Color(255, 255, 255, 100));
        preview.setPosition(sf::Vector2f(
            m_mousePosition.x - Constants::COMPONENT_SIZE/2,
            m_mousePosition.y - Constants::COMPONENT_SIZE/2
        ));
        m_window.draw(preview);
    }
    
    m_window.display();
}

void Application::renderGrid() {
    sf::VertexArray grid(sf::PrimitiveType::Lines);
    
    // Vertical lines
    for (int x = 0; x < Constants::WINDOW_WIDTH; x += Constants::GRID_SIZE) {
        grid.append(sf::Vertex(sf::Vector2f(x, Constants::TOOLBAR_HEIGHT), Constants::GRID_COLOR));
        grid.append(sf::Vertex(sf::Vector2f(x, Constants::WINDOW_HEIGHT), Constants::GRID_COLOR));
    }
    
    // Horizontal lines
    for (int y = Constants::TOOLBAR_HEIGHT; y < Constants::WINDOW_HEIGHT; y += Constants::GRID_SIZE) {
        grid.append(sf::Vertex(sf::Vector2f(0, y), Constants::GRID_COLOR));
        grid.append(sf::Vertex(sf::Vector2f(Constants::WINDOW_WIDTH, y), Constants::GRID_COLOR));
    }
    
    m_window.draw(grid);
}