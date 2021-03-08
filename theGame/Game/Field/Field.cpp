//
// Created by vikto on 13.09.2020.
//

#include "Field.h"
#include "../../Tools/AbstractFactory/CoinFactory.h"
#include "../../Tools/AbstractFactory/MushroomFactory.h"
#include "../../Tools/AbstractFactory/ChestFactory.h"
#include "../../Tools/Logger/LogFile.h"
#include "../../Tools/Logger/LogConsole.h"
#include "../Commands/Controller.h"

Field *Field::field_ = nullptr;


Field *Field::get_instance() {
    if (field_ == nullptr) {
        field_ = new Field();
    }
    return field_;
}

Field::Field() {
    set_size();
    //сделать границы поля, вход и выход
    cells = new Cell *[size_y];
    for (int i = 0; i < size_y; i++) {
        cells[i] = new Cell[size_x];
    }

    for (int i = 0; i < size_y; ++i) {
        for (int j = 0; j < size_x; ++j) {
            if (i == 0 || i == size_y - 1) {
                cells[i][j].set_type(HWALL);
            }
            if (j == 0 || j == size_x - 1) {
                cells[i][j].set_type(VWALL);
            }
            if (i == 0 && j == 0 || i == 0 && j == size_x - 1 || j == 0 && i == size_y - 1 ||
                j == size_x - 1 && i == size_y - 1) {
                cells[i][j].set_type(CWALL);
            }
            if (j == 0 && i == size_y / 2) {
                cells[i][j].set_type(ENTRANCE);
            }

            if (j == size_x - 1 && i == size_y / 2) {
                cells[i][j].set_type(EXIT);
            }
        }
    }
    player_one = nullptr;
    status = WAIT;
    count_coins = 0;
    big_enemy = nullptr;
    quick_enemy = nullptr;
    simple_enemy = nullptr;
    std::cout << "Select mode logging :press 1-in file, press 2 - in console\n";
    int logMode = 0;
    std::cin >> logMode;
    switch (logMode) {
        case 1:
            logger = new Logger(new LogFile);
            break;
        case 2:
            logger = new Logger(new LogConsole);
            break;
        default:
            std::cout << "Error: Incorrect logMode\n";
            return;
    }
    create_player();
    create_enemies();
    create_elements();

}

Field::~Field() {
    for (int i = 0; i < size_y; ++i) {
        delete cells[i];
    }
    delete[] cells;
    delete player_one;
    delete logger;
    delete big_enemy;
    delete quick_enemy;
    delete simple_enemy;
    delete field_;
}

Cell **Field::get_cells() {
    return cells;
}

int Field::get_size_x() const {
    return size_x;
};

int Field::get_size_y() const {
    return size_y;
}

Field::Field(const Field &obj) {
    this->size_x = obj.size_x;
    this->size_y = obj.size_y;
    this->cells = new Cell *[size_y];
    for (int i = 0; i < this->size_y; i++) {
        this->cells[i] = new Cell[size_x];
        for (int j = 0; j < this->size_x; ++j) {
            this->cells[i][j].set_type(obj.cells[i][j].get_type());
        }
    }
}

Field::Field(Field &&obj) {

    this->size_x = obj.size_x;
    this->size_y = obj.size_y;

    this->cells = obj.cells;
    obj.cells = nullptr;

    obj.size_y = 0;
    obj.size_x = 0;
}

Field &Field::operator=(const Field &obj) {
    if (&obj == this)
        return *this;

    this->size_x = obj.size_y;
    this->size_x = obj.size_x;

    for (int i = 0; i < this->size_x; i++) {
        delete[] this->cells[i];
    }
    delete[] this->cells;

    this->cells = new Cell *[size_y];
    for (int i = 0; i < this->size_y; i++) {
        this->cells[i] = new Cell[size_x];
        for (int j = 0; j < this->size_x; ++j) {
            this->cells[i][j].set_type(obj.cells[i][j].get_type());
        }
    }


    return *this;
}

