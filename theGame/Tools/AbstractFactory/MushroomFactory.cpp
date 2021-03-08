//
// Created by vikto on 31.10.2020.
//

#include "MushroomFactory.h"

Element *MushroomFactory::createElem() const {
    return new Mushroom();
}
