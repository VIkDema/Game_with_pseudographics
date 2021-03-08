//
// Created by vikto on 27.11.2020.
//

#ifndef MYGAME_SAVEGAME_H
#define MYGAME_SAVEGAME_H
#include "../../Tools/Command/Command.h"
#include "../../Tools/SaveAndLoad/SaveAndLoad.h"

class SaveGame: public Command {
    Game * game_;

public:
    SaveGame(Game* p):game_(p){}
    ~SaveGame() override;
    void execute() override;
};



#endif //MYGAME_SAVEGAME_H
