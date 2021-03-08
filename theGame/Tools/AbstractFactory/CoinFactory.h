//
// Created by vikto on 31.10.2020.
//

#ifndef MYGAME_COINFACTORY_H
#define MYGAME_COINFACTORY_H
#include "../../Game/Elements/Coin.h"
#include "AbstractFactory.h"

class CoinFactory: public AbstractFactory {
    ~CoinFactory() override=default;
    Element * createElem() const override;

};


#endif //MYGAME_COINFACTORY_H
