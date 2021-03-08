//
// Created by vikto on 05.12.2020.
//

#ifndef MYGAME_INVALIDFILEEXCEPTION_H
#define MYGAME_INVALIDFILEEXCEPTION_H



class InvalidFileException {
    int byte;
public:
    InvalidFileException(int& b){
        byte=b;
    };
    std::string invalid_file() {
        std::string ss="Invalid_file";
        ss=ss+std::to_string(byte);
        return ss;
    }
};


#endif //MYGAME_INVALIDFILEEXCEPTION_H
