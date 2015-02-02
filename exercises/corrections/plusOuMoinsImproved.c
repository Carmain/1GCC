#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

int random(int min, int max);
void menu();
int play(int lives, int min, int max);
int ask_number(int lives, int min, int max);
int check_number(int mystery_num, int try);

int main(void)
{
	srand(time(NULL));
	int continue_game = 1;

	while (continue_game) {
		if (continue_game == 1) {
			menu();
			scanf("%d", &continue_game);
		} else if (continue_game == 2) {
			play(5, 0, 100);
		}
	}
	return 0;
}

int random(int min, int max)
{
	return rand() % (max - min) + min;
}

void menu()
{
	system(CLEAR);
	printf("Welcome to + or - !\n");
	printf("1 - Play V.S. A.I.\n");
	printf("0 - Quit\n");
}

int play(int lives, int min, int max)
{
	int mystery_num = random(min, max);
	int try = -1;

	do {
		try = ask_number(lives, min, max);
	} while (check_number(mystery_num, try) && lives);

	return 1;
}

int ask_number(int lives, int min, int max)
{
	system(CLEAR);

	int tried = -1;

	do {
		printf("Try a number [%d - %d], %d remaining lives : ", min, max, lives);
		scanf("%d", &tried);
	} while (tried < min || tried > max);

	return tried;
}

int check_number(int mystery_num, int try)
{
	if (try < mystery_num) {
		printf("Try more ! ;)\n");
		return -1;
	} else if (try > mystery_num) {
		printf("Try less ! ;)\n");
		return 1;
	} else {
		return 0;
	}
}
