//
// Created by vikto on 01.11.2020.
//

#ifndef MYGAME_LOGFILE_H
#define MYGAME_LOGFILE_H

#include "LoggerImpl.h"
#include <direct.h>
class FileLog;
class LogFile : public LoggerImpl {
    FileLog *file_log;
public:
    LogFile();
    ~LogFile() override;
    void log_info(std::string str) override;
};

class FileLog {
public:
    FileLog(const char* filename ) : m_file_handle(std::fopen(filename, "w+"))
    {
            if( !m_file_handle )
                throw std::runtime_error("file open failure") ;
    }
    ~FileLog()
    {
        if( std::fclose(m_file_handle) != 0 )
        {
        }
    }

    void write( const char* str )
    {
        if(std::fputs(str,m_file_handle) == EOF )
            throw std::runtime_error("file write failure") ;
    }

private:
    std::FILE* m_file_handle ;
    FileLog(const FileLog & ) ;
    FileLog & operator=(const FileLog & ) ;
};
#endif //MYGAME_LOGFILE_H
