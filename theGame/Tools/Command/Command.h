//
// Created by vikto on 22.11.2020.
//

#ifndef MYGAME_COMMAND_H
#define MYGAME_COMMAND_H
#include "../../Game/Game.h"

class Command {
public:
    virtual ~Command() {}

    virtual void execute() = 0;
};


#endif //MYGAME_COMMAND_H
