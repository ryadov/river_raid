//
// Created by REM005 on 5/5/2023.
//

#ifndef TEST2_SCOREBOARD_H
#define TEST2_SCOREBOARD_H

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "Shapes.h"
#include "Collidable.hpp"
using namespace sf ;
using namespace std ;
class Scoreboard {
protected:

    float frame_width {1024};
    float frame_hight {1024};

    // Fuel interface sprites
    Sprite fuel_tank = pick_shape(fuel_interface);
    Sprite fuel_mark = pick_shape(fuel_bar);
    RenderTexture texture ;

    float mark_pose {};
    float fuel_amount {};
    float max_fuel {};

    int m_score {0};
    Text score_text ;

    int m_lifes {3};
    Text lifes_text ;

    Font font;
    stringstream stream ;

public:
    Scoreboard(){

        set_interface_pose();

    }

    void set_interface_pose();

    float getFuel( ){return  fuel_amount;}
    void setFuel(float amount){fuel_amount = amount;}
    void change_fuel( float amount);
    bool check_fuel();
    //void setMark_pose(float pose) { mark_pose = pose ;}
    //float getMark_pose() {return  mark_pose;}
    void update_score(int amount) ;
    void update_lifes(int d) ;
    Sprite draw();

};


#endif //TEST2_SCOREBOARD_H
