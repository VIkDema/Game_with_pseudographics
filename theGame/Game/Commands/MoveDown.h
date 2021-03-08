//
// Created by vikto on 22.11.2020.
//

#ifndef MYGAME_MOVEDOWN_H
#define MYGAME_MOVEDOWN_H
#include "../../Tools/Command/Command.h"

class MoveDown: public Command {
    Game * game_;

public:
    MoveDown(Game* p):game_(p){}
    ~MoveDown() override;
    void execute() override;
};


#endif //MYGAME_MOVEDOWN_H
