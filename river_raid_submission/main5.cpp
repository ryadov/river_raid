#include "Game.hpp"

using namespace std;
using namespace sf;

SoundBuffer shot_buf;           // buffer for shot sound
Sound shot_sound;               // shot sound from buffer
Texture texture;               // sprite sheet texture
//Texture texture_land;
RenderWindow window;           // window
Tile right_lane;                //          right side lane
Tile right_lane2;               // a second right side lane for double buffering purposes

Tile road_tl;                   // top    left  road
Tile road_tr;                   // top    right road
Tile road_bl;                   // bottom left  road
Tile road_br;                   // bottom right road

Tile corner_tl;                 // top    left  corner
Tile corner_tr;                 // top    right corner
Tile corner_bl;                 // bottom left  corner
Tile corner_br;                 // bottom right corner

Tile left_lane;                // right side lane
Tile left_lane2;                // left  side lane
Enemy enemys[enemy_nbr]{};     // Array of Enemy     objects initialized with a fixed enemy     count (enemies)
Character shots[shots_nbr]{};  // Array of Character objects initialized with a fixed Character count (bullets)
Fuel fuels[fuel_nbr]{};        // Array of Fuel      objects initialized with a fixed Fuel      count (fuel tanks)
Player pl;                      // Player object instantiation
bool reset{false};              // Boolean for game reset logic
Scoreboard board;              // Scoreboard object instantiation
Font displayFont;               // Font object instantiation

int main() {
    // window with width and height defined globally, title of game is passed
    window.create(VideoMode(WIN_W, WIN_H), "River Raid");
    // Limiting the frame rate
    window.setFramerateLimit(FRAME_RATE);

    // Loading the sprite sheet as a texture, with error handling
    if (!texture.loadFromFile("../sprite_sheet_roads.png")) {
        cout << "Could not load sprite sheet." << endl;
        return EXIT_FAILURE;
    }

//    if (!texture_land.loadFromFile("../map_enhanced_right.png")) {
//        cout << "Could not load texture." << endl;
//        return EXIT_FAILURE;
//    }

    // Loading a .ttf file as a font, with error handling
    if (!displayFont.loadFromFile(FONT)) {
        cout << "Could not load font." << endl;
        return EXIT_FAILURE;
    }

    // Loading a .mp3 file as a sound buffer, with error handling
    if (!shot_buf.loadFromFile("../shoot_sound.mp3")) {
        cout << "Could not load audio." << endl;
        return EXIT_FAILURE;
    }

    shot_sound.setBuffer(shot_buf);         // set the sound buffer to the sound object
    init_objects();                         // initializing all objects, or setting them back to their initial values

    int shot_c = 0;                        // defining a bullet shot count

    // Game Loop
    while (window.isOpen()) {

        Event event;                        // instantiating an event object for polling


        static bool shoot_button = false;  // defining a boolean variable for shoot button logic

        // check all the window's events that were triggered since the last iteration of the loop
        while (window.pollEvent(event)) {

            // if window close button is pressed
            if (event.type == Event::Closed)
                window.close(); // close window, exit program

            // if any key is pressed
            if (event.type == Event::KeyPressed) {

                // if the space key is pressed
                if (event.key.code == Keyboard::Space) {
                    shot_sound.play();                      // play bullet shot sound
                    shot_sound.setVolume(2);                // set volume of sound
                    shoot_button = true;                    // set the boolean button shot

                    // if the number of bullets shot is greater than or equal to bullet number allocated, shots_nbr
                    if (shot_c >= shots_nbr)
                        shot_c = 0;                         // reset shot count to 0

                    shots[shot_c] = pl.shoot();             // set the shot bullet to the sprite returned by pl.shoot()
                    ++shot_c;                               // increase the number of bullets shot
                }
            }
        }

        // if left button is pressed
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            pl.move(-DELTA_X, 0);                  // move the player to the left
            pl.changeSprite(pick_shape(player_l));    // change the shape to hovering left
        }

        // if right button is pressed
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            pl.move(DELTA_X, 0);                   // move the player to the right
            pl.changeSprite(pick_shape(player_r));    // change the shape to hovering right
        }

        // if neither right nor left buttons are pressed
        if (!Keyboard::isKeyPressed(Keyboard::Right) && !Keyboard::isKeyPressed(Keyboard::Left))
            pl.changeSprite(pick_shape(player));      // change back to original shape

        // if up button is pressed
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            pl.setSpeed(SPEED_UP);                          // speed the player up
        }

        // if down button is pressed
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            pl.setSpeed(SPEED_DOWN);                        // slow the player down

        }

        // if neither up nor down buttons are pressed
        if (!(Keyboard::isKeyPressed(Keyboard::Down)) && !(Keyboard::isKeyPressed(Keyboard::Up))) {
            pl.setSpeed(SPEED_NO_KEY);                      // keep player speed constant
        }

        kill_objects();                                    // call the kill objects function to kill any object
        kill_objects_outsideFrame();                        // call the kill objects outside frame to remove them
        updateTiles();                                      // call the update tiles function to update position of map
        move_objects_down();                               // call the move objects down function to scroll down screen
        move_objects();                                     // call the move objects function to move left and right
        refuel_player();                                    // call the refuel player function to add more fuel


        window.clear(Color::Blue);                    // clear window with blue background (Water)
        draw_scene();                                      // draw everything on the screen
        window.display();                                  // display it on the screen

        animate_delete();                                  // animate the deletion of objects (e.g. explosion)

        static int spawn_rate{0};                          // defining the spawn rate

        // if the spawn rate is more than 10
        if (spawn_rate > 10) {
            respawn_objects();                             // respawn objects
            spawn_rate = 0;                                // reset spawn rate
        }
        ++spawn_rate;                                      // increment spawn rate

        reset_game();                                      // reset game if boolean reset is true

    }

    return EXIT_SUCCESS;
}
