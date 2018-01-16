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


/************* PRIVATE *************/

// Coplien methods

Bullet::Bullet(int maxY, int maxX, unsigned int dmg, unsigned int speed, bool friendly) :
GameEntity(-1, -1, maxY, maxX, friendly, DEAD), _atkDmg(dmg), _speed(speed), _speedCD(speed), _friendly(friendly) {};

Bullet::Bullet(Bullet const& rhs) {
    *this = rhs;
};

Bullet& Bullet::operator=(Bullet const& rhs) {

    _maxY = rhs._maxY;
    _maxX = rhs._maxX;
    _posY = rhs._posY;
    _posX = rhs._posX;
    _direction = rhs._direction;
    _alive = rhs._alive;
    _atkDmg = rhs._atkDmg;
    _speed = rhs._speed;
    _speedCD = rhs._speedCD;
    _friendly = rhs._friendly;
    return *this;
};


/************* PUBLIC *************/

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

void         Bullet::activateBullet(int y, int x) {

    _alive = true;
    _posX = x;
    _posY = y + 1;
    return ;
};

void         Bullet::deactivateBullet() {

    // std::cerr << "Deactivate this shit\n";

    _alive = false;
    return ;
};

void         Bullet::hitTarget(Character& target) {

    target.takeDamage(_atkDmg);
    deactivateBullet();
};

void         Bullet::updateObject() {

    _speedCD -= 1;
    if (_speedCD == 0) {
        _posY += (_direction ? -1 : 1);
        _speedCD = _speed;
        if (_friendly) {
            if (_posY == CEILING)
                deactivateBullet();
        } else {
            if (_posY == _maxY)
                deactivateBullet();
        }

        return;    
    }
};

void         Bullet::setAtkDmg(int x) {
    _atkDmg = x;
};
