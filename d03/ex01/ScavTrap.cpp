#include <iostream>
#include <string>
#include <time.h>
#include "ScavTrap.hpp"

bool ScavTrap::_seeded = false;

ScavTrap::ScavTrap() :
_name("anonymous"), _HP(100), _maxHP(100), _EP(50), _maxEP(50),
_level(1), _meleeAtkDmg(20), _rangedAtkDmg(15), _armor(3) {

    if (!_seeded) {
        srand(time(NULL));
        _seeded = true;
    }
    
    std::cout << "Unnamed SC4V-TP constructed" << std::endl;
};

ScavTrap::ScavTrap(std::string name) :
_name(name), _HP(100), _maxHP(100), _EP(50), _maxEP(50),
_level(1), _meleeAtkDmg(20), _rangedAtkDmg(15), _armor(3) {

    if (!_seeded) {
        srand(time(NULL));
        _seeded = true;
    }

    std::cout << "SC4V-TP <" << name << "> constructed" << std::endl;
};

ScavTrap::~ScavTrap() {
    std::cout << "SC4V-TP <" << _name << "> terminated" << std::endl;
};

ScavTrap::ScavTrap(ScavTrap const& rhs) :
_name(rhs._name + " copy") {
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

void ScavTrap::rangedAttack(std::string const& target) {

    std::cout << "SC4V-TP <" << _name << "> performs a ranged attack on <" << target
    << ">, dealing <" << _rangedAtkDmg << "> points of damage" << std::endl;
};

void ScavTrap::meleeAttack(std::string const& target) {

    std::cout << "SC4V-TP <" << _name << "> performs a melee attack on <" << target
    << ">, dealing <" << _meleeAtkDmg << "> points of damage" << std::endl;
};

void ScavTrap::takeDamage(unsigned int amount) {

    std::cout << "SC4V-TP <" << _name << "> takes <" << amount
    << "> points of damage" << std::endl;

    if (amount >= _HP) {

        _HP = 0;
        std::cout << "SC4V-TP <" << _name << "> has taken critical damage"
        << std::endl;
    } else {

        _HP -= amount;
        std::cout << "SC4V-TP <" << _name << "> has <" << _HP
        << "/" << _maxHP << "> HP left" << std::endl;  
    }
};

void ScavTrap::beRepaired(unsigned int amount) {

    std::cout << "SC4V-TP <" << _name << "> restores <" << amount
    << "> HP" << std::endl;

    if (_HP + amount >= _maxHP) {

        _HP = _maxHP;
        std::cout << "SC4V-TP <" << _name << "> restored to full health <"
        << _maxHP << "/" << _maxHP << ">" << std::endl;
    } else {

        _HP += amount;
        std::cout << "SC4V-TP <" << _name << "> has <" << _HP
        << "/" << _maxHP << "> HP left" << std::endl;  
    }
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