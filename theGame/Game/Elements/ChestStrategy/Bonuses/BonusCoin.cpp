//
// Created by vikto on 26.10.2020.
//

#include "BonusCoin.h"

int BonusCoin::get_coin() const {
    return 3;
}

Status BonusCoin::get_status() const {
    return PLAY;
}

int BonusCoin::get_health() const {
    return 0;
}

