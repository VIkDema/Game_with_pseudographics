//
// Created by vikto on 26.10.2020.
//

#include "BonusDamage.h"

int BonusDamage::get_coin() const {
    return 0;
}

int BonusDamage::get_health() const {
    return -1;
}
Status BonusDamage::get_status() const {
    return PLAY;
}