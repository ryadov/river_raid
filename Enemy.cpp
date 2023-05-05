//
// Created by REM005 on 4/27/2023.
//

#include "Enemy.h"

void Enemy::move_lr() {

    if (m_dir){
        move(m_speed,0);
        if( x+w >= 1024){
            m_dir = !m_dir ;
            m_shape.scale(-1,1);
            //m_shape.move(w,0);

            setOrigin(w,0);
        }

    }
    else {
        move(-m_speed, 0);
        if( x <= 0  ){
            m_dir = !m_dir ;
            m_shape.scale(-1,1);


            setOrigin(0,0);
        }

    }
}


