#include "game.h"

int play(int lives, int min, int max, int generate_mystery)
{
        //actual_game = malloc(sizeof(struct game));
        
        if (generate_mystery) {
                game.mystery = (rand() % max) + min;
        } else {
                game.mystery = ask_mystery(min, max);
        }
        
        game.lives = lives;
        game.min = min;
        game.max = max;
        game.won = 0;
        game.last_hint = 0;
        
        while (game.lives > 0 && !game.won) {
                header();

                if (game.last_hint != 0) {
                        show_hint(game.last_hint);
                }

                int try = ask_try(game.lives, game.min, game.max);
                check_try(try);

                --game.lives;   
        }

        if (game.won) {
                win_scr();
        } else {
                loose_scr();
        }
        
        return 0;
}

void check_try(int n)
{
        if (n < game.mystery) {
                game.last_hint = -1;
        } else if (n > game.mystery) {
                game.last_hint = 1;
        } else {
                game.won = 1;
        }
}
