/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:47:33 by scollet           #+#    #+#             */
/*   Updated: 2018/01/13 10:47:34 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game(int y, int x)
{
  this->_player = new Player(y - 10, x / 2, y, x);
  _maxY = y;
  _maxX = x;
  return ;
}

Game::~Game(void) {
  return ;
}

Game::Game(Game const& rhs) {
    *this = rhs;
};

Game& Game::operator=(Game const& rhs) {

  _maxX = rhs._maxX;
  _maxY = rhs._maxY;
  _running = rhs._running;
  _player = rhs._player;
  _map = rhs._map;
  _enemies = rhs._enemies;
    return *this;
};

void Game::buildMaps(int sizey, int sizex)
{
  int i;

  _enemies = new Enemy*[sizey];
  for (i = 0; i < sizey; i++)
    _enemies[i] = new Enemy[sizex];
  _map = new char*[sizey];
  for (i = 0; i < sizey; i++)
    _map[i] = new char[sizex];
  return ;
}

int          Game::getMaxY(void)
{
  return _maxY;
}

int          Game::getMaxX(void)
{
  return _maxX;
}

void Game::setMap(int y, int x, char ch)
{
  this->_map[y][x] = ch;
  return ;
}

char Game::getMap(int y, int x)
{
  return this->_map[y][x];
}

Enemy & Game::getEnemy(int y, int x)
{
  return _enemies[y][x];
}

Player& Game::getPlayer(void)
{
  return *_player;
}

bool Game::isRunning(void)
{
  return this->_running;
}

void Game::keyCommand(int num)
{
  num = 0;
  return ;
}
