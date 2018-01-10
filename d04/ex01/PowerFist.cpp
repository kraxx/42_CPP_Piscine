#include <fstream>
#include <iostream>
#include <string>
#include "PowerFist.hpp"

PowerFist::PowerFist() :
AWeapon("Power Fist", 8, 50) {};

PowerFist::PowerFist(PowerFist const& rhs) {
    *this = rhs;
};

PowerFist& PowerFist::operator=(PowerFist const& rhs) {

    _name = rhs._name;
    _apcost = rhs._apcost;
    _damage = rhs._damage;
    return *this;
};

PowerFist::~PowerFist() {};

void        PowerFist::attack() const {
    std::cout << "* pschhh...SBAM! *" << std::endl;
};