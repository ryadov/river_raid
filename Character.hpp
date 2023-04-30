//
// Created by REM005 on 4/27/2023.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include "Collidable.hpp"

using namespace sf;

class Character: public Collidable {
protected:
    Sprite m_shape;

public:
    Character(Sprite shape) : Collidable(shape.getPosition().x, shape.getPosition().y, shape.getLocalBounds().width, shape.getLocalBounds().height), m_shape(shape) {}
    ~Character() ;

    Sprite  draw() ;
    void kill( Sprite shape);
    // setters
    void setPos(float x , float y);
    void setOrigin(float x, float y);
    //getters
    Vector2f getPos();
    void move(float xOff, float yOff);
    FloatRect getBoundingBox();

};


#endif // CHARACTER_H
