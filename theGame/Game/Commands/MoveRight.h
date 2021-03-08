//
// Created by vikto on 22.11.2020.
//

#ifndef MYGAME_MOVERIGHT_H
#define MYGAME_MOVERIGHT_H
#include "../../Tools/Command/Command.h"

class MoveRight : public Command{
    Game* game_;
public:
    MoveRight(Game* p):game_(p){}
    ~MoveRight() override;
    void execute() override;
};


#endif //MYGAME_MOVERIGHT_H
