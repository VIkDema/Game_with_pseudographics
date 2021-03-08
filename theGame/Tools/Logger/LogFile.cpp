//
// Created by vikto on 01.11.2020.
//

#include "LogFile.h"

void LogFile::log_info(std::string str) {
    time_t sec = time(NULL);
    std::string str_n=str+" :time(" + std::to_string(localtime(&sec)->tm_hour)+":"+std::to_string(localtime(&sec)->tm_min)+":"+std::to_string(localtime(&sec)->tm_sec) + ")\n";
    file_log->write(str_n.c_str());
}

LogFile::LogFile() {
    mkdir("Logs/");
    file_log = new FileLog("Logs/Logs.txt");
}

LogFile::~LogFile() { delete file_log; }