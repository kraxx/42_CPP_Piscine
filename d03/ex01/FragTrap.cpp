#include <iostream>
#include <string>
#include <time.h>
#include "FragTrap.hpp"

#define EP_VAULT_HUNTER 25

bool FragTrap::_seeded = false;

FragTrap::FragTrap() :
_name("anonymous"), _HP(100), _maxHP(100), _EP(100), _maxEP(100),
_level(1), _meleeAtkDmg(30), _rangedAtkDmg(20), _armor(5) {

    if (!_seeded) {
        srand(time(NULL));
        _seeded = true;
    }
    
    std::cout << "Unnamed FR4G-TP constructed" << std::endl;
};

FragTrap::FragTrap(std::string name) :
_name(name), _HP(100), _maxHP(100), _EP(100), _maxEP(100),
_level(1), _meleeAtkDmg(30), _rangedAtkDmg(20), _armor(5) {

    if (!_seeded) {
        srand(time(NULL));
        _seeded = true;
    }

    std::cout << "FR4G-TP <" << name << "> constructed" << std::endl;
};

FragTrap::~FragTrap() {
    std::cout << "FR4G-TP <" << _name << "> terminated" << std::endl;
};

FragTrap::FragTrap(FragTrap const& rhs) :
_name(rhs._name + " copy") {
    *this = rhs;
    std::cout << "FR4G-TP <" << _name << "> replicated from " << rhs._name << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const& rhs) {
    _HP = rhs._HP;
    _maxHP = rhs._maxHP;
    _EP = rhs._EP;
    _maxEP = rhs._maxEP;
    _level = rhs._level;
    _meleeAtkDmg = rhs._meleeAtkDmg;
    _rangedAtkDmg = rhs._rangedAtkDmg;
    _armor = rhs._armor;
    std::cout << "FR4G-TP <" << _name << "> stats copied from " << rhs._name << std::endl;
    return *this;
};

void FragTrap::rangedAttack(std::string const& target) {

    std::cout << "FR4G-TP <" << _name << "> performs a ranged attack on <" << target
    << ">, dealing <" << _rangedAtkDmg << "> points of damage" << std::endl;
};

void FragTrap::meleeAttack(std::string const& target) {

    std::cout << "FR4G-TP <" << _name << "> performs a melee attack on <" << target
    << ">, dealing <" << _meleeAtkDmg << "> points of damage" << std::endl;
};

void FragTrap::takeDamage(unsigned int amount) {

    std::cout << "FR4G-TP <" << _name << "> takes <" << amount
    << "> points of damage" << std::endl;

    if (amount >= _HP) {

        _HP = 0;
        std::cout << "FR4G-TP <" << _name << "> has taken critical damage"
        << std::endl;
    } else {

        _HP -= amount;
        std::cout << "FR4G-TP <" << _name << "> has <" << _HP
        << "/" << _maxHP << "> HP left" << std::endl;  
    }
};

void FragTrap::beRepaired(unsigned int amount) {

    std::cout << "FR4G-TP <" << _name << "> restores <" << amount
    << "> HP" << std::endl;

    if (_HP + amount >= _maxHP) {

        _HP = _maxHP;
        std::cout << "FR4G-TP <" << _name << "> restored to full health <"
        << _maxHP << "/" << _maxHP << ">" << std::endl;
    } else {

        _HP += amount;
        std::cout << "FR4G-TP <" << _name << "> has <" << _HP
        << "/" << _maxHP << "> HP left" << std::endl;  
    }
};

void FragTrap::vaulthunter_dot_exe(std::string const& target) {

    std::string attacks[] = {
        "Electric shock",
        "Rocket launch",
        "Headbutt",
        "Friendly wave",
        "Spin around three times"
    };

    if (_EP < EP_VAULT_HUNTER) {
        std::cout << "FR4G-TP <" << _name << "> does not enough energy to use <vaulthunter_dot_exe>" << std::endl;
    } else {
        _EP -= EP_VAULT_HUNTER;
        std::cout << "FR4G-TP <" << _name << "> performs <" << attacks[rand() % 5] << "> on <" << target << ">" << std::endl;
    }
    std::cout << "FR4G-TP <" << _name << "> has <" << _EP
    << "/" << _maxEP << "> energy left" << std::endl;  
};