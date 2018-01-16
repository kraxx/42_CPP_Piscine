/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:54:40 by jchow             #+#    #+#             */
/*   Updated: 2018/01/13 14:54:41 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_H
# define BULLET_H

# include <iostream>
# include "Character.hpp"
# include "GameEntity.hpp"

// Prototype protection against mutual dependency
class Character;

/******************************************************************************/

class Bullet : public GameEntity {

private:

    unsigned int _atkDmg;
    unsigned int _speed;
    unsigned int _speedCD;
    bool         _friendly;

    Bullet() {};

public:

    Bullet(int maxY, int maxX, unsigned int dmg, unsigned int speed, bool friendly);
    Bullet(Bullet const& rhs);
    Bullet& operator=(Bullet const& rhs);
    ~Bullet() {};

    // Getters

    unsigned int getAtkDmg() const;
    unsigned int getSpeed() const;
    unsigned int getSpeedCoolDown() const;
    bool         getFriendly() const;

    // Methods

    void         activateBullet(int y, int x);
    void         deactivateBullet();
    void         hitTarget(Character& target);
    void         updateObject();
    void         setAtkDmg(int x);

};

#endif
