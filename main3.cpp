#include "game.h"

#define DELTA_X 1
#define WIN_H 1024
#define WIN_W 1024
#define FRAME_RATE 60

sf::Texture texture ;
RenderWindow window ;

Enemy enemys[enemy_nbr] {};
Character shots[shots_nbr] {};
Fuel fuels[fuel_nbr] {};
Player pl;
Scoreboard board ;
int main() {
    window.create(VideoMode(WIN_W, WIN_H), "My window");
    window.setPosition(sf::Vector2i(0,0));
    window.setFramerateLimit(FRAME_RATE);
    //load an image
    //player straight

    if (!texture.loadFromFile("sprite_sheet_clear.png")) return 0 ;




    double x {100};
    int dir {1};

    init_objects();

    int shot_c = 0 ;
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        static bool shoot_botton = false ;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) window.close();
            if (event.type ==Event::KeyPressed) {
                if (event.key.code == Keyboard::Space) {
                    shoot_botton = true;
                    if (shot_c >= shots_nbr) shot_c = 0;
                    shots[shot_c] = pl.shoot();
                    cout << "shooted\n" ;
                    ++shot_c;

                }
            }
            if (event.type ==Event::KeyPressed) {
                if (event.key.code == Keyboard::Q) {


                }
            }


        }
        if (Keyboard::isKeyPressed(Keyboard::Left))
            pl.move(-1, 0);

        if (Keyboard::isKeyPressed(Keyboard::Right))
            pl.move(1, 0);

        if (Keyboard::isKeyPressed(Keyboard::Up)){


        }

        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            pl.setSpeed(1);

        }
        else if (!(Keyboard::isKeyPressed(Keyboard::Down))) {
            pl.setSpeed(3);

        }


        //for testing
        if (Keyboard::isKeyPressed(Keyboard::Q)) {
            board.change_fuel(-1);

        }
        if (Keyboard::isKeyPressed(Keyboard::W)) {
            board.change_fuel(1);

        }
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            board.update_score(100);

        }
        if (Keyboard::isKeyPressed(Keyboard::S)) {
            board.update_lifes(1);

        }


        kill_objects() ;
        kill_objects_outsideFrame();
        move_objects_down() ;
        move_objects();
        refuel_player();


        window.clear(sf::Color::Blue);
        draw_sean();
        window.display();

        animate_delete();


        // until we fix the deleteing of objects issue
        //this algorithem doesnt work for now
        static int spawn_rate{0};
        if (spawn_rate > 1) {
            respawn_objects();
            spawn_rate = 0 ;
        }
        ++spawn_rate ;

    }

    return 0;
}
