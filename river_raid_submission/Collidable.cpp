// Include the Collidable class header file
#include "Collidable.hpp"

using namespace sf;

// Constructor for the Collidable class with specified position and dimensions
Collidable::Collidable(float x, float y, float w, float h){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

// Function to check if two Collidable objects are colliding
bool Collidable::isColliding(const Collidable &other) {
    return x < other.x + other.w &&
           x + w > other.x &&
           y < other.y + other.h &&
           y + h > other.y;
}

// Getter functions for Collidable class attributes
float Collidable::getX() { return x; }
float Collidable::getY() { return y; }
float Collidable::getWidth() { return w; }
float Collidable::getHeight() { return h; }

// Default constructor for the Collidable class
Collidable::Collidable() {
    x = 0;
    y = 0;
    w = 0;
    h = 0;
}