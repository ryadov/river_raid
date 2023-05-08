//
// Created by REM005 on 4/27/2023.
//

#include "Shapes.hpp"
using namespace std;
using namespace sf;
Sprite  pick_shape (Shapes shape) {
    Sprite spt;
    spt.setTexture(texture);
    switch (shape) {
        case Shapes::empty :
            spt.setTextureRect(IntRect(0, 0, 0, 0));
            break;
        case player :
            spt.setTextureRect(IntRect(26, 17, 14, 13));
            break;
        case player_r :
            spt.setTextureRect(IntRect(13,18,10,14));
            break;
        case player_l :
            spt.setTextureRect(IntRect(43,18,10,14));
            break;
        case bullet :
            spt.setTextureRect(IntRect(6,21,2,8));
            break;

        case heli_1 :
            spt.setTextureRect(IntRect(3,46,16,10));
            break;
        case heli_2 :
            spt.setTextureRect(IntRect(21,46,16,10));
            break;
        case ship :
            spt.setTextureRect(IntRect(4,58,32,10));
            break;
        case plane :
            spt.setTextureRect(IntRect(40,49,16,6));
            break;

        case fuel :
            spt.setTextureRect(IntRect(153,15,14,24));
            break;
        case bridge :
            spt.setTextureRect(IntRect(172,16,63,22));
            break;

        case land_1 :
            spt.setTextureRect(IntRect(84,15,31,24));
            break;
        case land_2 :
            spt.setTextureRect(IntRect(117,15,31,24));
            break ;

        case corner_bottom_l :
            spt.setTextureRect(IntRect(117,6,32,8));
            break;
        case  corner_bottom_r:
            spt.setTextureRect(IntRect(84,6,32,8));
            break;
        case corner_top_l :
            spt.setTextureRect(IntRect(117,40,32,8));
            break;
        case corner_top_r :
            spt.setTextureRect(IntRect(84,40,32,8));
            break;


        case fuel_interface :
            spt.setTextureRect(IntRect(74,66,78,15));
            break;
        case fuel_bar :
            spt.setTextureRect(IntRect(154,70,4,10));
            break;
        case label :
            spt.setTextureRect(IntRect(88,84,64,7));
            break;
        case land_right:
            spt.setTextureRect(IntRect(150,146,88,941));
            break;
        case land_left:
            spt.setTextureRect(IntRect(0,146,72,941));
            break;
        case road_topLeft:
            spt.setTextureRect(IntRect(0,1100,112,50));
            break;
        case road_topRight:
            spt.setTextureRect(IntRect(117,1100,128,50));
            break;
        case road_bottomLeft:
            spt.setTextureRect(IntRect(0,1156,112,58));
            break;
        case road_bottomRight:
            spt.setTextureRect(IntRect(117,1156,128,58));
            break;
        case exp1:
            break;
        case exp2:
            break;
        case exp3:
            break;
        case exp4:
            break;
        case exp5:
            break;
        case s0:
            break;
        case s1:
            break;
        case s2:
            break;
        case s3:
            break;
        case s4:
            break;
        case s5:
            break;
        case s6:
            break;
        case s7:
            break;
        case s8:
            break;
        case s9:
            break;

    }
    return spt ;
}

