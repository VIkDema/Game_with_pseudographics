//
// Created by vikto on 26.10.2020.
//

#ifndef MYGAME_BONUSDAMAGE_H
#define MYGAME_BONUSDAMAGE_H
#include "../../../../Tools/Strategy/BonusStrategy.h"

class BonusDamage: public BonusStrategy {
    int get_health() const override;
    Status get_status() const override;
    int get_coin() const override;
};


#endif //MYGAME_BONUSDAMAGE_H
