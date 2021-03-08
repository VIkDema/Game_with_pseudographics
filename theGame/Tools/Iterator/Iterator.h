//
// Created by vikto on 13.09.2020.
//

#ifndef MYGAME_ITERATOR_H
#define MYGAME_ITERATOR_H

#include "../../Game/Field/Cell/Cell.h"


class CellIterator;

template<class U>
class Iterator {
public:
    virtual U &operator*() = 0;

    virtual Iterator<U> &operator++() = 0;

    virtual Iterator<U> &operator--() = 0;
};


class CellIterator : public Iterator<Cell> {
    Cell **cells;
    int width;
    int height;
    int cord_x;
    int cord_y;

public:
    CellIterator(Cell **temp, int width, int height);

    Cell &operator*() override;

    Iterator<Cell> &operator++() override;

    Iterator<Cell> &operator--() override;

    bool operator==(const CellIterator &other) const;

    bool operator!=(const CellIterator &other) const;

    int get_cord_x() const;

    int get_cord_y() const;

};


#endif //MYGAME_ITERATOR_H

