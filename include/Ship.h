#pragma once

#include "SFML/Graphics/ConvexShape.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics/Drawable.hpp>

// these are 1 and -1 because they make the code more compact
#define SHIP_TURN_RIGHT 1
#define SHIP_TURN_LEFT -1

class Ship {
public:
    Ship();
    sf::ConvexShape getDrawableShape();

    void accelerate();
    void turn(int direction);
    void update();

private:
    sf::ConvexShape m_shape;
    sf::Vector2f m_position = sf::Vector2f(0.f, 100.f);
    sf::Vector2f m_direction = sf::Vector2f(0.f, 0.f);
    float m_turn_speed = 2.f;
    float m_move_speed = 0.0f;
    float m_move_max_speed = 2.5f;
    float m_move_acceleration = 0.05f;
    float m_move_deceleration = 0.025f;
};
