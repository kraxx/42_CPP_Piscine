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
        _bullets[i] = new Bullet(_maxY, _maxX, _atkDmg, _bulletSpeed, ENEMY);
    }
};

void Enemy::triggerShootBullet() {

    if ((rand() % 100) < (_enemyType * ENEMY_SHOOT_FREQ)) {
        shootBullet();
    }
};

/************* PUBLIC *************/

// Coplien Methods

Enemy::Enemy() {

    Enemy::initBullets();
};

Enemy::Enemy(int x, int maxY, int maxX, unsigned int hp, unsigned int atkDmg, unsigned int bulletSpeed, unsigned int enemyType) :
Character(CEILING, x, maxY, maxX, DOWN, hp, atkDmg, bulletSpeed),
_speedCD(ENEMY_CD), _enemyType(enemyType) {

    // std::cerr << "ENEMY GENERATED\n";
    Enemy::initBullets();
 };


void         Enemy::activateEnemy(int y, int x) {
  _posX = x;
  _posY = y;
  _direction = 1;
  _alive = true;
  _speedCD = ENEMY_CD;
  int et = std::rand() % 10;


  if (et <= 2) {
    _hp = DEBRIS_HP;
    _atkDmg = DEBRIS_ATK_DMG;
    _bulletSpeed = DEBRIS_BULLET_SPD;
    _enemyType = TYPE_DEBRIS;
  }
  return ;
 };

Enemy::Enemy(Enemy const& rhs) {
    *this = rhs;
};

Enemy& Enemy::operator=(Enemy const& rhs) {

    _hp = rhs._hp;
    _atkDmg = rhs._atkDmg;
    _bulletSpeed = rhs._bulletSpeed;
    _posX = rhs._posX;
    _posY = rhs._posY;
    _maxY = rhs._maxY;
    _maxX = rhs._maxX;
    _direction = rhs._direction;
    _alive = rhs._alive;
    _speedCD = rhs._speedCD;
    _enemyType = rhs._enemyType;

    for (int i = 0; i < 1; i++) {
        _bullets[i] = rhs._bullets[i];
    }

    return *this;
};

// Getters

unsigned int Enemy::getSpeedCoolDown() const {
    return _speedCD;
};

unsigned int Enemy::getEnemyType() const {
    return _enemyType;
};

// Methods

void         Enemy::updateObject() {

    _speedCD -= 1;
    if (_speedCD == 0) {
        _posY += (_direction ? -1 : 1);
        _speedCD = ENEMY_CD;

        if (_posY == _maxY - 5) {
            // triggerRealDeath();
            triggerDeath();
            // delete this;
            return;
        }

       triggerShootBullet();
    }
};

void Enemy::triggerRealDeath() {
    delete this;
};

void Enemy::triggerDeath() {
    _alive = false;
};


/*******************************************************************************
************************************ DEBRIS ************************************
*******************************************************************************/

/************* PUBLIC *************/

// Coplien Methods

EnDebris::EnDebris(int x, int maxY, int maxX):
Enemy(x, maxY, maxX, DEBRIS_HP, DEBRIS_ATK_DMG, DEBRIS_BULLET_SPD, TYPE_DEBRIS) {};

EnDebris::EnDebris(EnDebris const& rhs) {
    *this = rhs;
};

EnDebris& EnDebris::operator=(EnDebris const& rhs) {

    _hp = rhs._hp;
    _atkDmg = rhs._atkDmg;
    _bulletSpeed = rhs._bulletSpeed;
    _posX = rhs._posX;
    _posY = rhs._posY;
    _maxY = rhs._maxY;
    _maxX = rhs._maxX;
    _direction = rhs._direction;
    _alive = rhs._alive;
    _speedCD = rhs._speedCD;
    _enemyType = rhs._enemyType;

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

EnScrub::EnScrub(int x, int maxY, int maxX):
Enemy(x, maxY, maxX, SCRUB_HP, SCRUB_ATK_DMG, SCRUB_BULLET_SPD, TYPE_SCRUB) {};

EnScrub::EnScrub(EnScrub const& rhs) {
    *this = rhs;
};

EnScrub& EnScrub::operator=(EnScrub const& rhs) {

    _hp = rhs._hp;
    _atkDmg = rhs._atkDmg;
    _bulletSpeed = rhs._bulletSpeed;
    _posX = rhs._posX;
    _posY = rhs._posY;
    _maxY = rhs._maxY;
    _maxX = rhs._maxX;
    _direction = rhs._direction;
    _alive = rhs._alive;
    _speedCD = rhs._speedCD;
    _enemyType = rhs._enemyType;

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

EnPro::EnPro(int x, int maxY, int maxX):
Enemy(x, maxY, maxX, PRO_HP, PRO_ATK_DMG, PRO_BULLET_SPD, TYPE_PRO) {};

EnPro::EnPro(EnPro const& rhs) {
    *this = rhs;
};

EnPro& EnPro::operator=(EnPro const& rhs) {

    _hp = rhs._hp;
    _atkDmg = rhs._atkDmg;
    _bulletSpeed = rhs._bulletSpeed;
    _posX = rhs._posX;
    _posY = rhs._posY;
    _maxY = rhs._maxY;
    _maxX = rhs._maxX;
    _direction = rhs._direction;
    _alive = rhs._alive;
    _speedCD = rhs._speedCD;
    _enemyType = rhs._enemyType;

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

EnGod::EnGod(int x, int maxY, int maxX):
Enemy(x, maxY, maxX, GOD_HP, GOD_ATK_DMG, GOD_BULLET_SPD, TYPE_GOD) {};

EnGod::EnGod(EnGod const& rhs) {
    *this = rhs;
};

EnGod& EnGod::operator=(EnGod const& rhs) {

    _hp = rhs._hp;
    _atkDmg = rhs._atkDmg;
    _bulletSpeed = rhs._bulletSpeed;
    _posX = rhs._posX;
    _posY = rhs._posY;
    _maxY = rhs._maxY;
    _maxX = rhs._maxX;
    _direction = rhs._direction;
    _alive = rhs._alive;
    _speedCD = rhs._speedCD;
    _enemyType = rhs._enemyType;

    for (int i = 0; i < MAX_BULLETS; i++) {
        _bullets[i] = rhs._bullets[i];
    }

    return *this;
};
