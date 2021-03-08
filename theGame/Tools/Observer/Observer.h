//
// Created by vikto on 01.11.2020.
//

#ifndef MYGAME_OBSERVER_H
#define MYGAME_OBSERVER_H
#include <iostream>

class Observer{
public:
    virtual ~Observer() {};
    virtual void update(std::string str) const=0;
};


#endif //MYGAME_OBSERVER_H
