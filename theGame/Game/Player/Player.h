//
// Created by vikto on 18.10.2020.
//

#ifndef MYGAME_PLAYER_H
#define MYGAME_PLAYER_H

#include "../Elements/Element.h"
#include "../Enemy/Enemy.h"

class Player : public Subject {
    Observer *logger = nullptr;
    int cord_x;
    int cord_y;
    int coins;
    int health;
    std::string message;
public:
    ~Player();

    Player();

    int get_cord_x() const;

    int get_cord_y() const;

    void set_cord_x(int x);

    void set_cord_y(int y);

    int get_coins_player() const;

    void set_coins_player(int coin);

    int get_health_player() const;

    void set_health_player(int health_player);

    Player operator+(const Element &d2);

    Player operator+(const IEnemy &d2);

    friend std::ostream &operator<<(std::ostream &out, const Player &player);


    void attach(Observer *observer) override;

    void detach() override;

    void notify() override;

    void set_message(std::string str);

    void log_cord_player();

    void log_win();

    void log_end();
};


#endif //MYGAME_PLAYER_H
