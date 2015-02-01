#include <stdio.h>
#include <stdlib.h>

int main(void) {

	// La boucle while permet de répéter un certain nombre de fois selon une condition
	int myVar;
	while (myVar != 10) { // tant que myVar est différent de 10 on va boucler
		printf("Please, give me a 10 : ");
		scanf("%d", &myVar); // On récupère la saisie de l'utilisateur
	}

	// --------------------------
	printf("\n\n");
	// --------------------------

	/*
	 * Deux mots clefs sont à connaitre à propos du while :
		* break : permet d'arrêter l'exécution d'une boucle
		* continue : permet de relancer un tour de boucle

	 * /!\ Dans l'exemple ci dessous nous avons une boucle infinie, heureusement,
	   celle çi peut être arrêté grâce à une condition. Par pitié, ne faites jamais
	   de boucles infinies sans conditions
	 */

	while (1) {
		printf("Please, give me another 10 : ");
		scanf("%d", &myVar); // On récupère la saisie de l'utilisateur

		// Si l'utilisateur nous donne un 10, on arrête le while
		if (myVar == 10) {
			break;
		}
	}



	return 0;
}
