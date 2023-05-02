#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Shapes.h"
#include "Character.hpp"
#include "Player.h"
#include "Enemy.h"

#include <cstdlib>
#include <iostream>

#define DELTA_X 1
#define WIN_H 1024
#define WIN_W 1024
#define FRAME_RATE 60

sf::Texture texture ;

int main() {
    sf::RenderWindow window(sf::VideoMode(WIN_W, WIN_H), "My window");
    window.setPosition(sf::Vector2i(0,0));
    window.setFramerateLimit(FRAME_RATE);
    //load an image
    //player straight

    if (!texture.loadFromFile("sprite_sheet_clear.png")) return 0 ;




    double x {100};
    int dir {1};
    Player pl;
    pl.setPos(500,800);

    const int enemy_nbr {20};
    Enemy enemy_list[enemy_nbr] {};
    for(int i{0} ; i < enemy_nbr;i++){
        Enemy::e_Enemy enm = static_cast<Enemy::e_Enemy>(rand()%5+5);

        enemy_list[i] = Enemy(enm);
        float x = static_cast<float >(rand()% 1024) ;
        float y = static_cast<float >(rand()% 1024) ;
        enemy_list[i].setPos(x,y);
        if (pl.isColliding(enemy_list[i])) {
            enemy_list[i] = Enemy();
            --i ;
        }
        for(int j{0} ; j < i;j++) {
            if (enemy_list[i].getPos().y - enemy_list[j].getPos().y <= 20 && enemy_list[i].getPos().y - enemy_list[j].getPos().y >= -20 ) {
                enemy_list[i] = Enemy();
                --i ;
                break;
            }
        }
    }
    Character shots[100] {};
    for(int i{0} ; i < 100;i++){
        shots[i] = Character(pick_shape(empty));
    }


    int shot_c = 0 ;
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        static bool shoot_botton = false ;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) window.close();
            if (event.type ==Event::KeyPressed) {
                if (event.key.code == Keyboard::Enter) {
                    shoot_botton = true;
                    if (shot_c >= 100) shot_c = 0;
                    shots[shot_c] = pl.shoot();
                    ++shot_c;

                }
            }


        }
        if (Keyboard::isKeyPressed(Keyboard::Left))
            pl.move(-1, 0);

        if (Keyboard::isKeyPressed(Keyboard::Right))
            pl.move(1, 0);

        if (Keyboard::isKeyPressed(Keyboard::Up)){
            //pl.move(0, 1);
            for (int i{0}; i < enemy_nbr ; i++){
                enemy_list[i].move_d();
            }
        }



        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            pl.move(0, 1);

        }

        for (int i{0}; i < enemy_nbr ; i++) {
            if (enemy_list[i].getState() == explode || enemy_list[i].getState() == killed ){
                continue;
            }
            if (pl.isColliding(enemy_list[i])) {
                pl.kill(pick_exp(exp1));
                enemy_list[i].kill(pick_exp(exp1));
            }
        }
        for (int i{0}; i < enemy_nbr ; i++) {
            if (enemy_list[i].getState() == explode || enemy_list[i].getState() == killed ){
                continue;
            }
            for (int j{0}; j < 100; j++)
                if (shots[j].isColliding(enemy_list[i])) {
                    shots[j] = Character();
                    enemy_list[i].kill(pick_exp(exp1));
                }
        }


        for (int i{0}; i < enemy_nbr ; i++){
            if (enemy_list[i].getState() == explode || enemy_list[i].getState() == killed ){
                continue;
            }
            enemy_list[i].move_lr();
        }
        for (int i{0}; i < 100 ; i++){
            shots[i].move(0,-2);
        }


        window.clear(sf::Color::Blue);
        window.draw(pl.draw());


        for (int i{0}; i < enemy_nbr ; i++){
            window.draw(enemy_list[i].draw());
        }
        for (int i{0}; i < 100 ; i++){
            window.draw(shots[i].draw());
        }

        window.display();



        static int  animation_c2 = 0 ;
        if (animation_c2 > 10) {
            for (int i{0}; i < enemy_nbr ; i++){
                if (enemy_list[i].getState() == killed ) enemy_list[i]=Enemy()   ;

            }
            animation_c2 = 0 ;
        }
        animation_c2++ ;

        static int  animation_c = 0 ;
        if (animation_c > 10) {
            for (int i{0}; i < enemy_nbr; i++) {
                if (enemy_list[i].getState() == explode) {
                    enemy_list[i].setState(killed);
                }

            }
        animation_c = 0 ;
        }
        animation_c++ ;



    }

    return 0;
}
