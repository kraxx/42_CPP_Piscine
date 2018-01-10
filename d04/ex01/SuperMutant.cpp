#include <iostream>
#include <string>
#include "SuperMutant.hpp"

SuperMutant::SuperMutant() :
Enemy(170, "Super Mutant") {

    std::cout << "Gaaah. Me want smash heads !" << std::endl;
};

SuperMutant::SuperMutant(SuperMutant const& rhs) {
    *this = rhs;
};

SuperMutant& SuperMutant::operator=(SuperMutant const& rhs) {

    _hp = rhs._hp;
    _type = rhs._type;
    return *this;
};

SuperMutant::~SuperMutant() {
    std::cout << "Aaargh ..." << std::endl;
};

void SuperMutant::takeDamage(int damage) {
    
    damage -= 3;

    if (damage > 0) {
        if (damage >= _hp) {
            _hp = 0;
        } else {
            _hp -= damage;
        }
    }
};