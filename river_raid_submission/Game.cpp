#include "Game.hpp"

// Initialize game objects
void init_objects() {
    // Initialize player object
    pl.setPos(PLAYER_INIT_X, PLAYER_INIT_Y);  // Set initial position of the player


    // Initialize greenery objects (land on both sides of the river)
    right_lane.setShape(land_right);
    right_lane2.setShape(land_right);
    left_lane.setShape(land_left);
    left_lane2.setShape(land_left);
    // Set initial position and shape for greenery objects
    right_lane2.move(0, -right_lane2.getHeight());
    left_lane2.move(0, -left_lane2.getHeight());


    // Initialize road objects
    // Set initial position and shape for road objects
    road_tl.setShape(road_topLeft);
    road_bl.setShape(road_bottomLeft);
    road_tr.setShape(road_topRight);
    road_br.setShape(road_bottomRight);
    road_br.move(0, -road_br.getHeight() + 1);
    road_bl.move(0, -road_bl.getHeight() + 1);

    // Initialize corner objects
    // Set initial position and shape for corner objects
    corner_tl.setShape(corner_top_l);
    corner_bl.setShape(corner_bottom_l);
    corner_tr.setShape(corner_top_r);
    corner_br.setShape(corner_bottom_r);
    corner_br.move(0, -2 * road_br.getHeight() + 1);
    corner_bl.move(0, -2 * road_bl.getHeight() + 1);





    // Initialize enemy objects
    for (int i{0}; i < enemy_nbr; i++) {
        //choose random enemy shape which are given the values between 5 to 8 (enumerated)
        Enemy::e_Enemy enm = static_cast<Enemy::e_Enemy>(rand() % 4 + 5);
        float x;
        // Set initial position and shape for enemy objects
        enemys[i] = Enemy(enm);
        int enemy_width = enemys[i].getWidth() + 2;
        static float y{pl.getPos().y - enemys[i].getHeight() - 100};  // let 100 be an offset between each character

        // Spawn enemies based on the y value of the narrow section of the river
        if (y < road_tl.getPos().y + road_tl.getHeight() && y > road_bl.getPos().y + road_bl.getHeight()) {
            enemys[i] = Enemy(Enemy::bridge);
            enemys[i].setPos(road_bl.getPos().x + road_bl.getWidth(), road_tl.getPos().y);
            enemys[i + 1] = Enemy(Enemy::bridge);
            enemys[i + 1].setPos(road_bl.getPos().x + road_bl.getWidth(),
                                 road_bl.getPos().y + road_bl.getHeight() * 1 / 2);
            y -= 100 + 2 * road_bl.getHeight();
            i++;
            continue;
        }

        if (enm != Enemy::plane)
            x = static_cast<float >(rand() % (SPAWN_AREA_END - SPAWN_AREA_BEGIN + 1 - enemy_width) +
                                    SPAWN_AREA_BEGIN);  // change depending on frame size or spawning window
        else
            x = static_cast<float >(rand() % (SPAWN_AREA_END + PLANE_OFFSET - (SPAWN_AREA_BEGIN - PLANE_OFFSET) + 1) +
                                    SPAWN_AREA_BEGIN - PLANE_OFFSET);
        enemys[i].setPos(x, y);
        y -= 100;
    }

    // Initialize bullets objects
    for (int i{0}; i < shots_nbr; i++) {
        // Set initial position and shape for bullets objects
        shots[i] = Character(pick_shape(Shapes::empty));
        shots[i].move(WIN_W + 100, WIN_H + 100);
    }

    // Initialize fuel tank objects
    for (int i{0}; i < fuel_nbr; i++) {
        // Set initial position and shape for fuel tank objects
        fuels[i] = Fuel(1); // spawns fuel
        int fuel_width = fuels[i].getWidth();
        float x = static_cast<float>(rand() % (SPAWN_AREA_END - SPAWN_AREA_BEGIN + 1 - fuel_width) +
                                     SPAWN_AREA_BEGIN);  //change depending on frame size or spawning window
        static float y{pl.getPos().y - fuels[i].getHeight() - 150};  // initial spwan with offset of 150
        fuels[i].setPos(x, y);
        y -= 150; // update it each time
    }
}

