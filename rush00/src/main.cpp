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

void setMapEnemy(Game* game, int enemyType, int y, int x) {

  if (enemyType == TYPE_DEBRIS) 
    game->setMap(y, x, '*');
  else if (enemyType == TYPE_SCRUB) {
    game->setMap(y - 1, x, '#');
    game->setMap(y, x, 'V');    
  }
  else if (enemyType == TYPE_PRO) {
    game->setMap(y, x, 'W');
    game->setMap(y, x - 1, '\\');
    game->setMap(y, x + 1, '/');
  }
  else if (enemyType == TYPE_GOD) {
    game->setMap(y, x, 'X');
    game->setMap(y, x - 1, '<');
    game->setMap(y, x + 1, '>');
    game->setMap(y, x - 2, '<');
    game->setMap(y, x + 2, '>');
    game->setMap(y - 1, x, '$');
    game->setMap(y - 2, x, '$');
  }

};

void play(Game *game)
{
  int uIn;
  int eKilled = 0;
  char pause[] = " GAME PAUSED ";

  Enemy** _en = new Enemy*[MAX_ENEMIES];
  for (int i = 0; i < MAX_ENEMIES; i++)
    _en[i] = nullptr;


  uIn = getch();
  while (game->getPlayer().getLives())
  {
    usleep(30000);
    timeout(0); // don't block for user
    uIn = getch();

    /*
      NOTE : CAPTURE USER INPUT AND ROUTE COMMANDS
    */

    switch (uIn)
    {
      case KEY_UP:
        if (game->getPlayer().getPosY() - 2 > PLAYER_BORDER)
        {
          game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX(), ' ');
          game->getPlayer().updateObject(-2, 0);
        }
        break;
      case KEY_DOWN:
        if (game->getPlayer().getPosY() + 2 < game->getMaxY() - PLAYER_BORDER)
        {
          game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX(), ' ');
          game->getPlayer().updateObject(2, 0);
        }
        break;
      case KEY_LEFT:
        if (game->getPlayer().getPosX() - 1 > PLAYER_BORDER)
        {
          game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX(), ' ');
          game->getPlayer().updateObject(0, -1);
        }
        break;
      case KEY_RIGHT:
        if (game->getPlayer().getPosX() + 1 < game->getMaxX() - PLAYER_BORDER)
        {
          game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX(), ' ');
          game->getPlayer().updateObject(0, 1);
        }
        break;
      case ' ':
        game->getPlayer().shootBullet();
        break;
      case 'p':
    	  attron(COLOR_PAIR(5) | A_BOLD);
    	  mvprintw(game->getMaxY() / 2, (game->getMaxX() - sizeof(pause)) / 2, "%s", pause);
    	  attroff(COLOR_PAIR(5) | A_BOLD);
        do {
          uIn = getch();
        } while(uIn != 'p');
        break;
      case KEY_END:
        game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX(), '*');
        game->getPlayer().triggerDeath();
        break;
      default:
        break;
    }

    /*
    **
      BIG NOTE ::: WIPE MAP
    **
    */

      //Wipe map, set stars
    for (int col = 0; col < game->getMaxY(); col++)
      for (int row = 0; row < game->getMaxX(); row++) {
        if (std::rand() % (5 * game->getMaxX()) <= 1) 
          game->setMap(col, row, '`');
        else          
          game->setMap(col, row, ' ');
      }

    /*
    **
      BIG NOTE ::: CYCLE THROUGH ALL ENEMIES
    **
    */

    // For Every Enemy we have
    for (int w = 0; w < MAX_ENEMIES; w++) {
      // If Enemy exists
      if (_en[w] != nullptr) {
        // Update Enemy coordinates
        _en[w]->updateObject();
        // If Enemy off screen
        if (_en[w]->getAliveStatus() == false) {
          // std::cerr <<"FUCK\n";
          delete _en[w];
          // std::cerr <<"SHIT\n";
          _en[w] = nullptr;
          continue;
        }
        // If Enemy collides with Player
        if (_en[w]->getPosX() == game->getPlayer().getPosX()
           && _en[w]->getPosY() == game->getPlayer().getPosY())
          game->getPlayer().takeDamage(_en[w]->getAtkDmg());
        // Set map with enemy
        setMapEnemy(game, _en[w]->getEnemyType(), _en[w]->getPosY(), _en[w]->getPosX());
        // For all bullets in Enemy
        for (int b = 0; b < MAX_BULLETS; b++) {
          // If bullet is active
          if (_en[w]->getBullet(b)->getAliveStatus() == true) {
            _en[w]->getBullet(b)->updateObject();
            // If bullet is now offscreen
            if (_en[w]->getBullet(b)->getAliveStatus() == false)
              continue;
            // If bullet collides with Player
            if (_en[w]->getBullet(b)->getPosX() == game->getPlayer().getPosX()
              && _en[w]->getBullet(b)->getPosY() == game->getPlayer().getPosY())
              // Hit Player
              _en[w]->getBullet(b)->hitTarget(game->getPlayer());
            // If bullet still alive
            if (_en[w]->getBullet(b)->getAliveStatus() == true)
              game->setMap(_en[w]->getBullet(b)->getPosY(), _en[w]->getBullet(b)->getPosX(), '|');
          }
        }
      }
    }

    /*
    **
      BIG NOTE ::: PLAYER UPDATES
    **
    */

    // For all bullets on player
    for (int b = 0; b < MAX_BULLETS; b++) {
      // If bullet is active
      if (game->getPlayer().getBullet(b)->getAliveStatus() == true) {
        // Update bullet coorinates
        game->getPlayer().getBullet(b)->updateObject();
        // Set map with bullet
        game->setMap(game->getPlayer().getBullet(b)->getPosY(),
          game->getPlayer().getBullet(b)->getPosX(), '!');
        // Check collision with enemies
        for (int w = 0; w < MAX_ENEMIES; w++) {
          // If enemy exists
          if (_en[w] != nullptr) {
            // If bullet coordinates collide with enemy's
            if ((game->getPlayer().getBullet(b)->getPosX() == _en[w]->getPosX())
              && (game->getPlayer().getBullet(b)->getPosY() == _en[w]->getPosY())) {
              // Hit target
              game->getPlayer().getBullet(b)->hitTarget(*_en[w]);
              // If Enemy is dead, set pointer to null
              if (_en[w]->getAliveStatus() == false) {
                // Update score
                eKilled += (_en[w]->getEnemyType() * 2) + 1;
                game->getPlayer().gainHP(_en[w]->getEnemyType());
                // Erase enemy from map
                game->setMap(_en[w]->getPosY(), _en[w]->getPosX(), ' ');
                delete _en[w];
                _en[w] = nullptr;
              }
              // Done with bullet here, stop iterating through enemies
              break;
            }
          }
        }
      }
    }
    // Set player on map
    game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX(), 'A');
    if (eKilled > 20) {
      game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX() + 1, '\\');
      game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX() - 1, '/');
    }
    if (eKilled > 50) {
      game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX() + 2, '\\');
      game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX() - 2, '/');
    }
    if (eKilled > 100) {
      game->setMap(game->getPlayer().getPosY() + 1, game->getPlayer().getPosX(), 'A');
      game->setMap(game->getPlayer().getPosY() + 2, game->getPlayer().getPosX(), 'A');
    }
    if (eKilled > 150) {
      game->setMap(game->getPlayer().getPosY() + 1, game->getPlayer().getPosX() + 1, '#');
      game->setMap(game->getPlayer().getPosY() + 1, game->getPlayer().getPosX() - 1, '#');
      game->setMap(game->getPlayer().getPosY() + 3, game->getPlayer().getPosX(), 'A');
      game->setMap(game->getPlayer().getPosY() + 4, game->getPlayer().getPosX(), 'A');
    }

    if (game->getPlayer().getAtkDmg() == 1 && eKilled > 20) {
        game->getPlayer().setAtkDmg(2);
    } else if (game->getPlayer().getAtkDmg() == 2 && eKilled > 50) {
        game->getPlayer().setAtkDmg(3);
    } else if (game->getPlayer().getAtkDmg() == 3 && eKilled > 100) {
        game->getPlayer().setAtkDmg(4);
    } else if (game->getPlayer().getAtkDmg() == 4 && eKilled > 150) {
        game->getPlayer().setAtkDmg(5);
    }


    /*
    **
      BIG NOTE ::: RANDOMLY GENERATE ENEMIES
    **
    */

    // Try generating enemies
    for (int z = 0; z < ENEMY_SPAWN_FREQ; z++) {
      // Rolling...
      if ((rand() % 100) < ENEMY_SPAWN_PERCENT) {

        // X coordinate to spawn on
        int spawnX;

        // Find empty spot
        int pp;
        for (pp = 0; pp <= 50; pp++) {
          spawnX = (rand() % (game->getMaxX() - 1) + 1);
          if ((game->getMap(2, spawnX) == ' ')
            && (game->getMap(2, spawnX + 1) == ' ')
            && (game->getMap(2, spawnX - 1) == ' '))
            break;
        }
        // If no spot, don't generate
        if (pp == 50)
          continue;

        // Find nullptr slot in array
        for (int w = 0; w < MAX_ENEMIES; w++) {
          if (_en[w] == nullptr) {

            // Roll for enemy type
            int rand = std::rand() % 12;
            // Assign enemy type
            if (rand <= 1)
              _en[w] = new EnGod(spawnX, game->getMaxY(), game->getMaxX());
            else if (rand <= 4)
              _en[w] = new EnPro(spawnX, game->getMaxY(), game->getMaxX());
            else if (rand <= 9)
              _en[w] = new EnScrub(spawnX, game->getMaxY(), game->getMaxX());
            else
              _en[w] = new EnDebris(spawnX, game->getMaxY(), game->getMaxX());
            // Set new enemy on map
            setMapEnemy(game, _en[w]->getEnemyType(), 4, spawnX);
            break;
          }
        }
      }
    }
    
  int i;
  int j;

    if (!game->getPlayer().getAliveStatus()) {
      for (i = game->getMaxY() - 1; i >= 0; --i)
        for (j = game->getMaxX() - 1; j >= 0; --j) {
          game->getEnemy(i, j).setAliveStatus(false);
        }
      move(0, 0);
      char deadTextDisp[] = " YOU DIED ";
      char deadTextInst[] = " PRESS R TO RESPAWN OR END TO QUIT ";
      attron(COLOR_PAIR(7) | A_BOLD);
      mvprintw(game->getMaxY() / 2,
      (game->getMaxX() - sizeof(deadTextDisp)) / 2, "%s", deadTextDisp);
      mvprintw((game->getMaxY() / 2) + 4,
      (game->getMaxX() - sizeof(deadTextInst)) / 2, "%s", deadTextInst);
      attroff(COLOR_PAIR(7) | A_BOLD);
      curs_set(0);
      do {
        uIn = getch();
      } while (uIn != 'r' && uIn != KEY_END);
      game->getPlayer().setAliveStatus(true);
    }


		move(0, 0);
    /*
      NOTE : BUFFER OUTPUT FOR PRINTING
    */

		for (int a = 0; a < game->getMaxY(); a++)
			for (int b = 0; b < game->getMaxX(); b++)
			{
        if (game->getMap(a, b) == 'W')
          attron(COLOR_PAIR(2) | A_BOLD);
        else if (game->getMap(a, b) == 'V')
          attron(COLOR_PAIR(2) | A_BOLD);
        else if (game->getMap(a, b) == 'X')
          attron(COLOR_PAIR(2) | A_BOLD);
        else if (game->getMap(a, b) == 'A')
          attron(COLOR_PAIR(9) | A_BOLD);
        else if (game->getMap(a, b) == '|')
          attron(COLOR_PAIR(3) | A_BOLD);
        else if (game->getMap(a, b) == '\\' || game->getMap(a, b) == '/')
          attron(COLOR_PAIR(1) | A_BOLD);
        else if (game->getMap(a, b) == ' ')
          attron(COLOR_PAIR(4) | A_BOLD);
        else if (game->getMap(a, b) == '`')
          attron(COLOR_PAIR(4) | A_BOLD);
        else if (game->getMap(a, b) == '!')
          attron(COLOR_PAIR(8) | A_BOLD);
        else if (game->getMap(a, b) == '<')
          attron(COLOR_PAIR(6) | A_BOLD);
        else if (game->getMap(a, b) == '>')
          attron(COLOR_PAIR(6) | A_BOLD);
        else if (game->getMap(a, b) == '$')
          attron(COLOR_PAIR(6) | A_BOLD);
        else if (game->getMap(a, b) == '#')
          attron(COLOR_PAIR(1) | A_BOLD);
        else if (game->getMap(a, b) == '*') {
          attron(COLOR_PAIR(7) | A_BOLD);
        }
        addch(game->getMap(a, b));
			}
		attron(COLOR_PAIR(6) | A_BOLD);
    mvprintw(game->getMaxY() - 4, 2, "/|========================================================================|\\");
		mvprintw(game->getMaxY() - 3, 2, "|| Score : %d ", eKilled);
    mvprintw(game->getMaxY() - 3, 20, "|=====| Lives : %d  ", game->getPlayer().getLives());
    mvprintw(game->getMaxY() - 3, 40, "|=====| HP : %2d  ", game->getPlayer().getHP());
    mvprintw(game->getMaxY() - 3, 58, "|=====| Dmg : %2d  ||", game->getPlayer().getAtkDmg());
    mvprintw(game->getMaxY() - 2, 2, "\\|========================================================================|/");
		attroff(COLOR_PAIR(6) | A_BOLD);
    if (uIn == KEY_END) break;
  }
  return ;
}

