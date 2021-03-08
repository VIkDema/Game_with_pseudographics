//
// Created by vikto on 26.10.2020.
//

#ifndef MYGAME_STRATEGY_H
#define MYGAME_STRATEGY_H
#include "../../Game/StatusEnum.h"
class BonusStrategy{
public:
    virtual ~BonusStrategy() {  };
    virtual int get_coin() const=0;
    virtual int get_health()const=0;
    virtual Status get_status()const=0;
};
#endif //MYGAME_STRATEGY_H
