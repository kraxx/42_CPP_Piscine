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

// Player Stats
# define PLAYER_LIVES        3
# define PLAYER_BULLET_SPEED 3
# define PLAYER_START_X      0
# define PLAYER_START_Y      0
# define PLAYER_HP           1
# define PLAYER_DAMAGE       1
# define PLAYER_START_Y      0
# define MAX_BULLETS         10

// General Enemy Stats
# define ENEMY_CD            10

// Debris Stats
# define DEBRIS_HP           3
# define DEBRIS_ATK_DMG      0
# define DEBRIS_BULLET_SPD   1

// Scrub Stats
# define SCRUB_HP            2
# define SCRUB_ATK_DMG       1
# define SCRUB_BULLET_SPD    7

// Pro Stats
# define PRO_HP              6
# define PRO_ATK_DMG         1
# define PRO_BULLET_SPD      4

// God Stats
# define GOD_HP              10
# define GOD_ATK_DMG         1
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

// enum eDirection : bool {
//     UP = true,
//     DOWN = false,
// };

// enum eFriendly : bool {
//     ALLY = true,
//     ENEMY = false,
// };


#endif
