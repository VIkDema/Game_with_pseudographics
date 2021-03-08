//
// Created by vikto on 22.11.2020.
//

#ifndef MYGAME_MOVELEFT_H
#define MYGAME_MOVELEFT_H
#include "../../Tools/Command/Command.h"

class MoveLeft: public Command {
    Game * game_;
public:

    MoveLeft(Game* p):game_(p){}
    ~MoveLeft() override;
     void execute() override;
};


#endif //MYGAME_MOVELEFT_H
