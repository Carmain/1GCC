#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0
#define MAX 100
#define LIVES 5

int randint(int min, int max);
void menu();

int main(void) {
	// On définit le point de départ de rand()
	srand(time(NULL));

	int menu_choice = -1;
	while (menu_choice) {
		if (menu_choice == -1) {
			menu();
			scanf("%d", &menu_choice);
		} else if (menu_choice == 1) {

		} else if (menu_choice == 2) {

		}
	}

	return 0;
}

/* randint : return a randomly generated number between min and max */
int randint(int min, int max) {
	return rand() % (max - min) + min;
}

/* menu : display the game menu */
void menu() {
	printf("Welcome to + or - !\n\n");
	printf("Please, take a seat and enjoy !\n\n");
	printf("1 - Play alone\n");
	printf("2 - Play with a friend\n");
	printf("0 - Quit\n");
}
