// Define the Character class header guard
#ifndef CHARACTER_H
#define CHARACTER_H
// Include necessary SFML libraries
#include <SFML/Graphics.hpp>
// Include the Collidable class for handling collisions
#include "Collidable.hpp"
// Include the Shapes class for setting the character's shape
#include "Shapes.hpp"

using namespace sf;

// Define the State enumeration for character states
enum State {
    alive,
    explode,
    killed,
    deleted,
};

// Define the Character class, inheriting from Collidable
class Character: public Collidable {
protected:
    Sprite m_shape{pick_shape(Shapes::empty)}; // Character's sprite
    State m_killed {alive}; // Character's state
    int m_score {}; // Character's score


public:
    // Default constructor for the Character class
    Character( ) : Collidable(m_shape.getPosition().x, m_shape.getPosition().y, m_shape.getLocalBounds().width, m_shape.getLocalBounds().height), m_shape(pick_shape(Shapes::empty)) {
    m_killed = deleted;
    }

    // Constructor for the Character class with a specified shape
    Character(Sprite shape ) : Collidable(shape.getPosition().x, shape.getPosition().y, shape.getLocalBounds().width, shape.getLocalBounds().height), m_shape(shape) , m_killed{alive} {}
    // Destructor for the Character class
    ~Character() ;

    // Function to draw the character's sprite
    Sprite  draw() ;

    // Function to set the character to explode state and update its sprite
    void kill(Sprite shape);
    // Function to move the character vertically by a specified speed
    void move_d(float speed);

    // Setters
    void setPos(float x , float y);// Set the character's position
    void setOrigin(float x, float y);// Set the character's origin for rotation and scaling
    void setState(State state) ; // Set the character's state
    // Getters
    int getScore() { return m_score; }  // Get the character's score
    State getState();                   // Get the character's state
    Vector2f getPos();                  // Get the character's position
    void move(float xOff, float yOff);  // Move the character by an x and y offset
};


#endif // CHARACTER_H
