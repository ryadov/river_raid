#include "Game.hpp"

using namespace std;
using namespace sf;

Texture texture ;
Texture texture_land;
RenderWindow window ;
Tile right_lane{Shapes::land_right};
//Tile left_lane;
Enemy enemys[enemy_nbr] {};
Character shots[shots_nbr] {};
Fuel fuels[fuel_nbr] {};
Player pl;
bool reset{false};
Scoreboard board ;
Font displayFont;

int main() {
    window.create(VideoMode(WIN_W, WIN_H), "River Raid");
//    window.setPosition(Vector2i(0,0));    // set the window position relative to monitor
    window.setFramerateLimit(FRAME_RATE);
    //load an image // ??
    //player straight // ??

    if (!texture.loadFromFile("../sprite_sheet_clear.png")) {
        cout << "Could not load sprite sheet." << endl;
        return EXIT_FAILURE;
    }

    if (!texture_land.loadFromFile("../map_enhanced_right.png")) {
        cout << "Could not load texture." << endl;
        return EXIT_FAILURE;
    }

    if (!displayFont.loadFromFile(FONT)) {
        cout << "Could not load font." << endl;
        return EXIT_FAILURE;
    }

    double x {100}; // ??
    int dir {1};    // ??

    init_objects();

    int shot_c = 0 ;
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        Event event;

        static bool shoot_botton = false ;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == Event::Closed) window.close();
            if (event.type ==Event::KeyPressed) {
                if (event.key.code == Keyboard::Space) {
                    shoot_botton = true;
                    if (shot_c >= shots_nbr) shot_c = 0;
                    shots[shot_c] = pl.shoot();
                    cout << "Bullet Shot" << endl;
                    ++shot_c;
                }
            }
//            if (event.type ==Event::KeyPressed) {
//                if (event.key.code == Keyboard::Q) {
//
//
//                }
//            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            pl.move(-DELTA_X, 0);
            pl.changeSprite(pick_shape(player_l));
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)){
            pl.move(DELTA_X, 0);
            pl.changeSprite(pick_shape(player_r));
        }

        if(!Keyboard::isKeyPressed(Keyboard::Right) && !Keyboard::isKeyPressed(Keyboard::Left))
            pl.changeSprite(pick_shape(player));


        if (Keyboard::isKeyPressed(Keyboard::Up)){
            pl.setSpeed(SPEED_UP);
        }

        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            pl.setSpeed(SPEED_DOWN);

        }
        if (!(Keyboard::isKeyPressed(Keyboard::Down)) && !(Keyboard::isKeyPressed(Keyboard::Up))) {
            pl.setSpeed(SPEED_NO_KEY);
        }


//        for testing
//        if (Keyboard::isKeyPressed(Keyboard::Q)) {
//            board.change_fuel(-1);
//
//        }
//        if (Keyboard::isKeyPressed(Keyboard::W)) {
//            board.change_fuel(1);
//
//        }
//        if (Keyboard::isKeyPressed(Keyboard::A)) {
//            board.update_score(100);
//
//        }
//        if (Keyboard::isKeyPressed(Keyboard::S)) {
//            board.update_lifes(1);
//
//        }


        kill_objects() ;
        kill_objects_outsideFrame();
        move_objects_down() ;
        move_objects();
        refuel_player();


        window.clear(Color::Blue);
        draw_scene();
        window.display();

        animate_delete();


        // until we fix the deleteing of objects issue
        //this algorithem doesnt work for now
        static int spawn_rate{0};
        if (spawn_rate > 5) {
            respawn_objects();
            spawn_rate = 0 ;
        }
        ++spawn_rate ;

        reset_game();

    }

    return 0;
}
