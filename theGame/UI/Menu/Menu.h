//
// Created by vikto on 28.11.2020.
//

#ifndef MYGAME_MENU_H
#define MYGAME_MENU_H

#include <SFML/graphics.hpp>

using namespace sf;

void menu(RenderWindow &window) {
    Texture menu1, menu2, menu3, menu4;

    menu1.loadFromFile("img/menu/startButton.png");
    menu2.loadFromFile("img/menu/quitButton.png");
    menu3.loadFromFile("img/menu/loadButton.png");
    menu4.loadFromFile("img/menu/aboutButton.png");

    Sprite menuStart(menu1), menuQuit(menu2), menuLoad(menu3), menuAbout(menu4);

    CircleShape shape(100.f);
    shape.setFillColor(Color::Red);

    bool isMenu = true;
    int menuNum = 0;

    menuStart.setPosition(300, 0);
    menuLoad.setPosition(300, 200);
    menuAbout.setPosition(300, 400);
    menuQuit.setPosition(300, 600);

    while (window.isOpen() && isMenu) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        menuNum = 0;
        window.clear(Color(0, 0, 0));
        if (IntRect(300, 0, 439, 139).contains(Mouse::getPosition(window))) menuNum = 1;
        if (IntRect(300, 200, 439, 139).contains(Mouse::getPosition(window))) menuNum = 2;
        if (IntRect(300, 400, 439, 139).contains(Mouse::getPosition(window))) menuNum = 3;
        if (IntRect(300, 600, 439, 139).contains(Mouse::getPosition(window))) menuNum = 4;

        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (menuNum == 1) isMenu = false;
            if (menuNum == 2) {
                window.close();
                isMenu = false;
            }    //вместо закрытия закругка файла
            if (menuNum == 3) {
                window.draw(shape);//Вместо shape about
                window.display();
                while (!Keyboard::isKeyPressed(Keyboard::Escape));
            }
            if (menuNum == 4) {
                window.close();
                isMenu = false;
            }
        }
        window.draw(menuStart);
        window.draw(menuLoad);
        window.draw(menuAbout);
        window.draw(menuQuit);

        window.display();
    }
}

#endif //MYGAME_MENU_H
