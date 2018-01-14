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

Game::Game(void)
{
  std::srand(std::time(nullptr));
  initscr();
  start_color();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
  init_pair(1, COLOR_GREEN, COLOR_GREEN);
	init_pair(2, COLOR_WHITE, COLOR_GREEN);
	init_pair(3, COLOR_YELLOW, COLOR_GREEN);
	init_pair(4, COLOR_BLACK, COLOR_GREEN);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_GREEN);
	init_pair(7, COLOR_RED, COLOR_RED);
  this->_running = true;
  return ;
}

Game::~Game(void)
{
  for(int i = 0; i < 1; ++i)
    delete this->map[i];
  return ;
}

void Game::buildMap(int sizeX, int sizeY)
{
  int i;
  this->map = new char*[sizeY];

  for (i = 0; i < sizeY; ++i)
    this->map[i] = new char[sizeX];
  return ;
}

void Game::setMap(int X, int Y, char c)
{
  this->map[X][Y] = c;
  return ;
}

char Game::getMap(int X, int Y)
{
  return this->map[X][Y];
}

bool Game::isRunning(void)
{
  return this->_running;
}

void Game::terminate(int err)
{
  std::cout
  << "Goodybe"
  << std::endl;
  exit(err);
}

void Game::keyCommand(int num)
{
  num = 0;
  return ;
}
//
// Player & Game::getPlayer(void)
// {
//   return this->_player;
// }
