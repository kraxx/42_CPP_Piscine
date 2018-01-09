#include <iostream>
#include <string>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {

    _name = "anonymous";
    _HP = 100;
    _maxHP = 100;
    _EP = 50;
    _maxEP = 50;
    _level = 1;
    _meleeAtkDmg = 20;
    _rangedAtkDmg = 15;
    _armor = 3;
    std::cout << "Unnamed SC4V-TP constructed" << std::endl;
};

ScavTrap::ScavTrap(std::string name) {

    _name = name;
    _HP = 100;
    _maxHP = 100;
    _EP = 50;
    _maxEP = 50;
    _level = 1;
    _meleeAtkDmg = 20;
    _rangedAtkDmg = 15;
    _armor = 3;
    std::cout << "SC4V-TP <" << name << "> constructed" << std::endl;
};

ScavTrap::~ScavTrap() {
    std::cout << "Terminating SC4V-TP <" << _name << ">..." << std::endl;
};

ScavTrap::ScavTrap(ScavTrap const& rhs) {
    _name = rhs._name + " copy";
    *this = rhs;
    std::cout << "SC4V-TP <" << _name << "> replicated from " << rhs._name << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& rhs) {
    _HP = rhs._HP;
    _maxHP = rhs._maxHP;
    _EP = rhs._EP;
    _maxEP = rhs._maxEP;
    _level = rhs._level;
    _meleeAtkDmg = rhs._meleeAtkDmg;
    _rangedAtkDmg = rhs._rangedAtkDmg;
    _armor = rhs._armor;
    std::cout << "SC4V-TP <" << _name << "> stats copied from " << rhs._name << std::endl;
    return *this;
};

void ScavTrap::challengeNewcomer(std::string const& target) {

    std::string challenges[] = {
        "Dance off",
        "Spank off",
        "Hack off",
        "Bake off",
        "Hoop off"
    };

    std::cout << "SC4V-TP <" << _name << "> challenges <" << target << "> to a <" << challenges[rand() % 5] << ">" << std::endl;
};