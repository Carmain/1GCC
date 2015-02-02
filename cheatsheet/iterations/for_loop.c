// /!\ Les parties du code non commentés sont expliqués dans d'autres tutoriels !

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	/* Les boucles for permettent de faire un nombre précis d'itérations selon 3 conditions :
		* Le nombre de départ
		* La limite (tant que la condition sera à true, la boucle continuera)
		* Le pas de la boucle

	 * L'exemple sera décliné en deux :
		* Un premier conforme pour la version C89 (ainsi qu'aux versions supérieures)
		* Un second conforme à la version C99 (non comptatible avec la version C89)

	 * L'idéal est que le code soit exécutable avec la version C99, cela demande
	   une petite modification selon vos IDE, je vous laisse chercher la solution :)
	 */

	printf(" * Loop in C89 : \n");

	// Exemple en C89 : la déclaration de i est à l'extérieur du for
	int i; // On déclare i à L'EXTERIEUR du for
	for (i = 0; i < 10; i ++) {
		printf("Value of i : %d\n", i);
	}
	/*
	 * Trois instructions séparés par des ";":
		* La valeur de départ (ici 0)
		* La condition qui tant qu'elle sera à true fera tourner la boucle
		* Le pas de la boucle (ici 1 par 1)
	 */

	// -----------------------
	printf("\n");
	// -----------------------

	printf(" * Loop in C99 : \n");

	// Exemple en C99 : la déclaration du i est à l'intérieur du for
	for (int j = 0; j < 10; j ++) {
		printf("Value of i : %d\n", j);
	}

	// -----------------------
	printf("\n");
	// -----------------------

	printf(" * Nested for : \n");

	/*
	 * for imbriqués :
	 * Comme toutes instructions du genre while ou if, il est possible de les imbriquer
	 * Cela peux servir par exemple à parcourir des tableaux à 2 dimensions.
	 */

	for (int a = 0; a <= 10; a ++) { // Premier for
		printf("Table de %d : ", a);
		for (int b = 0; b <= 10; b ++) { // Second for inclus dans le second
			printf("%d ", b * a); // On affiche le produit de a et b
		}
		printf("\n");
	}

	// -----------------------
	printf("\n");
	// -----------------------

	printf(" * for like a while : \n");

	/*
	 * le for déguisé en while (Non conseillé)
	 * On ne spécifie que la seconde condition. le for s'exécutera tant que cette dernière
	   est vraie.
	 */
	int my_var;
	for(; my_var != 10 ;) {
		printf("Please enter the number 10 : ");
		scanf("%d", &my_var);
	}

	// -----------------------
	printf("\n");
	// -----------------------


	printf(" * for like a while(true) : \n");

	/*
	 * le for déguisé en while(true) (non conseillé non plus)
	 * ATTENTION BOUCLE INFINIE! Pensez à votre condition d'arrêt
	 */
	int my_other_var;
	for(;;) { // Aucune condition n'est remplie, le for va tourner à l'infini!
		printf("Please enter the number 10 for the last time : ");
		scanf("%d", &my_other_var);

		// On donne une possibilité d'arrêter la boucle
		if (my_other_var == 10) {
			break; // Comme le while, le break arrête le processus de boucle
		}
	}

	// -----------------------
	printf("\n");
	// -----------------------

	printf(" * while like a for : \n");

	/*
	 * Le while déguisé en for
	 * Nous avons vu que le for demandait 3 conditions, ces dernières sont parfaitement
	   réalisable dans un while.

	 * ici nous allons au pas de 2 au lieu de 1 comme les exemples précédents
	   += 2 revient à faire un whileVar + 2
	 */

	int while_var = 0; // Premier élément
	while (while_var < 10) { // Second élément
		printf("Value of myVar : %d\n", while_var);
		while_var += 2; // Troisème élément
	}

	return 0;
}
