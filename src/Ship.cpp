#include <cmath>

#include "Ship.h"
#include "SFML/System/Vector2.hpp"

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

    m_shape.setFillColor(sf::Color(0, 0, 0, 0));
    m_shape.setOutlineColor(sf::Color::White);
    m_shape.setOutlineThickness(5.0f);

    m_shape.setRotation(m_direction * 180 / M_PI);
    m_shape.setPosition(m_position);
}

sf::ConvexShape Ship::getDrawableShape()
{
    return m_shape;
}

void Ship::update(float deltaTime)
{
    m_direction += m_angularDisplacement * deltaTime;

    m_position += m_velocity*deltaTime + static_cast<float>(0.5)*m_acceleration*(deltaTime*deltaTime);
    m_velocity += m_acceleration*deltaTime;
    m_velocity *= 1 - m_shipDrag*deltaTime;

    m_shape.setPosition(m_position);
    // we need to convert the direction from radians to degrees
    m_shape.setRotation(m_direction * 180 / M_PI);

    m_angularDisplacement = 0.f;
    m_acceleration = sf::Vector2f(0.f, 0.f);
}

void Ship::accelerate()
{
    m_acceleration.x = std::sin(m_direction) * m_shipThrust;
    m_acceleration.y = -std::cos(m_direction) * m_shipThrust;
}

void Ship::turn(int direction)
{
    m_angularDisplacement = direction * m_angularVelocity;
}
