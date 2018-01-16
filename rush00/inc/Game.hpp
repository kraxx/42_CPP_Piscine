/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:47:39 by scollet           #+#    #+#             */
/*   Updated: 2018/01/13 10:47:40 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

#include <ncurses.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include "Enemy.hpp"
#include "Character.hpp"
#include "Player.hpp"


class Game {

public:
  Game(int y, int x);
  ~Game(void);
  Game(Game const& rhs);
  Game& operator=(Game const& rhs);

  bool isRunning(void);
  void keyCommand(int num);
  void terminate(int err);
  int getMaxY(void);
  int getMaxX(void);
  void setMap(int y, int x, char ch);
  char getMap(int y, int x);
  Enemy & getEnemy(int y, int x);
  void buildMaps(int sizey, int sizex);
  Player& getPlayer(void);

private:
  int     _maxX;
  int     _maxY;
  bool    _running;
  Player  *_player;
  char    **_map;
  Enemy   **_enemies;
};

#endif
