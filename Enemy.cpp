//
// Created by REM005 on 4/27/2023.
//

#include "Enemy.hpp"
#include "Game.hpp"
void Enemy::move_lr() {

    if (m_dir){
        move(m_speed,0);
        if( x+w >= SPAWN_AREA_END && m_speed != 2){
            m_dir = !m_dir ;
            m_shape.scale(-1,1);
            setOrigin(w,0);
        }
        else if ((x+w >= SPAWN_AREA_END + PLANE_OFFSET) && m_speed == 2){
            m_dir = !m_dir ;
            m_shape.scale(-1,1);
            setOrigin(w,0);
        }

    }
    else {
        move(-m_speed, 0);
        if( x <= SPAWN_AREA_BEGIN && m_speed != 2){
            m_dir = !m_dir ;
            m_shape.scale(-1,1);
            setOrigin(0,0);
        }
        else if ((x+w <= SPAWN_AREA_BEGIN - PLANE_OFFSET) && m_speed == 2){
            m_dir = !m_dir ;
            m_shape.scale(-1,1);
            setOrigin(0,0);
        }

    }
}

Enemy::e_Enemy Enemy::getEnemyType() {
    return enemy_type;
}


