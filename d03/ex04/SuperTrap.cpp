#include <iostream>
#include <string>
#include "SuperTrap.hpp"

SuperTrap::SuperTrap() {

    _name = "anonymous";
    _HP = 100;
    _maxHP = 100;
    _EP = 120;
    _maxEP = 120;
    _level = 1;
    _meleeAtkDmg = 60;
    _rangedAtkDmg = 20;
    _armor = 5;
    std::cout << "Unnamed 5UP3R-TP constructed" << std::endl;
};

SuperTrap::SuperTrap(std::string name) {

    _name = name;
    _HP = 100;
    _maxHP = 100;
    _EP = 120;
    _maxEP = 120;
    _level = 1;
    _meleeAtkDmg = 60;
    _rangedAtkDmg = 20;
    _armor = 5;
    std::cout << "5UP3R-TP <" << name << "> constructed" << std::endl;
};

SuperTrap::~SuperTrap() {
    std::cout << "Terminating 5UP3R-TP <" << _name << ">..." << std::endl;
};

SuperTrap::SuperTrap(SuperTrap const& rhs) {

    _name = rhs._name + " copy";
    *this = rhs;
    std::cout << "5UP3R-TP <" << _name << "> replicated from " << rhs._name << std::endl;
}

SuperTrap& SuperTrap::operator=(SuperTrap const& rhs) {
    
    _HP = rhs._HP;
    _maxHP = rhs._maxHP;
    _EP = rhs._EP;
    _maxEP = rhs._maxEP;
    _level = rhs._level;
    _meleeAtkDmg = rhs._meleeAtkDmg;
    _rangedAtkDmg = rhs._rangedAtkDmg;
    _armor = rhs._armor;
    std::cout << "5UP3R-TP <" << _name << "> stats copied from " << rhs._name << std::endl;
    return *this;
};