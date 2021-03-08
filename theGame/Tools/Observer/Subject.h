//
// Created by vikto on 01.11.2020.
//

#ifndef MYGAME_SUBJECT_H
#define MYGAME_SUBJECT_H

#include "Observer.h"

class Subject {
public:

    virtual void attach(Observer *observer)  = 0;

    virtual void detach()  = 0;

    virtual void notify()  = 0;
};

#endif //MYGAME_SUBJECT_H
