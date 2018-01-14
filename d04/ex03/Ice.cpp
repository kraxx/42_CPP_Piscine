#include <iostream>
#include "Ice.hpp"

Ice::Ice() :
// _xp(0), _type("ice") {};
AMateria("ice") {};

Ice::Ice(Ice const& rhs) {
    *this = rhs;
};

Ice& Ice::operator=(Ice const& rhs) {

    _xp = rhs._xp;
    _type = rhs._type;
    return *this;
};

Ice::~Ice() {};

AMateria*  Ice::clone() const {

    AMateria* ret = new Ice();
    // AMateria* ret = new AMateria("ice");
    // AMateria* ret = new AMateria(_type);
    return ret;
};

void       Ice::use(ICharacter& target) {

    _xp += 10;
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
};