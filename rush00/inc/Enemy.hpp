/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:44:44 by jchow             #+#    #+#             */
/*   Updated: 2018/01/13 18:44:45 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "Character.hpp"

/******************************************************************************/
// Generic Enemy Parent

class Enemy : public Character {

protected:

    unsigned int _speedCD;
    unsigned int _enemyType;

    void         initBullets();
    void         triggerShootBullet();

public:


    Enemy();
    Enemy(int x, int maxY, int maxX, unsigned int hp, unsigned int atkDmg, unsigned int bulletSpeed, unsigned int enemyType);
    Enemy(Enemy const& rhs);
    Enemy& operator=(Enemy const& rhs);
    virtual ~Enemy() {};

    // Getters

    unsigned int getSpeedCoolDown() const;
    unsigned int getEnemyType() const;

    // Methods
    void         triggerDeath();
    void         triggerRealDeath();
    void         activateEnemy(int y, int x);
    void         updateObject();
};


/******************************************************************************/
// Debris

class EnDebris : public Enemy {

private:

    EnDebris() {};

public:

    EnDebris(int x, int maxY, int maxX);
    EnDebris(EnDebris const& rhs);
    EnDebris& operator=(EnDebris const& rhs);
    ~EnDebris() {};
};


/******************************************************************************/
// Scrub-Tier

class EnScrub : public Enemy {

private:

    EnScrub() {};

public:

    EnScrub(int x, int maxY, int maxX);
    EnScrub(EnScrub const& rhs);
    EnScrub& operator=(EnScrub const& rhs);
    ~EnScrub() {};
};


/******************************************************************************/
// Pro-Tier

class EnPro : public Enemy {

private:

    EnPro() {};

public:

    EnPro(int x, int maxY, int maxX);
    EnPro(EnPro const& rhs);
    EnPro& operator=(EnPro const& rhs);
    ~EnPro() {};
};


/******************************************************************************/
// God-Tier

class EnGod : public Enemy {

private:

    EnGod() {};

public:

    EnGod(int x, int maxY, int maxX);
    EnGod(EnGod const& rhs);
    EnGod& operator=(EnGod const& rhs);
    ~EnGod() {};
};

#endif
