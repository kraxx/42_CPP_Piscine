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

/************ PROTECTED ************/


// Coplien methods

GameEntity::GameEntity(int x, int y, bool direction, bool alive) :
_posX(x), _posY(y), _direction(direction), _alive(alive) {};

GameEntity::GameEntity(GameEntity const& rhs) {
    *this = rhs;
};

GameEntity& GameEntity::operator=(GameEntity const& rhs) {

    _posX = rhs._posX;
    _posY = rhs._posY;
    _direction = rhs._direction;
    _alive = rhs._alive;
    return *this;
};


/************ PUBLIC ************/

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

// Methods

void         GameEntity::drawObject() const {

    // Do something with Ncurses

};