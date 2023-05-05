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
    deleted,
};

class Character: public Collidable {
protected:
    Sprite m_shape;
    State m_killed {alive};
    int m_score {};


public:
    Character( ) : Collidable(m_shape.getPosition().x, m_shape.getPosition().y, m_shape.getLocalBounds().width, m_shape.getLocalBounds().height), m_shape(pick_shape(Shapes::empty)) {

    m_killed = deleted;
    }
    Character(Sprite shape ) : Collidable(shape.getPosition().x, shape.getPosition().y, shape.getLocalBounds().width, shape.getLocalBounds().height), m_shape(shape) , m_killed{alive} {
    }
    ~Character() ;

    Sprite  draw() ;
    void kill( Sprite shape);
    void move_d(float speed);
    void delete_character();
    // setters
    void setPos(float x , float y);
    void setOrigin(float x, float y);
    void setState(State state) ;
    //getters
    int getScore(){ return m_score;}
    State getState() ;
    Vector2f getPos();
    void move(float xOff, float yOff);
    FloatRect getBoundingBox();

};


#endif // CHARACTER_H
