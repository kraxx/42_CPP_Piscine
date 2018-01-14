/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:00:29 by jchow             #+#    #+#             */
/*   Updated: 2018/01/13 15:13:14 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"
#include "Bullet.hpp"
#include "Character.hpp"

/*******************************************************************************
************************************  BULLET  **********************************
*******************************************************************************/


/************* PUBLIC *************/

// Coplien methods

Bullet::Bullet(unsigned int dmg, unsigned int speed, bool friendly) :
GameEntity(-1, -1, friendly, DEAD), _atkDmg(dmg), _speed(speed), _friendly(friendly) {};

Bullet::Bullet(Bullet const& rhs) {
    *this = rhs;
};

Bullet& Bullet::operator=(Bullet const& rhs) {

    _posX = rhs._posX;
    _posY = rhs._posY;
    _direction = rhs._direction;
    _alive = rhs._alive;

    _atkDmg = rhs._atkDmg;
    _speed = rhs._speed;
    _speedCD = rhs._speedCD;

    _friendly = rhs._friendly;
    
    return *this;
};

// Getters

unsigned int Bullet::getAtkDmg() const {
    return _atkDmg;
};

unsigned int Bullet::getSpeed() const {
    return _speed;
};

bool         Bullet::getFriendly() const {
    return _friendly;
};

unsigned int Bullet::getSpeedCoolDown() const {
    return _speedCD;
};

// Methods

void         Bullet::activateBullet(int x, int y) {

    _alive = true;
    _posX = x;
    _posY = y;

};

void         Bullet::deactivateBullet() {

    _alive = false;

};

void         Bullet::hitTarget(Character& target) {

    target.takeDamage(_atkDmg);
    deactivateBullet();
};

void         Bullet::updateObject() {

    _speedCD -= 1;
    if (_speedCD == 0) {

        int dir = (_direction == UP ? 1 : -1);
        _posX += 1 * dir;
        _posY += 1 * dir;
        _speedCD = _speed;
    }
}; 