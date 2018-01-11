#include <iostream>
#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() {};

Cure::Cure(std::string const& type) :
_xp(0), _type(type) {};

Cure::Cure(Cure const& rhs) {
    *this = rhs;
};

Cure& Cure::operator=(Cure const& rhs) {

    _xp = rhs._xp;
    _type = rhs._type;
    return *this;
};

Cure::~Cure() {};

std::string const& Cure::getType() const {
    return _type;
};

unsigned int       Cure::getXP() const {
    return _xp;
};

Cure*  Cure::clone() {

    Cure* ret = new Cure::Cure(_type);
    return ret;
};

void       Cure::use(ICharacter& target) {

    _xp += 10;
    std::cout << "* heals " << target << "'s wounds *" << std::endl;
};