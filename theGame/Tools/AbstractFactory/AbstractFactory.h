//
// Created by vikto on 20.10.2020.
//

#ifndef MYGAME_ABSTRACTFACTORY_H
#define MYGAME_ABSTRACTFACTORY_H
#include "../../Game/Elements/Element.h"

class AbstractFactory{
public:
    virtual ~AbstractFactory() {  };
    virtual Element *createElem() const = 0;
};
#endif //MYGAME_ABSTRACTFACTORY_H
