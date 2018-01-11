#include <iostream>
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
    return _listSize;
};

int           Squad::push(ISpaceMarine* unit) {

    if (unit != NULL && checkDupe(unit) == false) {

        struct _marine* tmp = _list;
        struct _marine* newUnit = new _marine();
        newUnit->unit = unit;
        newUnit->next = NULL;

        if (_listSize > 0) {
            for (int i = 1; i < _listSize; i++) {
                tmp = tmp->next;
            }
            tmp->next = newUnit;
        } else {
            _list = newUnit;
        }
        _listSize += 1;
    }
    return _listSize;
};

bool          Squad::checkDupe(ISpaceMarine* unit) {

    struct _marine* tmp = _list;
    for (int i = 0; i < _listSize; i++) {
        if (tmp->unit == unit) {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

ISpaceMarine* Squad::getUnit(int n) const {
    
    struct _marine* tmp = _list;

    if (_list != NULL && n < _listSize) {
        for (int i = 0; i < n; i++) {
            tmp = tmp->next;
        }
    } else {
        std::cout << "getUnit: unit of index " << n << " does not exist" << std::endl;
        exit(1);
    }
    return tmp->unit;
};
