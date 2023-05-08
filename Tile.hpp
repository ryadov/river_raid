//
// Created by Riyadh Alghamdi on 06/05/2023.
//

#ifndef RIVER_RAID_TILE_HPP
#define RIVER_RAID_TILE_HPP
#include <SFML/Graphics.hpp>
#include "Shapes.hpp"
#include "Collidable.hpp"

using namespace std;
using namespace sf;

class Tile: public Collidable {
protected:
    Sprite m_shape;
    float x{0};
    float y{0};
public:
    float m_speed;
    Tile();
    Tile(Shapes s) : Collidable(), m_shape{pick_shape(s)} {
        if(s == land_left || s == road_topLeft)
            m_shape.setPosition(0,0);
        else if(s == land_right)
            m_shape.setPosition(216,0); // win_w - thickness of right lane = 304 - 88 = 216
        else if(s == road_topRight || s == road_bottomRight)
            m_shape.setPosition(176,0); // win_w - road_w = 304 - 124 = 176
        else if(s == corner_top_l)
            m_shape.setPosition(72,50);
        else if(s == corner_top_r)
            m_shape.setPosition(176,50);
        Collidable::x = m_shape.getPosition().x;
        Collidable::y = m_shape.getPosition().y;
        Collidable::w = m_shape.getLocalBounds().width;
        Collidable::h = m_shape.getLocalBounds().height;
    }
    void move_d(float speed);
    void move(float xOff, float yOff);
    void updatePosition();
    void setShape(Shapes);
    Sprite draw();

    Vector2f getPos();

};


#endif //RIVER_RAID_TILE_HPP
