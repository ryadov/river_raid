#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

void Hitting (Event event, int &score, Text &text_score);

int main() {
    const int WIDTH = 1200;
    const int HEIGHT = 640;

    Font font;
    if (!font.loadFromFile("../Phosphate.ttc")) cout << "errooorr"<< endl;

    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Score");
    window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(60);

    // LeaderBoard
    RectangleShape LeaderBoard(Vector2f(WIDTH, 150.f));
    LeaderBoard.setFillColor(Color(100, 100, 100));
    LeaderBoard.setPosition(0, HEIGHT-150);

    Texture texture;
    if (!texture.loadFromFile("../sprite_sheet_clear.png")) return false;
    // Fuel bar
    Sprite in1;
    in1.setTexture(texture);
    in1.setTextureRect(IntRect(74, 66, 78, 15));
    in1.setPosition(WIDTH/2 - 78/2*3, HEIGHT-100);
    in1.scale(3,3);

    // Fuel line
    Sprite in3;
    in3.setTexture(texture);
    in3.setTextureRect(IntRect(154, 70, 4, 10));
    in3.setPosition(in1.getPosition().x +78*3 -4*3 -10, in1.getPosition().y +4*3);
    int in3_initial_P = in3.getPosition().x;
    in3.scale(3,3);

    // Score
    int score = 0;
    Text text_score;
    text_score.setFont(font); // select the font

    text_score.setString(to_string(score));
    text_score.setCharacterSize(58); // set the character size in pixels
    text_score.setFillColor(Color::Yellow); // set the color
    text_score.setPosition(WIDTH/2 - 78/2*3+5, HEIGHT-165);
    //text_score.setOrigin(0, 0);

    //life
    int score_life = 10000;
    int life = 3;
    Text text_life;
    text_life.setFont(font); // select the font

    text_life.setString(to_string(life));
    text_life.setCharacterSize(58); // set the character size in pixels
    text_life.setFillColor(Color::Yellow); // set the color
    text_life.setPosition(WIDTH/2 + 78/2*2, HEIGHT-70);


    //while window
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) window.close();

            Hitting (event, score, text_score);

            // Get Fuel
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Right
            && in3.getPosition().x <= in3_initial_P) {
                in3.move(10,0);
            }
            // Consume Fuel
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Left) {
                in3.move(-5,0);
            }
            // Finish Fuel
            if (in3.getPosition().x <= in1.getPosition().x) {
                life--;
                text_life.setString(to_string(life)); // Die
                in3.setPosition(in1.getPosition().x +78*3 -4*3 -10, in1.getPosition().y +4*3);
            }
            if (score >= score_life) {
                score_life += 10000;
                life++;
                text_life.setString(to_string(life));
            }

        }
        window.clear(Color(Color::Black));
        window.draw(LeaderBoard);
        window.draw(text_score);
        window.draw(text_life);
        window.draw(in3);
        window.draw(in1);
        window.display();
    }

    return 0;
}

void Hitting (Event event, int &score, Text &text_score) {
    // hit Ship
    if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
        score += 30;
        text_score.setString(to_string(score));
    }
    // hit Helicopter
    if (event.type == Event::KeyPressed && event.key.code == Keyboard::LShift) {
        score += 60;
        text_score.setString(to_string(score));
    }
    // hit Fuel
    if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter) {
        score += 80;
        text_score.setString(to_string(score));
    }
    // hit Bridge
    if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up) {
        score += 500;
        text_score.setString(to_string(score));
    }
    // hit Plane
    if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down) {
        score += 100;
        text_score.setString(to_string(score));
    }
}
