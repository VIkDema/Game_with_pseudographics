//
// Created by vikto on 19.10.2020.
//

#ifndef MYGAME_CHEST_H
#define MYGAME_CHEST_H

#include "Element.h"
#include "../../Tools/Strategy/BonusStrategy.h"

class Chest : public Element {
    Observer *logger = nullptr;
    BonusStrategy *strategy_;
    Status status = PLAY;
    int health = 0;
    int coin = 0;
    std::string message;
public:
    ~Chest() override;

    Chest(BonusStrategy *strategy);
    Chest();

    Status get_status() const override;

    int get_health() const override;

    int get_coin() const override;

    void print_element() const override;

    void set_strategy(BonusStrategy *strategy);

    void attach(Observer *observer) override;

    void detach() override;

    void notify() override;

    void set_message(std::string mes) override;

    void log_end() override;

    friend std::ostream &operator<<(std::ostream &out, const Chest &ch);

    sf::Color get_color() override;

    void set_coin(int c) override;

    void set_health(int h) override;

    void set_status(Status st) override;
};


#endif //MYGAME_CHEST_H