Sprite  pick_score (Shapes shape) {
    Sprite spt ;
    spt.setTexture(texture);
    switch (shape) {
        case s0 :
            spt.setTextureRect(IntRect(84+14*8,96,12,8));
            break;
        case s1 :
            spt.setTextureRect(IntRect(74,96,8,8));
            break;
        case s2 :
            spt.setTextureRect(IntRect(84+14*0,96,12,8));
            break;
        case s3 :
            spt.setTextureRect(IntRect(84+14*1,96,12,8));
            break;
        case s4 :
            spt.setTextureRect(IntRect(84+14*2,96,12,8));
            break;
        case s5 :
            spt.setTextureRect(IntRect(84+14*3,96,12,8));
            break;
        case s6 :
            spt.setTextureRect(IntRect(84+14*4,96,12,8));
            break;
        case s7 :
            spt.setTextureRect(IntRect(84+14*5,96,12,8));
            break;
        case s8 :
            spt.setTextureRect(IntRect(84+14*6,96,12,8));
            break;
        case s9 :
            spt.setTextureRect(IntRect(84+14*7,96,12,8));
            break;

        case Shapes::empty:
            break;
        case player:
            break;
        case player_r:
            break;
        case player_l:
            break;
        case bullet:
            break;
        case heli_1:
            break;
        case heli_2:
            break;
        case ship:
            break;
        case plane:
            break;
        case bridge:
            break;
        case fuel:
            break;
        case land_1:
            break;
        case land_2:
            break;
        case corner_top_r:
            break;
        case corner_top_l:
            break;
        case corner_bottom_r:
            break;
        case corner_bottom_l:
            break;
        case land_right:
            break;
        case land_left:
            break;
        case fuel_interface:
            break;
        case fuel_bar:
            break;
        case label:
            break;
        case exp1:
            break;
        case exp2:
            break;
        case exp3:
            break;
        case exp4:
            break;
        case exp5:
            break;
    }
    return spt;
}

Sprite  pick_exp (Shapes shape) {
    Sprite spt;
    spt.setTexture(texture);
    switch (shape) {
        case exp1 :
            spt.setTextureRect(IntRect(8,78,14,11));
            break;
        case exp2 :
            spt.setTextureRect(IntRect(7,99,12,8));
            break;
        case exp3 :
            spt.setTextureRect(IntRect(30,99,26,8));
            break;
        case exp4 :
            spt.setTextureRect(IntRect(5,111,16,13));
            break;
        case exp5 :
            spt.setTextureRect(IntRect(26,111,34,13));
            break;

        case Shapes::empty:
            break;
        case player:
            break;
        case player_r:
            break;
        case player_l:
            break;
        case bullet:
            break;
        case heli_1:
            break;
        case heli_2:
            break;
        case ship:
            break;
        case plane:
            break;
        case bridge:
            break;
        case fuel:
            break;
        case land_1:
            break;
        case land_2:
            break;
        case corner_top_r:
            break;
        case corner_top_l:
            break;
        case corner_bottom_r:
            break;
        case corner_bottom_l:
            break;
        case land_right:
            break;
        case land_left:
            break;
        case fuel_interface:
            break;
        case fuel_bar:
            break;
        case label:
            break;
        case s0:
            break;
        case s1:
            break;
        case s2:
            break;
        case s3:
            break;
        case s4:
            break;
        case s5:
            break;
        case s6:
            break;
        case s7:
            break;
        case s8:
            break;
        case s9:
            break;
    }
    return spt ;
}
int setScore(Shapes shape) {
    int score {};
    switch (shape) {
        case heli_1:
            score = 60 ;
            break;
        case heli_2:
            score = 60 ;
            break;
        case ship:
            score = 30 ;
            break;
        case plane:
            score = 100 ;
            break;
        case bridge:
            score = 500 ;
            break;
        case fuel:
            score = 80 ;
            break;
        case Shapes::empty:
            break;
        case player:
            break;
        case player_r:
            break;
        case player_l:
            break;
        case bullet:
            break;
        case land_1:
            break;
        case land_2:
            break;
        case corner_top_r:
            break;
        case corner_top_l:
            break;
        case corner_bottom_r:
            break;
        case corner_bottom_l:
            break;
        case land_right:
            break;
        case land_left:
            break;
        case fuel_interface:
            break;
        case fuel_bar:
            break;
        case label:
            break;
        case exp1:
            break;
        case exp2:
            break;
        case exp3:
            break;
        case exp4:
            break;
        case exp5:
            break;
        case s0:
            break;
        case s1:
            break;
        case s2:
            break;
        case s3:
            break;
        case s4:
            break;
        case s5:
            break;
        case s6:
            break;
        case s7:
            break;
        case s8:
            break;
        case s9:
            break;
    }
    return score;
}

Sprite pick_land(Shapes shape){
    Sprite spt_land;
//    spt_land.setTexture(texture_land);

    switch (shape) {
        case land_right:
            spt_land.setTexture(texture_land);
            break;
    }
    return spt_land;
}