// Move game objects
void move_objects() {
    for (int i{0}; i < enemy_nbr; i++) {
        if (enemys[i].getState() == explode || enemys[i].getState() == killed || enemys[i].getState() == deleted) {
            continue;
        }
        // Move enemy objects horizontally
        enemys[i].move_lr();
    }
    // Move bullets objects vertically
    for (int i{0}; i < shots_nbr; i++) {
        if (shots[i].getState() == deleted) continue;
        shots[i].move(0, -3);
    }
}

// Move game objects downwards based on player's speed
void move_objects_down() {

    //===Move enemies, fuels, greenery, roads, and corners downwards===//

    for (int i{0}; i < enemy_nbr; i++) {
        if (enemys[i].getState() == deleted) continue;  // addtion to stop motion of deleted objects
        enemys[i].move_d(pl.getSpeed());
    }
    for (int i{0}; i < fuel_nbr; i++) {
        if (fuels[i].getState() == deleted) continue;  // addtion to stop motion of deleted objects
        fuels[i].move_d(pl.getSpeed());
    }

    right_lane.move_d(pl.getSpeed());
    right_lane2.move_d(pl.getSpeed());
    left_lane.move_d(pl.getSpeed());
    left_lane2.move_d(pl.getSpeed());

    road_tl.move_d(pl.getSpeed());
    road_tr.move_d(pl.getSpeed());
    road_bl.move_d(pl.getSpeed());
    road_br.move_d(pl.getSpeed());

    corner_tl.move_d(pl.getSpeed());
    corner_tr.move_d(pl.getSpeed());
    corner_bl.move_d(pl.getSpeed());
    corner_br.move_d(pl.getSpeed());

    // Reduce fuel level based on player's speed
    board.change_fuel(-0.1);
}

// Kill game objects upon collision
void kill_objects() {
    // Check if the player is out of fuel
    if (!board.check_fuel()) {
        pl.kill(pick_exp(exp1));
        board.update_lifes(-1);
        reset = true;
    }

    // Kill player and update lives if colliding with greenery or roads
    if (pl.isColliding(right_lane) || pl.isColliding(right_lane2) || pl.isColliding(left_lane) ||
        pl.isColliding(left_lane2)) {
        pl.kill(pick_exp(exp1));
        board.update_lifes(-1);
        reset = true;
    }
    if (pl.isColliding(road_tl) || pl.isColliding(road_tr) || pl.isColliding(road_bl) || pl.isColliding(road_br)) {
        pl.kill(pick_exp(exp1));
        board.update_lifes(-1);
        reset = true;
    }

    // Kill player and enemy if they collide, update lives and set reset flag
    for (int i{0}; i < enemy_nbr; i++) {
        if (enemys[i].getState() == explode || enemys[i].getState() == killed || enemys[i].getState() == deleted) {
            continue;
        }
        if (pl.isColliding(enemys[i])) {
            pl.kill(pick_exp(exp1));
            enemys[i].kill(pick_exp(exp1));
            board.update_lifes(-1);
            reset = true;
        }
    }

    // Remove bullets that collide with roads
    for (int i{0}; i < shots_nbr; i++) {
        if (shots[i].isColliding(road_tl)
            || shots[i].isColliding(road_bl)
            || shots[i].isColliding(road_tr)
            || shots[i].isColliding(road_br)
                ) {
            shots[i] = Character();
            shots[i].move(WIN_W + 100, WIN_H + 100);
        }
    }

    // Kill enemy objects when they collide with bullets and update score
    for (int i{0}; i < enemy_nbr; i++) {
        if (enemys[i].getState() == explode || enemys[i].getState() == killed || enemys[i].getState() == deleted) {
            continue;
        }
        for (int j{0}; j < shots_nbr; j++)
            if (shots[j].isColliding(enemys[i])) {
                shots[j] = Character();
                shots[j].move(WIN_W + 100, WIN_H + 100);
                enemys[i].kill(pick_exp(exp1));
                board.update_score(enemys[i].getScore());
            }
    }

    // Kill fuel objects when they collide with bullets and update score
    for (int i{0}; i < fuel_nbr; i++) {
        if (fuels[i].getState() == explode || fuels[i].getState() == killed || fuels[i].getState() == deleted) {
            continue;
        }
        for (int j{0}; j < shots_nbr; j++) {
            if (shots[j].isColliding(fuels[i])) {
                shots[j] = Character();
                shots[j].setPos(WIN_W + 100, WIN_H +
                                             100);  // a random location so the ampty shot will not collide with the empty enemy
                fuels[i].kill(pick_exp(exp2));
                board.update_score(fuels[i].getScore());
            }
        }
    }
}

