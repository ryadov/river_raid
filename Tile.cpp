//
// Created by Riyadh Alghamdi on 06/05/2023.
//

#include "Tile.hpp"



Tile::Tile(Shapes s) {
    m_shape = pick_shape(s);
    m_shape.setPosition(150,500);
}

Sprite Tile::draw() {
    return m_shape;
}
