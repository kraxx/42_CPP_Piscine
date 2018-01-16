/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:25:00 by jchow             #+#    #+#             */
/*   Updated: 2018/01/14 14:25:01 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "Character.hpp"

/******************************************************************************/
// Playable Human Character

class Player : public Character {

private:

    unsigned int _lives;

    Player() {};

    void         initBullets();

public:

    Player(int y, int x, int maxY, int maxX);
    Player(Player const& rhs);
    Player& operator=(Player const& rhs);
    ~Player() {};

    // Getters

    unsigned int getLives() const;

    // Methods

    void         updateObject(int y, int x);
    void         triggerDeath();
    void         gainHP(int x);
    void         setAtkDmg(int x);

};

#endif
