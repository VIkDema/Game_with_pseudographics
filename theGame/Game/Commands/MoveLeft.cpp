//
// Created by vikto on 22.11.2020.
//

#include "MoveLeft.h"

void MoveLeft::execute() {
    game_->left();
}

MoveLeft::~MoveLeft() = default;