int main(void)
{
  int uIn;
  std::srand(std::time(nullptr));
  initscr();
  start_color();
	cbreak();
	noecho();
	keypad(stdscr, true);
  init_pair(1, COLOR_BLUE, COLOR_BLACK); // PLAYER
	init_pair(2, COLOR_RED, COLOR_BLACK); // ENEMY
	init_pair(3, COLOR_YELLOW, COLOR_BLACK); // BULLET
	init_pair(4, COLOR_WHITE, COLOR_BLACK); // BACKGROUND
	init_pair(5, COLOR_BLUE, COLOR_BLACK); // MESSAGES
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(7, COLOR_RED, COLOR_BLACK); // MESSAGES
  init_pair(8, COLOR_GREEN, COLOR_BLACK); // MESSAGES
  init_pair(9, COLOR_CYAN, COLOR_BLACK); // MESSAGES

	int maxX, maxY;
  getmaxyx(stdscr, maxY, maxX);
  if (maxY <= 10 || maxX <= 10) {
    std::cerr << "ERROR - RESIZE WINDOW" << std::endl;
    std::exit(-1);
  }
  int posY = maxY - 10, posX = maxX / 2;

  const char menuTextName[] = "ft_retro!";
  const char menuTextAuth[] = "SCollet:JChow";
  const char menuTextInst[] = "Press any key to continue...";
  const char endTextDisp[] = " GAME OVER ";
  const char endTextReset[] = " PRESS R TO PLAY AGAIN ";
  const char endTextInst[] = " PRESS END TO EXIT ";

  while (true) {
    Game *game = new Game(maxY, maxX);
    game->buildMaps(maxY, maxX);


    attron(COLOR_PAIR(5));
    mvprintw((maxY / 2) - 2, (maxX - sizeof(menuTextName)) / 2, "%s", menuTextName);
  	mvprintw(maxY / 2, (maxX - sizeof(menuTextAuth)) / 2, "%s", menuTextAuth);
  	attroff(COLOR_PAIR(5));

  	attron(A_BOLD);
  	mvprintw((maxY / 2) + 4, (maxX - sizeof(menuTextInst)) / 2, "%s", menuTextInst);
  	attroff(A_BOLD);
  	curs_set(0);

    for (int a = 0; a < maxY - 1; a++)
      for (int b = 0; b < maxX - 1; b++)
        game->setMap(a, b, ' ');

    game->setMap(posY, posX, 'A');

    play(game);

  	attron(COLOR_PAIR(7) | A_BOLD);
    mvprintw(maxY / 2, (maxX - sizeof(endTextDisp)) / 2, "%s", endTextDisp);
    mvprintw((maxY / 2) + 2, (maxX - sizeof(endTextReset)) / 2, "%s", endTextReset);
    mvprintw((maxY / 2) + 4, (maxX - sizeof(endTextInst)) / 2, "%s", endTextInst);
  	attroff(COLOR_PAIR(7) | A_BOLD);
    curs_set(0);

  	timeout(-1);
  	do {
  		uIn = getch();
  	} while(uIn != KEY_END && uIn != 'r');

    endwin();
    delete game;
    if (uIn == KEY_END)
      break;
  }

  std::cout << "Thanks for playing!" << std::endl;
  return 0;
}
