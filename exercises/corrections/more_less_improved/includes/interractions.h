#ifndef _DISPLAY_H
#define _DISPLAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void header();
int menu();
void show_hint(int hint);
int ask_try(int lives, int min, int max);
int ask_mystery(int min, int max);
void win_scr();
void loose_scr();

#endif
