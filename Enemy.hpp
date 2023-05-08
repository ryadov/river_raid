//
// Created by REM005 on 4/27/2023.
//

#ifndef TEST_ENEMY_H
#define TEST_ENEMY_H
#include <iostream>
#include "Character.hpp"
#include "Shapes.hpp"


using namespace std;



class Enemy : public Character {
public:
    enum e_Enemy {
        empty = Shapes::empty,
        heli_1 = Shapes::heli_1,
        heli_2 = Shapes::heli_2,
        ship = Shapes::ship,
        plane = Shapes::plane,
        bridge = Shapes::bridge,


    };
protected:
    bool m_dir{true};
    float m_speed {};
    e_Enemy enemy_type;

public:
    Enemy()  {

    }
    Enemy(e_Enemy enemy) : Character(pick_shape(static_cast<Shapes>(enemy))) {

        switch (enemy) {
            case heli_1 :
                enemy_type = heli_1;
                break;
            case heli_2:
                m_speed = 1 ;
                enemy_type = heli_2;
                break;
            case ship:
                m_speed = 0.5 ;
                enemy_type = ship;
                break;
            case plane:
                m_speed = 2 ;
                enemy_type = plane;
                break;
            case bridge:
                m_speed = 0 ;
                enemy_type = bridge;
                break;
            case empty:
                break;
        }
        m_score = setScore(static_cast<Shapes>(enemy));

    }

    void move_lr ();
    void setDir(bool dir) {m_dir = dir ;}
    e_Enemy getEnemyType();



};


#endif //TEST_ENEMY_H
