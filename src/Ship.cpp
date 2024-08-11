#include "SFML/Graphics/ConvexShape.hpp"
#include <algorithm>
#include <cmath>

#include "Ship.h"

Ship::Ship()
{
    m_shape.setPointCount(4);

    // define the points
    m_shape.setPoint(0, sf::Vector2f(0.f, 0.f));
    m_shape.setPoint(1, sf::Vector2f(50.f, 100.f));
    m_shape.setPoint(2, sf::Vector2f(0.f, 80.f));
    m_shape.setPoint(3, sf::Vector2f(-50.f, 100.f));

    m_shape.setOrigin(sf::Vector2f(0.f, 50.f));

    m_shape.scale(sf::Vector2f(0.25, 0.25));

    m_shape.setFillColor(sf::Color::Black);
    m_shape.setOutlineColor(sf::Color::White);
    m_shape.setOutlineThickness(5.0f);
}

sf::ConvexShape Ship::getDrawableShape()
{
    m_shape.setPosition(m_position);
    return m_shape;
}

void Ship::update()
{
    m_position += m_move_speed * m_direction;
    m_move_speed = std::max(m_move_speed - m_move_deceleration, 0.f);
}

void Ship::accelerate()
{
    m_move_speed = std::min(m_move_speed + m_move_acceleration, m_move_max_speed);
}

void Ship::turn(int direction)
{
    float angle = m_turn_speed * direction;
    m_shape.rotate(angle);

    float rad_angle = m_shape.getRotation() * M_PIf / 180.f;
    m_direction.x = std::sin(rad_angle);
    m_direction.y = -std::cos(rad_angle);
}
