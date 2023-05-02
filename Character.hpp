//
// Created by REM005 on 4/27/2023.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include "Collidable.hpp"
#include "Shapes.h"

using namespace sf;

enum State {
    alive,
    explode,
    killed,
};

class Character: public Collidable {
protected:
    Sprite m_shape;
    State m_killed {alive};

public:
    Character( ) : Collidable(m_shape.getPosition().x, m_shape.getPosition().y, m_shape.getLocalBounds().width, m_shape.getLocalBounds().height), m_shape(pick_shape(Shapes::empty)) {

        m_killed = killed ;
    }
    Character(Sprite shape ) : Collidable(shape.getPosition().x, shape.getPosition().y, shape.getLocalBounds().width, shape.getLocalBounds().height), m_shape(shape) {}
    ~Character() ;

    Sprite  draw() ;
    void kill( Sprite shape);
    // setters
    void setPos(float x , float y);
    void setOrigin(float x, float y);
    State setState(State state) ;
    //getters
    State getState() ;
    Vector2f getPos();
    void move(float xOff, float yOff);
    FloatRect getBoundingBox();

};


#endif // CHARACTER_H
