#include <fstream>
#include <iostream>
#include <string>
#include "AWeapon.hpp"

// Copien functions

AWeapon::AWeapon() {};

AWeapon::AWeapon(std::string const& name, int apcost, int damage) :
_name(name), _apcost(apcost), _damage(damage) {};

AWeapon::AWeapon(AWeapon const& rhs) {
    *this = rhs;
};

AWeapon& AWeapon::operator=(AWeapon const& rhs) {

    _name = rhs._name;
    _apcost = rhs._apcost;
    _damage = rhs._damage;
    return *this;
};

AWeapon::~AWeapon() {};

// Getters

std::string AWeapon::getName() const {
    return _name;
};

int         AWeapon::getAPCost() const {
    return _apcost;
};

int         AWeapon::getDamage() const {
    return _damage;
};

// Member methods

void        AWeapon::attack() const {};