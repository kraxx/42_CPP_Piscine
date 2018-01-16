/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:18:36 by jchow             #+#    #+#             */
/*   Updated: 2018/01/13 16:18:36 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEntity.hpp"

/*******************************************************************************
*******************************  GAME OBJECT  **********************************
*******************************************************************************/

/************ PUBLIC ************/


// Coplien methods

GameEntity::GameEntity(int y, int x, int maxY, int maxX, bool direction, bool alive) :
_posY(y), _posX(x), _maxY(maxY), _maxX(maxX), _direction(direction), _alive(alive) {};

GameEntity::GameEntity(GameEntity const& rhs) {
    *this = rhs;
};

GameEntity& GameEntity::operator=(GameEntity const& rhs) {

    _posX = rhs._posX;
    _posY = rhs._posY;
    _maxY = rhs._maxY;
    _maxX = rhs._maxX;
    _direction = rhs._direction;
    _alive = rhs._alive;
    return *this;
};

// Getters

int          GameEntity::getPosX() const {
    return _posX;
};

int          GameEntity::getPosY() const {
    return _posY;
};

bool         GameEntity::getDirection() const {
    return _direction;
};

bool         GameEntity::getAliveStatus() const {
    return _alive;
};

int GameEntity::getMaxY(void) {
  return _maxY;
}

int GameEntity::getMaxX(void) {
  return _maxX;
}

// Setters

void         GameEntity::setAliveStatus(bool status) {
  _alive = status;
}

// Methods

void         GameEntity::drawObject() const {

    // Do something with Ncurses

};
