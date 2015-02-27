#ifndef _GAME_H
#define _GAME_H

#include <time.h>

#include "interractions.h"

struct game {
	int mystery;
	int lives;
	int min;
	int max;
	int won;
	int last_hint;
};

struct game game;

int play(int lives, int min, int max, int generate_mystery);
void check_try(int n);

#endif
