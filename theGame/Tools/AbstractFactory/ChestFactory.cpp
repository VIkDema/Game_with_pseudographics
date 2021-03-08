//
// Created by vikto on 20.10.2020.
//

#include "ChestFactory.h"


Element *ChestFactory::createElem() const {
    Chest* ch= new Chest(new BonusCoin);
    const int x=rand()%37+1;
    if(x==37){
        ch->set_strategy(new BonusWinGame);
    }else if(x>=18){
        ch->set_strategy(new BonusDamage);
    }else if(x>=27){
        ch->set_strategy(new BonusHealth);
    }
    return ch;
}

ChestFactory::~ChestFactory() = default;
