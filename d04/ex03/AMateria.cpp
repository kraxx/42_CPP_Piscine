#include <iostream>
#include "AMateria.hpp"
// #include "Ice.hpp"
// #include "Cure.hpp"

// class Ice;
// class Cure;

AMateria::AMateria() :
_xp(0) {};

AMateria::AMateria(std::string const& type) :
_xp(0), _type(type) {};

AMateria::AMateria(AMateria const& rhs) {
    *this = rhs;
};

AMateria& AMateria::operator=(AMateria const& rhs) {

    _xp = rhs._xp;
    _type = rhs._type;
    return *this;
};

AMateria::~AMateria() {};

std::string const& AMateria::getType() const {
    return _type;
};

unsigned int       AMateria::getXP() const {
    return _xp;
};

void               AMateria::use(ICharacter& target) {

    _xp += 10;
    // if (_type == "ice") {
    //     Ice::use(target);
    // } else if (_type == "cure") {
    //     Cure::use(target);
    // }
    (void)target;
};