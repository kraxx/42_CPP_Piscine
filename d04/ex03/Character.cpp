#include <iostream>
#include "Character.hpp"

Character::Character() {};

Character::Character(std::string const& name) :
_name(name), AMateria*():_materia{NULL, NULL, NULL, NULL}{} {

    // for (int i = 0; i < 4; i++) {
    //     _materia[i] = NULL;
    // }
};

Character::Character(Character const& rhs) {
    *this = rhs;
};

Character& Character::operator=(Character const& rhs) {

    _name = rhs._name;
    for (int i = 0; i < 4; i++) {
        _materia[i] = rhs._materia[i];
    }
    return *this;
};

Character::~Character() {};

std::string const& Character::getName() const {
    return _name;
};

void Character::equip(AMateria* m) {

    int i = 0;
    for (; i < 4; i++) {
        if (_materia[i] != NULL) {
            break;
        }
    }
    if (i == 4) {
        std::cout << _name << ": Materia slots full, cannot equip any more" << std::endl;
    } else {
        _materia[i] = m;
    }
};

void Character::unequip(int idx) {

    if (_materia[idx] != NULL) {
        _materia[idx] = NULL;
    } else {
        std::cout << "No materia equipped in slot " << idx << std::endl;
    }
};

void Character::use(int idx, ICharacter& target) {

    if (_materia[idx] != NULL) {
        _materia[idx]->use(target);
    }
};