//
// Created by vikto on 02.11.2020.
//

#ifndef MYGAME_LOGGER_H
#define MYGAME_LOGGER_H


#include "LoggerImpl.h"
#include "../Observer/Observer.h"


class Logger : public Observer {

    LoggerImpl *logger_impl = nullptr;
public:

    Logger(LoggerImpl *logger);

    ~Logger() override;

    void update(std::string str) const override;
};


#endif //MYGAME_LOGGER_H
