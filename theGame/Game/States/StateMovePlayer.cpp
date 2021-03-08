//
// Created by vikto on 24.11.2020.
//

#include "StateMovePlayer.h"
#include "StateMoveEnemy.h"


StateMovePlayer::StateMovePlayer(Game *game) {
    this->game_=game;
}

void StateMovePlayer::move() {
    game_->move_player();
    game_->set_state(new StateMoveEnemy(game_));
}
