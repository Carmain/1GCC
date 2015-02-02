// /!\ Les parties du code non commentés sont expliqués dans d'autres tutoriels !

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	printf(" * First example :\n");

	// La boucle while permet de répéter un certain nombre de fois selon une condition
	int my_var;
	while (my_var != 10) { // tant que myVar est différent de 10 on va boucler
		printf("Please, give me a 10 : ");
		scanf("%d", &my_var); // On récupère la saisie de l'utilisateur
	}

	// --------------------------
	printf("\n");
	// --------------------------

	printf(" * Second example :\n");

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
		scanf("%d", &my_var); // On récupère la saisie de l'utilisateur

		// Si l'utilisateur nous donne un 10, on arrête le while
		if (my_var == 10) {
			break;
		}
	}

	printf("\n");
	printf(" * Third example :\n");

	// Un autre exemple avec le continue, regardez le résultat !
	int a = 0;
	while (a != 10) {
		a++; // On incrémente a (revient à faire a + 1)
		if (a == 4) {
			// Si a est égal à 4 on saute le déroulement du while
			continue;
		}
		printf("Value of a : %d\n", a);
	}

	// --------------------------
	printf("\n");
	// --------------------------

	printf(" * Last example :\n");

	/*
	 * Le do...while
	 * A la différence du while, le do...while permettera l'exécution au moins une fois
	   des instructions avant la vérification de la condition.
	 * La syntaxe est cependant totalement différente.
	 * ATTENTION de ne pas oublier le ; à la fin du do...while!
	 */

	// On commence par le do
	do {
		// Les instructions sont dans les accolades
		printf("Come on! Ge me for the last time a 10 : ");
		scanf("%d", &my_var);
	} while (my_var != 10); // La condition est déterminé à la fin avec un ;

	return 0;
}
