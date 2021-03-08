//
// Created by vikto on 01.11.2020.
//

#ifndef MYGAME_LOGCONSOLE_H
#define MYGAME_LOGCONSOLE_H

#include "LoggerImpl.h"

class LogConsole : public LoggerImpl {
public:
    ~LogConsole() override;
    void log_info(std::string str) override;
};


#endif //MYGAME_LOGCONSOLE_H
