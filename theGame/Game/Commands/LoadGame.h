//
// Created by vikto on 27.11.2020.
//

#ifndef MYGAME_LOADGAME_H
#define MYGAME_LOADGAME_H
#include "../../Tools/Command/Command.h"
#include "../../Tools/SaveAndLoad/SaveAndLoad.h"

class LoadGame: public Command {
    Game * game_;

public:
    LoadGame(Game* p):game_(p){}
    ~LoadGame() override;
    void execute() override;
};


#endif //MYGAME_LOADGAME_H
