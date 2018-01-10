#include <fstream>
#include <iostream>
#include <string>
#include "Squad.hpp"

Squad::Squad() :
_list(NULL), _listSize(0) {};

Squad::Squad(Squad const& rhs) {
    *this = rhs;
};

Squad& Squad::operator=(Squad const& rhs) {

    _list = rhs._list;
    return *this;
};

Squad::~Squad() {

    struct _marine* tmp = _list;

    for (int i = 0; i < _listSize; i++) {
        delete tmp->unit;
        tmp = tmp->next;
    }
    delete _list;
};

int           Squad::getCount() const {
    std::cout << "TEEHEE\n";
    return _listSize;
};

int           Squad::push(ISpaceMarine* unit) {

    if (unit != NULL) {

        struct _marine* tmp = _list;
        struct _marine* newUnit = new _marine();
        newUnit->unit = unit;
        newUnit->next = NULL;

        if (_listSize == 0) {
             std::cout << "www\n";
            tmp = newUnit;
        } else {
            for (int i = 1; i < _listSize; i++) {
                tmp = tmp->next;
            }
              std::cout << "fff\n";
            tmp->next = newUnit;
              std::cout << "ggdsaf\n";
        }
        _listSize += 1;
    }
    std::cout << "REE\n";
    return _listSize;
};

ISpaceMarine* Squad::getUnit(int n) const {
    
    struct _marine* ret = _list;

    for (int i = 0; i == n; i++) {
        ret = ret->next;
    }
    return ret->unit;
};
