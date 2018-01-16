/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:13:45 by jchow             #+#    #+#             */
/*   Updated: 2018/01/13 16:13:46 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENTITY_HPP
# define GAMEENTITY_HPP

# include "Header.hpp"

class GameEntity {

protected:

    int          _posY;
    int          _posX;
    int          _maxY;
    int          _maxX;
    bool         _direction;
    bool         _alive;

    GameEntity() {};

public:

    GameEntity(int y, int x, int maxY, int maxX, bool direction, bool alive);
    GameEntity(GameEntity const& rhs);
    GameEntity& operator=(GameEntity const& rhs);
    virtual ~GameEntity() {};

    // Getters

    int          getMaxY(void);
    int          getMaxX(void);
    int          getPosX() const;
    int          getPosY() const;
    bool         getDirection() const;
    bool         getAliveStatus() const;

    // Setters

    void         setAliveStatus(bool status);

    // Methods

    void         drawObject() const;

    // Must not be pure virtual (though effectively can be), otherwise class
    // GameEntity becomes an "abstract class", rendering allocation of child
    // classes (specifically Bullet for use in Character) impossible
    virtual void updateObject() {};
    virtual void updateObject(int x, int y) {(void)x;(void)y;};
};

#endif
