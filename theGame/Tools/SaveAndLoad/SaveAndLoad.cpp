//
// Created by vikto on 24.11.2020.
//

#include "SaveAndLoad.h"

void SaveAndLoad::save() {
    std::string f_name = "Save/save.txt";
    Game::Memento mem = game_->save_memento();
    File_binary_out *file = new File_binary_out(f_name.c_str());

    file->write(mem.field->get_size_x());
    file->write(mem.field->get_size_y());

    file->write(mem.field->get_player()->get_cord_x());
    file->write(mem.field->get_player()->get_cord_y());
    file->write(mem.field->get_player()->get_coins_player());
    file->write(mem.field->get_player()->get_health_player());

    if (mem.field->get_big_enemy()) {
        file->write(1);
        file->write(mem.field->get_big_enemy()->get_cord_x());
        file->write(mem.field->get_big_enemy()->get_cord_y());
    } else {
        file->write(0);
    }
    if (mem.field->get_simple_enemy()) {
        file->write(1);
        file->write(mem.field->get_simple_enemy()->get_cord_x());
        file->write(mem.field->get_simple_enemy()->get_cord_y());
    } else {
        file->write(0);
    }
    if (mem.field->get_quick_enemy()) {
        file->write(1);
        file->write(mem.field->get_quick_enemy()->get_cord_y());
        file->write(mem.field->get_quick_enemy()->get_cord_y());
    } else {
        file->write(0);
    }
    file->write(mem.field->get_count_coins());
    file->write(mem.field->get_status());
    Cell **write_cells = mem.field->get_cells();
    for (int i = 0; i < mem.field->get_size_y(); ++i) {
        for (int j = 0; j < mem.field->get_size_x(); ++j) {
            file->write(write_cells[i][j].get_type());
            if (write_cells[i][j].get_element()) {
                file->write(1);
                file->write(write_cells[i][j].get_element()->get_coin());
                file->write(write_cells[i][j].get_element()->get_health());
                file->write(write_cells[i][j].get_element()->get_status());
            } else {
                file->write(0);
            }
        }
    }
    getch();
    delete file;
}

void SaveAndLoad::load() {
    std::string f_name = "Save/save.txt";
    try {
        File_binary_in *file = new File_binary_in(f_name.c_str());
        test_load(file);
        file->begin();
        load_to_game(file);
    } catch (InvalidFileException exception) {
        std::cout << exception.invalid_file();
        getch();
        return;
    }
}

SaveAndLoad::SaveAndLoad(Game *game) : game_(game) {

}

void SaveAndLoad::test_load(File_binary_in *file) {
    int byte = 0;
    int test_x = file->read();
    if (test_x < 0 || test_x > 150) {
        throw InvalidFileException(byte);
    }
    byte++;
    int test_y = file->read();

    if (test_y < 0 || test_y > 150) {
        throw InvalidFileException(byte);
    }
    byte++;
    test = file->read();
    if (test > test_x - 1 || test < 1) {
        throw InvalidFileException(byte);
    }
    byte++;
    test = file->read();
    if (test > test_y - 1 || test < 1) {
        throw InvalidFileException(byte);
    }
    byte++;
    test = file->read();
    if (test > test_x * test_y / 50 || test < 0) {
        throw InvalidFileException(byte);
    }
    byte++;
    test = file->read();
    if (test < 0) {
        throw InvalidFileException(byte);
    }
    byte++;
    for (int i = 0; i < 3; ++i) {
        test = file->read();
        if (test != 0 && test != 1) {
            throw InvalidFileException(byte);
        }
        byte++;
        test = file->read();
        if (test > test_x - 1 || test < 1) {
            throw InvalidFileException(byte);
        }
        byte++;
        test = file->read();
        if (test > test_y - 1 || test < 1) {
            throw InvalidFileException(byte);
        }
        byte++;
    }
    test = file->read();
    if (test > test_x * test_y / 50 || test < 0) {
        throw InvalidFileException(byte);
    }
    byte++;
    test = file->read();
    if (test < 0 || test > 5) {
        throw InvalidFileException(byte);
    }
    byte++;
    for (int i = 0; i < test_y; ++i) {
        for (int j = 0; j < test_x; ++j) {
            test = file->read();
            if (test < 0 || test > 5) {
                throw InvalidFileException(byte);
            }
            byte++;
            test = file->read();
            byte++;
            if (test != 0 && test != 1) {
                throw InvalidFileException(byte);
            }
            if (test) {
                for (int k = 0; k < 2; ++k) {
                    test = file->read();
                    if (test < 0) {
                        throw InvalidFileException(byte);
                    }
                    byte++;
                }
                test = file->read();
                if ((test < 0 || test > 5)) {
                    throw InvalidFileException(byte);
                }
                byte++;
            }
        }
    }
}

void SaveAndLoad::load_to_game(File_binary_in *file) {
    Element *elem;
    int coin = 0;
    int health = 0;
    Status status;

    Field *field = Field::get_instance();
    field->set_size(file->read(), file->read());
    field->get_player()->set_cord_x(file->read());
    field->get_player()->set_cord_y(file->read());
    field->get_player()->set_coins_player(file->read());
    field->get_player()->set_health_player(file->read());
    if (file->read()) {
        field->get_big_enemy()->set_cord_x(file->read());
        field->get_big_enemy()->set_cord_y(file->read());
    }
    if (file->read()) {
        field->get_simple_enemy()->set_cord_x(file->read());
        field->get_simple_enemy()->set_cord_y(file->read());
    }
    if (file->read()) {
        field->get_quick_enemy()->set_cord_x(file->read());
        field->get_quick_enemy()->set_cord_y(file->read());
    }
    field->set_count_coint(file->read());
    field->set_status((Status) file->read());
    Cell **cells = new Cell *[field->get_size_y()];
    for (int i = 0; i < field->get_size_y(); ++i) {
        cells[i] = new Cell[field->get_size_x()];
        for (int j = 0; j < field->get_size_x(); ++j) {
            cells[i][j].set_type((TypeCell) file->read());
            if (cells[i][j].get_type() != EMPTY) {
                file->read();
                continue;
            }
            if (file->read()) {
                coin = file->read();
                health = file->read();
                status = (Status) file->read();
                if (coin == 1) {
                    elem = new Coin();
                } else if (health == 1) {
                    elem = new Mushroom();
                } else {
                    elem = new Chest();
                    elem->set_coin(coin);
                    elem->set_health(health);
                    elem->set_status(status);
                }
                cells[i][j].set_element(elem);
            }
        }
    }
    field->set_cells(cells);
    delete file;
}

