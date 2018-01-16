/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:48:30 by scollet           #+#    #+#             */
/*   Updated: 2018/01/13 10:48:31 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP

// TESTING

# define TEST_DISPLAY_BULLETS_WORKING "TEST DISPLAY BULLETS WORKING"
# define TEST_DISPLAY_BULLETS_NOT_WORKING "TEST DISPLAY BULLETS NOT WORKING"

// Map Specs
# define CEILING             2
# define PLAYER_BORDER       5

// Player Stats
# define PLAYER_LIVES        3
# define PLAYER_MAX_HP       50
# define PLAYER_BULLET_SPEED 1
# define PLAYER_HP           10
# define PLAYER_DAMAGE       1
# define MAX_BULLETS         10
# define MAX_ENEMIES         125

// General Enemy Stats
# define ENEMY_CD            8 //Movement speed
# define ENEMY_SHOOT_FREQ    5
# define ENEMY_SPAWN_FREQ    7
# define ENEMY_SPAWN_PERCENT 3

// Debris Stats
# define DEBRIS_HP           3
# define DEBRIS_ATK_DMG      1
# define DEBRIS_BULLET_SPD   1

// Scrub Stats
# define SCRUB_HP            2
# define SCRUB_ATK_DMG       2
# define SCRUB_BULLET_SPD    7

// Pro Stats
# define PRO_HP              6
# define PRO_ATK_DMG         3
# define PRO_BULLET_SPD      4

// God Stats
# define GOD_HP              10
# define GOD_ATK_DMG         5
# define GOD_BULLET_SPD      2

// Direction
# define UP     true
# define DOWN   false

// Friendly Status
# define ALLY   true
# define ENEMY  false

// Alive Status
# define ALIVE  true
# define DEAD   false

enum eEnemyType {
    TYPE_DEBRIS = 0,
    TYPE_SCRUB = 1,
    TYPE_PRO = 2,
    TYPE_GOD = 3
};

#endif
