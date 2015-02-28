#include <stdio.h>
#include <stdlib.h>

int main(void) {

	/* Le swich case est une condition permettant d'éviter d'enchaîner les if
	 * de manière abusive.
	 *
	 * Le switch reste assez rarement utilisé. Il est nettement moins fréquent
	 * qu'un for ou un if. Cependant, il peut s'avérer très utile pour faire des
	 * menus et déterminer des actions en conséquences.
	 */

	// ----------------------------------------------------------------
	// La mauvaise façon de le faire : enchaîner les if et les else if.
	// ----------------------------------------------------------------

	int apples = 5; // On déclare notre entier et on lui affecte une valeur

	printf("How many apples do I've got ?\n");
	if (apples == 0) {
		printf("Sorry for you!\n");
	}

	// On echaîne les else if afin de proposer du contenu à chaque valeur
	else if (apples == 1) {
		printf("Enjoy !\n");
	}
	else if (apples == 2) {
		printf("Can you give me your second apple ?\n");
	}
	else if (apples == 3) {
		printf("It's pretty nice !\n");
	}

	// Valeur par défaut si aucune des conditions n'est réalisé
	else {
		printf("I don't have anything to say...\n");
	}

	// -----------------------------------------------------------------
	// La bonne façon de le faire : le switch case avec options default.
	// -----------------------------------------------------------------

	// On va tester la condition sur notre nombre de pommes.
	switch(apples) { // Le switch sera inclus dans des parenthèses
		case 0 : // Si le cas est égal (==) à 0
			printf("Sorry for you!\n"); // On exécute le code en conséquence
			break; // Le break marque la fin de l'instruction pour le cas
		case 1 :
			printf("Enjoy !\n");
			break;
		case 2 :
			printf("Can you give me your second apple ?\n");
			break;
		case 3 :
			printf("It's pretty nice !\n");
			break;
		default : // Si aucune condition au dessus n'est vraie (else)
			printf("I don't have anything to say...\n");
			break;
	}

	/*
	 * A RETENIR : le break permet de définir la fin des instructions pour le cas,
	 * Si jamais il est oublié, les cas suivants seront aussi exécutés jusqu'à la
	 * rencontre du prochain break ou de la fin du switch.
	 *
	 * Le break recontré va faire sortir le "lecteur d'instruction" en dehors des
	 * accolades du switch
	 */

	// Exécution de plusieurs cas en même temps

	apples = 1; // Nous nous retrouvons qu'avec une seule pomme !

	switch(apples) {
	    /* Comme dit plus haut, les cas s'exécutent tant qu'un break
		 * n'est pas la pour les arrêter. On peux donc combiner les cas.
		 */
		case 1 :
		case 2 : // Cela revient à faire if (apples == 1 || apples == 2)
			printf("How can you get 1 and 2 apples ?\n");
			break;
		case 3 : // On n'exécute le cas que si le nombreest égal à 3 (==)
			printf("Oh! You have 3 apples !\n");
			break;
		// Le default n'est pas obligatoire
	}

	return 0;
}

