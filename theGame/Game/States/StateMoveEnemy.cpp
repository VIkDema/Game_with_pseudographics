//
// Created by vikto on 24.11.2020.
//
#include "StateMoveEnemy.h"
#include "StateMovePlayer.h"

StateMoveEnemy::StateMoveEnemy(Game *game) {
    this->game_=game;
}

void StateMoveEnemy::move() {
    Field* field=Field::get_instance();
    field->move_enemies();
    game_->set_state(new StateMovePlayer(game_));
}
