#include <iostream>
#include "Ice.hpp"

Ice::Ice() {};

Ice::Ice(std::string const& type) :
_xp(0), _type(type) {};

Ice::Ice(Ice const& rhs) {
    *this = rhs;
};

Ice& Ice::operator=(Ice const& rhs) {

    _xp = rhs._xp;
    _type = rhs._type;
    return *this;
};

Ice::~Ice() {};

std::string const& Ice::getType() const {
    return _type;
};

unsigned int       Ice::getXP() const {
    return _xp;
};

Ice*  Ice::clone() {

    Ice* ret = new Ice::Ice(_type);
    return ret;
};

void       Ice::use(ICharacter& target) {

    _xp += 10;
    std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
};