//
// Created by vikto on 31.10.2020.
//

#ifndef MYGAME_MUSHROOMFACTORY_H
#define MYGAME_MUSHROOMFACTORY_H
#include "../../Game/Elements/Mushroom.h"
#include "AbstractFactory.h"

class MushroomFactory: public AbstractFactory {
    Element * createElem() const override;
};


#endif //MYGAME_MUSHROOMFACTORY_H
