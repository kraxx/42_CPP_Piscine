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
    game->setMap(y, x, 'X');
  else if (enemyType == TYPE_SCRUB)
    game->setMap(y, x, 'W');
  else if (enemyType == TYPE_PRO)
    game->setMap(y, x, 'P');
  else if (enemyType == TYPE_GOD)
    game->setMap(y, x, 'G');
};

void play(Game *game)
{
  int i;
  int j;
  int uIn;
  int eKilled = 0;
  char pause[] = " GAME PAUSED ";


  Enemies** _en = new Enemies*[MAX_ENEMIES];
  for (int i = 0; i < MAX_ENEMIES; i++)
    _en[i] = NULL;


  uIn = getch();
  std::cout << "play entered" << std::endl;
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
        if (game->getPlayer().getPosY() - 1 > 1)
        {
          game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX(), ' ');
          game->getPlayer().updateObject(-1, 0);
        }
        break;
      case KEY_DOWN:
        if (game->getPlayer().getPosY() + 1 < game->getMaxY() - 1)
        {
          game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX(), ' ');
          game->getPlayer().updateObject(1, 0);
        }
        break;
      case KEY_LEFT:
        if (game->getPlayer().getPosX() - 1 > 1)
        {
          game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX(), ' ');
          game->getPlayer().updateObject(0, -1);
        }
        break;
      case KEY_RIGHT:
        if (game->getPlayer().getPosX() + 1 < game->getMaxX() - 1)
        {
          game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX(), ' ');
          game->getPlayer().updateObject(0, 1);
        }
        break;
      case ' ':
        game->getPlayer().shootBullet();
        break;
      case 'p':
        move(0, 0);
    	  attron(COLOR_PAIR(5) | A_BOLD);
    	  mvprintw(game->getMaxY() / 2, (game->getMaxX() - sizeof(pause)) / 2, "%s", pause);
    	  attroff(COLOR_PAIR(5) | A_BOLD);
        do {
          uIn = getch();
        } while(uIn != 'p');
        break;
      case KEY_END:
        game->getPlayer().triggerDeath(); // currently doesn't exit properly
        break;
      default:
        break;
    }


    /*
      NOTE : CHECK ENEMY ALIVE STATUS
    */



    for (i = game->getMaxY() - 1; i >= 0; --i) // pre-increment
      for (j = game->getMaxX() - 1; j >= 0; --j) { // pre-increment

        

        if (game->getEnemy(i, j).getAliveStatus() == true) {

          

          /*
            NOTE : WIPE LAST POSITION AND UPDATE OBJECT
          */

          
          if (game->getMap(i + 1, j) != '|' && game->getMap(i + 1, j) != 'A') {

              game->setMap(i, j, ' ');

            // Bottom border: kill enemy
            if (i >= game->getMaxY() - 4) {
              game->getEnemy(i, j).setAliveStatus(false);
              continue ;
            }
            game->getEnemy(i, j).updateObject();

            // game->getEnemy(i + 1, j).activateEnemy(i + 1, j);
            game->getEnemy(i + 1, j) = game->getEnemy(i, j);

            game->setMap(i + 1, j, 'W');
            game->setMap(i + 1, j + 1, '/');
            game->setMap(i + 1, j - 1, '\\');

          } else if (game->getMap(i + 1, j) == '|') {


            game->setMap(i, j, '*');

            eKilled++;
          } else if (game->getMap(i + 1, j) == 'A') {
            // exit(1);
            game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX(), ' ');
            game->getPlayer().triggerDeath();
          }
          // game->setMap(game->getEnemy(ey, ex).getPosY()),
          // game->getEnemy(ey + 1, ex).getPosX(), 'W');

          // game->getEnemy(game->getEnemy(ey, ex).getPosY(),
          // game->getEnemy(ey + 1, ex).setAliveStatus(true);

          game->getEnemy(i, j).setAliveStatus(false);

        } else if (std::rand() % 1000 == 1 && i == 2) {

          /*
            NOTE : RANDOM CHANCE TO SPAWN ENEMIES
          */

          

          int r = std::rand() % (game->getMaxX() - 2);
          if (!game->getEnemy(2, r).getAliveStatus()) {
            game->getEnemy(i, j).activateEnemy(i, j);
            game->setMap(i, r, 'W');
          }
        } else if (i <= 2 || j <= 2 ||
          i >= game->getMaxY() - 2 || j >= game->getMaxX() - 2) {
          game->setMap(i, j, ' ');
        } else {
          game->setMap(i, j, ' ');
        }
        /*else if (!game->getEnemy(i, j).getAliveStatus()) {
          game->getEnemy(i, j).setAliveStatus(true);
          if (game->getMap(i, j) != '|') {
            game->setMap(i, j, 'W');
          } else {
            game->setMap(i, j, ' ');
            game->getEnemy(i, j).setAliveStatus(false);
            eKilled++;
          }
        }*/

          // else if (!game->getEnemy(i, j).getAliveStatus()) {
          // game->setMap(i, j, ' ');
          // game->getEnemy(i, j).triggerDeath();
        // }

        // std::cerr << game->getEnemy(i, j).getAliveStatus() << std::endl;*/
      }

    /*
      NOTE : CHECK BULLET ALIVE STATUS
    */

    for (i = 0; i < MAX_BULLETS; i++)
    {
      if (game->getPlayer().getBullet(i)->getAliveStatus()) {
        int by = game->getPlayer().getBullet(i)->getPosY();
        int bx = game->getPlayer().getBullet(i)->getPosX();

        /*
          NOTE : SET BULLET PREVIOUS POSITION TO EMPTY && UPDATE BULLET OBJECT POSITION
        */

        
        game->setMap(by, bx, ' ');
        

        // yo this thing YO
        game->getPlayer().getBullet(i)->updateObject();

        
        game->setMap(game->getPlayer().getBullet(i)->getPosY(),
        game->getPlayer().getBullet(i)->getPosX(), '|');

        /*
          NOTE : CHECK IF BULLET INTERSECTS WITH ENEMY OR LEAVES SCREEN
        */

        

        if (game->getEnemy(game->getPlayer().getBullet(i)->getPosY(),
        game->getPlayer().getBullet(i)->getPosX()).getAliveStatus()) {
          game->getEnemy(game->getPlayer().getBullet(i)->getPosY(),
          game->getPlayer().getBullet(i)->getPosX()).takeDamage(game->getPlayer().getAtkDmg());
          game->setMap(game->getPlayer().getBullet(i)->getPosY(),
          game->getPlayer().getBullet(i)->getPosX(), '*');
          eKilled++;
        } else if (game->getPlayer().getBullet(i)->getPosY() < 2) {
          game->getPlayer().getBullet(i)->deactivateBullet();
          game->setMap(game->getPlayer().getBullet(i)->getPosY(),
          game->getPlayer().getBullet(i)->getPosX(), ' ');
        }
      }
    }

    /*
      NOTE : SET PLAYER'S NEW POSITION
    */

    game->setMap(game->getPlayer().getPosY(), game->getPlayer().getPosX(), 'A');

    if (game->getMap(game->getPlayer().getPosY() - 1, game->getPlayer().getPosX()) == 'W') {
      game->getPlayer().triggerDeath();
    }

    if (!game->getPlayer().getAliveStatus()) {
      // exit(1);
      for (i = game->getMaxY() - 1; i >= 0; --i)
        for (j = game->getMaxX() - 1; j >= 0; --j) {
          game->getEnemy(i, j).setAliveStatus(false);
        }
      game->getPlayer().setAliveStatus(true);
      // exit(1);
    }
    // exit(1);

    
		move(0, 0);


