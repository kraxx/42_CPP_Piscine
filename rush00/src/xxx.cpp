// Test main.

#include "Bullet.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "GameEntity.hpp"
#include "Header.hpp"
#include "Player.hpp"

int main() {

    Player p = Player(5, 5);

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
    Enemy* s = new EnGod(22);

    std::cout
    << "\nType: " << g->getEnemyType()
    << "\nX,Y: " << g->getPosX() << ", " << g->getPosY()
    << "\nDirection: " << g->getDirection()
    << "\nAlive: " << g->getAliveStatus()
    << "\nHP: " << g->getHP()
    << "\natkDmg: " << g->getAtkDmg()
    << "\nbulletSpeed: " << g->getBulletSpeed()
    << "\nspeedCD: " << g->getSpeedCoolDown() << std::endl;

    g->getBullet(2)->activateBullet(1, 1);


    for (int i = 0; i < MAX_BULLETS; i++) {
        std::cout << i << ": " << g->getBullet(i)->getAliveStatus() << std::endl;

        s->getBullet(i)->activateBullet(2,1);
    }

    g = s;

    std::cout
    << "\nType: " << g->getEnemyType()
    << "\nX,Y: " << g->getPosX() << ", " << g->getPosY()
    << "\nDirection: " << g->getDirection()
    << "\nAlive: " << g->getAliveStatus()
    << "\nHP: " << g->getHP()
    << "\natkDmg: " << g->getAtkDmg()
    << "\nbulletSpeed: " << g->getBulletSpeed()
    << "\nspeedCD: " << g->getSpeedCoolDown() << std::endl;

    for (int i = 0; i < MAX_BULLETS; i++) {
        std::cout << i << ": " << g->getBullet(i)->getAliveStatus() << std::endl;
    }

    g->takeDamage(100);

    std::cout
    << "\nType: " << g->getEnemyType()
    << "\nX,Y: " << g->getPosX() << ", " << g->getPosY()
    << "\nDirection: " << g->getDirection()
    << "\nAlive: " << g->getAliveStatus()
    << "\nHP: " << g->getHP()
    << "\natkDmg: " << g->getAtkDmg()
    << "\nbulletSpeed: " << g->getBulletSpeed()
    << "\nspeedCD: " << g->getSpeedCoolDown() << std::endl;

    for (int i = 0; i < MAX_BULLETS; i++) {
        std::cout << i << ": " << g->getBullet(i)->getAliveStatus() << std::endl;
    }

    g->updateObject();
    g->updateObject();
    g->updateObject();
    g->updateObject();
    g->updateObject();
    g->updateObject();
}
