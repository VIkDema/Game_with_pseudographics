//
// Created by vikto on 02.11.2020.
//

#ifndef MYGAME_LOGGERIMPL_H
#define MYGAME_LOGGERIMPL_H
#include <iostream>
#include <ctime>

class LoggerImpl {
public:
    virtual  ~LoggerImpl() {  };
    virtual void log_info(std::string str)=0;
};


#endif //MYGAME_LOGGERIMPL_H
