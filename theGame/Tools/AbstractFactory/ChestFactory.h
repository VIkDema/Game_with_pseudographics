//
// Created by vikto on 20.10.2020.
//

#ifndef MYGAME_CHESTFACTORY_H
#define MYGAME_CHESTFACTORY_H
#include "AbstractFactory.h"
#include "../../Game/Elements/Chest.h"
#include "../../Game/Elements/ChestStrategy/Bonuses/Bonuses.h"
#include <cstdlib>


class ChestFactory: public AbstractFactory {
public:
    ~ChestFactory() override;
    Element * createElem() const override;
};


#endif //MYGAME_CHESTFACTORY_H
