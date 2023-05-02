//
// Created by REM005 on 4/27/2023.
//

#ifndef TEST_PLAYER_H
#define TEST_PLAYER_H
#include "Character.hpp"
#include "Shapes.h"

class Player : public Character {
private:
    float fuel_amount {};
    float m_speed {};
    int m_lifes{3};

public:
    Player( ) : Character(pick_shape(player)) {}
    Sprite shoot() ;
    void refueling ();
    void defueling(float speed);

    //getters
    float getFuel(){return fuel_amount;}
    float getSpeed(){return m_speed;}
    int getLifes(){return m_lifes;}
    //setters
    void setSpeed(float speed){m_speed = speed;}
    void setLifes(int lifes){m_lifes = lifes;}

};


#endif //TEST_PLAYER_H
