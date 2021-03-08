//
// Created by vikto on 24.11.2020.
//

#ifndef MYGAME_STATE_H
#define MYGAME_STATE_H


class StateMove{
public:
    virtual ~StateMove(){};
    virtual void move()=0;
};

#endif //MYGAME_STATE_H
