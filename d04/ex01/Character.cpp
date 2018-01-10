#include <iostream>
#include <string>
#include "Character.hpp"

// Coplien functions

Character::Character() {};

Character::Character(std::string const& name) :
_name(name), _ap(40), _weapon(NULL) {};

Character::Character(Character const& rhs) {
    *this = rhs;
};

Character& Character::operator=(Character const& rhs) {

    _name = rhs._name;
    _ap = rhs._ap;
    _weapon = rhs._weapon;
    return *this;
};

Character::~Character() {};

// Getters

std::string   Character::getName() const {
    return _name;
};

int           Character::getAP() const {
    return _ap;
};

AWeapon*      Character::getWeapon() const {
    return _weapon;
};

// Member methods

void          Character::recoverAP() {
    _ap += 40;
};

void          Character::equip(AWeapon* weapon) {
    _weapon = weapon;
};

void          Character::attack(Enemy* target) {

    if (_weapon != NULL && target != NULL) {

        if (_ap >= _weapon->getAPCost()) {

            _ap -= _weapon->getAPCost();
            std::cout << _name << " attacks " << target->getType() << " with a " << _weapon->getName() << std::endl;
            _weapon->attack();
            target->takeDamage(_weapon->getDamage());
            if (target->getHP() <= 0) {
                delete target;
            }
        } else {
            std::cout << _name << " does not have enough AP (" << _ap << ") to use a " << _weapon->getName() << " (AP Cost: " << _weapon->getAPCost() << ")" << std::endl;
        }
    }
};

// Non-member functions

std::ostream& operator<<(std::ostream& output, Character const& rhs) {

    if (rhs.getWeapon() != NULL) {
        output << rhs.getName() << " has " << rhs.getAP() << " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
    } else {
        output << rhs.getName() << " has " << rhs.getAP() << " AP and is unarmed" << std::endl;        
    }
    return output;
};