/***************************************************************************************/


    // Wipe every point of the map
    for (int col = 0; col < game->getMapY(); col++)
      for (int row = 0; row < game->getMapX(); row++)
        game->setMap(col, row, ' ');


    /*
    **
      BIG NOTE ::: CYCLE THROUGH ALL ENEMIES
    **
    */

    // For Every Enemy we have
    for (int w = 0; w < MAX_ENEMIES; w++) {
      // If Enemy exists
      if (_en[w] != NULL) {
        // For all bullets in Enemy
        for (int b = 0; b < MAX_BULLETS; b++) {
          // If bullet is active
          if (_en[w]->getBullet(b)->getAliveStatus() == true) {
            _en[w]->getBullet(b)->updateObject();
            // If bullet collides with Player
            if (_en[w]->getBullet(b)->getPosX == game->getPlayer()->getPosX
              && _en[w]->getBullet(b)->getPosY == game->getPlayer()->getPosY)
              // Hit Player
              _en[w]->getBullet(b)->hitTarget(game->getPlayer());
            // If bullet still alive
            if (_en[w]->getBullet(b)->getAliveStatus() == true)
              game->setMap(_en[w]->getBullet(b)->PosY, _en[w]->getBullet(b)->PosX, '\'');
          }
        }
        // Update Enemy coordinates
        _en[w]->updateObject();
        // If Enemy collides with Player
        if (_en[w]->getPosX == game->getPlayer()->getPosX
           && _en[w]->getBullet(b)->getPosY == game->getPlayer()->getPosY)
          game->getPlayer()->takeDamage(_en[w]->getAtkDmg());
        // Set map with enemy
        setMapEnemy(_en[w]->getPosY, _en[w]->getPosX, game, _en[w]->getEnemyType)
      }
    }

    // will have to handle bullets of dead enemies... maybe

    /*
    **
      BIG NOTE ::: PLAYER UPDATES
    **
    */

    // For all bullets on player
    for (int b = 0; b < MAX_BULLETS; b++) {
      // If bullet is active
      if (game->getPlayer()->getBullet(b)->getAliveStatus() == true) {
        // Update bullet coorinates
        game->getPlayer()->getBullet(b)->updateObject();
        // Set map with bullet
        game->setMap(game->getPlayer()->getBullet(b)->getPosY,
          game->getPlayer()->getBullet(b)->getPosX, '|');
        // Check collision with enemies
        for (int w = 0; w < MAX_ENEMIES; w++) {
          // If enemy exists
          if (_en[w] != NULL) {
            // If bullet coordinates collide with enemy's
            if ((game->getPlayer()->getBullet(b)->getPosX == _en[w]->getPosX)
              && (game->getPlayer()->getBullet(b)->getPosY == _en[w]->getPosY))
              // Hit target
              game->getPlayer()->getBullet(b)->hitTarget(_en[w]);
              // If Enemy is dead, set pointer to null
              if (_en[w]->getAliveStatus() == false) {
                // Erase enemy from map
                game->setMap(_en[w]->getPosY, _en[w]->getPosX, ' ');
                _en[w] = NULL;
              }
              // Erase bullet from map
            game->setMap(game->getPlayer()->getBullet(b)->getPosY,
              game->getPlayer()->getBullet(b)->getPosX, ' ');
          }
        }
      }
    }

    game->setMap(game->getPlayer()->getPosY, game->getPlayer()->getPosX, 'A');


    /*
    **
      BIG NOTE ::: RANDOMLY GENERATE ENEMIES
    **
    */

    // Try generating enemies
    for (int z = 0; z < 20; z++) {
      // Rolling...
      if ((rand() % 100) < 15) {

        int spawnX;

        // Find empty spot
        for (int pp = 0; pp < 50; pp++) {
          spawnX = rand() % game->maxX;
          if (game->getMap(4, spawnX) == ' ')
            break;
        }
        // If no spot, don't generate
        if (pp == 50)
          continue;

        // Find NULL slot in array
        for (int w = 0; w < MAX_ENEMIES; w++) {
          if (_en[w] == NULL) {

            // Roll for enemy type
            int rand = rand() % 10;

            if (rand <= 1)
              _en[w] = new EnGod();
            else if (rand <= 3)
              _en[w] = new EnPro();
            else if (rand <= 7)
              _en[w] = new EnScrub();
            else
              _en[w] = new EnDebris();

            setMapEnemy(4, spawnX, game. _en[w].getEnemyType());
          }
        }
      }
    }

