//
// Created by vikto on 02.11.2020.
//

#include "Logger.h"

void Logger::update(std::string str) const {
    logger_impl->log_info(str);
}


Logger::Logger(LoggerImpl *logger) {
    this->logger_impl=logger;
}

Logger::~Logger() {
    delete logger_impl;
}

