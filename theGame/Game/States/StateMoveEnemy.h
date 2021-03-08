//
// Created by vikto on 24.11.2020.
//

#ifndef MYGAME_STATEMOVEENEMY_H
#define MYGAME_STATEMOVEENEMY_H

#include "../../Tools/State/State.h"
#include "../Game.h"

class StateMoveEnemy : public StateMove {
    Game *game_;
public:
    ~StateMoveEnemy()  override =default;
    void move() override;
    explicit StateMoveEnemy(Game *game);
};


#endif //MYGAME_STATEMOVEENEMY_H
