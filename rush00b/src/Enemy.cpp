/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:44:53 by jchow             #+#    #+#             */
/*   Updated: 2018/01/13 18:44:53 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"
#include "Enemy.hpp"

/*******************************************************************************
************************************  ENEMY  ***********************************
*******************************************************************************/


/************ PROTECTED ************/

void Enemy::initBullets() {

    for (int i = 0; i < MAX_BULLETS; i++) {
        _bullets[i] = new Bullet(_atkDmg, _bulletSpeed, ENEMY);
    }
};

void Enemy::triggerDeath() {

    _alive = false;
};


/************* PUBLIC *************/

// Coplien Methods

Enemy::Enemy(int x, unsigned int hp, unsigned int atkDmg, unsigned int bulletSpeed) :
Character(x, 0, DOWN, hp, atkDmg, bulletSpeed),
_speedCD(ENEMY_CD) {

    Enemy::initBullets();
 };


Enemy::Enemy(Enemy const& rhs) {
    *this = rhs;
};

Enemy& Enemy::operator=(Enemy const& rhs) {

    _posX = rhs._posX;
    _posY = rhs._posY;
    _direction = rhs._direction;
    _alive = rhs._alive;

    _hp = rhs._hp;
    _atkDmg = rhs._atkDmg;
    _bulletSpeed = rhs._bulletSpeed;
    
    _speedCD = rhs._speedCD;

    for (int i = 0; i < MAX_BULLETS; i++) {
        _bullets[i] = rhs._bullets[i];
    }

    return *this;
};

// Getters

unsigned int Enemy::getSpeedCoolDown() const {
    return _speedCD;
};

// Methods

void         Enemy::updateObject() {

    _speedCD -= 1;
    if (_speedCD == 0) {

        int dir = (_direction == UP ? 1 : -1);
        _posX += 1 * dir;
        _posY += 1 * dir;
        _speedCD = ENEMY_CD;
    }

};


/*******************************************************************************
************************************ DEBRIS ************************************
*******************************************************************************/

/************* PUBLIC *************/

// Coplien Methods

EnDebris::EnDebris(int x):
Enemy(x, DEBRIS_HP, DEBRIS_ATK_DMG, DEBRIS_BULLET_SPD) {};

EnDebris::EnDebris(EnDebris const& rhs) {
    *this = rhs;
};

EnDebris& EnDebris::operator=(EnDebris const& rhs) {

    _posX = rhs._posX;
    _posY = rhs._posY;
    _direction = rhs._direction;
    _alive = rhs._alive;

    _hp = rhs._hp;
    _atkDmg = rhs._atkDmg;
    _bulletSpeed = rhs._bulletSpeed;
    
    _speedCD = rhs._speedCD;

    for (int i = 0; i < MAX_BULLETS; i++) {
        _bullets[i] = rhs._bullets[i];
    }

    return *this;
};


/*******************************************************************************
************************************ SCRUB *************************************
*******************************************************************************/

/************* PUBLIC *************/

// Coplien Methods

EnScrub::EnScrub(int x): 
Enemy(x, SCRUB_HP, SCRUB_ATK_DMG, SCRUB_BULLET_SPD) {};

EnScrub::EnScrub(EnScrub const& rhs) {
    *this = rhs;
};

EnScrub& EnScrub::operator=(EnScrub const& rhs) {

    _posX = rhs._posX;
    _posY = rhs._posY;
    _direction = rhs._direction;
    _alive = rhs._alive;

    _hp = rhs._hp;
    _atkDmg = rhs._atkDmg;
    _bulletSpeed = rhs._bulletSpeed;
    
    _speedCD = rhs._speedCD;

    for (int i = 0; i < MAX_BULLETS; i++) {
        _bullets[i] = rhs._bullets[i];
    }

    return *this;
};


/*******************************************************************************
************************************* PRO **************************************
*******************************************************************************/

/************* PUBLIC *************/

// Coplien Methods

EnPro::EnPro(int x): 
Enemy(x, PRO_HP, PRO_ATK_DMG, PRO_BULLET_SPD) {};

EnPro::EnPro(EnPro const& rhs) {
    *this = rhs;
};

EnPro& EnPro::operator=(EnPro const& rhs) {

    _posX = rhs._posX;
    _posY = rhs._posY;
    _direction = rhs._direction;
    _alive = rhs._alive;

    _hp = rhs._hp;
    _atkDmg = rhs._atkDmg;
    _bulletSpeed = rhs._bulletSpeed;
    
    _speedCD = rhs._speedCD;

    for (int i = 0; i < MAX_BULLETS; i++) {
        _bullets[i] = rhs._bullets[i];
    }

    return *this;
};


/*******************************************************************************
************************************* GOD **************************************
*******************************************************************************/

/************* PUBLIC *************/

// Coplien Methods

EnGod::EnGod(int x): 
Enemy(x, GOD_HP, GOD_ATK_DMG, GOD_BULLET_SPD) {};

EnGod::EnGod(EnGod const& rhs) {
    *this = rhs;
};

EnGod& EnGod::operator=(EnGod const& rhs) {

    _posX = rhs._posX;
    _posY = rhs._posY;
    _direction = rhs._direction;
    _alive = rhs._alive;

    _hp = rhs._hp;
    _atkDmg = rhs._atkDmg;
    _bulletSpeed = rhs._bulletSpeed;
    
    _speedCD = rhs._speedCD;

    for (int i = 0; i < MAX_BULLETS; i++) {
        _bullets[i] = rhs._bullets[i];
    }

    return *this;
};