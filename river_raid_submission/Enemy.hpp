#ifndef TEST_ENEMY_H
#define TEST_ENEMY_H
#include <iostream>
#include "Character.hpp"
#include "Shapes.hpp"

using namespace std;

// Enemy class inherits from Character class
class Enemy : public Character {
public:
    // Define the enemy types
    enum e_Enemy {
        empty = Shapes::empty,
        heli_1 = Shapes::heli_1,
        heli_2 = Shapes::heli_2,
        ship = Shapes::ship,
        plane = Shapes::plane,
        bridge = Shapes::bridge,
    };

protected:
    bool m_dir{true}; // Direction of the enemy (true: right, false: left)
    float m_speed {}; // Speed of the enemy
    e_Enemy enemy_type; // Type of the enemy

public:
    Enemy()  {

    }

    // Constructor with enemy type as parameter
    Enemy(e_Enemy enemy) : Character(pick_shape(static_cast<Shapes>(enemy))) {

        // Assign enemy attributes based on the type
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

    // Method to move the enemy left or right
    void move_lr();
};

#endif //TEST_ENEMY_H
