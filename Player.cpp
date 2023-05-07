//
// Created by REM005 on 4/27/2023.
//

#include "Player.hpp"

using namespace sf ;

Sprite Player::shoot() {
    Character shot{pick_shape(bullet)} ;
    shot.setPos(x+w/2 - shot.getWidth()/2,y);
    return shot.draw();
}

void  Player::refueling() {
    fuel_amount += 1 ;
    setSpeed(1);
}

void Player::defueling(float speed) {
    fuel_amount -= speed;
}

void Player::changeSprite(Sprite s) {
    s.setPosition(this->m_shape.getPosition());
    this->m_shape = s;
}