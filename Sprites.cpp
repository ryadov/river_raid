//
// Created by Riyadh Alghamdi on 27/04/2023.
//
#include <SFML/Graphics.hpp>
#include "Sprites.hpp"

using namespace sf;
Texture texture;
Sprite spt1;
Sprite spt2;
Sprite spt3;
Sprite spt4;
Sprite spt5;
Sprite spt6;
Sprite spt7;
Sprite spt8;
Sprite spt9;
Sprite spt10;
Sprite spt11;
Sprite spt12;
Sprite spt13;
Sprite spt14;
Sprite l1;
Sprite l2;
Sprite l3;
Sprite l4;
Sprite l5;
Sprite l6;
Sprite l7;
Sprite in1;
Sprite in2;
Sprite in3;
Sprite s1;
Sprite s2;
Sprite s3;
Sprite s4;
Sprite s5;
Sprite s6;
Sprite s7;
Sprite s8;
Sprite s9;
Sprite s0;
bool defineSprites() {
    if (!texture.loadFromFile("../sprite_sheet_clear.png"))
        return false;
    spt1.setTexture(texture);
    spt1.setTextureRect(IntRect(26, 17, 14, 13));
//right lean
    spt2.setTexture(texture);
    spt2.setTextureRect(IntRect(43, 18, 10, 14));
//left lean
    spt3.setTexture(texture);
    spt3.setTextureRect(IntRect(43, 18, 10, 14));
//heli 1
    spt4.setTexture(texture);
    spt4.setTextureRect(IntRect(3, 46, 16, 10));
//heli 2
    spt5.setTexture(texture);
    spt5.setTextureRect(IntRect(21, 46, 16, 10));
//plane
    spt6.setTexture(texture);
    spt6.setTextureRect(IntRect(40, 49, 16, 6));
//ship
    spt7.setTexture(texture);
    spt7.setTextureRect(IntRect(4, 58, 32, 10));
//explosion 1
    spt8.setTexture(texture);
    spt8.setTextureRect(IntRect(8, 78, 14, 11));
//explosion 2
    spt9.setTexture(texture);
    spt9.setTextureRect(IntRect(7, 99, 12, 8));
//explosion 3
    spt10.setTexture(texture);
    spt10.setTextureRect(IntRect(30, 99, 26, 8));
//explosion 4
    spt11.setTexture(texture);
    spt11.setTextureRect(IntRect(5, 111, 16, 13));
//explosion 5
    spt12.setTexture(texture);
    spt12.setTextureRect(IntRect(26, 111, 34, 13));
//fuel
    spt13.setTexture(texture);
    spt13.setTextureRect(IntRect(153, 15, 14, 24));
//bridge
    spt14.setTexture(texture);
    spt14.setTextureRect(IntRect(172, 16, 63, 22));
//land1
    l1.setTexture(texture);
    l1.setTextureRect(IntRect(84, 15, 31, 24));
//land2
    l2.setTexture(texture);
    l2.setTextureRect(IntRect(117, 15, 31, 24));
//land top right
    l3.setTexture(texture);
    l3.setTextureRect(IntRect(117, 6, 31, 8));
//land top left
    l4.setTexture(texture);
    l4.setTextureRect(IntRect(84, 6, 31, 8));
//land bottom right
    l5.setTexture(texture);
    l5.setTextureRect(IntRect(117, 40, 31, 8));
//land bottom left
    l6.setTexture(texture);
    l6.setTextureRect(IntRect(84, 40, 31, 8));
//street
    l7.setTexture(texture);
    l7.setTextureRect(IntRect(67, 14, 15, 26));
//interface
//fuel bar
    in1.setTexture(texture);
    in1.setTextureRect(IntRect(74, 66, 78, 15));
//label
    in2.setTexture(texture);
    in2.setTextureRect(IntRect(88, 84, 64, 7));
//lifes
    in3.setTexture(texture);
    in3.setTextureRect(IntRect(154, 70, 4, 10));
//score
    s1.setTexture(texture);
    s1.setTextureRect(IntRect(74, 96, 8, 8));
    s2.setTexture(texture);
    s2.setTextureRect(IntRect(84, 96, 12, 8));
    s3.setTexture(texture);
    s3.setTextureRect(IntRect(84 + 14, 96, 12, 8));
    s4.setTexture(texture);
    s4.setTextureRect(IntRect(84 + 14 * 2, 96, 12, 8));
    s5.setTexture(texture);
    s5.setTextureRect(IntRect(84 + 14 * 3, 96, 12, 8));
    s6.setTexture(texture);
    s6.setTextureRect(IntRect(84 + 14 * 4, 96, 12, 8));
    s7.setTexture(texture);
    s7.setTextureRect(IntRect(84 + 14 * 5, 96, 12, 8));
    s8.setTexture(texture);
    s8.setTextureRect(IntRect(84 + 14 * 6, 96, 12, 8));
    s9.setTexture(texture);
    s9.setTextureRect(IntRect(84 + 14 * 7, 96, 12, 8));
    s0.setTexture(texture);
    s0.setTextureRect(IntRect(84 + 14 * 8, 96, 12, 8));
    return true;
}