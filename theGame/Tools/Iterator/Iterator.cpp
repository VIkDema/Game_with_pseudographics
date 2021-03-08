
//
// Created by vikto on 14.09.2020.
//
#include "Iterator.h"


CellIterator::CellIterator(Cell **temp, int width, int height) : cells(temp), width(width), height(height) {
    cord_x = 0;
    cord_y = 0;
}

Cell &CellIterator::operator*() {
    return cells[cord_y][cord_x];

}

Iterator<Cell> &CellIterator::operator--() {
    //не работает
    return *this;
}

Iterator<Cell> &CellIterator::operator++() {
    if (cord_x == width - 1 && cord_y == height - 1) {
        return *this;
    }
    cord_x++;
    if (cord_x == width) {
        cord_x = 0;
        cord_y++;
    }


    return *this;
}

bool CellIterator::operator==(const CellIterator &other) const {
    return this->cord_y == other.cord_y && this->cord_x == other.cord_x;
}

bool CellIterator::operator!=(const CellIterator &other) const {
    return !(this->cord_y == other.cord_y && this->cord_x == other.cord_x);
}

int CellIterator::get_cord_y() const {
    return cord_y;
}

int CellIterator::get_cord_x() const {
    return cord_x;
}
