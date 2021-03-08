//
// Created by vikto on 13.09.2020.
//

#include "Cell.h"

Cell::Cell() {
    type = EMPTY;
}



void Cell::set_type(TypeCell typeCell) {
    this->type = typeCell;
}

TypeCell Cell::get_type() {
    return type;
}

void Cell::set_element(Element* element) {
    this->elem=element;
}

 Element * Cell::get_element() {
    return this->elem;
}


