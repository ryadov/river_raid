//
// Created by Riyadh Alghamdi on 27/04/2023.
//

#include "Collidable.hpp"
#include "Character.hpp"

using namespace sf;


Collidable::Collidable(float x, float y, float w, float h){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

CollisionDirection Collidable::collidesWith(const Collidable& other) {
    if (y + h < other.y) {
        return CollisionDirection::TOP;
    }
    if (y > other.y + other.h) {
        return CollisionDirection::BOTTOM;
    }
    if (x + w < other.x) {
        return CollisionDirection::LEFT;
    }
    if (x > other.x + other.w) {
        return CollisionDirection::RIGHT;
    }
    return CollisionDirection::NONE;
}

bool Collidable::isColliding(const Collidable &other) {
    return x < other.x + other.w &&
           x + w > other.x &&
           y < other.y + other.h &&
           y + h > other.y;
}

float Collidable::getX()  { return x; }
float Collidable::getY()  { return y; }
float Collidable::getWidth()  { return w; }
float Collidable::getHeight()  { return h; }
float Collidable::getRight(){return x + w;}
float Collidable::getLeft(){return x;}
float Collidable::getTop(){return y;}
float Collidable::getBottom(){return y + h;}
