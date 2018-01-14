// Test main.

#include "Bullet.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "GameEntity.hpp"
#include "Header.hpp"

int main() {

    Player p = Player();

    std::cout << "X/Y: " << p.getPosX() << p.getPosY() << "\nDirection: " << p.getDirection() << "\nLives: " << p.getLives()
    << "\nHP: " << p.getHP() << "\nATK dmg: " << p.getAtkDmg() << "\nBullet SPD: " << p.getBulletSpeed() << std::endl;

    std::cout << "Bullet status:\n";

    for (int i = 0; i < MAX_BULLETS; i++) {
        std::cout << i << ": " << p.getBullet(i)->getAliveStatus() << std::endl;
    }


    p.takeDamage(1);
    p.takeDamage(1);
    p.takeDamage(1);
    
    Enemy* g = new EnGod(1);
    Enemy* s = new EnScrub(22);

    std::cout
    << "Godtype\nX,Y: " << g->getPosX() << ", " << g->getPosY()
    << "\nDirection: " << g->getDirection()
    << "\nAlive: " << g->getAliveStatus()
    << "\nHP: " << g->getHP()
    << "\natkDmg: " << g->getAtkDmg()
    << "\nbulletSpeed: " << g->getBulletSpeed()
    << "\nspeedCD: " << g->getSpeedCoolDown() << std::endl;

    g = s;

    std::cout
    << "Scrubtype\nX,Y: " << g->getPosX() << ", " << g->getPosY()
    << "\nDirection: " << g->getDirection()
    << "\nAlive: " << g->getAliveStatus()
    << "\nHP: " << g->getHP()
    << "\natkDmg: " << g->getAtkDmg()
    << "\nbulletSpeed: " << g->getBulletSpeed()
    << "\nspeedCD: " << g->getSpeedCoolDown() << std::endl;

    g->takeDamage(100);

    std::cout
    << "Scrubtype\nX,Y: " << g->getPosX() << ", " << g->getPosY()
    << "\nDirection: " << g->getDirection()
    << "\nAlive: " << g->getAliveStatus()
    << "\nHP: " << g->getHP()
    << "\natkDmg: " << g->getAtkDmg()
    << "\nbulletSpeed: " << g->getBulletSpeed()
    << "\nspeedCD: " << g->getSpeedCoolDown() << std::endl;
}
