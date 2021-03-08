//
// Created by vikto on 26.10.2020.
//

#include "BonusHealth.h"

int BonusHealth::get_health() const {
    return 2;
}

int BonusHealth::get_coin() const {
    return 0;
}

Status BonusHealth::get_status() const {
    return PLAY;
}
