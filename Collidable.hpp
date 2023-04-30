//
// Created by Riyadh Alghamdi on 27/04/2023.
//

#ifndef COLLIDABLE_HPP
#define COLLIDABLE_HPP
#include <SFML/Graphics.hpp>
using namespace sf;
enum CollisionDirection {
    NONE,
    TOP,
    BOTTOM,
    LEFT,
    RIGHT
};

class Collidable {
public:
    Collidable(float x, float y, float w, float h);
    CollisionDirection collidesWith(const Collidable&);
    bool isColliding(const Collidable&);
    float getX();
    float getY();
    float getWidth();
    float getHeight();

    float getRight();
    float getLeft();
    float getTop();
    float getBottom();
protected:
    float x;
    float y;
    float w;
    float h;
};



#endif //COLLIDABLE_HPP
