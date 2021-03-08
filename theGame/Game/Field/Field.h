//
// Created by vikto on 13.09.2020.
//

#ifndef MYGAME_FIELD_H
#define MYGAME_FIELD_H


#include "Cell/Cell.h"
#include <iostream>
#include "../Player/Player.h"
#include "../../Tools/Iterator/Iterator.h"
#include "../../Tools/Logger/Logger.h"
#include "../../Tools/AbstractFactory/AbstractFactory.h"


class Field {
    Cell **cells;
    int size_x;
    int size_y;
    Player *player_one;
    IEnemy *big_enemy;
    IEnemy *quick_enemy;
    IEnemy *simple_enemy;
    Logger *logger = nullptr;
    int count_coins;
    enum Status status;


protected:

    Field();

    static Field *field_;

public:

    void set_size(int x = 15, int y = 15);

    ~Field();

    Field(const Field &obj);

    Field(Field &&obj);

    Field &operator=(const Field &obj);

    Field &operator=(Field &&obj);

    static Field *get_instance();

    Cell **get_cells();

    int get_size_x() const;

    int get_size_y() const;

    void get_cord_player(float &x, float &y);

    Player *get_player();

    void move_enemies();

    bool test_cord_enemy(int x, int y);

    void create_concrete_enemy(IEnemy *enemy);

    int random_move();

    int random_y();

    int random_x();

    void move_concrete_enemy(IEnemy *enemy);

    void create_enemies();

    bool test_cord_of_enemy(int x, int y, IEnemy *enemy);

    bool test_cord_of_player(CellIterator *it);

    IEnemy *get_big_enemy();

    IEnemy *get_quick_enemy();

    IEnemy *get_simple_enemy();

    void create_player();

    void create_concrete_element(AbstractFactory *factory, int k);

    void create_elements();

    bool test_cell(int move_x, int move_y);

    bool test_cell(int move_x, int move_y, IEnemy *enemy);

    int get_count_coins() const;

    void interaction_with_elements();

    bool test_status();

    Status get_status();

    void set_status(Status st);

    void set_status_from_element(Element *elem);

    void set_count_coint(int count);

    void set_cells(Cell **cell);
};


#endif //MYGAME_FIELD_H
