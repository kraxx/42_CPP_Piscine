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

#include <ncurses.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include "Character.hpp"

class Game {
public:
  Game(void);
  ~Game(void);

  bool isRunning(void);
  void keyCommand(int num);
  void terminate(int err);
  // Player & getPlayer(void);
  void setMap(int X, int Y, char c);
  char getMap(int X, int Y);
  void buildMap(int sizeX, int sizeY);
private:
  bool _running;
  // Player _player;
  char **map;
};
