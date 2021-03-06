#ifndef _SNAKE_STUCTURE_GAME_H_
#define _SNAKE_STUCTURE_GAME_H_

#include "geometry.h"
#include "player.h"
#include "map.h"

enum bonus
{
    GROW,
    FASTER,
};

enum mallus
{
    DIVIDE,
    DEATH
};

typedef struct  s_game
{
    t_map *     map;
    t_player *  player;
    const char *      file;
}               t_game;

#endif //_SNAKE_STUCTURE_GAME_H_
