#include "interractions.h"

/* flushin : flush input buffer */
static void flushin()
{
	while(getchar() != '\n');
}

/* txt_ctrd : display centered str text */
static void txt_ctrd(char *str)
{
	int padding = (CON_WIDTH - (strlen(str) - 1)) / 2;
		
	for( ; padding-- ; ) {
		printf(" ");
	}

	printf("%s", str);
}

/* clscr : clear console screen */
static void clscr()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

/* header : display program header */
void header()
{
	clscr();
	printf("\n");
	txt_ctrd("-------------\n");
	txt_ctrd("|           |\n");
	txt_ctrd("|  MORPION  |\n");
	txt_ctrd("|           |\n");
	txt_ctrd("-------------\n");
	printf("\n\n");
}

/* disp_board : display actual game board */
void disp_board(int **board)
{
	char str[50];
	sprintf(str, "  0  1  2   \n");
	txt_ctrd(str);

	sprintf(str, "  |------------  \n");
	txt_ctrd(str);

	for(int i = 0; i < 3; ++i) {
		char line[3];
		
		for(int j = 0; j < 3; ++j) {
			if (board[i][j] < 0)
				line[j] = '.';
			else
				line[j] = smbls[board[i][j]];
		} 
		
		sprintf(str, "%d |  %c  %c  %c  |  \n", i, line[0], line[1], line[2]);
		txt_ctrd(str);
		txt_ctrd("  |           |  \n"); 
	}	
	
	sprintf(str, "  ------------|  \n");
	txt_ctrd(str);

	printf("\n");
}

/* ask_coordonates : ask for player's playing position */
struct coordonates *ask_coordonates(int player)
{
	int x;
	int y;
	do {
		char str[50];
		sprintf(str, "Player %d - Type playing coordonates : ", player + 1);
		txt_ctrd(str);

		scanf("%d %d", &x, &y);
		flushin();
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
	
	txt_ctrd("Press a key to quit...\n");
	getchar();
}

/* nul_scr : display nul screen */
void nul_scr()
{
	header();
	
	txt_ctrd("Equality ! Better luck next time !\n");	

	txt_ctrd("Press a key to quit...\n");
	getchar();
}
