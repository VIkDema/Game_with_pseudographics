//
// Created by vikto on 19.10.2020.
//

#ifndef MYGAME_MUSHROOM_H
#define MYGAME_MUSHROOM_H

#include "Element.h"

class Mushroom : public Element {
    Observer *logger = nullptr;
    std::string message;
    Status status = PLAY;
    int health = 1;
    int coin = 0;
public:
    ~Mushroom() override;

    int get_coin() const override;

    int get_health() const override;

    Status get_status() const override;

    void print_element() const override;

    void attach(Observer *observer) override;

    void detach() override;

    void notify() override;

    void set_message(std::string mes)override;

    void log_end() override;

    friend std::ostream& operator<< (std::ostream &out, const Mushroom &mushroom);
    sf::Color get_color() override;
    void set_coin(int c) override;
    void set_health(int h) override;
    void set_status(Status st) override;
};

#endif //MYGAME_MUSHROOM_H
