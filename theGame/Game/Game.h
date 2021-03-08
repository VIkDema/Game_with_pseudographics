//
// Created by vikto on 13.09.2020.
//


#ifndef MYGAME_GAME_H
#define MYGAME_GAME_H

#include "StatusEnum.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include "Field/Field.h"
#include "Player/Player.h"
#include "../Tools/MyCollections/collections.h"
#include "../Tools/AbstractFactory/AbstractFactory.h"
#include "../Tools/AbstractFactory/ChestFactory.h"
#include "../Tools/AbstractFactory/CoinFactory.h"
#include "../Tools/AbstractFactory/MushroomFactory.h"
#include "../Tools/Logger/Logger.h"
#include "../Tools/Logger/LogFile.h"
#include "../Tools/Logger/LogConsole.h"
#include "Enemy/Enemy.h"
#include "../Tools/State/State.h"


class Game {
protected:

    static Game *game_;

    Game(Game &other) = delete;

    void operator=(const Game &) = delete;

public:
    class Memento {
    public:
        Memento();

        Memento(Field *field);

        Field *field;
    };

    ~Game();

    void play();

    void left();

    void right();

    void down();

    void up();

    void close();

    void start();

    void print_console();

    void set_state(StateMove *state);

    StateMove *get_state();

    void move_player();//move in field

    Memento save_memento();

    void load_memento(Memento *load);

    static Game *get_instance();


private:

    Game();

    StateMove *state;

    Iterator<Cell> *it;

    Field *field;

    void print_specifications_console();

};


#endif //MYGAME_GAME_H
