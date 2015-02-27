#include <stdio.h>

#include "game.h"
#include "interractions.h"

int main(void)
{
	int stay_here = 1;
	int menu_choice = -1;

	while (stay_here) {
		if (menu_choice == -1) {
			menu_choice = menu();
		} else if (menu_choice == 1 || menu_choice == 2) {
			play(7, 0, 100);
			menu_choice = -1;
		} else if (menu_choice == 0) {
			stay_here = 0;
		}
	}

	return 0;
}
