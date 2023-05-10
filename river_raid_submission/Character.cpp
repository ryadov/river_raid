// Include the Character class header file
#include "Character.hpp"
using namespace sf;

// Destructor for the Character class
Character::~Character() {

}

// Function to draw the character sprite
Sprite  Character::draw() {
    return m_shape;
}

// Function to set the character to explode state and update its sprite
void Character::kill(Sprite shape) {
    m_killed = explode;
    m_shape = shape ;
    m_shape.setPosition(Collidable::x,Collidable::y);
}

// Function to move the character vertically by a specified speed
void Character::move_d(float speed){
    move(0,speed);
}

// Function to set the character's position
void Character::setPos(float x , float y){
    m_shape.setPosition(x, y);
    Collidable::x = x;
    Collidable::y = y;
}

// Function to set the character's state (default is killed)
void Character::setState(State state = killed) {
    m_shape = pick_exp(exp5);
    m_shape.setPosition(Collidable::x,Collidable::y);
    m_killed = state ;
}

// Function to get the character's state
State Character::getState() {
    return m_killed;
}

// Function to get the character's position
Vector2f Character::getPos(){
    return m_shape.getPosition();
}

// Function to move the character by an x and y offset
void Character::move(float xOff, float yOff){
    m_shape.move(xOff, yOff);
    Collidable::x = m_shape.getPosition().x;
    Collidable::y = m_shape.getPosition().y;
}

// Function to set the character's origin for rotation and scaling
void Character::setOrigin(float x, float y){
    m_shape.setOrigin(x, y);
}
