#ifndef COLLIDABLE_HPP
#define COLLIDABLE_HPP

// Include the SFML Graphics library
#include <SFML/Graphics.hpp>

using namespace sf;

// Collidable class declaration
class Collidable {
public:
// Constructors
    Collidable();
    Collidable(float x, float y, float w, float h);
    // Method to check for collisions with another Collidable object
    bool isColliding(const Collidable&);

    // Getter functions for Collidable attributes
    float getX();
    float getY();
    float getWidth();
    float getHeight();
protected:
    // Position and dimensions attributes
    float x;
    float y;
    float w;
    float h;
};

#endif //COLLIDABLE_HPP
