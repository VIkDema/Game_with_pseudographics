//
// Created by vikto on 01.11.2020.
//

#include "LogConsole.h"



void LogConsole::log_info(std::string str) {
    time_t sec= time(NULL);
    std::cout<<str<<":time(" + std::to_string(localtime(&sec)->tm_hour)+":"+std::to_string(localtime(&sec)->tm_min)+":"+std::to_string(localtime(&sec)->tm_sec) + ")\n"<<"\n";
}

LogConsole::~LogConsole() = default;
