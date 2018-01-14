/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:41:14 by scollet           #+#    #+#             */
/*   Updated: 2018/01/13 10:41:15 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Enemy.hpp"
#include "Header.hpp"
#include "Character.hpp"
#include "GameEntity.hpp"

void play(Player *player, Enemy *enemies, Game *game)
{
  int i;
  int uIn;

  while (player->getAliveStatus())
  {
    uIn = getch();
    switch (uIn)
    {
      case KEY_UP:
        if (player->getPosY() - 1 > 1)
        {
          game->setMap(player->getPosY(), player->getPosX(), ' ');
          game->setMap(player->getPosY(), player->getPosX() - 1, ' ');
          player->updateObject(0, -1);
        }
        break;
      case KEY_DOWN:
        if (player->getPosY() + 1 < game->getMaxY())
        {
          game->setMap(player->getPosY(), player->getPosX(), ' ');
          game->setMap(player->getPosY(), player->getPosX() - 1, ' ');
          player->updateObject(0, 1);
        }
        break;
      case KEY_LEFT:
        if (player->getPosX() - 1 > 1)
        {
          game->setMap(player->getPosY(), player->getPosX(), ' ');
          game->setMap(player->getPosY(), player->getPosX() - 1, ' ');
          player->updateObject(-1, 0);
        }
        break;
      case KEY_RIGHT:
        if (player->getPosX() + 1 < game->getMaxX())
        {
          game->setMap(player->getPosY(), player->getPosX(), ' ');
          game->setMap(player->getPosY(), player->getPosX() - 1, ' ');
          player->updateObject(1, 0);
        }
        break;
      case ' ':
        player->shootBullet();
        break;
      case 27:
        player->setAliveStatus(false);
        break;
      default:
        break;
    }
    game->setMap(player->getPosY(), player->getPosX(), player);

    for (i = 0; !enemies[i].getSpeedCoolDown(); i++)
      enemies[i].updateObject();
    for (i = 0; !player->getBullet(i)->getAliveStatus(); i++)
      player->getBullet(i)->updateObject();

		move(0, 0);

		for (int a = 0; a < game->getMaxY(); a++)
			for (int b = 0; b < game->getMaxX(); b++)
			{
				// if (game->getMapN(a, b) attron(COLOR_PAIR(1) | A_BOLD);
				if (game->getMapN(a, b) == 100)
        {
          attron(COLOR_PAIR(2) | A_BOLD);
          addch('A');
        }
				else if (game->getMapN(a, b) == -1)
        {
          addch('|');
          attron(COLOR_PAIR(4));
        }
        else if (game->getMapN(a, b) >= 0 && game->getMapN(a, b) < 100)
        {
          addch('#');
          attron(COLOR_PAIR(6));
        }
				// else if (game->getMapN(a, b) == ) attron(COLOR_PAIR(4));
				// else if (game->getMapN(a, b) == '@') attron(COLOR_PAIR(6));
				// else if (game->getMapN(a, b) == '%') attron(COLOR_PAIR(7) | A_BOLD);
				else attron(COLOR_PAIR(2) | A_BOLD);
				// addch(game->getMapN(a, b).getCh());
				standend();
			}
			attron(COLOR_PAIR(2) | A_BOLD);
			mvprintw(game->getMaxX() - 1, 0, "Enemies killed: %i", 0);
			attroff(COLOR_PAIR(2) | A_BOLD);
	}
  return ;
}

int main(void)
{
  // init
  std::srand(std::time(nullptr));
  initscr();
  start_color();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
  init_pair(1, COLOR_GREEN, COLOR_BLUE);
	init_pair(2, COLOR_WHITE, COLOR_BLUE);
	init_pair(3, COLOR_YELLOW, COLOR_GREEN);
	init_pair(4, COLOR_BLACK, COLOR_GREEN);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_GREEN);
	init_pair(7, COLOR_RED, COLOR_RED);

	int maxX, maxY;
  int i;
  getmaxyx(stdscr, maxY, maxX);
  int posY = maxY - 5, posX = maxX / 2;

  Game *game = new Game(maxY, maxX);
  Player *player = new Player();
  EnScrub *enemies = new EnScrub[MAX_ENEMIES];

  game->setMap(posX, posY, player);

  for (i = 0; i < MAX_ENEMIES; i++)
    game->setMap(enemies[i].getPosX(), enemies[i].getPosY(), i);

  attron(COLOR_PAIR(5));
  mvprintw((maxY / 2) - 2, (maxX - sizeof(menuTextName)) / 2, "%s", menuTextName);
	mvprintw(maxY / 2, (maxX - sizeof(menuTextAuth)) / 2, "%s", menuTextAuth);
	attroff(COLOR_PAIR(5));

	attron(A_BOLD);
	mvprintw((maxY / 2) + 4, (maxX - sizeof(menuTextInst)) / 2, "%s", menuTextInst);
	attroff(A_BOLD);

	curs_set(0);

  for (int i = 0; i < maxX; ++i)
         map[0][i] = ' ';

  for (int i = 0; i < maxY; ++i)
  {
     map[i][maxX - 5] = '/';
     map[i][maxX - 2] = '/';
  }
  for (int a = 2; a < maxY - 2; ++a)
     for (int b = 0; b < maxX; ++b)
         map[a][b] = ' ';
  for (int i = 0; i < maxX; ++i)
     map[maxY - 1][i] = ' ';
	map[posY][posX] = 'A';

  play(player, enemies, game);

  char text[] = " You lost... ";
	attron(COLOR_PAIR(7) | A_BOLD);
	mvprintw(maxX / 2, (maxY - sizeof(text)) / 2, "%s", text);
	attroff(COLOR_PAIR(7) | A_BOLD);

	//the player needs the press enter to quit (so he gets time to see how many zombies he killed)
	timeout(-1);
	do {
		uIn = getch();
	} while(uIn != 10);

  endwin();
  // delete[] enemies;
  delete player;
  delete game;
  return 0;
}
