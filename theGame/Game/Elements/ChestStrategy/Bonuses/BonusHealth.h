//
// Created by vikto on 26.10.2020.
//

#ifndef MYGAME_BONUSHEALTH_H
#define MYGAME_BONUSHEALTH_H
#include "../../../../Tools/Strategy/BonusStrategy.h"

class BonusHealth: public BonusStrategy {
    int get_health() const override;
    int get_coin() const override;
    Status get_status() const override;
};


#endif //MYGAME_BONUSHEALTH_H
