#include <SFML/Graphics.hpp>
#include <optional>

int main()
{
    // Create window
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Digital Logic Simulator");
    window.setFramerateLimit(144);

    // Load a font (ensure "arial.ttf" or another font is in your project folder)
    sf::Font font;
    if (!font.openFromFile("assets/fonts/arial.ttf")) {
        return -1; // Error: font not found
    }

    // Create text
    sf::Text titleText(font,"Welcome to the Digital Logic Simulator by Mohiuddin",  48);
    titleText.setFillColor(sf::Color::Red);
    titleText.setPosition(sf::Vector2f(100.f, 100.f)); // x, y

    // Main loop
    while (window.isOpen())
    {
        // Handle events
        while (const std::optional<sf::Event> event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        // Render
        window.clear(sf::Color::Black);
        window.draw(titleText); // Draw the text
        window.display();
    }
}
