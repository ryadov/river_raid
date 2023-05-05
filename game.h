//
// Created by REM005 on 5/2/2023.
//

#ifndef TEST2_GAME_H
#define TEST2_GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>

#include "Shapes.h"
#include "Character.hpp"
#include "Player.h"
#include "Enemy.h"
#include "Fuel.h"
#include "Scoreboard.h"
using namespace std ;


//globals
const int  enemy_nbr = 10 ;
const int  shots_nbr = 100 ;
const int  fuel_nbr =  10 ;

extern Enemy enemys[enemy_nbr];
extern Character shots[shots_nbr];
extern Fuel  fuels[fuel_nbr];
extern Scoreboard board ;
//player
extern Player pl ;

//window object
extern RenderWindow window ;

// game instenstiation
void init_objects() ;
void respawn_objects(); //this algorithm doesnt work for now // until we fix the deleting of objects issue
void move_objects() ;
void move_objects_down();
void kill_objects() ;
void kill_objects_outsideFrame() ;
void control_player();
void refuel_player();

void animate_delete() ;

//draw
void draw_sean();

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
