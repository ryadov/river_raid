//
// Created by REM005 on 4/27/2023.
//

#ifndef TEST_ENEMY_H
#define TEST_ENEMY_H
#include "Character.hpp"
#include "Shapes.h"




class Enemy : public Character {
protected:
    bool m_dir{true};
    float m_speed {};

public:

    enum e_Enemy {
        heli_1 = Shapes::heli_1,
        heli_2,
        ship,
        plane,
        bridge = Shapes::bridge,
        empty = Shapes::empty

    };
public:
    Enemy()  {

    }
    Enemy(e_Enemy enemy) : Character(pick_shape(static_cast<Shapes>(enemy))) {

        switch (enemy) {
            case heli_1 :
            case heli_2:
                m_speed = 1 ;
                break;
            case ship:
                m_speed = 0.5 ;
                break;
            case plane:
                m_speed = 2 ;
                break;
            case bridge:
                m_speed = 0 ;
                break;
        }
        m_score = setScore(static_cast<Shapes>(enemy));

    }

    void move_lr ();
    void move_d ();

    //Sprite draw() ;


};


#endif //TEST_ENEMY_H
