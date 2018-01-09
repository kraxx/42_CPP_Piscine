#include <iostream>
#include <string>
#include <time.h>
#include "ClapTrap.hpp"

bool ClapTrap::_seeded = false;

ClapTrap::ClapTrap() {

    if (!_seeded) {
        srand(time(NULL));
        _seeded = true;
    }
    
    std::cout << "Constructing new CL4P-TP..." << std::endl;
};

ClapTrap::~ClapTrap() {
    std::cout << "CL4P-TP terminated" << std::endl;
};

ClapTrap::ClapTrap(ClapTrap const& rhs) :
_name(rhs._name + " copy") {

    *this = rhs;
    std::cout << "Replicating CL4P-TP..." << rhs._name << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs) {
    
    _HP = rhs._HP;
    _maxHP = rhs._maxHP;
    _EP = rhs._EP;
    _maxEP = rhs._maxEP;
    _level = rhs._level;
    _meleeAtkDmg = rhs._meleeAtkDmg;
    _rangedAtkDmg = rhs._rangedAtkDmg;
    _armor = rhs._armor;
    std::cout << "CL4P-TP <" << _name << "> stats copied from " << rhs._name << std::endl;
    return *this;
};

void ClapTrap::rangedAttack(std::string const& target) {

    std::cout << "CL4P-TP <" << _name << "> performs a ranged attack on <" << target
    << ">, dealing <" << _rangedAtkDmg << "> points of damage" << std::endl;
};

void ClapTrap::meleeAttack(std::string const& target) {

    std::cout << "CL4P-TP <" << _name << "> performs a melee attack on <" << target
    << ">, dealing <" << _meleeAtkDmg << "> points of damage" << std::endl;
};

void ClapTrap::takeDamage(unsigned int amount) {

    std::cout << "CL4P-TP <" << _name << "> takes <" << amount
    << "> points of damage" << std::endl;

    if (amount >= _HP) {

        _HP = 0;
        std::cout << "CL4P-TP <" << _name << "> has taken critical damage"
        << std::endl;
    } else {

        _HP -= amount;
        std::cout << "CL4P-TP <" << _name << "> has <" << _HP
        << "/" << _maxHP << "> HP left" << std::endl;  
    }
};

void ClapTrap::beRepaired(unsigned int amount) {

    std::cout << "CL4P-TP <" << _name << "> restores <" << amount
    << "> HP" << std::endl;

    if (_HP + amount >= _maxHP) {

        _HP = _maxHP;
        std::cout << "CL4P-TP <" << _name << "> restored to full health <"
        << _maxHP << "/" << _maxHP << ">" << std::endl;
    } else {

        _HP += amount;
        std::cout << "CL4P-TP <" << _name << "> has <" << _HP
        << "/" << _maxHP << "> HP left" << std::endl;  
    }
};
