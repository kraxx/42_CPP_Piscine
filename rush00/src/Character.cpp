/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:47:21 by scollet           #+#    #+#             */
/*   Updated: 2018/01/13 15:13:04 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"
#include "Character.hpp"

/*******************************************************************************
**********************************  CHARACTER  *********************************
*******************************************************************************/


/************* PUBLIC *************/

// Coplien Methods

Character::Character(int y, int x, int maxY, int maxX, bool direction, unsigned int hp, unsigned int atkDmg, unsigned int bulletSpeed):
GameEntity(y, x, maxY, maxX, direction, ALIVE),
_hp(hp), _atkDmg(atkDmg), _bulletSpeed(bulletSpeed) {};

Character::Character(Character const& rhs) {
    *this = rhs;
};

Character& Character::operator=(Character const& rhs) {

    _hp = rhs._hp;
    _atkDmg = rhs._atkDmg;
    _bulletSpeed = rhs._bulletSpeed;
    _posX = rhs._posX;
    _posY = rhs._posY;
    _maxY = rhs._maxY;
    _maxX = rhs._maxX;
    _direction = rhs._direction;
    _alive = rhs._alive;

    for (int i = 0; i < MAX_BULLETS; i++) {
        _bullets[i] = rhs._bullets[i];
    }

    return *this;
};

Character::~Character() {

    // std::cerr << "Char deletion\n";
    for (int i = 0; i < MAX_BULLETS; i++) {
        // std::cerr << "bullets getting rigaronid\n";
        delete _bullets[i];
    }
};

// Getters

unsigned int Character::getHP() const {
    return _hp;
};

unsigned int Character::getAtkDmg() const {
    return _atkDmg;
};

unsigned int Character::getBulletSpeed() const {
    return _bulletSpeed;
};

Bullet*      Character::getBullet(int idx) const {
    if (idx >= 0 && idx < MAX_BULLETS) {
        return _bullets[idx];
    }
    return NULL;
};

// Methods

void         Character::shootBullet() {

    for (int i = 0; i < MAX_BULLETS; i++) {
        if (this->_bullets[i]->getAliveStatus() == false) {
            this->_bullets[i]->activateBullet(_posY + (_direction ? -1 : 1), _posX);
            return ;
        }
    }

    // Else, bullet slots are full, do not fire.

};

void         Character::takeDamage(unsigned int dmg) {

    if (dmg >= _hp) {

        _hp = 0;
        triggerDeath();

    } else {
        _hp -= dmg;
    }
};


// void        Character::triggerDeath() {
//     delete this;
// }
