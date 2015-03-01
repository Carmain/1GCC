#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0
#define MAX 100
#define LIVES 9

void menu();

int main(void)
{
        /* On définit le point de départ de rand() */
        srand(time(NULL));

        int menu_choice = -1;
        while (menu_choice) {                           /* La boucle principale */
                if (menu_choice == -1) {                /* Menu */
                        menu();
                        scanf("%d", &menu_choice);
                } else if (menu_choice == 1) {  /* Pour jouer */
                        int mystery_num = rand() % (MAX - MIN) + MIN;
                        int try;
                        int lives = LIVES;

                        do { /* Tant que le joueur a des vies / il n'a pas reussis */
                                printf("Try a value [%d - %d], %d lives remaining :\n", MIN, MAX, lives);
                                scanf("%d", &try);

                                if (try < MIN ||try > MAX) {
                                        continue;
                                } else {
                                        if (try < mystery_num) {
                                                printf("Try more (+) !\n\n");
                                        } else if (try > mystery_num) {
                                                printf("Try less (-) !\n\n");
                                        }
                                        lives--;
                                }
                        } while (lives != 0 && try != mystery_num);

                        if (!lives) {
                                printf("You loose, mystery number was %d\n", mystery_num);
                        } else {
                                printf("Congratulations, you win !\n");
                        }

                        menu_choice = -1;
                }
        }

        return 0;
}

/* menu : display the game menu */
void menu() {
        printf("Welcome to + or - !\n\n");
        printf("Please, take a seat and enjoy !\n\n");
        printf("1 - Play alone\n");
        printf("0 - Quit\n");
}
