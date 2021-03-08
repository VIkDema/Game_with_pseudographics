//
// Created by vikto on 26.10.2020.
//

#ifndef MYGAME_BONUSWINGAME_H
#define MYGAME_BONUSWINGAME_H
#include "../../../../Tools/Strategy/BonusStrategy.h"

class BonusWinGame: public BonusStrategy {
    ~BonusWinGame() override =default;
    int get_coin() const override;
    Status get_status() const override;
    int get_health() const override;
};


#endif //MYGAME_BONUSWINGAME_H