/***************************************************************************************/

    /*
    **
      BIG NOTE ::: SET THE WHOLE MAP
    **
    */

    // For Every point on the map
    for (int col = 0; col < game->getMapY(); col++) {

      for (int row = 0; row < game->getMapX(); row++) {

        // If Enemy exists on this point
        if (game->getEnemy(col, row).getAliveStatus() == true) {

          // For all bullets on Enemy
          for (int b = 0; b < MAX_BULLETS; b++) {
            // If bullet is active, set bullet on map
            if (game->getEnemy(col, row)->getBullet(b)->getAliveStatus() == true) {
              game->setMap(game->getEnemy(col, row)->getBullet(b)->getPosY,
              game->getEnemy(col, row)->getBullet(b)->getPosX, '\'');
            }
          }

          // Set Enemy on map
          // game->setMap(col, row - 1, '\\');
          game->setMap(col, row, 'W');
          // game->setMap(col, row + 1, '/');

        }
      }
    }

    // For all bullets on Player
    for (int b = 0; b < MAX_BULLETS; b++) {
      // If bullet is active, set on map
      if (game->getPlayer()->getBullet(b)->getAliveStatus() == true) {
        game->setMap()(game->getPlayer()->getBullet(b)->getPosY,
          game->getPlayer()->getBullet(b)->getPosX, '|');
      }
    }

    // Set player's position on map
    game->setMap(game->getPlayer()->getPosY, game->getPlayer()->getPosX, 'A');