// Animate and delete game objects
void animate_delete() {
    // respawning to an empty state if state is killed
    static int animation_c2 = 0;
    if (animation_c2 > 10) {
        for (int i{0}; i < enemy_nbr; i++) {
            // Remove killed objects after the animation is finished
            if (enemys[i].getState() == killed) {
                enemys[i] = Enemy();
                enemys[i].move(-100, -100);
            }
        }
        for (int i{0}; i < fuel_nbr; i++) {
            if (fuels[i].getState() == killed) {
                fuels[i] = Fuel();
                fuels[i].move(-100, -100);
            }
        }
        animation_c2 = 0;
    }
    animation_c2++;

    // Change object state from exploding to killed after the animation
    static int animation_c = 0;
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

        animation_c = 0;
    }
    animation_c++;
}

// Kill objects that are outside the frame
void kill_objects_outsideFrame() {
    // Kill enemy and fuel objects that are below the frame
    for (int i{0}; i < enemy_nbr; i++) {
        if (enemys[i].getY() > WIN_H) {
            enemys[i].setState(killed);
        }
    }
    for (int i{0}; i < fuel_nbr; i++) {
        if (fuels[i].getY() > WIN_H) {
            fuels[i].setState(killed);
        }
    }

    // Remove bullets that are above the frame
    for (int i{0}; i < shots_nbr; i++) {
        if (shots[i].getY() + shots[i].getHeight() < 0) {
            shots[i] = Character();
            shots[i].move(WIN_W + 100, WIN_H + 100);
        }
    }
}

// Update position of tiles
void updateTiles() {
    // Update position for greenery, roads, and corner objects
    right_lane.updatePosition();
    right_lane2.updatePosition();
    left_lane.updatePosition();
    left_lane2.updatePosition();

    road_tl.updatePosition();
    road_tr.updatePosition();
    road_bl.updatePosition();
    road_br.updatePosition();

    corner_tl.updatePosition();
    corner_tr.updatePosition();
    corner_bl.updatePosition();
    corner_br.updatePosition();
}

