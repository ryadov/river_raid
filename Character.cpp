//
// Created by REM005 on 4/27/2023.
//

#include "Character.hpp"
using namespace sf;

Character::~Character() {
}


Sprite  Character::draw() {
    return m_shape;
}


void Character::kill(Sprite shape) {
    m_killed = explode;
    m_shape = shape ;
    m_shape.setPosition(Collidable::x,Collidable::y);

}

void Character::setPos(float x , float y){
    m_shape.setPosition(x, y);
    Collidable::x = x;
    Collidable::y = y;
}

State Character::setState(State state = killed) {
    m_shape = pick_exp(exp5);
    m_shape.setPosition(Collidable::x,Collidable::y);
    return m_killed = state ;
}

State Character::getState() {
    return m_killed;
}

Vector2f Character::getPos(){
    return m_shape.getPosition();
}

FloatRect Character::getBoundingBox(){
    return m_shape.getLocalBounds();
}
void Character::move(float xOff, float yOff){
    m_shape.move(xOff, yOff);
    Collidable::x = m_shape.getPosition().x;
    Collidable::y = m_shape.getPosition().y;
}

void Character::setOrigin(float x, float y){
    m_shape.setOrigin(x, y);
}