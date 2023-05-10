#include "Scoreboard.hpp"
#include "Game.hpp"

void  Scoreboard::set_interface_pose() {
    frame_width = WIN_W;
    frame_hight = WIN_H;
    float scale {WIN_H/WIN_W/1.5f};
    fuel_tank.scale(scale,scale);
    fuel_mark.scale(scale,scale);
    float tank_w { fuel_tank.getLocalBounds().width * scale};
    float tank_h { fuel_tank.getLocalBounds().height* scale};
    float mark_w { fuel_mark.getLocalBounds().width * scale};
    float marker_d = 6 * scale;
    float marker_h = 4 * scale;
    max_fuel = tank_w - 2 * marker_d -mark_w ;
    fuel_amount = max_fuel ;
    fuel_tank.setPosition(frame_width/2 - tank_w /2, SB_H/2 - tank_h/2);  //  ( offset from score board rectangle)
    mark_pose = fuel_tank.getPosition().x + marker_d + fuel_amount;
    fuel_mark.setPosition(mark_pose, fuel_tank.getPosition().y + marker_h);
    score_text.setFont(displayFont);
    lifes_text.setFont(displayFont);
    stream << m_score ;
    score_text.setString(stream.str());
    score_text.setCharacterSize(FONT_SIZE*scale); // set the character size in pixels
    score_text.setFillColor(Color::Yellow); // set the color
    score_text.setPosition(frame_width/2 - tank_w/2, SB_H/2 - score_text.getCharacterSize()*1.7);
    stream.str("");

    stream << m_lifes ;
    lifes_text.setString(stream.str());
    lifes_text.setCharacterSize(FONT_SIZE*scale); // set the character size in pixels
    lifes_text.setFillColor(Color::Yellow); // set the color
    lifes_text.setPosition(frame_width/2 - tank_w/2, SB_H/2 + tank_h/2 - score_text.getCharacterSize()*0.2);
    stream.str("");

}



void Scoreboard::change_fuel( float amount){
    if ( (fuel_amount >= max_fuel && amount > 0) || (fuel_amount <= 0 && amount < 0 ) ){
        return ;
    }

    fuel_amount += amount ;
    mark_pose += amount ;
    fuel_mark.setPosition(mark_pose , fuel_mark.getPosition().y) ;
}

bool Scoreboard::check_fuel() {
    if(fuel_amount>0) return true;
    return false ;
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
    if (!texture.create(frame_width, SB_H))   // 150 is the scoreboard hieght
        return sprite ;
    texture.clear(Color(100, 100, 100));
    texture.draw(fuel_mark);
    texture.draw(fuel_tank);
    texture.draw(score_text);
    texture.draw(lifes_text);
    texture.display();
    sprite.setTexture(texture.getTexture()) ;
    sprite.setPosition(0,frame_hight-SB_H);      // to dispaly it at the bottom of the scean 150 is the hieght

    return sprite ;

}