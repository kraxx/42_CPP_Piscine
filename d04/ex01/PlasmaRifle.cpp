#include <fstream>
#include <iostream>
#include <string>
#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() :
AWeapon("Plasma Rifle", 5, 21) {};

PlasmaRifle::PlasmaRifle(PlasmaRifle const& rhs) {
    *this = rhs;
};

PlasmaRifle& PlasmaRifle::operator=(PlasmaRifle const& rhs) {

    _name = rhs._name;
    _apcost = rhs._apcost;
    _damage = rhs._damage;
    return *this;
};

PlasmaRifle::~PlasmaRifle() {};

void        PlasmaRifle::attack() const {
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
};