#include <iostream>
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource() :
_materia(){NULL, NULL, NULL, NULL} {

    // for (int i = 0; i < 4; i++) {
    //     _materia[i] = NULL;
    // }
};

MateriaSource::MateriaSource(MateriaSource const& rhs) {
    *this = rhs;
};

MateriaSource& MateriaSource::operator=(MateriaSource const& rhs) {

    for (int i = 0; i < 4; i++) {
        _materia[i] = rhs._materia[i];
    }
    return *this;
};

MateriaSource::~MateriaSource() {};

void MateriaSource::learnMateria(AMateria* materia) {

    int i = 0;
    for (; i < 4; i++) {
        if (_materia[i] != NULL) {
            break;
        }
    }
    if (i == 4) {
        std::cout << "MateriaSource: Materia slots full, cannot equip any more" << std::endl;
    } else {
        _materia[i] = materia;
    }
};

AMateria* MateriaSource::createMateria(std::string const & type) {

    if (type == "ice") {
        return new Ice();
    } else if (type == "cure") {
        return new Cure();
    }
    // AMateria* ret = new AMateria(type);
    return NULL;
};