//
// Created by REM005 on 5/2/2023.
//

#include "game.h"

void init_objects() {
    //Player pl;
    pl.setPos(500,800);  //change depending on frame size or spawning window

    // enemy initilization
    //Enemy enemys[enemy_nbr] {};
    for(int i{0} ; i < enemy_nbr;i++){
        //choose random enemy shape which are given the values between 5 to 9
        Enemy::e_Enemy enm = static_cast<Enemy::e_Enemy>(rand()%5+5);

        enemys[i] = Enemy(enm);
        float x = static_cast<float >(rand()% 1024) ;  // change depending on frame size or spawning window
        float y = static_cast<float >(rand()% 1024) ;  // change depending on frame size or spawning window
        enemys[i].setPos(x,y);
        if (pl.isColliding(enemys[i])) {
            enemys[i] = Enemy();
            cout << "object misplaced\n";
            --i ;
        }
        for(int j{0} ; j < i;j++) {
            if (enemys[i].getPos().y - enemys[j].getPos().y <= 20 && enemys[i].getPos().y - enemys[j].getPos().y >= -20 ) {
                enemys[i] = Enemy();
                cout << "object misplaced\n";
                --i ;
                break;
            }
        }
    }

    // bullets initilization
    //Character shots[shots_nbr] {};
    for(int i{0} ; i < shots_nbr;i++){
        shots[i] = Character(pick_shape(Shapes::empty));
    }

    // fuel tank initilization
    //Fuel fuels[fuel_nbr] {};
    for(int i{0} ; i < fuel_nbr;i++){
        fuels[i] = Fuel(1); // spawns fuel
        float x = static_cast<float >(rand()% 1024) ;  //change depending on frame size or spawning window
        float y = static_cast<float >(rand()% 1024) ;  //change depending on frame size or spawning window
        fuels[i].setPos(x,y);
        for(int j{0} ; j < i;j++) {
            if (fuels[i].getPos().y - fuels[j].getPos().y <= 20 && fuels[i].getPos().y - fuels[j].getPos().y >= -20 ) {
                fuels[i] = Fuel();  //kills fuel
                --i ;
                break;
            }
        }
    }
}

void move_objects() {
    for (int i{0}; i < enemy_nbr ; i++){
        if (enemys[i].getState() == explode || enemys[i].getState() == killed || enemys[i].getState() == deleted  ){
            continue;
        }
        enemys[i].move_lr();
    }
    for (int i{0}; i < shots_nbr ; i++){
        if(shots[i].getState() == deleted) continue;
        shots[i].move(0,-3);
    }
}

void move_objects_down() {
    for (int i{0}; i < enemy_nbr ; i++){
        enemys[i].move_d(pl.getSpeed());
    }
    for (int i{0}; i < fuel_nbr ; i++){
        fuels[i].move_d(pl.getSpeed());
    }
    board.change_fuel(-0.1);
}

void kill_objects() {
    for (int i{0}; i < enemy_nbr ; i++) {
        if (enemys[i].getState() == explode || enemys[i].getState() == killed || enemys[i].getState() == deleted ){
            continue;
        }
        if (pl.isColliding(enemys[i])) {
            pl.kill(pick_exp(exp1));
            enemys[i].kill(pick_exp(exp1));
            board.update_lifes(-1);
            reset = true ;
        }
    }
    for (int i{0}; i < enemy_nbr ; i++) {
        if (enemys[i].getState() == explode || enemys[i].getState() == killed  || enemys[i].getState() == deleted){
            continue;
        }
        for (int j{0}; j < shots_nbr; j++)
            if (shots[j].isColliding(enemys[i])) {
                shots[j] = Character();
                enemys[i].kill(pick_exp(exp1));
                board.update_score(enemys[i].getScore());
            }
    }
    for (int i{0}; i < fuel_nbr ; i++) {
        if (fuels[i].getState() == explode || fuels[i].getState() == killed || fuels[i].getState() == deleted ){
            continue;
        }
        for (int j{0}; j < shots_nbr; j++)
            if (shots[j].isColliding(fuels[i])) {
                shots[j] = Character();
                shots[j].setPos(1030,1030);  // a random location so the ampty shot will not collide with the empty enemy
                fuels[i].kill(pick_exp(exp2));
                board.update_score(fuels[i].getScore());
            }
    }
}


