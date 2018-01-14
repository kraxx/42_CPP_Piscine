#include <iostream>
#include "Cure.hpp"

Cure::Cure() :
// _xp(0), _type("cure") {};
AMateria("cure") {};

Cure::Cure(Cure const& rhs) {
    *this = rhs;
};

Cure& Cure::operator=(Cure const& rhs) {

    _xp = rhs._xp;
    _type = rhs._type;
    return *this;
};

Cure::~Cure() {};

AMateria*  Cure::clone() const {

    AMateria* ret = new Cure();
    // AMateria* ret = new AMateria(_type);
    // AMateria* ret = new AMateria("cure");
    return ret;
};

void       Cure::use(ICharacter& target) {

    _xp += 10;
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
};