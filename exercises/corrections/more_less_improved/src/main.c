#include <stdio.h>

#include <time.h>

#include "game.h"
#include "interractions.h"

int main(void)
{
        srand(time(NULL));

        int stay_here = 1;
        int menu_choice = -1;

        while (stay_here) {
                if (menu_choice == -1) {
                        menu_choice = menu();
                } else if (menu_choice == 1 || menu_choice == 2) {
                        int generate_mystery = (menu_choice == 1) ? 1 : 0;
                        play(7, 0, 100, generate_mystery);
                        menu_choice = -1;
                } else if (menu_choice == 0) {
                        stay_here = 0;
                }
        }

        return 0;
}