void animate_delete() {
    // respawning to an empty state if state is killed
    static int  animation_c2 = 0 ;
    if (animation_c2 > 10) {
        for (int i{0}; i < enemy_nbr ; i++){
            if (enemys[i].getState() == killed ) {
                enemys[i]=Enemy() ;
                cout << i << " enemy killed\n";
            }

        }

        for (int i{0}; i < fuel_nbr ; i++){
            if (fuels[i].getState() == killed ) {
                fuels[i]=Fuel()   ;
                cout << i <<" fuel killed\n";

            }

        }
        animation_c2 = 0 ;
    }
    animation_c2++ ;

    //turn from exploding state to killed state
    static int  animation_c = 0 ;
    if (animation_c > 10) {
        for (int i{0}; i < enemy_nbr; i++) {
            if (enemys[i].getState() == explode) {
                enemys[i].setState(killed);
            }
        }
        for (int i{0}; i < fuel_nbr; i++) {
            if (fuels[i].getState() == explode) {
                fuels[i].setState(killed);
            }
        }

        animation_c = 0 ;
    }
    animation_c++ ;
}

void kill_objects_outsideFrame(){
    for (int i{0}; i < enemy_nbr; i++) {
        if (enemys[i].getY() > 1024) {
            enemys[i].setState(killed);
        }
    }
    for (int i{0}; i < fuel_nbr; i++) {
        if (fuels[i].getY() > 1024) {
            fuels[i].setState(killed);
        }
    }

    for (int i{0}; i < shots_nbr; i++) {
        if (shots[i].getY() + shots[i].getHeight() < 0) {
            shots[i] = Character();
        }
    }
}

void respawn_objects(){
    for (int i{0}; i < enemy_nbr; i++) {
        if (enemys[i].getState() == deleted) {
            //choose random enemy shape which are given the values between 5 to 9
            Enemy::e_Enemy enm = static_cast<Enemy::e_Enemy>(rand()%5+5);

            enemys[i] = Enemy(enm);
            float x = static_cast<float >(rand()% 1024) ;  // change depending on frame size or spawning window

            enemys[i].setPos(x,0 - enemys[i].getHeight());
            break;
            for(int j{0} ; j < i;j++) {
                if (enemys[i].getPos().y - enemys[j].getPos().y <= 1 && enemys[i].getPos().y - enemys[j].getPos().y >= -1 ) {
                    enemys[i] = Enemy();
                    --i ;
                    break;
                }
            }
        }
    }
    for (int i{0}; i < fuel_nbr; i++) {
        if (fuels[i].getState() == deleted) {
            fuels[i] = Fuel(1); // spawns fuel
            float x = static_cast<float >(rand()% 1024) ;  //change depending on frame size or spawning window

            fuels[i].setPos(x,0 - enemys[i].getHeight());
            break;
            for(int j{0} ; j < i;j++) {
                if (fuels[i].getPos().y - fuels[j].getPos().y <= 20 && fuels[i].getPos().y - fuels[j].getPos().y >= -20 ) {
                    fuels[i] = Fuel();  //kills fuel
                    --i ;
                    break;
                }
            }
        }
    }



}


void draw_sean(){
    window.draw(pl.draw());


    for (int i{0}; i < enemy_nbr ; i++){
        window.draw(enemys[i].draw());
    }
    for (int i{0}; i < 100 ; i++){
        window.draw(shots[i].draw());
    }
    for (int i{0}; i < fuel_nbr ; i++){
        window.draw(fuels[i].draw());
    }
    window.draw(board.draw());
}

void refuel_player() {
    for(int i{0} ; i < fuel_nbr; i++){
        if(pl.isColliding(fuels[i])) {
            board.change_fuel(5);
        }
    }
}

void reset_game(){
    bool old {reset};
    while(reset) {

        Text text;
        text.setFont(font);
        if(board.get_lifes()) {
            text.setString("press Q to respawn");
            if (Keyboard::isKeyPressed(Keyboard::Q)) {
                reset = false;
            }
        }
        else {
            text.setString("Game over press Q to exit");
            if (Keyboard::isKeyPressed(Keyboard::Q)) {
                window.close();
                break;
            }
        }
        text.setCharacterSize(58); // set the character size in pixels
        text.setFillColor(Color::Yellow); // set the color
        text.setPosition(500-text.getLocalBounds().width/2,500);

        window.clear(Color::Transparent);
        window.draw(text);
        window.display();
    }
    if(reset != old ){
        pl = Player();
        board.change_fuel(board.getTankSize()-board.getFuel());
        init_objects();
    }
}