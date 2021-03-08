//
// Created by vikto on 22.11.2020.
//

#include "CloseGame.h"

void CloseGame::execute() {
    game_->close();
}

CloseGame::~CloseGame() = default;
