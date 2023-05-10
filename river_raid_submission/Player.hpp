#ifndef TEST_PLAYER_H
#define TEST_PLAYER_H
#include "Character.hpp"
#include "Shapes.hpp"

// Player class, derived from Character class
class Player : public Character {
private:
    float fuel_amount {}; // Amount of fuel the player has
    float m_speed {3}; // Player's speed
    int m_lifes{3}; // Number of lives the player has

public:
    // Default constructor for Player class
    Player() : Character(pick_shape(player)) {
    }

    // Method for the player to shoot a bullet
    Sprite shoot();

    // Getters
    float getSpeed() { return m_speed; }

    // Setters
    void setSpeed(float speed) { m_speed = speed; }
    void changeSprite(Sprite); // Method to change the player's sprite
};

#endif //TEST_PLAYER_H
