//
// Created by REM005 on 5/2/2023.
//

#ifndef TEST2_GAME_H
#define TEST2_GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

#include "Shapes.hpp"
#include "Character.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Fuel.hpp"
#include "Scoreboard.hpp"
#include "Tile.hpp"

#define DELTA_X 1
#define WIN_H 1049
//#define WIN_H 304
#define WIN_W 304
#define SPAWN_AREA_BEGIN 80
#define SPAWN_AREA_END 224
#define PLANE_OFFSET 200
#define PLAYER_INIT_X 138
#define PLAYER_INIT_Y 1031
#define SPEED_DOWN 1
#define SPEED_NO_KEY 2
#define SPEED_UP 3
#define FRAME_RATE 60
#define FONT "../8_bit_1_6 Regular.ttf"
#define FONT_SIZE 30
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
extern bool reset ;
//lanes
extern Tile right_lane;

extern Font displayFont ;
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
void draw_scene();

void reset_game();

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
