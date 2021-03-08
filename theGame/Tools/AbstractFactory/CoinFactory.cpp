//
// Created by vikto on 31.10.2020.
//

#include "CoinFactory.h"

Element *CoinFactory::createElem() const {
    return new Coin();
}