// Respawn game objects
void respawn_objects() {
    // Respawn enemy objects and set their position and shape
    for (int i{0}; i < enemy_nbr; i++) {
        if (enemys[i].getState() == deleted) {
            //choose random enemy shape which are given the values between 5 to 8
            Enemy::e_Enemy enm = static_cast<Enemy::e_Enemy>(rand() % 4 + 5);
            float x;
            enemys[i] = Enemy(enm);
            int enemy_width = enemys[i].getWidth() + 2;
            if (enm == Enemy::plane)
                x = static_cast<float >(
                        rand() % (SPAWN_AREA_END + PLANE_OFFSET - (SPAWN_AREA_BEGIN - PLANE_OFFSET) + 1 - enemy_width) +
                        SPAWN_AREA_BEGIN - PLANE_OFFSET);
            else
                x = static_cast<float >(rand() % (SPAWN_AREA_END - SPAWN_AREA_BEGIN + 1) + SPAWN_AREA_BEGIN);

            enemys[i].setPos(x, 0 - enemys[i].getHeight());
            // Spawn enemies based on the y value of the narrow section of the river
            if (enemys[i].getPos().y < road_tl.getPos().y + road_tl.getHeight() &&
                enemys[i].getPos().y > road_bl.getPos().y + road_bl.getHeight()) {
                enemys[i] = Enemy(Enemy::bridge);
                enemys[i].setPos(road_bl.getPos().x + road_tl.getWidth(), road_tl.getPos().y);
                enemys[i + 1] = Enemy(Enemy::bridge);
                enemys[i + 1].setPos(road_bl.getPos().x + road_tl.getWidth(),
                                     road_bl.getPos().y + road_bl.getHeight() * 1 / 2);
                i++;
                continue;
            }
            break;
        }
    }

    // Respawn fuel objects and set their position and shape
    for (int i{0}; i < fuel_nbr; i++) {
        if (fuels[i].getState() == deleted) {
            fuels[i] = Fuel(1); // spawns fuel
            int fuel_width = fuels[i].getWidth() + 2;
            float x = static_cast<float >(rand() % (SPAWN_AREA_END - SPAWN_AREA_BEGIN + 1 - fuel_width) +
                                          SPAWN_AREA_BEGIN);  //change depending on frame size or spawning window
            fuels[i].setPos(x, 0 - fuels[i].getHeight());
            break;
        }
    }
}

// Function to draw all objects in the game scene
void draw_scene() {
    // Draw lanes
    window.draw(right_lane.draw());
    window.draw(right_lane2.draw());
    window.draw(left_lane.draw());
    window.draw(left_lane2.draw());

    // Draw road lines
    window.draw(road_tl.draw());
    window.draw(road_tr.draw());
    window.draw(road_bl.draw());
    window.draw(road_br.draw());

    // Draw road corners
    window.draw(corner_tl.draw());
    window.draw(corner_tr.draw());
    window.draw(corner_bl.draw());
    window.draw(corner_br.draw());

    // Draw player's plane
    window.draw(pl.draw());

    // Draw enemy vehicles
    for (int i{0}; i < enemy_nbr; i++) {
        window.draw(enemys[i].draw());
    }

    // Draw shots
    for (int i{0}; i < shots_nbr; i++) {
        window.draw(shots[i].draw());
    }

    // Draw fuel items
    for (int i{0}; i < fuel_nbr; i++) {
        window.draw(fuels[i].draw());
    }

    // Draw game scoreboard
    window.draw(board.draw());
}

// Function to refuel player's vehicle when colliding with fuel items
void refuel_player() {
    for (int i{0}; i < fuel_nbr; i++) {
        if (pl.isColliding(fuels[i])) {
            board.change_fuel(1);
        }
    }
}

// Function to reset the game state when player's vehicle is destroyed
void reset_game() {
    bool old{reset};

    // Display appropriate text depending on player's remaining lives
    while (reset) {
        pl.setSpeed(0);
        Text text;
        text.setFont(displayFont);
        if (board.get_lifes()) {
            text.setString("R TO RESPAWN");
            if (Keyboard::isKeyPressed(Keyboard::R)) {
                reset = false;
            }
        } else {
            text.setString("Game Over\n\nQ TO EXIT");
            if (Keyboard::isKeyPressed(Keyboard::Q)) {
                window.close();
                break;
            }
        }

        // Set text properties and position
        text.setCharacterSize(FONT_SIZE * (WIN_H / WIN_W / 1.5f)); // set the character size in pixels
        text.setFillColor(Color::Yellow); // set the color
        text.setPosition((WIN_W - text.getLocalBounds().width) / 2, WIN_H / 2);

        // Clear window and draw the scene and text
        window.clear(Color::Blue);
        draw_scene();
        window.draw(text);

        window.display();
    }

    // Reset player's vehicle and fuel when exiting the reset loop
    if (reset != old) {
        pl = Player();
        board.change_fuel(board.getTankSize() - board.getFuel());
        init_objects();
    }
}