Field &Field::operator=(Field &&obj) {
    if (&obj == this)
        return *this;

    this->size_x = obj.size_y;
    this->size_x = obj.size_x;

    for (int i = 0; i < this->size_x; i++) {
        delete[] this->cells[i];
    }
    delete[] this->cells;


    this->cells = obj.cells;
    obj.cells = nullptr;
    obj.size_x = 0;
    obj.size_y = 0;

    return *this;
}

void Field::set_size(int x, int y) {
    size_x = x;
    size_y = y;
}

void Field::get_cord_player(float &x, float &y) {
    x = (float) player_one->get_cord_x();
    y = (float) player_one->get_cord_y();
}

Player *Field::get_player() {
    return player_one;
}

bool Field::test_cord_enemy(int x, int y) {
    return test_cord_of_enemy(x, y, big_enemy) || test_cord_of_enemy(x, y, quick_enemy) ||
           test_cord_of_enemy(x, y, simple_enemy);
}

void Field::move_enemies() {
    move_concrete_enemy(big_enemy);
    move_concrete_enemy(simple_enemy);
    move_concrete_enemy(quick_enemy);
}

void Field::create_concrete_enemy(IEnemy *enemy) {
    enemy->set_cord_y(random_y());
    enemy->set_cord_x(random_x());
}

int Field::random_move() {
    int random_cord = rand() % 3 - 1; //-1 0 1
    return random_cord;
}

int Field::random_y() {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    int max_y = this->size_y - 3;
    int min_y = 1;
    int random_y = static_cast<int>(rand() * fraction * (max_y - min_y + 1) + min_y);
    return random_y;
}

int Field::random_x() {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    int max_x = this->size_x - 3;
    int min_x = 1;
    int random_x = static_cast<int>(rand() * fraction * (max_x - min_x + 1) + min_x);
    return random_x;
}

void Field::move_concrete_enemy(IEnemy *enemy) {
    if (enemy) {
        int rand_x = 0;
        int rand_y = 0;
        for (int i = 0; i < enemy->get_speed(); ++i) {
            if (random_move()) {
                rand_x = random_move();
            } else {
                rand_y = random_move();
            }
            if (test_cell(rand_x, rand_y, enemy)) {
                enemy->set_cord_x(enemy->get_cord_x() + rand_x);
                enemy->set_cord_y(enemy->get_cord_y() + rand_y);
            }
            rand_x = 0;
            rand_y = 0;
        }
    }
}

void Field::create_enemies() {
    simple_enemy = new Enemy<2, 1, 2>();
    big_enemy = new Enemy<3, 2, 1>();
    quick_enemy = new Enemy<1, 1, 3>();
    //random
    create_concrete_enemy(simple_enemy);
    create_concrete_enemy(big_enemy);
    create_concrete_enemy(quick_enemy);
}

bool Field::test_cord_of_enemy(int x, int y, IEnemy *enemy) {
    if (!enemy) {
        return false;
    }
    if (this->get_cells()[y][x].get_type() != EMPTY) {
        return false;
    }
    if (enemy->get_size() < 2) {
        return enemy->get_cord_x() == x &&
               enemy->get_cord_y() == y;
    } else {
        bool enemy_in_cord = false;
        for (int i = 0; i < enemy->get_size(); ++i) {
            for (int j = 0; j < enemy->get_size(); ++j) {
                if (enemy->get_cord_x() + i == x &&
                    enemy->get_cord_y() + j == y) {
                    enemy_in_cord = true;
                    break;
                }
            }
        }
        return enemy_in_cord;
    }
}

bool Field::test_cord_of_player(CellIterator *it) {
    return player_one->get_cord_x() == (it)->get_cord_x() &&
           player_one->get_cord_y() == (it)->get_cord_y();
}

IEnemy *Field::get_big_enemy() {
    return big_enemy;
}

IEnemy *Field::get_simple_enemy() {
    return simple_enemy;
}

