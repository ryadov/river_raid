//
// Created by REM005 on 5/2/2023.
//

#ifndef TEST2_GAME_H
#define TEST2_GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "Shapes.h"
#include "Character.hpp"
#include "Player.h"
#include "Enemy.h"
#include "Fuel.h"

//globals
const int  enemy_nbr = 20 ;
const int  shots_nbr = 100 ;
const int  fuel_nbr =  5 ;

extern Enemy enemys[enemy_nbr];
extern Character shots[shots_nbr];
extern Fuel  fuels[fuel_nbr];
//player
extern Player pl ;

// game instenstiation
void init_objects() ;
void move_objects() ;
void move_objects_down();
void kill_objects() ;
void control_player();
void refuel_player();

void animate_delete() ;

/*
class Game {
protected:
    const int enemy_nbr {};
    const int shots_nbr {};
    const int fuel_nbr {};

public:
};
*/

#endif //TEST2_GAME_H
