#include "interractions.h"

/* txt_ctrd : display centered str text */
static void txt_ctrd(char *str)
{
	int padding = (CON_WIDTH - (strlen(str) - 1)) / 2;
		
	for( ; padding-- ; ) {
		printf(" ");
	}

	printf("%s", str);
}

/* header : display program header */
void header()
{
	txt_ctrd("MORPION");	
}

/* disp_board : display actual game board */
void disp_board(int **board)
{
	char str[50];
	sprintf(str, "  0  1  2\n");
	txt_ctrd(str);

	sprintf(str, "  |---------\n");
	txt_ctrd(str);
	
	sprintf(str, "0 |%c  %c  %c |\n", '0', '0', '0');
	txt_ctrd(str);
	
	sprintf(str, "  |        |\n");
	txt_ctrd(str);

	sprintf(str, "1 |%c  %c  %c |\n", '0', '0', '0');
	txt_ctrd(str);

	sprintf(str, "  |        |\n");
	txt_ctrd(str);

	sprintf(str, "2 |%c  %c  %c |\n", '0', '0', '0');
	txt_ctrd(str);

	sprintf(str, "  ---------|\n");
	txt_ctrd(str);

}

/* ask_coordonates : ask for player's playing position */
struct coordonates *ask_coordonates(int player)
{
	int x;
	int y;
	do {
		char str[50];
		sprintf(str, "Player %d - Type playing coordonates : ", player);
		txt_ctrd(str);

		scanf("%d %d", &x, &y);
	} while (x < 0 || x > 2 || y < 0 || y > 2 || !playable(x, y));

	struct coordonates *coord = malloc(sizeof(struct coordonates));
	coord->x = x;
	coord->y = y;

	return coord;
}

/* win_scr : display win screen */
void win_scr(int player)
{
	header();
	
	char str[50];
	sprintf(str, "Congratulations Player %d, you win !\n", 	player + 1);

	txt_ctrd(str);
}

/* nul_scr : display nul screen */
void nul_scr()
{
	header();
	txt_ctrd("You loose !\n");
}
