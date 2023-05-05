//
// Created by REM005 on 5/5/2023.
//

#include "Scoreboard.h"

void  Scoreboard::set_interface_pose() {

    int scale {3};
    fuel_tank.scale(scale,scale);
    fuel_mark.scale(scale,scale);
    float tank_w { fuel_tank.getLocalBounds().width * scale};
    float mark_w { fuel_mark.getLocalBounds().width * scale};
    float marker_d = 6 * scale;
    float marker_h = 4 * scale;
    max_fuel = tank_w - 2 * marker_d -mark_w ;
    fuel_amount = max_fuel ;
    fuel_tank.setPosition(frame_width/2 - tank_w /2, 50);  //  ( offset from score board rectangle)
    mark_pose = fuel_tank.getPosition().x + marker_d + fuel_amount;
    fuel_mark.setPosition(mark_pose, fuel_tank.getPosition().y + marker_h);

    font.loadFromFile("../Phosphate.ttc");
    score_text.setFont(font);
    lifes_text.setFont(font);
    stream << m_score ;
    score_text.setString(stream.str());
    score_text.setCharacterSize(58); // set the character size in pixels
    score_text.setFillColor(Color::Yellow); // set the color
    score_text.setPosition(frame_width/2 - tank_w/2+5, -15);
    stream.str("");

    stream << m_lifes ;
    lifes_text.setString(stream.str());
    lifes_text.setCharacterSize(58); // set the character size in pixels
    lifes_text.setFillColor(Color::Yellow); // set the color
    lifes_text.setPosition(frame_width/2 - tank_w/2+5, 80);
    stream.str("");

}



void Scoreboard::change_fuel( float amount){
    if ( (fuel_amount >= max_fuel && amount > 0) || (fuel_amount <= 0 && amount < 0 ) ){
        return ;
    }

    fuel_amount += amount ;
    mark_pose += amount ;
    fuel_mark.setPosition(mark_pose , fuel_mark.getPosition().y) ;
    cout << fuel_amount << "/" << max_fuel << endl ;
}

void Scoreboard::update_score(int amount) {
    int cycle = 10000 ;
    m_score += amount;
    if (!(m_score % cycle)) {
        update_lifes(1);
    }
    stream.str("");
    stream << m_score ;
    score_text.setString(stream.str());
    stream.str("");

}

void Scoreboard::update_lifes(int d) {
    if (m_lifes < 0) return;
    m_lifes += d ;

    stream.str("");
    stream << m_lifes ;
    lifes_text.setString(stream.str());
    stream.str("");
}

Sprite Scoreboard::draw() {
    Sprite sprite ;
    if (!texture.create(frame_width, 150))   // 150 is the scoreboard hieght
        return sprite ;
    texture.clear(Color(100, 100, 100));
    texture.draw(fuel_tank);
    texture.draw(fuel_mark);
    texture.draw(score_text);
    texture.draw(lifes_text);
    texture.display();
    sprite.setTexture(texture.getTexture()) ;
    sprite.setPosition(0,frame_hight-150);      // to dispaly it at the bottom of the scean 150 is the hieght

    return sprite ;

}