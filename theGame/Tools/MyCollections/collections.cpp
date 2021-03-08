//
// Created by vikto on 13.09.2020.
//

#include "collections.h"

CellCollection::CellCollection(Cell **cells,int width,int height):cells(cells),width(width),height(height) {
    head= new CellIterator(cells,width,height);
    back= new CellIterator(cells,width,height);
    while (back->get_cord_y()!=height-1){
        back->operator++();
    }
    while (back->get_cord_x()!=width-1){
        back->operator++();
    }


}

Iterator<Cell> *CellCollection::create_iterator() {
    CellIterator* a = new CellIterator(cells,width,height);
    return a;
}

Iterator<Cell> *CellCollection::begin() {

    return head;
}

Iterator<Cell> *CellCollection::end() {

    return back;
}
