//
// Created by vikto on 18.10.2020.
//

#include "Player.h"

int Player::get_cord_x() const {
    return cord_x;
}

int Player::get_cord_y() const {
    return cord_y;
}

void Player::set_cord_x(int x) {
    cord_x = x;
}

void Player::set_cord_y(int y) {
    cord_y = y;
}

Player Player::operator+(const Element &d2) {
    this->coins = coins + d2.get_coin();
    this->health = health + d2.get_health();
    return *this;
}

Player::Player() {
    health = 1;
    coins = 0;
    cord_x = 0;
    cord_y = 0;
}

int Player::get_coins_player() const {
    return coins;
}

int Player::get_health_player() const {
    return health;
}

void Player::attach(Observer *observer) {
    this->logger = observer;
}

void Player::detach() {
    delete this->logger;
}

void Player::notify() {
    this->logger->update(this->message);
}

Player::~Player() {
    this->logger = nullptr;
}

void Player::log_cord_player() {
    std::string str = "Player(Cord:( " + std::to_string(cord_x) + ", " + std::to_string(cord_y) + "), Health:(" +
                      std::to_string(health) + "), " + " Coins(" + std::to_string(coins) + "))";
    set_message(str);
    notify();
}

void Player::set_message(std::string mes) {
    this->message = mes;
}

void Player::log_end() {
    std::string str = "Player dead";
    set_message(str);
    notify();
}

void Player::log_win() {
    std::string str = "Player win";
    set_message(str);
    notify();
}

std::ostream &operator<<(std::ostream &out, const Player &player) {
    out << "Player(Cord:( " + std::to_string(player.get_cord_x()) + ", " + std::to_string(player.get_cord_y()) +
           "), Health:(" + std::to_string(player.get_health_player()) + "), " + " Coins(" +
           std::to_string(player.get_coins_player()) + "))";
    return out;
}

Player Player::operator+(const IEnemy &d2) {
    this->health = this->health - d2.get_damage();
    return *this;
}

void Player::set_coins_player(int coin) {
    coins = coin;
}

void Player::set_health_player(int health_player) {
    health = health_player;
}


