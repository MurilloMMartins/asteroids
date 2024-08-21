#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/View.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/System/Time.hpp"

#include "Asteroids.h"
#include "SFML/Window/WindowStyle.hpp"
#include "Ship.h"

void Asteroids::run()
{
    sf::RenderWindow window = sf::RenderWindow { { 960u, 540u }, "Asteroids", sf::Style::Close | sf::Style::Titlebar };
    window.setFramerateLimit(144);

    Ship ship;
    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Time deltaTime = deltaClock.restart();

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

        ship.update(deltaTime.asSeconds());

        window.clear(sf::Color::Black);

        window.draw(ship.getDrawableShape());

        window.display();
    }
}
