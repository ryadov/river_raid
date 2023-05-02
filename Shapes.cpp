//
// Created by REM005 on 4/27/2023.
//

#include "Shapes.h"

sf::Sprite  pick_shape (Shapes shape) {
    sf::Sprite spt ;
    spt.setTexture(texture);
    switch (shape) {
        case empty :
            spt.setTextureRect(sf::IntRect(0, 0, 0, 0));
        case player :
            spt.setTextureRect(sf::IntRect(26, 17, 14, 13));
            break;
        case player_r :
            spt.setTextureRect(sf::IntRect(13,18,10,14));
            break;
        case player_l :
            spt.setTextureRect(sf::IntRect(43,18,10,14));
            break;
        case bullet :
            spt.setTextureRect(sf::IntRect(6,21,2,8));
            break;

        case heli_1 :
            spt.setTextureRect(sf::IntRect(3,46,16,10));
            break;
        case heli_2 :
            spt.setTextureRect(sf::IntRect(21,46,16,10));
            break;
        case ship :
            spt.setTextureRect(sf::IntRect(4,58,32,10));
            break;
        case plane :
            spt.setTextureRect(sf::IntRect(40,49,16,6));
            break;

        case fuel :
            spt.setTextureRect(sf::IntRect(153,15,14,24));
            break;
        case bridge :
            spt.setTextureRect(sf::IntRect(172,16,63,22));
            break;

        case land_1 :
            spt.setTextureRect(sf::IntRect(84,15,31,24));
            break;
        case land_2 :
            spt.setTextureRect(sf::IntRect(117,15,31,24));
            break ;
        case corner_top_r :
            spt.setTextureRect(sf::IntRect(117,6,31,8));
            break;
        case corner_top_l :
            spt.setTextureRect(sf::IntRect(84,6,31,8));
            break;
        case corner_bottom_r :
            spt.setTextureRect(sf::IntRect(117,40,31,8));
            break;
        case corner_bottom_l :
            spt.setTextureRect(sf::IntRect(84,40,31,8));
            break;


        case fuel_interface :
            spt.setTextureRect(sf::IntRect(74,66,78,15));
            break;
        case fuel_bar :
            spt.setTextureRect(sf::IntRect(154,70,4,10));
            break;
        case label :
            spt.setTextureRect(sf::IntRect(88,84,64,7));
            break;




    }
    return spt ;
}

sf::Sprite  pick_score (Shapes shape) {
    sf::Sprite spt ;
    spt.setTexture(texture);
    switch (shape) {
        case s0 :
            spt.setTextureRect(sf::IntRect(84+14*8,96,12,8));
            break;
        case s1 :
            spt.setTextureRect(sf::IntRect(74,96,8,8));
            break;
        case s2 :
            spt.setTextureRect(sf::IntRect(84+14*0,96,12,8));
            break;
        case s3 :
            spt.setTextureRect(sf::IntRect(84+14*1,96,12,8));
            break;
        case s4 :
            spt.setTextureRect(sf::IntRect(84+14*2,96,12,8));
            break;
        case s5 :
            spt.setTextureRect(sf::IntRect(84+14*3,96,12,8));
            break;
        case s6 :
            spt.setTextureRect(sf::IntRect(84+14*4,96,12,8));
            break;
        case s7 :
            spt.setTextureRect(sf::IntRect(84+14*5,96,12,8));
            break;
        case s8 :
            spt.setTextureRect(sf::IntRect(84+14*6,96,12,8));
            break;
        case s9 :
            spt.setTextureRect(sf::IntRect(84+14*7,96,12,8));
            break;

    }
    return spt;
}

sf::Sprite  pick_exp (Shapes shape) {
    sf::Sprite spt;
    spt.setTexture(texture);
    switch (shape) {
        case exp1 :
            spt.setTextureRect(sf::IntRect(8,78,14,11));
            break;
        case exp2 :
            spt.setTextureRect(sf::IntRect(7,99,12,8));
            break;
        case exp3 :
            spt.setTextureRect(sf::IntRect(30,99,26,8));
            break;
        case exp4 :
            spt.setTextureRect(sf::IntRect(5,111,16,13));
            break;
        case exp5 :
            spt.setTextureRect(sf::IntRect(26,111,34,13));
            break;

    }
    return spt ;
}