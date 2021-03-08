//
// Created by vikto on 19.10.2020.
//

#ifndef MYGAME_ELEMENT_H
#define MYGAME_ELEMENT_H

#include "../StatusEnum.h"
#include "../../Tools/Observer//Observer.h"
#include "../../Tools/Observer/Subject.h"
#include <iostream>
#include <SFML/Graphics/Color.hpp>

class Element : public Subject {
public:
    virtual ~Element() {};

    virtual int get_coin() const = 0;

    virtual int get_health() const = 0;

    virtual Status get_status() const = 0;

    virtual void print_element() const = 0;

    virtual void attach(Observer *observer) override = 0;

    virtual void detach() override = 0;

    virtual void notify() override = 0;

    virtual void set_message(std::string mes) = 0;

    virtual sf::Color get_color() = 0;

    virtual void log_end() = 0;

    virtual void set_status(Status st) = 0;

    virtual void set_health(int h) = 0;

    virtual void set_coin(int c) = 0;
};


#endif //MYGAME_ELEMENT_H
