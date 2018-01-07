#include <iostream>
#include <string>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) :
_name(name), _weapon(weapon) {};

HumanA::~HumanA() {};

void HumanA::attack() const {
    std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
};

void HumanA::setWeapon(Weapon &weapon) {
    _weapon = weapon;
};
