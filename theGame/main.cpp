#include <iostream>

#include "Game/Game.h"
#include "Game/Commands/Controller.h"

#include <ctime>
#include <SFML/Graphics.hpp>
#include <cmath>

#include <vector>
#include <algorithm>

#include "UI/Menu/Menu.h"

int nScreenWidth = 1600;            // Console Screen Size X (columns)
int nScreenHeight = 900;            // Console Screen Size Y (rows)
int nMapWidth = 16;                // World Dimensions
int nMapHeight = 16;
float prev_y = -1;
float prev_x = -1;

float pos_y = 1.0f;            // Player Start Position
float pos_x = 1.0f;
float fPlayerA = 0.0f;            // Player Start Rotation
float fFOV = 3.14159f / 4.0f;    // Field of View
float fDepth = 10.0f;            // Maximum rendering distance
float fSpeed = 2.0f;            // Walking Speed
using namespace std;
using namespace sf;


int main() {
    srand(time(0));
    cout << "Press 1 to play in console,Press 2 to play in exe" << endl;
    int mode = 0;
    cin >> mode;

    if (mode == 1) {

        Game *game = Game::get_instance();
        Field *field = Field::get_instance();

        game->start();

        while (field->test_status()) {
            game->print_console();
            game->get_state()->move();
        }

        std::cout << "Press ESC to close game\n";
        Controller controller(game);

        while (field->get_status() != CLOSE) {
            controller.inputCommand();
        }

    } else {

        Game *game = Game::get_instance();
        Field *field = Field::get_instance();
        Cell **map = field->get_cells();
        nMapWidth = field->get_size_x();
        nMapHeight = field->get_size_y();
        sf::Image icon;

        if (!icon.loadFromFile("img/icon32x32.png")) {
            return 1;
        }

        game->start();

        sf::RenderWindow window(sf::VideoMode(1600, 900), "MyGame");
        window.setIcon(32, 32, icon.getPixelsPtr());

        menu(window);

        Clock clock;

        field->get_cord_player(pos_x, pos_y);
        pos_x += 0.5;
        pos_y += 0.5;

        Image coin;
        if (!coin.loadFromFile("img/Elements/coin.png")) {
            cout << "img";
        }
        Texture coin_texture;
        coin_texture.loadFromImage(coin);
        Sprite coin_sprite;
        coin_sprite.setTexture(coin_texture);

        game->print_console();

        while (window.isOpen() && field->test_status()) {
            //game->print_console();
            window.clear();
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();


            Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            float fElapsedTime = time;
            // Handle CCW Rotation
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                fPlayerA -= (fSpeed * 0.75f) * fElapsedTime;
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                game->close();
            }

            // Handle CW Rotation
            if (Keyboard::isKeyPressed(Keyboard::Right))
                fPlayerA += (fSpeed * 0.75f) * fElapsedTime;

            // Handle Forwards movement & collision
            if (Keyboard::isKeyPressed(Keyboard::Up)) {
                pos_y += sinf(fPlayerA) * fSpeed * fElapsedTime;
                pos_x += cosf(fPlayerA) * fSpeed * fElapsedTime;
                field->get_cord_player(prev_x, prev_y);

                if (trunc(pos_x) - prev_x >= 1) {
                    cout << pos_x << " " << trunc(pos_x) << " " << trunc(pos_x) - prev_x << " " << prev_x << endl;
                    game->right();
                    field->move_enemies();
                    game->print_console();
                }
                if (trunc(pos_x) - prev_x <= -1) {
                    cout << pos_x << " " << trunc(pos_x) << " " << trunc(pos_x) - prev_x << " " << prev_x << endl;
                    game->left();
                    field->move_enemies();
                    game->print_console();

                }
                if (trunc(pos_y) - prev_y >= 1) {
                    cout << pos_y << " " << trunc(pos_y) << " " << trunc(pos_y) - prev_y << " " << prev_y << endl;
                    game->down();
                    field->move_enemies();
                    game->print_console();

                }
                if (trunc(pos_y) - prev_y <= -1) {
                    cout << pos_y << " " << trunc(pos_y) << " " << trunc(pos_y) - prev_y << " " << prev_y << endl;
                    game->up();
                    field->move_enemies();
                    game->print_console();

                }


                if (map[(int) pos_y][(int) pos_x].get_type() == HWALL ||
                    map[(int) pos_y][(int) pos_x].get_type() == VWALL ||
                    map[(int) pos_y][(int) pos_x].get_type() == CWALL) {
                    pos_y -= sinf(fPlayerA) * fSpeed * fElapsedTime;
                    pos_x -= cosf(fPlayerA) * fSpeed * fElapsedTime;
                }
            }
            // Handle backwards movement & collision
            if (Keyboard::isKeyPressed(Keyboard::Down)) {
                pos_y -= sinf(fPlayerA) * fSpeed * fElapsedTime;
                pos_x -= cosf(fPlayerA) * fSpeed * fElapsedTime;
                field->get_cord_player(prev_x, prev_y);

                if (pos_x - prev_x >= 1) {
                    game->left();
                    field->move_enemies();
                    game->print_console();

                }
                if (pos_x - prev_x <= -1) {
                    game->right();
                    field->move_enemies();
                    game->print_console();

                }
                if (pos_y - prev_y >= 1) {
                    game->up();
                    field->move_enemies();
                    game->print_console();

                }
                if (pos_y - prev_y <= -1) {
                    game->down();
                    field->move_enemies();
                    game->print_console();

                }


                if (map[(int) pos_y][(int) pos_x].get_type() == HWALL ||
                    map[(int) pos_y][(int) pos_x].get_type() == VWALL ||
                    map[(int) pos_y][(int) pos_x].get_type() == CWALL) {
                    pos_y += sinf(fPlayerA) * fSpeed * fElapsedTime;;
                    pos_x += cosf(fPlayerA) * fSpeed * fElapsedTime;;
                }
            }

            //рисовка стен
            for (int x = 0; x < nScreenWidth; x++) {
                // For each column, calculate the projected ray angle into world space
                float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float) x / (float) nScreenWidth) * fFOV;
                int nTestX;
                int nTestY;
                // Find distance to wall
                float fStepSize = 0.1f;          // Increment size for ray casting, decrease to increase
                float fDistanceToWall = 0.0f; //                                      resolution

                bool bHitWall = false;        // Set when ray hits wall block
                bool bBoundary = false;        // Set when ray hits boundary between two wall blocks

                float fEyeX = sinf(fRayAngle); // Unit vector for ray in player space
                float fEyeY = cosf(fRayAngle);

                // Incrementally cast ray from player, along ray angle, testing for
                // intersection with a block
                while (!bHitWall && fDistanceToWall < fDepth) {
                    fDistanceToWall += fStepSize;
                    nTestX = (int) (pos_y + fEyeX * fDistanceToWall);
                    nTestY = (int) (pos_x + fEyeY * fDistanceToWall);

                    // Test if ray is out of bounds
                    if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight) {
                        bHitWall = true;            // Just set distance to maximum depth
                        fDistanceToWall = fDepth;
                    } else {
                        // Ray is inbounds so test to see if the ray cell is a wall block
                        if ((map[nTestX][nTestY].get_type() == HWALL ||
                             map[nTestX][nTestY].get_type() == VWALL ||
                             map[nTestX][nTestY].get_type() == CWALL ||
                             map[nTestX][nTestY].get_type() == EXIT ||
                             map[nTestX][nTestY].get_type() == ENTRANCE)) {
                            // Ray has hit wall
                            bHitWall = true;

                            // To highlight tile boundaries, cast a ray from each corner
                            // of the tile, to the player. The more coincident this ray
                            // is to the rendering ray, the closer we are to a tile
                            // boundary, which we'll shade to add detail to the walls
                            std::vector<pair<float, float>> p;

                            // Test each corner of hit tile, storing the distance from
                            // the player, and the calculated dot product of the two rays
                            for (int tx = 0; tx < 2; tx++)
                                for (int ty = 0; ty < 2; ty++) {
                                    // Angle of corner to eye
                                    float vy = (float) nTestY + ty - pos_x;
                                    float vx = (float) nTestX + tx - pos_y;
                                    float d = sqrt(vx * vx + vy * vy);
                                    float dot = (fEyeX * vx / d) + (fEyeY * vy / d);
                                    p.push_back(make_pair(d, dot));
                                }

                            // Sort Pairs from closest to farthest
                            sort(p.begin(), p.end(),
                                 [](const pair<float, float> &left, const pair<float, float> &right) {
                                     return left.first < right.first;
                                 });

                            // First two/three are closest (we will never see all four)
                            float fBound = 0.01;
                            if (acos(p.at(0).second) < fBound) bBoundary = true;
                            if (acos(p.at(1).second) < fBound) bBoundary = true;
                            if (acos(p.at(2).second) < fBound) bBoundary = true;
                        }
                    }
                }
                {
                    // Calculate distance to ceiling and floor
                    int nCeiling = (float) (nScreenHeight / 2.0) - nScreenHeight / ((float) fDistanceToWall);
                    int nFloor = nScreenHeight - nCeiling;

                    // Shader walls based on distance
                    Color color;
                    if (map[nTestX][nTestY].get_type() == EXIT) {
                        color = Color(0, 75, 0);
                    } else if (map[nTestX][nTestY].get_type() == ENTRANCE) {
                        color = Color(0, 0, 75);
                    } else {
                        color = Color(150, 75, 0);
                    }
                    color.a = color.a * (1 - fDistanceToWall) / fDepth;
                    if (color.a > 255) color.a = 255;
                    if (color.a < 0) color.a = 0;

                    if (bBoundary) color.g = 0; // Black it out
                    //рисовка
                    VertexArray line(Lines, 2);
                    line[0].position = Vector2f(x, nCeiling);
                    line[0].color = color;
                    line[1].position = Vector2f(x, nFloor);
                    line[1].color = color;
                    window.draw(line);

                    Color color_pixel = Color(215, 142, 54);

                    float b = (((float) nFloor - nScreenHeight / 2.0f) / ((float) nScreenHeight / 2.0f));

                    color_pixel.a = color_pixel.a * b / 4;
                    line[0].position = Vector2f(x, nFloor);
                    line[0].color = color_pixel;
                    line[1].position = Vector2f(x, nScreenHeight);
                    color_pixel = Color(215, 142, 54);
                    color_pixel.a = color_pixel.a * 0.25;
                    line[1].color = color_pixel;
                    window.draw(line);
                }
            }

            //рисовка элементов
            for (int x = 0; x < nScreenWidth; x++) {
                // For each column, calculate the projected ray angle into world space
                float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float) x / (float) nScreenWidth) * fFOV;
                int nTestX = 0;
                int nTestY = 0;
                // Find distance to wall
                float fStepSize = 0.1f;          // Increment size for ray casting, decrease to increase
                float fDistanceToWall = 0.0f; //                                      resolution

                bool bHitWall = false;        // Set when ray hits wall block
                bool bBoundary = false;        // Set when ray hits boundary between two wall blocks

                float fEyeX = sinf(fRayAngle); // Unit vector for ray in player space
                float fEyeY = cosf(fRayAngle);

                // Incrementally cast ray from player, along ray angle, testing for
                // intersection with a block
                while (!bHitWall && fDistanceToWall < fDepth) {
                    fDistanceToWall += fStepSize;
                    nTestX = (int) (pos_y + fEyeX * fDistanceToWall);
                    nTestY = (int) (pos_x + fEyeY * fDistanceToWall);

                    // Test if ray is out of bounds
                    if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight) {
                        bHitWall = true;            // Just set distance to maximum depth
                        fDistanceToWall = fDepth;
                    } else {
                        // Ray is inbounds so test to see if the ray cell is a wall block
                        if (map[nTestX][nTestY].get_element() || field->test_cord_enemy(nTestX, nTestY)) {
                            // Ray has hit wall
                            bHitWall = true;

                            // To highlight tile boundaries, cast a ray from each corner
                            // of the tile, to the player. The more coincident this ray
                            // is to the rendering ray, the closer we are to a tile
                            // boundary, which we'll shade to add detail to the walls
                            std::vector<pair<float, float>> p;

                            // Test each corner of hit tile, storing the distance from
                            // the player, and the calculated dot product of the two rays
                            for (int tx = 0; tx < 2; tx++)
                                for (int ty = 0; ty < 2; ty++) {
                                    // Angle of corner to eye
                                    float vy = (float) nTestY + ty - pos_x;
                                    float vx = (float) nTestX + tx - pos_y;
                                    float d = sqrt(vx * vx + vy * vy);
                                    float dot = (fEyeX * vx / d) + (fEyeY * vy / d);
                                    p.push_back(make_pair(d, dot));
                                }

                            // Sort Pairs from closest to farthest
                            sort(p.begin(), p.end(),
                                 [](const pair<float, float> &left, const pair<float, float> &right) {
                                     return left.first < right.first;
                                 });

                            // First two/three are closest (we will never see all four)
                            float fBound = 0.01;
                            if (acos(p.at(0).second) < fBound) bBoundary = true;
                            if (acos(p.at(1).second) < fBound) bBoundary = true;
                            if (acos(p.at(2).second) < fBound) bBoundary = true;
                        }
                    }
                }
                if (bHitWall && fDistanceToWall < fDepth) {
                    int nCeiling = (float) (nScreenHeight / 2.0) - nScreenHeight / ((float) fDistanceToWall);
                    int nFloor = nScreenHeight - nCeiling;
                    int hight = (nCeiling - nFloor) / 3;
                    if (field->test_cord_enemy(nTestX, nTestY)) {
                        // Shader walls based on distance
                        Color color = Color::Red;
                        color.a = color.a * (1 - fDistanceToWall) / fDepth;
                        if (color.a > 255) color.a = 255;
                        if (color.a < 0) color.a = 0;

                        if (bBoundary) color.g = 0; // Black it out
                        //рисовка
                        VertexArray line(Lines, 2);
                        line[0].position = Vector2f(x, nCeiling);
                        line[0].color = color;
                        line[1].position = Vector2f(x, nFloor + hight);
                        line[1].color = color;
                        window.draw(line);
                    } else {
                        Color color = map[nTestX][nTestY].get_element()->get_color();
                        color.a = color.a * (1 - fDistanceToWall) / fDepth;
                        if (color.a > 255) color.a = 255;
                        if (color.a < 0) color.a = 0;

                        if (bBoundary) color.g = 0; // Black it out
                        //рисовка
                        VertexArray line(Lines, 2);
                        line[0].position = Vector2f(x, nCeiling - hight);
                        line[0].color = color;
                        line[1].position = Vector2f(x, nFloor + hight);
                        line[1].color = color;
                        window.draw(line);

                    }
                }


            }

            window.display();

        }
    }
    return 0;
}
