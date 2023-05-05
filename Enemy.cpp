//
// Created by REM005 on 4/27/2023.
//

#include "Enemy.h"

void Enemy::move_lr() {
    if( x+w >= 1024 || x <= 0 ){
        m_dir = !m_dir ;
    }
    if (m_dir){
        move(m_speed,0);
    }
    else move(-m_speed,0);
}


/*
Sprite Enemy::draw() {
    if (!m_dir) {
        m_shape.scale(-1,1);
        m_shape.setPosition(Collidable::x,Collidable::y);
    }
    else {
        m_shape.scale(1,1);
        m_shape.setPosition(Collidable::x,Collidable::y);
    }

    return m_shape ;
}
*/