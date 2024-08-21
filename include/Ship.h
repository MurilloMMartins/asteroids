/**
 * @file Ship.h
 * @brief
 */

#pragma once

#include "SFML/Graphics/ConvexShape.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics/Drawable.hpp>

// these are 1 and -1 because they make the code more compact
/**
 *  macro for rotating the ship to the right
 */
#define SHIP_TURN_RIGHT 1
/**
 *  macro for rotating the ship to the left
 */
#define SHIP_TURN_LEFT -1

class Ship {
public:
    Ship();
    sf::ConvexShape getDrawableShape();

    void accelerate();
    /**
     * @brief Rotates the ship based on the linear rotation formula:
     * - \f$ \theta = \theta_0 + \omega t \f$.
     *
     * Where \f$\omega\f$ is the #m_angularVelocity variable. 
     *
     * @param direction Should be either #SHIP_TURN_RIGHT or #SHIP_TURN_LEFT
     */
    void turn(int direction);
    void update(float deltaTime);

private:
    sf::ConvexShape m_shape;

    // this direction is in radians
    float m_direction = 0.f;
    float m_angularDisplacement = 0.f;

    /**
    *   Angular velocity of the ship, this indicates how much the angle of the ship will change in a second.
    */
    const float m_angularVelocity = 6.28f;

    sf::Vector2f m_position = sf::Vector2f(480.f, 270.f);
    sf::Vector2f m_velocity = sf::Vector2f(0.f, 0.f);
    sf::Vector2f m_acceleration = sf::Vector2f(0.f, 0.f);

    const float m_shipThrust = 1000.f;
    const float m_shipDrag = 0.9f;
};
