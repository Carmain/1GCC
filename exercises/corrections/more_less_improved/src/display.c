#include "display.h"

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

/* menu : display the game menu */
void menu() 
{
	txt_ctrd("========================", '\n');
	txt_ctrd("|| + OR -, THE GAME ! ||", '\n');
	txt_ctrd("========================", '\n');
	printf("\n");
}


