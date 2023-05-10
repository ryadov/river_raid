#ifndef TEST2_SCOREBOARD_H
#define TEST2_SCOREBOARD_H

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "Shapes.hpp"
#include "Collidable.hpp"

using namespace sf;
using namespace std;

// Scoreboard class to manage the game's scoreboard
class Scoreboard {
protected:
    float frame_width; // Width of the frame
    float frame_hight; // Height of the frame

    // Fuel interface sprites
    Sprite fuel_tank = pick_shape(fuel_interface);
    Sprite fuel_mark = pick_shape(fuel_bar);
    RenderTexture texture;

    float mark_pose{}; // Position of the fuel mark
    float fuel_amount{}; // Amount of fuel
    float max_fuel{}; // Maximum fuel capacity

    int m_score{0}; // Score
    Text score_text; // Score text

    int m_lifes{3}; // Number of lives
    Text lifes_text; // Lives text

    Font font; // Font used for text
    stringstream stream; // String stream for text manipulation

public:
    // Default constructor for Scoreboard class
    Scoreboard() { set_interface_pose(); }
    void set_interface_pose(); // Set the position of the fuel interface

    float getFuel() { return fuel_amount; } // Get the current fuel amount
    float getTankSize() { return max_fuel; } // Get the maximum fuel capacity
    void change_fuel(float amount); // Change the fuel amount
    bool check_fuel(); // Check if there's enough fuel

    void update_score(int amount); // Update the score
    void update_lifes(int d); // Update the number of lives
    int get_lifes() { return m_lifes; } // Get the number of lives
    Sprite draw(); // Draw the scoreboard
};

#endif //TEST2_SCOREBOARD_H
