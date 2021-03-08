//
// Created by vikto on 19.10.2020.
//
#include "Chest.h"

#include <utility>


Status Chest::get_status() const {
    return status;
}

int Chest::get_health() const {
    return health;
}

int Chest::get_coin() const {
    return coin;
}


void Chest::print_element() const {
    std::cout << "H";
}

void Chest::set_strategy(BonusStrategy *strategy) {
    if (this->strategy_ != nullptr) {
        this->strategy_ = strategy;
        return;
    }
    delete this->strategy_;
    this->strategy_ = strategy;
    status = strategy->get_status();
    health = strategy->get_health();
    coin = strategy->get_coin();
}

Chest::Chest(BonusStrategy *strategy) : strategy_(strategy) {
    status = strategy->get_status();
    health = strategy->get_health();
    coin = strategy->get_coin();
}

void Chest::attach(Observer *observer) {
    this->logger = observer;
}

void Chest::detach() {
    this->logger = nullptr;
}

void Chest::notify() {
    logger->update(message);
}

Chest::~Chest() {
    delete this->strategy_;
    this->logger = nullptr;
}

void Chest::set_message(std::string mes) {
    this->message = mes;
}

void Chest::log_end() {
    if (logger != nullptr) {
        this->set_message("The Chest was open");
        this->notify();
    }
}

std::ostream &operator<<(std::ostream &out, const Chest &ch) {
    out << "Chest\n";
    return out;
}

sf::Color Chest::get_color() {
    return sf::Color::Magenta;
}

void Chest::set_health(int h) {
    health = h;
}

void Chest::set_status(Status st) {
    status = st;
}

void Chest::set_coin(int c) {
    coin = c;
}

Chest::Chest() {
    strategy_ = nullptr;
};
