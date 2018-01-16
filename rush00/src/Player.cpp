/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:25:09 by jchow             #+#    #+#             */
/*   Updated: 2018/01/14 14:25:09 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

/*******************************************************************************
***********************************  PLAYER  ***********************************
*******************************************************************************/


/************ PRIVATE ************/

void    Player::initBullets() {

    for (int i = 0; i < MAX_BULLETS; i++) {
        _bullets[i] = new Bullet(_maxY, _maxX, _atkDmg, _bulletSpeed, ALLY);
    }
};

void         Player::triggerDeath() {
    _lives -= 1;
    _alive = false;
    _posY = _maxY - 10;
    _posX = _maxX / 2;
    _hp = PLAYER_HP;
};

/************* PUBLIC *************/

// Coplien Methods

Player::Player(int y, int x, int maxY, int maxX) :
Character(y, x, maxY, maxX, UP, PLAYER_HP, PLAYER_DAMAGE, PLAYER_BULLET_SPEED),
 _lives(PLAYER_LIVES) {

    Player::initBullets();
};

Player::Player(Player const& rhs) {
    *this = rhs;
};

Player& Player::operator=(Player const& rhs) {

    _hp = rhs._hp;
    _lives = rhs._lives;
    _atkDmg = rhs._atkDmg;
    _bulletSpeed = rhs._bulletSpeed;
    _posX = rhs._posX;
    _posY = rhs._posY;
    _direction = rhs._direction;
    _alive = rhs._alive;

    for (int i = 0; i < MAX_BULLETS; i++) {
        _bullets[i] = rhs._bullets[i];
    }

    return *this;
};

// Getters

unsigned int Player::getLives() const {
    return _lives;
};

// Methods

void         Player::updateObject(int y, int x) {
  _posX += x;
  _posY += y;
  return ;

};
void         Player::gainHP(int x) {

    _hp += x;
    if (_hp > PLAYER_MAX_HP) {
        _hp = PLAYER_MAX_HP;
    }
};

void         Player::setAtkDmg(int x) {
    
    _atkDmg = x;
    for (int i = 0; i < MAX_BULLETS; i++) {
        _bullets[i]->setAtkDmg(x);
    }

};
