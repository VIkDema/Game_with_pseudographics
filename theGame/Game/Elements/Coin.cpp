//
// Created by vikto on 19.10.2020.
//

#include "Coin.h"


Status Coin::get_status() const {
    return PLAY;
}

int Coin::get_coin() const {
    return 1;
}

int Coin::get_health() const {
    return 0;
}

void Coin::print_element() const {
    std::cout << "O";
}

void Coin::attach(Observer *observer) {
    this->logger=observer;
}

void Coin::detach() {
    delete this->logger;
    this->logger = nullptr;
}

void Coin::notify() {
    logger->update(message);
}

Coin::~Coin() {
    this->logger = nullptr;

}

void Coin::set_message(std::string mes) {
    this->message = mes;
}

void Coin::log_end() {
    if (logger != nullptr) {
        set_message("The coin was collected");
        notify();
    }
}

std::ostream &operator<<(std::ostream &out, const Coin &coin) {
    out<<"Coin\n";
    return out;
}

sf::Color Coin::get_color() {
    return sf::Color::Yellow;
}
void Coin::set_health(int h) {
    health = h;
}

void Coin::set_status(Status st) {
    status = status;
}

void Coin::set_coin(int c) {
    coin = c;
}
