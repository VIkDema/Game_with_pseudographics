//
// Created by vikto on 22.11.2020.
//
#include <conio.h>
#include "Controller.h"
#include "MoveUp.h"
#include "MoveLeft.h"
#include "MoveRight.h"
#include "MoveDown.h"
#include "CloseGame.h"
#include "StartGame.h"
#include "../../Tools/SaveAndLoad/SaveAndLoad.h"
#include "LoadGame.h"
#include "SaveGame.h"


void Controller::inputCommand() {
    int ch = _getch();
    switch (ch) {
        case 72://down
            up->execute();
            break;
        case 75://left
            left->execute();
            break;
        case 77://right
            right->execute();
            break;
        case 80://up
            down->execute();
            break;
        case 27://esc
            close->execute();
            break;
        case 13://enter
            start->execute();
            break;
        case 76://L
            load->execute();
            break;
        case 83://S
            save->execute();
            break;
        case 108://l
            load->execute();
            break;
        case 115://s
            save->execute();
            break;
        default:
            break;
    }

}

Controller::Controller(Game *game) {
    up = new MoveUp(game);
    left = new MoveLeft(game);
    right = new MoveRight(game);
    down = new MoveDown(game);
    close = new CloseGame(game);
    start = new StartGame(game);
    load = new LoadGame(game);
    save = new SaveGame(game);
}

Controller::~Controller() {
    delete up;
    delete left;
    delete right;
    delete down;
    delete close;
    delete start;
}