/***************************************************************************************/

    /*
      NOTE : BUFFER OUTPUT FOR PRINTING
    */

		for (int a = 0; a < game->getMaxY(); a++)
			for (int b = 0; b < game->getMaxX(); b++)
			{
        if (game->getMap(a, b) == 'W')
          attron(COLOR_PAIR(2) | A_BOLD);
        else if (game->getMap(a, b) == 'A')
          attron(COLOR_PAIR(1) | A_BOLD);
        else if (game->getMap(a, b) == '\'')
          attron(COLOR_PAIR(1) | A_BOLD);
        else if (game->getMap(a, b) == '\\' || game->getMap(a, b) == '/')
          attron(COLOR_PAIR(1) | A_BOLD);
        else if (game->getMap(a, b) == ' ')
          attron(COLOR_PAIR(4) | A_BOLD);
        else if (game->getMap(a, b) == '|')
          attron(COLOR_PAIR(3) | A_BOLD);
        else if (game->getMap(a, b) == '*') {
          attron(COLOR_PAIR(7) | A_BOLD);
        }
        addch(game->getMap(a, b));
			}
    
    /*for (i = 0; i < MAX_BULLETS - 1; i++)
    {
      if (game->getPlayer().getBullet(i)->getAliveStatus()) {
        
        attron(COLOR_PAIR(5));
        
        mvprintw((game->getMaxY() / 2), (game->getMaxX() - sizeof(TEST_DISPLAY_BULLETS_WORKING))
        / 2, "%s", TEST_DISPLAY_BULLETS_WORKING);
        
        attroff(COLOR_PAIR(5));
      } else {
        

        attron(COLOR_PAIR(5));
        mvprintw((game->getMaxY() / 2), (game->getMaxX() - sizeof(TEST_DISPLAY_BULLETS_NOT_WORKING))
        / 2, "%s", TEST_DISPLAY_BULLETS_NOT_WORKING);
        attroff(COLOR_PAIR(5));
      }
    }*/
		attron(COLOR_PAIR(6) | A_BOLD);
    mvprintw(game->getMaxY() - 4, 2, "|| ======================================== ||");
		mvprintw(game->getMaxY() - 3, 2, "|| Enemies killed : %d ", eKilled);
    mvprintw(game->getMaxY() - 3, 27, "|=====| Lives : %d  ||", game->getPlayer().getLives());
    mvprintw(game->getMaxY() - 2, 2, "|| ======================================== ||");
		attroff(COLOR_PAIR(6) | A_BOLD);
  }
  return ;
}

int main(void)
{
  // init
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
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_BLACK);
	init_pair(7, COLOR_RED, COLOR_BLACK);

	int maxX, maxY;
  // int i;
  getmaxyx(stdscr, maxY, maxX);
  int posY = maxY - 10, posX = maxX / 2;

  std::cout << "game obj init" << std::endl;
  Game *game = new Game(maxY, maxX);
  game->buildMaps(maxY, maxX);
  std::cout << "game compiles" << std::endl;

  const char menuTextName[] = "ft_retro!";
  const char menuTextAuth[] = "SCollet:JChow";
  const char menuTextInst[] = "Press any key to continue...";

  std::cout << "strings declared" << std::endl;

  attron(COLOR_PAIR(5));
  mvprintw((maxY / 2) - 2, (maxX - sizeof(menuTextName)) / 2, "%s", menuTextName);
	mvprintw(maxY / 2, (maxX - sizeof(menuTextAuth)) / 2, "%s", menuTextAuth);
	attroff(COLOR_PAIR(5));

	attron(A_BOLD);
	mvprintw((maxY / 2) + 4, (maxX - sizeof(menuTextInst)) / 2, "%s", menuTextInst);
	attroff(A_BOLD);

	curs_set(0);

  /*for (i = 0; i < maxX; i++)
    game->setMap(0, i, ' ');
  std::cout << "game compiles" << std::endl;
  for (i = 0; i < maxY; i++)
  {
    game->setMap(i - 2, 0, '-');
    game->setMap(i - 2, 0, '-');
  }*/
  std::cout << "before stacking map" << std::endl;
  for (int a = 0; a < maxY - 1; a++)
    for (int b = 0; b < maxX - 1; b++)
    {
      // std::cout << a << b << std::endl;
      game->setMap(a, b, ' ');
    }
  std::cout << "before setting player" << std::endl;
  // for (i = 0; i < maxX; i++)
    // game->setMap(0, i, ' ');
  game->setMap(posY, posX, 'A');

  play(game);

  char endTextDisp[] = " GAME OVER ";
  char endTextInst[] = " PRESS END TO EXIT ";
	attron(COLOR_PAIR(7) | A_BOLD);
	mvprintw(maxY / 2, (maxX - sizeof(endTextDisp)) / 2, "%s", endTextDisp);
  mvprintw((maxY / 2) + 4, (maxX - sizeof(endTextInst)) / 2, "%s", endTextInst);
	attroff(COLOR_PAIR(7) | A_BOLD);
  curs_set(0);

	//the player needs the press enter to quit (so he gets time to see how many zombies he killed)
	timeout(-1);
	do {
		uIn = getch();
	} while(uIn != KEY_END);

  endwin();
  // delete[] enemies;
  delete game;
  return 0;
}
