//
// Created by vikto on 13.09.2020.
//

#ifndef MYGAME_MYCOLLECTIONS_H
#define MYGAME_MYCOLLECTIONS_H

#include "../../Game/Field/Cell/Cell.h"
#include "../Iterator/Iterator.h"

template<class U>
class Collection {
    virtual Iterator<U> *create_iterator() = 0;
    virtual Iterator<U> *begin() = 0;
    virtual Iterator<U> *end() = 0;
};

class CellCollection : public Collection<class Cell> {
    //хранит коллекцию
    Cell **cells;
    CellIterator* head;
    CellIterator* back;
    int height;
    int width;
public:
    CellCollection(Cell **cells,int width,int height);
    Iterator<Cell> *create_iterator() override;
    Iterator<Cell> *begin() override;
    Iterator<Cell> *end() override;

};


#endif //MYGAME_MYCOLLECTIONS_H
