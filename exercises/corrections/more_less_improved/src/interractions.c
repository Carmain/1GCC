#include "interractions.h"

/* flushin : flush input buffer */
static void flushin()
{
	while (getchar() != '\n');
}

/* clscr : clear console screen */
static void clsrc()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

/* txt_ctrd : display str centered in console */
static void txt_ctrd(const char *str, char endline)
{
	int txt_len = strlen(str);
	int padding = (80 - txt_len) / 2;

	for(int i = padding; i > 0; --i) {
		printf(" ");
	}
	printf("%s%c", str, endline);
}

/* header : display the game header */
void header() 
{
	clsrc();
	
	printf("\n\n");
	txt_ctrd("========================", '\n');
	txt_ctrd("|| + OR -, THE GAME ! ||", '\n');
	txt_ctrd("========================", '\n');
	printf("\n\n\n");
}

/* menu : display the game menu */
int menu()
{
	header();

	txt_ctrd("1. 1 player", '\n');
	txt_ctrd("2. 2 players", '\n');
	txt_ctrd("0. Quit", '\n');
	printf("\n");

	int choice;
	do {
		txt_ctrd("Your choice : ", ' ');
		scanf("%d", &choice);
		flushin();
	} while (choice < 0 || choice > 2);

	return choice;
}

/* ask_try : ask for user's try and check it */
int ask_try(int lives, int min, int max)
{
	char rmlives[50];
	char try_str[50];
	int try;
	
	sprintf(rmlives, "Remaining lives : %d", lives);
	sprintf(try_str, "Try a value [%d - %d] : ", min, max);
		
	do {
		txt_ctrd(rmlives, '\n');
		txt_ctrd(try_str, ' ');
		scanf("%d", &try);
		flushin();
	} while(try < min || max < try);	

	return try;
}

/* show__hint : announce result for user's last try */
void show_hint(int hint) 
{
	if (hint == -1) {
		txt_ctrd("Try more !", '\n');
	} else if (hint == 1) {
		txt_ctrd("Try less !", '\n');
	}
}

/* win_scr : display the winning screen */
void win_scr()
{
	header();

	txt_ctrd("YOU WON !", '\n');
	txt_ctrd("Press a key to continue...", '\n');
	getchar();
}

/* loose_scr : display loosing screen */
void loose_scr()
{
	header();
	
	txt_ctrd("YOU LOOSE ! LOOSER !", '\n');
	txt_ctrd("Press a key to continue...", '\n');
	getchar();
}
