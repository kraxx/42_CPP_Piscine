/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:47:26 by scollet           #+#    #+#             */
/*   Updated: 2018/01/13 15:13:26 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "Bullet.hpp"
# include "GameEntity.hpp"

// Prototype protection against mutual dependency
class Bullet;


/******************************************************************************/
// Generic Character Parent

class Character : public GameEntity {

protected:

    unsigned int _hp;
    unsigned int _atkDmg;
    unsigned int _bulletSpeed;
    Bullet*      _bullets[MAX_BULLETS];

    Character() {};

    virtual void initBullets() = 0;
public:

    Character(int y, int x, int maxY, int maxX, bool direction, unsigned int hp, unsigned int atkDmg, unsigned int bulletSpeed);
    Character(Character const& rhs);
    Character& operator=(Character const& rhs);
    virtual ~Character();

    // Getters

    unsigned int getHP() const;
    unsigned int getAtkDmg() const;
    unsigned int getBulletSpeed() const;
    Bullet*      getBullet(int idx) const;

    // Methods

    void         shootBullet();
    void         takeDamage(unsigned int dmg);
    virtual void triggerDeath() {};


};

#endif
