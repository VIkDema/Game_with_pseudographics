//
// Created by vikto on 26.10.2020.
//

#ifndef MYGAME_BONUSCOIN_H
#define MYGAME_BONUSCOIN_H
#include "../../../../Tools/Strategy/BonusStrategy.h"

class BonusCoin: public BonusStrategy {
    int get_coin() const override;
    Status get_status() const override;
    int get_health() const override;
};


#endif //MYGAME_BONUSCOIN_H
