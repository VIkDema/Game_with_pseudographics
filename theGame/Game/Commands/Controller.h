//
// Created by vikto on 22.11.2020.
//

#ifndef MYGAME_CONTROLLER_H
#define MYGAME_CONTROLLER_H
#include "../../Tools/Command/Command.h"
//save_or_load
class Controller {
    Command* left;
    Command* right;
    Command* up;
    Command* down;
    Command* start;
    Command* close;
    Command* save;
    Command* load;
public:
    Controller(Game* game);
    ~Controller();
    void inputCommand();
};


#endif //MYGAME_CONTROLLER_H
