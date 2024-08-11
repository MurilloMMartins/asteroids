#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "Asteroids.h"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/View.hpp"
#include "Ship.h"

void Asteroids::run()
{
    sf::RenderWindow window = sf::RenderWindow { { 960u, 540u }, "Asteroids" };
    window.setFramerateLimit(144);

    Ship ship;

    while (window.isOpen()) {
        // Event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            ship.turn(SHIP_TURN_RIGHT);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            ship.turn(SHIP_TURN_LEFT);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            ship.accelerate();
        ship.update();

        window.clear(sf::Color::Black);

        window.draw(ship.getDrawableShape());

        window.display();
    }
}
