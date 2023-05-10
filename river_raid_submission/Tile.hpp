#ifndef RIVER_RAID_TILE_HPP
#define RIVER_RAID_TILE_HPP
#include <SFML/Graphics.hpp>
#include "Shapes.hpp"
#include "Collidable.hpp"

using namespace std;
using namespace sf;

// Tile class, inherits from Collidable
class Tile: public Collidable {
protected:
    Sprite m_shape; // Sprite for the tile
    float x{0}; // X position of the tile
    float y{0}; // Y position of the tile

public:
    float m_speed; // Speed of the tile
    Tile(); // Default constructor
    // Constructor taking a Shapes enum value as an argument
    Tile(Shapes s) : Collidable(), m_shape{pick_shape(s)} {
        // Set the position of the tile based on the shape type
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

        // Update the Collidable properties
        Collidable::x = m_shape.getPosition().x;
        Collidable::y = m_shape.getPosition().y;
        Collidable::w = m_shape.getLocalBounds().width;
        Collidable::h = m_shape.getLocalBounds().height;
    }

    void move_d(float speed); // Move the tile vertically
    void move(float xOff, float yOff); // Move the tile with given offsets
    void updatePosition(); // Update the position of the tile
    void setShape(Shapes); // Set the shape of the tile
    Sprite draw(); // Draw the tile

    Vector2f getPos(); // Get the position of the tile
};

#endif //RIVER_RAID_TILE_HPP
