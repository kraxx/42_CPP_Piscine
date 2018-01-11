#include <iostream>
#include "AMateria.hpp"

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

// AMateria*  AMateria::clone() {

//     AMateria* ret = new AMateria::AMateria(_type);
//     return ret;
// };

// void       AMateria::use(ICharacter& target) {
    
//     (void)target;
//     _xp += 10;
// };