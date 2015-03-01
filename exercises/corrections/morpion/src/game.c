#include "game.h"

/* is_finish : check if the game is finish */
static int is_finish()
{
        for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                        if (game.board[i][j] == -1)
                                return 0;
                }
        }

        return 1;
}

/* is_winner : check if a player won */
static int is_winner()
{
        for(int i = 0; i < 3; ++i) {
                if (game.board[0][i] != -1 && game.board[0][i] == game.board[1][i] && game.board[0][i] == game.board[2][i]) {
                        game.winner = game.board[0][i];
                        return 1;
                }

                if (game.board[i][0] != -1 && game.board[i][0] == game.board[i][1] && game.board[i][0] == game.board[i][2]) {
                        game.winner = game.board[i][0];
                        return 1;
                }
        }

        if (game.board[0][0] != -1 && game.board[0][0] == game.board[1][1] && game.board[0][0] == game.board[2][2]) {
                game.winner = game.board[0][0];
                return 1;
        }

        if (game.board[0][2] != -1 && game.board[0][2] == game.board[1][1] && game.board[0][2] == game.board[2][0]) {
                game.winner = game.board[0][2];
                return 1;
        }

        return 0;
}

/* init_game : initialize game struct */
static void init_game(int players)
{       
        game.board = (int **)malloc(3 * sizeof(int *));
        for (int i = 0; i < 3; ++i) {
                game.board[i] = (int *)malloc(3 * sizeof(int));
                memset(game.board[i], -1, 3 * sizeof(int));
        }
                
        game.players = players;
        game.actual_player = 0;
        game.winner = -1;
}

/* clean_game : clean game assets */
static void clean_game()
{
        for (int i = 0; i < 3; ++i)
                free(game.board[i]);

        free(game.board);
}

/* play : handle and manage a game */
int play(int players)
{
        init_game(players);

        while(1) {
                header();
                disp_board(game.board);

                struct coordonates *coord = ask_coordonates(game.actual_player);
                game.board[coord->x][coord->y] = game.actual_player;
                free(coord);

                if(is_winner() || is_finish())
                        break;

                ++game.actual_player;
                game.actual_player %= 2;
        }

        if (game.winner != -1)
                win_scr(game.actual_player);    
        else 
                nul_scr();

        clean_game();
        return 0;
}

/* playable : check is the cell is playable */
int playable(int x, int y)
{
        if(game.board[x][y] == -1)
                return 1;               
        
        return 0;
}
