//
// Created by vikto on 22.11.2020.
//

#ifndef MYGAME_STARTGAME_H
#define MYGAME_STARTGAME_H

#include "../../Tools/Command/Command.h"

class StartGame : public Command {
    Game *game_;
public:
    StartGame(Game *p) : game_(p) {}

    ~StartGame() override;

    void execute() override;
};


#endif //MYGAME_STARTGAME_H
