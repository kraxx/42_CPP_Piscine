#include <iostream>
#include <string>
#include "Enemy.hpp"

// Coplien functions

Enemy::Enemy() {};

Enemy::Enemy(int hp, std::string const& type) :
_hp(hp), _type(type) {};

Enemy::Enemy(Enemy const& rhs) {
    *this = rhs;
};

Enemy& Enemy::operator=(Enemy const& rhs) {

    _hp = rhs._hp;
    _type = rhs._type;
    return *this;
};

Enemy::~Enemy() {};

// Member methods

std::string Enemy::getType() const {
    return _type;
};

int         Enemy::getHP() const {
    return _hp;
};

void        Enemy::takeDamage(int damage) {

    if (damage > 0) {
        if (damage >= _hp) {
            _hp = 0;
        } else {
            _hp -= damage;
        }
    }
};