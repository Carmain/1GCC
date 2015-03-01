#ifndef _INTERRACTIONS_H
#define _INTERRACTIONS_H

#define CON_WIDTH 80

#include <stdlib.h>
#include <stdio.h>
#include "game.h"

static char smbls[2] = {'O', 'X'};
static char *assets[5] = {"     0  1  2   \n", 
                          "  |------------\n",
                          "%d |  %c  %c  %c  |\n",
                          "  |           |\n",
                          "  ------------|\n"};

void header();
void disp_board(int **board);
struct coordonates *ask_coordonates(int player);
void win_scr(int player);
void nul_scr();

#endif
