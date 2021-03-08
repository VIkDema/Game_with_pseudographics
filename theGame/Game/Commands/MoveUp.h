//
// Created by vikto on 22.11.2020.
//

#ifndef MYGAME_MOVEUP_H
#define MYGAME_MOVEUP_H
#include "../../Tools/Command/Command.h"

class MoveUp: public Command {
    Game* game_;
public:
    MoveUp(Game* p):game_(p){}
    ~MoveUp() override;
    void execute() override;
};


#endif //MYGAME_MOVEUP_H
