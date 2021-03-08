//
// Created by vikto on 24.11.2020.
//

#ifndef MYGAME_STATEMOVEPLAYER_H
#define MYGAME_STATEMOVEPLAYER_H

#include "../../Tools/State/State.h"
#include "../Game.h"

class StateMovePlayer : public StateMove {
    Game *game_;
public:
    ~StateMovePlayer() override = default;

    explicit StateMovePlayer(Game *game);

    void move() override;
};


#endif //MYGAME_STATEMOVEPLAYER_H
