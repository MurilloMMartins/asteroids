#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

#include "Asteroids.h"

void Asteroids::run()
{
    sf::RenderWindow window = sf::RenderWindow { { 1920u, 1080u }, "Asteroids" };
    window.setFramerateLimit(144);

    // create an empty shape
    sf::ConvexShape convex;

    // resize it to 4 points
    convex.setPointCount(4);

    // define the points
    convex.setPoint(0, sf::Vector2f(0.f, 0.f));
    convex.setPoint(1, sf::Vector2f(50.f, 100.f));
    convex.setPoint(2, sf::Vector2f(0.f, 80.f));
    convex.setPoint(3, sf::Vector2f(-50.f, 100.f));

    convex.setFillColor(sf::Color::Black);
    convex.setOrigin(sf::Vector2f(0.f, 50.f));
    convex.scale(sf::Vector2f(0.5, 0.5));
    convex.setPosition(sf::Vector2f(100.f, 100.f));
    convex.setOutlineColor(sf::Color::White);
    convex.setOutlineThickness(5.0f);

    while (window.isOpen()) {
        // Event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        convex.rotate(1.f);

        window.draw(convex);

        window.display();
    }
}