IEnemy *Field::get_quick_enemy() {
    return quick_enemy;
}

void Field::create_player() {
    player_one = new Player();
    player_one->set_cord_x(1);
    player_one->set_cord_y(this->get_size_y() / 2);
    player_one->attach(logger);
}

void Field::create_concrete_element(AbstractFactory *factory, int k) {
    int randomx = 0;
    int randomy = 0;
    for (int i = 0; i < k; ++i) {
        randomx = random_x();
        randomy = random_y();
        this->get_cells()[randomy][randomx].set_element(factory->createElem());
        this->get_cells()[randomy][randomx].get_element()->attach(logger);
    }
    delete factory;
}

void Field::create_elements() {
    int size_y = this->get_size_y();
    int size_x = this->get_size_x();
    int k = size_y * size_x / 50;

    create_concrete_element(new CoinFactory, k / 2);
    create_concrete_element(new MushroomFactory, k / 3);
    create_concrete_element(new ChestFactory, k / 3);

    count_coins = k / 2;
}

bool Field::test_cell(int move_x, int move_y) {
    return cells[player_one->get_cord_y() + move_y][player_one->get_cord_x() + move_x].get_type() == EMPTY;
}

bool Field::test_cell(int move_x, int move_y, IEnemy *enemy) {
    return cells[enemy->get_cord_y() + move_y][enemy->get_cord_x() + move_x].get_type() == EMPTY;
}

int Field::get_count_coins() const {
    return count_coins;
}

void Field::interaction_with_elements() {
    if (cells[player_one->get_cord_y()][player_one->get_cord_x()].get_element()) {
        *player_one =
                *player_one + *cells[player_one->get_cord_y()][player_one->get_cord_x()].get_element();

        set_status_from_element(cells[player_one->get_cord_y()][player_one->get_cord_x()].get_element());

        cells[player_one->get_cord_y()][player_one->get_cord_x()].get_element()->log_end();
        if (player_one->get_health_player() <= 0) {
            this->status = LOSE;
        }

        delete cells[player_one->get_cord_y()][player_one->get_cord_x()].get_element();
        cells[player_one->get_cord_y()][player_one->get_cord_x()].set_element(nullptr);
    } else if (test_cord_of_enemy(player_one->get_cord_x(), player_one->get_cord_y(), big_enemy)) {
        *player_one = *player_one + *big_enemy;
        if (player_one->get_health_player() <= 0) {
            this->status = LOSE;
        }
        delete big_enemy;
        big_enemy = nullptr;
    } else if (test_cord_of_enemy(player_one->get_cord_x(), player_one->get_cord_y(), simple_enemy)) {
        *player_one = *player_one + *simple_enemy;
        if (player_one->get_health_player() <= 0) {
            this->status = LOSE;
        }
        delete simple_enemy;
        simple_enemy = nullptr;
    } else if (test_cord_of_enemy(player_one->get_cord_x(), player_one->get_cord_y(), quick_enemy)) {
        *player_one = *player_one + *quick_enemy;
        if (player_one->get_health_player() <= 0) {
            this->status = LOSE;
        }
        delete quick_enemy;
        quick_enemy = nullptr;
    }
}

bool Field::test_status() {
    if (status == WIN) {
        player_one->log_win();
        std::cout << "You win\n";
        return false;
    }
    if (status == LOSE) {
        player_one->log_end();
        std::cout << "You lose\n";
        return false;
    }
    if (status == PLAY) {
        return true;
    }
    if (status == WAIT) {
        std::cout << "Press enter to statr\n";
        return false;
    }
    if (status == CLOSE) {
        return false;
    }
    return false;
}

Status Field::get_status() {
    return status;
}

void Field::set_status(Status st) {
    status = st;
}

void Field::set_status_from_element(Element *elem) {
    this->status = elem->get_status();
}

void Field::set_count_coint(int count) {
    this->count_coins=count;
}

void Field::set_cells(Cell **cell) {
    delete cells;
    this->cells=cell;
}

