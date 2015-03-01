#ifndef _GAME_H
#define _GAME_H

#include <stdlib.h>
#include <string.h>
#include "interractions.h"

struct coordonates {
        int x;
        int y;
};

struct game {
        int **board;
        int players;
        int actual_player;
        int end;
        int winner;
};

struct game game;

int play(int players);
int playable(int x, int y);
void check_finish();

#endif
