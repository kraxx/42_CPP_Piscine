#include <iostream>
#include <string>
#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap() {

    _name = "anonymous";
    _HP = 60;
    _maxHP = 60;
    _EP = 120;
    _maxEP = 120;
    _level = 1;
    _meleeAtkDmg = 60;
    _rangedAtkDmg = 5;
    _armor = 0;
    std::cout << "Unnamed N1NJ4-TP constructed" << std::endl;
};

NinjaTrap::NinjaTrap(std::string name) {

    _name = name;
    _HP = 60;
    _maxHP = 60;
    _EP = 120;
    _maxEP = 120;
    _level = 1;
    _meleeAtkDmg = 60;
    _rangedAtkDmg = 5;
    _armor = 0;
    std::cout << "N1NJ4-TP <" << name << "> constructed" << std::endl;
};

NinjaTrap::~NinjaTrap() {
    std::cout << "Terminating N1NJ4-TP <" << _name << ">..." << std::endl;
};

NinjaTrap::NinjaTrap(NinjaTrap const& rhs) {
    _name = rhs._name + " copy";
    *this = rhs;
    std::cout << "N1NJ4-TP <" << _name << "> replicated from " << rhs._name << std::endl;
}

NinjaTrap& NinjaTrap::operator=(NinjaTrap const& rhs) {
    _HP = rhs._HP;
    _maxHP = rhs._maxHP;
    _EP = rhs._EP;
    _maxEP = rhs._maxEP;
    _level = rhs._level;
    _meleeAtkDmg = rhs._meleeAtkDmg;
    _rangedAtkDmg = rhs._rangedAtkDmg;
    _armor = rhs._armor;
    std::cout << "N1NJ4-TP <" << _name << "> stats copied from " << rhs._name << std::endl;
    return *this;
};

void NinjaTrap::meleeAttack(std::string const& target) {

    std::cout << "N1NJ4-TP <" << _name << "> performs a melee attack on <" << target
    << ">, dealing <" << _meleeAtkDmg << "> points of damage" << std::endl;
};

void NinjaTrap::ninjaShoebox(std::string const& target) {

    std::cout << "N1NJ4-TP <" << _name << "> presents <" << target << "> with his glorious shoebox collection" << std::endl;
};