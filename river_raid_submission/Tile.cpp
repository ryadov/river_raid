#include "Tile.hpp"
#include "Game.hpp"

// Default constructor for the Tile class
Tile::Tile(): Collidable() {
    m_shape.setPosition(0,0);
    x = m_shape.getPosition().x;
    y = m_shape.getPosition().y;
    Collidable::x = m_shape.getPosition().x;
    Collidable::y = m_shape.getPosition().y;
}

// Function to draw the tile
Sprite Tile::draw() {
    return m_shape;
}

// Function to set the shape of the tile
void Tile::setShape(Shapes s){
    // Set the position of the tile based on the shape type
    m_shape = pick_shape(s);
    if(s == land_left || s == road_topLeft || s == road_bottomLeft)
        m_shape.setPosition(0,0);
    else if(s == land_right)
        m_shape.setPosition(216,0); // win_w - thickness of right lane = 304 - 88 = 216
    else if(s == road_topRight || s == road_bottomRight)
        m_shape.setPosition(176,0); // win_w - road_w = 304 - 124 = 176
    else if(s == corner_top_l || s == corner_bottom_l)
        m_shape.setPosition(72,50);
    else if(s == corner_top_r || s == corner_bottom_r)
        m_shape.setPosition(216-32,50);



    x = m_shape.getPosition().x;
    y = m_shape.getPosition().y;

    Collidable::x = m_shape.getPosition().x;
    Collidable::y = m_shape.getPosition().y;
    Collidable::w = m_shape.getLocalBounds().width;
    Collidable::h = m_shape.getLocalBounds().height;
}
// Function to move the tile vertically by a given speed
void Tile::move_d(float speed) {
    move(0,speed);
}

// Function to move the tile by given offsets
void Tile::move(float xOff, float yOff) {
    m_shape.move(xOff, yOff);
    x = m_shape.getPosition().x;
    y = m_shape.getPosition().y;
    Collidable::x = m_shape.getPosition().x;
    Collidable::y = m_shape.getPosition().y;
}

// Function to update the position of the tile
void Tile::updatePosition() {
    if (y > WIN_H - TOL){
        m_shape.setPosition(x,-WIN_H);
        y = m_shape.getPosition().y;
        Collidable::y = m_shape.getPosition().y;
    }
}

// Function to get the position of the tile
Vector2f Tile::getPos(){
    return m_shape.getPosition();
}