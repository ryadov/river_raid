//
// Created by REM005 on 4/27/2023.
//

#ifndef TEST_SHAPES_H
#define TEST_SHAPES_H

#include <SFML/Graphics.hpp>
extern sf::Texture texture ;

enum Shapes {
    //
    empty ,
    // players
    player,
    player_r,
    player_l,
    bullet,

    // enemies
    heli_1,
    heli_2,
    ship,
    plane,

    // objects
    bridge,
    fuel,


    //land grids
    land_1,
    land_2,
    corner_top_r,
    corner_top_l,
    corner_bottom_r,
    corner_bottom_l,

    // interface
    fuel_interface,
    fuel_bar,
    label,

    // explosions
    exp1,
    exp2,
    exp3,
    exp4,
    exp5,

    // score
    s0,
    s1,
    s2,
    s3,
    s4,
    s5,
    s6,
    s7,
    s8,
    s9,
};

sf::Sprite  pick_shape (Shapes shape) ;

sf::Sprite  pick_score (Shapes shape) ;

sf::Sprite  pick_exp (Shapes shape) ;


#endif //TEST_SHAPES_H
