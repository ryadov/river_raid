//
// Created by REM005 on 4/27/2023.
//

#ifndef TEST_PLAYER_H
#define TEST_PLAYER_H
#include "Character.hpp"
#include "Shapes.h"

class Player : public Character {
private:

public:
    Player( ) : Character(pick_shape(player)) {}
    Sprite shoot() ;

};


#endif //TEST_PLAYER_H
