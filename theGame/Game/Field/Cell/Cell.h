//
// Created by vikto on 13.09.2020.
//

#ifndef MYGAME_CELL_H
#define MYGAME_CELL_H
#include "../../Elements/Element.h"
#include "../../Enemy/Enemy.h"

enum TypeCell {
    HWALL,
    VWALL,
    CWALL,
    EMPTY,
    ENTRANCE,
    EXIT
};


class Cell {

    Element* elem= nullptr;
    TypeCell type;
public:
    Cell();
    void set_type(TypeCell typeCell);
    void set_element(Element* element);
     Element * get_element();

    TypeCell get_type();

};


#endif //MYGAME_CELL_H
