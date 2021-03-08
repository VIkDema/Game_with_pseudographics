//
// Created by vikto on 24.11.2020.
//

#ifndef MYGAME_SAVEANDLOAD_H
#define MYGAME_SAVEANDLOAD_H

#include "../../Game/Game.h"
#include "fstream"
#include "../Errors/InvalidFileException.h"

class File_binary_out;

class File_binary_in;

class SaveAndLoad {
    Game *game_;
    int test;

    void test_load(File_binary_in *file);

    void load_to_game(File_binary_in *file);

public:
    SaveAndLoad(Game *game);

    void save();


    void load();
};

class File_binary_out {
public:
    File_binary_out(const char *filename) {
        m_file_handle = new std::ofstream(filename, std::ios::binary);
        if (!m_file_handle->is_open())
            throw std::runtime_error("file open failure");
    }

    ~File_binary_out() {
        m_file_handle->close();
    }

    void write(const int &a) {
        std::cout << a;
        m_file_handle->write((char *) &a, sizeof(a));
        if (!m_file_handle)
            throw std::runtime_error("file write failure");
    }


private:
    std::ofstream *m_file_handle;

    File_binary_out(const File_binary_out &);

    File_binary_out &operator=(const File_binary_out &);
};

class File_binary_in {
public:
    File_binary_in(const char *filename) {
        m_file_handle = new std::ifstream(filename, std::ios::binary);
        if (!m_file_handle->is_open())
            throw std::runtime_error("file open failure");
    }

    ~File_binary_in() {
        m_file_handle->close();
    }

    int read() {

        m_file_handle->read((char *) &mem, sizeof(mem));
        std::cout << mem;
        return mem;
    }

    void begin() {

        m_file_handle->clear();
        m_file_handle->seekg(std::ios::beg);
    }


private:
    std::ifstream *m_file_handle;
    int mem = 0;
    Element *elem;
    int tell;

    File_binary_in(const File_binary_in &);

    File_binary_in &operator=(const File_binary_in &);
};


#endif //MYGAME_SAVEANDLOAD_H
