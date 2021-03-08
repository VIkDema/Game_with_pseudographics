//
// Created by vikto on 22.11.2020.
//

#ifndef MYGAME_CLOSEGAME_H
#define MYGAME_CLOSEGAME_H
#include "../../Tools/Command/Command.h"

class CloseGame: public Command {
    Game * game_;

public:
    CloseGame(Game* p):game_(p){}
    ~CloseGame() override;
    void execute() override;
};


#endif //MYGAME_CLOSEGAME_H
