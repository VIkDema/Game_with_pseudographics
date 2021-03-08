//
// Created by vikto on 13.09.2020.
//

#include "Game.h"
#include "Commands/Controller.h"
#include "States/StateMovePlayer.h"

Game *Game::game_ = nullptr;

Game::Game() {
    field = Field::get_instance();
    state = new StateMovePlayer(this);
}


Game *Game::get_instance() {
    if (game_ == nullptr) {
        game_ = new Game();
    }
    return game_;
}

void Game::play() {
    field->set_status(PLAY);

}

void Game::print_console() {
    system("cls");
    field->get_player()->log_cord_player();
    int size_y = field->get_size_y();
    int size_x = field->get_size_x();
    Cell **cells = field->get_cells();

    CellCollection cont(cells, size_x, size_y);

    it = cont.create_iterator();

    while ((*(CellIterator *) it) != *(CellIterator *) cont.end()) {
        if (field->test_cord_of_player(dynamic_cast<CellIterator *>(it))) {
            std::cout << "+";
            ++(*it);
            continue;
        }

        if (field->test_cord_of_enemy(dynamic_cast<CellIterator *>(it)->get_cord_x(),
                    dynamic_cast<CellIterator *>(it)->get_cord_y(), field->get_big_enemy())) {
            field->get_big_enemy()->print_enemy();
            ++(*it);
            continue;
        }
        if (field->test_cord_of_enemy(dynamic_cast<CellIterator *>(it)->get_cord_x(),
                                      dynamic_cast<CellIterator *>(it)->get_cord_y(), field->get_quick_enemy())) {
            field->get_quick_enemy()->print_enemy();
            ++(*it);
            continue;
        }
        if (field->test_cord_of_enemy(dynamic_cast<CellIterator *>(it)->get_cord_x(),
                                      dynamic_cast<CellIterator *>(it)->get_cord_y(), field->get_simple_enemy())) {
            field->get_simple_enemy()->print_enemy();
            ++(*it);
            continue;
        }
        if ((**it).get_element() != nullptr) {
            (**it).get_element()->print_element();
            ++(*it);
            continue;
        }
        if ((**it).get_type() == EMPTY) {
            std::cout << " ";
        }
        if ((**it).get_type() == HWALL) {
            std::cout << "_";
        }
        if ((**it).get_type() == VWALL || (**it).get_type() == CWALL) {
            std::cout << "|";
        }

        if ((**it).get_type() == EXIT) {
            std::cout << "$";
        }
        if ((**it).get_type() == ENTRANCE) {
            std::cout << "#";
        }
        if (((CellIterator *) it)->get_cord_x() == size_x - 1) {
            std::cout << "\n";
        }
        ++(*it);

    }
    std::cout << "|" << std::endl;
    print_specifications_console();
}

Game::~Game() {
    delete (CellIterator *) it;
    delete field;
    delete game_;
}

void Game::print_specifications_console() {
    std::cout << "Health:" << field->get_player()->get_health_player() << "\n";
    std::cout << "Coins:" << field->get_player()->get_coins_player() << "\n";
    if (field->get_count_coins() - field->get_player()->get_coins_player() < 0) {
        std::cout << "You need coins to win:" << 0 << "\n";
        return;
    }
    std::cout << "You need coins to win:" << field->get_count_coins() - field->get_player()->get_coins_player() << "\n";
}

void Game::left() {
    if (field->get_status() == PLAY) {
        if (field->test_cell(-1, 0)) {
            field->get_player()->set_cord_x(field->get_player()->get_cord_x() - 1);
        }
        field->interaction_with_elements();
    }
}

void Game::right() {
    if (field->get_status() == PLAY) {
        if (field->test_cell(1, 0)) {
            field->get_player()->set_cord_x(field->get_player()->get_cord_x() + 1);
            field->interaction_with_elements();
        } else {
            if (field->get_cells()[field->get_player()->get_cord_y()][field->get_player()->get_cord_x() +
                                                                      1].get_type() == EXIT &&
                field->get_player()->get_coins_player() >= field->get_count_coins()) {
                field->set_status(WIN);
                field->get_player()->set_cord_x(field->get_player()->get_cord_x() + 1);
            } else {
                std::cout << "Not enough coins!" << std::endl;
            }
        }
    }
}

void Game::down() {
    if (field->get_status() == PLAY) {
        if (field->test_cell(0, 1)) {
            field->get_player()->set_cord_y(field->get_player()->get_cord_y() + 1);
        }
        field->interaction_with_elements();
    }
}

void Game::up() {
    if (field->get_status() == PLAY) {
        if (field->test_cell(0, -1)) {
            field->get_player()->set_cord_y(field->get_player()->get_cord_y() - 1);
        }
        field->interaction_with_elements();
    }
}

void Game::close() {
    field->set_status(CLOSE);
}

void Game::start() {
    if (field->get_status() == WAIT) {
        field->set_status(PLAY);
    }
}


void Game::set_state(StateMove *state) {
    delete this->state;
    this->state = state;
}

void Game::move_player() {
    Controller controller(this);
    controller.inputCommand();
}


Game::Memento Game::save_memento() {
    Game::Memento save(field);
    return save;
}

void Game::load_memento(Game::Memento *load) {
     field = load->field;
}


Game::Memento::Memento(Field *field) : field(field) {

}

Game::Memento::Memento(): field(nullptr){

}

StateMove *Game::get_state() {
    return state;
}




