//
// Created by vikto on 19.10.2020.
//
#include "Mushroom.h"


Status Mushroom::get_status() const {
    return status;
}

int Mushroom::get_health() const {
    return health;
}

int Mushroom::get_coin() const {
    return coin;
}

void Mushroom::print_element() const {
    std::cout << "M";
}

void Mushroom::notify() {
    logger->update(message);

}

void Mushroom::detach() {

}

void Mushroom::attach(Observer *observer) {
    this->logger = observer;
}

Mushroom::~Mushroom() {
    this->logger = nullptr;
}

void Mushroom::set_message(std::string mes) {
    this->message = mes;
}

void Mushroom::log_end() {
    if (logger != nullptr) {
        this->set_message("The mushroom was eaten");
        this->notify();
    }
}

std::ostream &operator<<(std::ostream &out, const Mushroom &player) {
    out << "Mushroom\n";
    return out;
}

sf::Color Mushroom::get_color() {
    return sf::Color::Green;
}

void Mushroom::set_health(int h) {
    health = h;
}

void Mushroom::set_status(Status st) {
    status = status;
}

void Mushroom::set_coin(int c) {
    coin = c;
}

