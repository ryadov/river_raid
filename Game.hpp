// Header guard to prevent multiple inclusions
#ifndef TEST2_GAME_H
#define TEST2_GAME_H

// Include necessary libraries and header files
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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

// Define constants for game properties
#define DELTA_X 1
//#define WIN_H 304
#define WIN_H 941
#define WIN_W 304
#define TOL 2
#define SPAWN_AREA_BEGIN 72
#define SPAWN_AREA_END 216
#define PLANE_OFFSET 200
#define SB_H WIN_H*0.1
#define PLAYER_INIT_X WIN_W/2-14/2
#define PLAYER_INIT_Y WIN_H-SB_H-13-2
#define SPEED_DOWN 1
#define SPEED_NO_KEY 2
#define SPEED_UP 3
#define FRAME_RATE 60
#define FONT "../8_bit_1_6 Regular.ttf"
#define FONT_SIZE 15


using namespace std ;


// Global variable declarations
const int  enemy_nbr = 10 ;
const int  shots_nbr = 30 ;
const int  fuel_nbr =  5 ;

extern Enemy enemys[enemy_nbr];
extern Character shots[shots_nbr];
extern Fuel  fuels[fuel_nbr];
extern Scoreboard board ;
//player
extern Player pl ;
extern bool reset ;
//lanes
extern Tile right_lane;
extern Tile right_lane2;
extern Tile left_lane;
extern Tile left_lane2;

extern Tile corner_tl;
extern Tile corner_tr;
extern Tile corner_bl;
extern Tile corner_br;

extern Tile road_tl;
extern Tile road_tr;
extern Tile road_bl;
extern Tile road_br;

extern Font displayFont ;
//window object
extern RenderWindow window ;

// Function prototypes for game initialization and management
void init_objects() ;
void respawn_objects();
void move_objects() ;
void move_objects_down();
void kill_objects() ;
void kill_objects_outsideFrame() ;
void updateTiles();
void refuel_player();
void animate_delete() ;

// Function prototypes for drawing and game state management
void draw_scene();
void reset_game();

#endif //TEST2_GAME_H
