#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.hpp"
#include "Sprites.hpp"

#define DELTA_X 1
#define WIN_H 1024
#define WIN_W 1024
#define FRAME_RATE 60

using namespace sf;
using namespace std;
int main() {

    if(!defineSprites())
        return EXIT_FAILURE;

//    int collisionCount{0};
    Image mapImage;
    if (!mapImage.loadFromFile("../Map_enhanced.png")) {
        return EXIT_FAILURE;
    }
    Texture mapTexture;
    if (!mapTexture.loadFromImage(mapImage)) {
        return EXIT_FAILURE;
    }

    Sprite mapSprite;
    mapSprite.setTexture(mapTexture);

    int map_H = mapSprite.getLocalBounds().height;
    int map_W = mapSprite.getLocalBounds().width;

    RenderWindow window(VideoMode(map_W, map_W), "River Raid");
    window.setFramerateLimit(FRAME_RATE);
//    mapSprite.move(0, - map_H + map_W); // set y to - 1049 + 304 = - 745

    Color riverColor(45, 50, 187);
    Color riverbankColor(110, 156, 66);

    Character player(spt1);
    player.setOrigin(player.getX() + player.getWidth()/2, player.getY() + player.getHeight()/2);
    player.setPos(100, 100);


    cout << "Player (x,y,w,h): ";
    cout << player.getX() << " " << player.getY() << " " << player.getWidth() << " " << player.getHeight()<< endl;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Left))
            player.move(-DELTA_X, 0);

        if (Keyboard::isKeyPressed(Keyboard::Right))
            player.move(DELTA_X, 0);

        if (Keyboard::isKeyPressed(Keyboard::Up))
            player.move(0, -DELTA_X);

        if (Keyboard::isKeyPressed(Keyboard::Down))
            player.move(0, DELTA_X);

//        Image mapImage = mapTexture.copyToImage();
//        mapImage.move();
        Color pix1 = mapImage.getPixel(player.getX() - player.getWidth() / 2, player.getY() - player.getHeight() / 2);
        Color pix2 = mapImage.getPixel(player.getX() - player.getWidth() / 2, player.getY());
        Color pix3 = mapImage.getPixel(player.getX() - player.getWidth() / 2, player.getY() + player.getHeight() / 2);
        Color pix4 = mapImage.getPixel(player.getX(), player.getY() - player.getHeight() / 2);
        Color pix5 = mapImage.getPixel(player.getX(), player.getY() + player.getHeight() / 2);
        Color pix6 = mapImage.getPixel(player.getX() + player.getWidth() / 2, player.getY() - player.getHeight() / 2);
        Color pix7 = mapImage.getPixel(player.getX() + player.getWidth() / 2, player.getY());
        Color pix8 = mapImage.getPixel(player.getX() + player.getWidth() / 2, player.getY() + player.getHeight() / 2);

        bool planeCrashed = (pix1 == riverbankColor)
                            || (pix2 == riverbankColor)
                            || (pix3 == riverbankColor)
                            || (pix4 == riverbankColor)
                            || (pix5 == riverbankColor)
                            || (pix6 == riverbankColor)
                            || (pix7 == riverbankColor)
                            || (pix8 == riverbankColor);
        if (planeCrashed) {
            cout << "collided with riverbank!" << endl;
            break;
        }

        window.clear(Color::White);
        window.draw(mapSprite);
        window.draw(player.draw());



















        window.display();
    }

    return EXIT_SUCCESS;
}
