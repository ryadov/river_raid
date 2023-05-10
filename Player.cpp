#include "Player.hpp"

using namespace sf;

// Method for the player to shoot a bullet
Sprite Player::shoot() {
    Character shot{pick_shape(bullet)}; // Create a new bullet character
    shot.setPos(x + w / 2 - shot.getWidth() / 2, y); // Set the position of the bullet
    return shot.draw(); // Return the sprite of the bullet
}

// Method to change the player's sprite
void Player::changeSprite(Sprite s) {
    s.setPosition(this->m_shape.getPosition()); // Set the position of the new sprite
    this->m_shape = s; // Replace the player's sprite with the new sprite
}
