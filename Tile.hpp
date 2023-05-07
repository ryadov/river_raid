//
// Created by Riyadh Alghamdi on 06/05/2023.
//

#ifndef RIVER_RAID_TILE_HPP
#define RIVER_RAID_TILE_HPP
#include <SFML/Graphics.hpp>
#include "Shapes.hpp"

using namespace std;
using namespace sf;

class Tile {
private:
    Sprite m_shape;
    float x{0};
    float y{0};
public:
    float m_speed;
    Tile(Shapes);
    Sprite draw();

};


#endif //RIVER_RAID_TILE_HPP
